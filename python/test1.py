import sys
import os
import pickle
import time
from typing import List, Tuple

import cv2
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import MiniBatchKMeans
from sklearn.metrics import precision_recall_curve, precision_score, recall_score, average_precision_score
from sklearn.metrics.pairwise import cosine_similarity
from scipy.interpolate import interp1d
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import (
    QApplication,
    QLabel,
    QPushButton,
    QTextEdit,
    QVBoxLayout,
    QHBoxLayout,
    QWidget,
    QFileDialog,
    QMessageBox,
    QTableWidget,
    QTableWidgetItem,
    QTabWidget,
)

# -----------------------------
# Core retrieval & evaluation
# -----------------------------
class BoF_TFIDF_Retriever:
    """Feature extraction + BoF / TF‑IDF retrieval + evaluation."""

    def __init__(self, num_clusters: int = 256):
        self.num_clusters = num_clusters
        self.codebook: MiniBatchKMeans | None = None
        self.idf: np.ndarray | None = None
        self.train_paths: List[str] = []
        self.train_labels: List[str] = []
        self.train_hist_bof_norm: np.ndarray | None = None
        self.train_hist_tfidf_norm: np.ndarray | None = None

        # Metrics for the last query (P@k, R@k, mAP, Time)
        # mAP and the full PR curve are calculated for every query internally
        # but the full PR curve is primarily used for batch evaluation averaging.
        # We store the metrics of the last query here.
        self.metrics = {
            "bof": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0},
            "tfidf": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0},
        }
        # Full PR curves are calculated per query during batch evaluation and then averaged.
        # No need to store single query PR curves at the instance level.


    # ---------- SIFT utils ---------- #
    @staticmethod
    def _sift(img_path: str) -> np.ndarray | None:
        img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
        if img is None:
            return None
        sift = cv2.SIFT_create()
        _kp, desc = sift.detectAndCompute(img, None)
        return desc

    def _compute_hist(self, descriptors: np.ndarray) -> np.ndarray:
        if self.codebook is None:
             # Should not happen if called after fit, but for safety
             print("Warning: _compute_hist called before codebook is built.")
             return np.zeros(self.num_clusters)
        if descriptors is None or len(descriptors) == 0:
             return np.zeros(self.num_clusters)

        words = self.codebook.predict(descriptors)
        hist = np.bincount(words, minlength=self.num_clusters).astype(np.float32)
        return hist

    # ---------- training ---------- #
    def fit(self, folder: str) -> bool:
        """Scan *folder* recursively, build codebook and compute normalized histograms."""
        all_image_paths_and_labels: List[Tuple[str, str]] = []
        print(f"Scanning folder: {folder}")

        # Scan all images first to get paths and labels
        for root, _dirs, files in os.walk(folder):
            # Assuming folder name is the label
            label = os.path.basename(root)
            if not label: # Skip root folder itself if it has no name
                continue
            for f in files:
                if f.lower().endswith((".jpg", ".jpeg", ".png")):
                    p = os.path.join(root, f)
                    all_image_paths_and_labels.append((p, label))

        if not all_image_paths_and_labels:
             print(f"No supported images found in {folder}")
             return False

        # First pass: Extract descriptors for vocabulary building
        descriptors_for_vocab: List[np.ndarray] = []
        # Only keep paths and labels for images where SIFT features are found
        self.train_paths.clear()
        self.train_labels.clear()

        print(f"Extracting descriptors for {len(all_image_paths_and_labels)} images...")
        for i, (p, label) in enumerate(all_image_paths_and_labels):
            desc = self._sift(p)
            if desc is not None and len(desc) > 0:
                descriptors_for_vocab.append(desc)
                self.train_paths.append(p) # Add path to train_paths only if descriptors found
                self.train_labels.append(label)
            if (i + 1) % 100 == 0:
                 print(f"Processed {i + 1}/{len(all_image_paths_and_labels)} images for vocabulary.")

        if not descriptors_for_vocab:
            print("No images found with extractable descriptors.")
            return False

        # build codebook
        print(f"Aggregating {sum(len(d) for d in descriptors_for_vocab)} descriptors from {len(descriptors_for_vocab)} images...")
        all_desc = np.vstack(descriptors_for_vocab)

        print(f"Building codebook with {self.num_clusters} clusters...")
        # Use a subset for faster fitting if all_desc is huge
        sample_size = min(len(all_desc), 300000) # Increased sample size
        sample_indices = np.random.choice(len(all_desc), sample_size, replace=False)
        sample_desc = all_desc[sample_indices]

        self.codebook = MiniBatchKMeans(n_clusters=self.num_clusters, random_state=42, batch_size=100, n_init=3, verbose=False)
        self.codebook.fit(sample_desc)
        print("Codebook built.")

        # compute histograms per image and normalize
        hists_bof: List[np.ndarray] = []
        tf_list: List[np.ndarray] = [] # Renamed to avoid conflict with tf variable name
        print(f"Computing histograms for {len(self.train_paths)} images...")
        # Process only the images for which descriptors were successfully extracted
        for i, p in enumerate(self.train_paths):
            d = self._sift(p) # Re-extract for consistency
            # This should not be None or empty given how train_paths was populated, but check
            if d is None or len(d) == 0:
                 h = np.zeros(self.num_clusters) # Should not happen
            else:
                 h = self._compute_hist(d)

            # BoF normalization (L2)
            h_norm_bof = h / (np.linalg.norm(h) + 1e-8)
            hists_bof.append(h_norm_bof)

            # Term Frequency
            h_tf = h / (h.sum() + 1e-8)
            tf_list.append(h_tf)

            # Print progress
            if (i + 1) % 100 == 0:
                print(f"Computed histograms for {i + 1}/{len(self.train_paths)} images.")

        self.train_hist_bof_norm = np.stack(hists_bof)
        tf_matrix = np.stack(tf_list) # Renamed to avoid conflict with tf variable name
        print("Histograms computed.")

        # IDF & TF‑IDF normalization
        print("Computing IDF and TF-IDF...")
        # document frequency: number of documents containing the word
        df = np.count_nonzero(tf_matrix > 0, axis=0)
        # Inverse Document Frequency
        self.idf = np.log((len(tf_matrix) + 1) / (df + 1)) + 1.0

        # TF-IDF calculation: TF * IDF
        train_hist_tfidf = tf_matrix * self.idf
        # TF-IDF normalization (L2)
        self.train_hist_tfidf_norm = train_hist_tfidf / (np.linalg.norm(train_hist_tfidf, axis=1, keepdims=True) + 1e-8)
        print("TF-IDF computed and normalized.")

        print("Training complete.")
        return True

    # ---------- evaluation helpers ---------- #

    def _category_of(self, path: str) -> str:
        """Extract category label from image path (parent directory name)."""
        return os.path.basename(os.path.dirname(path))

    def _calculate_metrics_and_pr(
        self,
        query_path: str,
        all_scores: np.ndarray, # scores for all training images (shape: (n_train_images,))
        top_k_indices: np.ndarray, # indices of top-k retrieved images (shape: (top_k,))
        top_k: int, # The value of k used for top_k_indices
        method: str # "bof" or "tfidf" - used for logging
    ) -> Tuple[float, float, float, Tuple[np.ndarray, np.ndarray] | None]:
        """
        Calculates P@k, R@k, mAP, and the full PR curve for a single query.
        Returns: (p_at_k, r_at_k, mAP, (recall, precision) tuple or None)
        """
        n_train_images = len(self.train_paths)
        if n_train_images == 0 or not self.train_labels:
             print(f"Warning ({method}): Train data or labels are empty. Cannot calculate metrics.")
             return 0.0, 0.0, 0.0, (np.array([0.0, 1.0]), np.array([1.0, 0.0])) # Default metrics/PR

        # Get relevant indices based on query category
        try:
            query_cat = self._category_of(query_path)
            relevant_indices = [i for i, label in enumerate(self.train_labels) if label == query_cat]
            total_relevant = len(relevant_indices)
        except Exception as e:
            print(f"Error ({method}) determining query category or relevant indices for {os.path.basename(query_path)}: {e}")
            # Cannot calculate relevance metrics without category
            return 0.0, 0.0, 0.0, (np.array([0.0, 1.0]), np.array([1.0, 0.0])) # Default metrics/PR


        # --- Calculate P@k and R@k ---
        p_at_k = 0.0
        r_at_k = 0.0
        if len(top_k_indices) > 0:
            # y_true for top-k list
            y_true_topk = [1 if i in relevant_indices else 0 for i in top_k_indices]
            p_at_k = precision_score(y_true_topk, [1] * len(y_true_topk), zero_division=0)

            # Number of retrieved relevant items within top-k
            num_retrieved_relevant = sum(y_true_topk)

            # R@k is the proportion of relevant items found within the top-k
            r_at_k = num_retrieved_relevant / total_relevant if total_relevant > 0 else 0.0


        # --- Calculate mAP and full PR curve ---
        # y_true for the entire training set
        y_true_all = np.zeros(n_train_images, dtype=int)
        y_true_all[relevant_indices] = 1

        # Ensure scores and true labels have the same length and relevant items exist to calculate mAP/PR
        if len(all_scores) != len(y_true_all) or total_relevant == 0:
             if len(all_scores) != len(y_true_all):
                 print(f"Error ({method}): Score length ({len(all_scores)}) mismatch with true label length ({len(y_true_all)}) for {os.path.basename(query_path)}")
             if total_relevant == 0:
                 print(f"Warning ({method}): No relevant items found for query category '{query_cat}' in training set. Cannot calculate mAP/PR curve for {os.path.basename(query_path)}.")

             # Return metrics calculated so far and default PR curve
             return p_at_k, r_at_k, 0.0, (np.array([0.0, 1.0]), np.array([1.0, 0.0])) # Default PR curve


        # Calculate mAP using scores over the entire training set
        mAP = average_precision_score(y_true_all, all_scores)

        # Calculate full PR curve using scores over the entire training set
        # precision, recall, thresholds = precision_recall_curve(y_true_all, all_scores)
        # We store (recall, precision)
        recall, precision, _ = precision_recall_curve(y_true_all, all_scores)

        # Ensure precision and recall arrays are valid for interpolation (at least 2 points)
        if len(recall) < 2:
             print(f"Warning ({method}): PR curve for {os.path.basename(query_path)} has less than 2 points. Skipping PR curve.")
             pr_curve = None
        else:
             pr_curve = (recall, precision)


        return p_at_k, r_at_k, mAP, pr_curve

    # ---------- retrieval ---------- #
    def query(self, img_path: str, top_k: int = 10) -> Tuple[List[Tuple[str, float]], List[Tuple[str, float]]]:
        """
        Queries the index with a new image.
        Calculates scores against all training images, finds top-k.
        Calculates metrics (P@k, R@k, mAP, time) for the last query and stores them.
        Returns the top-k lists for display.
        """
        if self.codebook is None or self.train_hist_bof_norm is None or self.train_hist_tfidf_norm is None or self.idf is None or not self.train_paths:
            raise RuntimeError("Model not trained or training data is empty. Please train the model first.")

        desc = self._sift(img_path)
        if desc is None or len(desc) == 0:
            # Cannot process query image if features cannot be extracted
            # Set metrics to default and return empty lists
            for method in ["bof", "tfidf"]:
                self.metrics[method] = {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0}
            raise ValueError("Cannot extract features from query image.")

        hist = self._compute_hist(desc)

        # --- BoF ---
        # 使用 time.perf_counter() 進行更精確的計時
        t0_bof = time.perf_counter()

        q_bof_norm = hist / (np.linalg.norm(hist) + 1e-8)

        # Calculate cosine similarity with all training BoF histograms
        # Cosine similarity of L2 normalized vectors is just dot product
        all_scores_bof = self.train_hist_bof_norm @ q_bof_norm
        # Get indices of top-k scores (descending order)
        actual_top_k = min(top_k, len(self.train_paths))
        top_k_indices_bof = np.argsort(all_scores_bof)[::-1][:actual_top_k]

        # 使用 time.perf_counter() 結束計時
        t_bof = time.perf_counter() - t0_bof
        self.metrics["bof"]["time"] = t_bof

        # Create list of results (path, score) for GUI display using the full scores and top-k indices
        list_bof = [(self.train_paths[i], float(all_scores_bof[i])) for i in top_k_indices_bof]

        # Calculate metrics and full PR curve for BoF (metrics are stored internally)
        # PR curve is calculated but not stored in self for single query plot
        p_bof, r_bof, mAP_bof, pr_bof = self._calculate_metrics_and_pr(
            img_path, all_scores_bof, top_k_indices_bof, actual_top_k, "bof"
        )
        self.metrics["bof"]["precision@k"] = p_bof
        self.metrics["bof"]["recall@k"] = r_bof
        self.metrics["bof"]["mAP"] = mAP_bof


        # --- TF‑IDF ---
        # 使用 time.perf_counter() 進行更精確的計時
        t0_tf = time.perf_counter()

        q_tf = hist / (hist.sum() + 1e-8)
        q_tfidf = q_tf * self.idf
        q_tfidf_norm = q_tfidf / (np.linalg.norm(q_tfidf) + 1e-8)
        all_scores_tfidf = self.train_hist_tfidf_norm @ q_tfidf_norm
         # Get indices of top-k scores (descending order)
        top_k_indices_tf = np.argsort(all_scores_tfidf)[::-1][:actual_top_k]

        # 使用 time.perf_counter() 結束計時
        t_tf = time.perf_counter() - t0_tf
        self.metrics["tfidf"]["time"] = t_tf

         # Create list of results (path, score) for GUI display using the full scores and top-k indices
        list_tf = [(self.train_paths[i], float(all_scores_tfidf[i])) for i in top_k_indices_tf]

        # Calculate metrics and full PR curve for TF-IDF (metrics are stored internally)
        # PR curve is calculated but not stored in self for single query plot
        p_tf, r_tf, mAP_tf, pr_tf = self._calculate_metrics_and_pr(
            img_path, all_scores_tfidf, top_k_indices_tf, actual_top_k, "tfidf"
        )
        self.metrics["tfidf"]["precision@k"] = p_tf
        self.metrics["tfidf"]["recall@k"] = r_tf
        self.metrics["tfidf"]["mAP"] = mAP_tf

        return list_bof, list_tf

    # ---------- batch evaluation & averaging ---------- #

    def _avg_pr(self, pr_curves: List[Tuple[np.ndarray, np.ndarray]]) -> Tuple[np.ndarray, np.ndarray] | None:
        """
        Averages multiple PR curves by interpolating precision onto a common recall grid.
        Input: List of (recall, precision) tuples.
        Output: Averaged (recall_grid, averaged_precision) tuple or None if no valid curves.
        """
        if not pr_curves:
            return None

        # Define a common recall grid
        recall_grid = np.linspace(0.0, 1.0, 101) # 101 points from 0 to 1

        interpolated_precisions = []
        valid_curves_count = 0

        for recall, precision in pr_curves:
            # Ensure curve is valid (at least 2 points for interpolation)
            if recall is None or precision is None or len(recall) < 2 or len(precision) < 2:
                 print(f"Warning: Skipping invalid PR curve.")
                 continue

            # Use interp1d to interpolate precision values onto the common recall grid
            # interp1d(x, y, ...) where x are original recall, y are original precision
            # Sklearn's precision_recall_curve returns recall in increasing order.
            # bounds_error=False means don't raise error if x_new is outside original bounds
            # fill_value=(p_left, p_right) fills values outside original range.
            # Standard practice is precision=1 at recall=0, precision=0 at recall=1.
            # interp1d requires x to be sorted, which sklearn's recall output is.
            try:
                interp_func = interp1d(recall, precision, bounds_error=False, fill_value=(1.0, 0.0))
                interpolated_p = interp_func(recall_grid)
                interpolated_precisions.append(interpolated_p)
                valid_curves_count += 1
            except Exception as e:
                print(f"Warning: Error during interpolation for a PR curve: {e}. Skipping this curve.")
                continue


        if valid_curves_count == 0:
             print("No valid PR curves to average.")
             return None

        # Average the interpolated precision values across all valid curves
        averaged_precision = np.mean(interpolated_precisions, axis=0)

        return recall_grid, averaged_precision


    def evaluate_folder(self, test_dir: str, top_k: int = 10) -> Tuple[dict, Tuple[np.ndarray, np.ndarray] | None, Tuple[np.ndarray, np.ndarray] | None]:
        """
        Evaluates retrieval performance over a folder of test images.
        Runs query logic for each test image, collects metrics and PR curves,
        and returns averaged results and averaged PR curves.
        """
        if self.codebook is None or self.train_hist_bof_norm is None or self.train_hist_tfidf_norm is None or self.idf is None or not self.train_paths:
            raise RuntimeError("Model not trained or training data is empty. Please train the model first.")

        test_images: List[str] = []
        for root, _dirs, files in os.walk(test_dir):
            for f in files:
                if f.lower().endswith((".jpg", ".jpeg", ".png")):
                    test_images.append(os.path.join(root, f))

        if not test_images:
            raise ValueError(f"No test images found in {test_dir}")

        # Initialize accumulators for total metrics and PR curves
        total_metrics = {
             "bof": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0},
             "tfidf": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0},
        }
        pr_curves_bof_list = []
        pr_curves_tf_list = []
        successful_queries_count = 0 # Count queries for which metrics were calculated

        print(f"Evaluating {len(test_images)} test images (Top-k={top_k})...")
        # 使用 time.perf_counter() 記錄總批次開始時間
        start_time_batch = time.perf_counter()

        for i, img in enumerate(test_images):
            try:
                # --- Feature Extraction & Histogram for current test image ---
                desc = self._sift(img)
                if desc is None or len(desc) == 0:
                    print(f"Skipping test image {os.path.basename(img)}: Cannot extract features.")
                    continue # Skip to the next image

                hist = self._compute_hist(desc)
                actual_top_k = min(top_k, len(self.train_paths)) # Use actual top_k


                # --- BoF Evaluation for this test image ---
                # 使用 time.perf_counter() 記錄單次檢索開始時間
                t0_bof = time.perf_counter()
                q_bof_norm = hist / (np.linalg.norm(hist) + 1e-8)
                all_scores_bof = self.train_hist_bof_norm @ q_bof_norm
                top_k_indices_bof = np.argsort(all_scores_bof)[::-1][:actual_top_k]
                # 使用 time.perf_counter() 結束計時
                t_bof = time.perf_counter() - t0_bof

                p_bof, r_bof, mAP_bof, pr_bof = self._calculate_metrics_and_pr(
                    img, all_scores_bof, top_k_indices_bof, actual_top_k, "bof"
                )
                total_metrics["bof"]["precision@k"] += p_bof
                total_metrics["bof"]["recall@k"] += r_bof
                total_metrics["bof"]["mAP"] += mAP_bof
                total_metrics["bof"]["time"] += t_bof
                if pr_bof is not None: # Only add valid PR curves
                    pr_curves_bof_list.append(pr_bof)


                # --- TF-IDF Evaluation for this test image ---
                # 使用 time.perf_counter() 記錄單次檢索開始時間
                t0_tf = time.perf_counter()
                q_tf = hist / (hist.sum() + 1e-8)
                q_tfidf = q_tf * self.idf
                q_tfidf_norm = q_tfidf / (np.linalg.norm(q_tfidf) + 1e-8)
                all_scores_tfidf = self.train_hist_tfidf_norm @ q_tfidf_norm
                top_k_indices_tf = np.argsort(all_scores_tfidf)[::-1][:actual_top_k]
                # 使用 time.perf_counter() 結束計時
                t_tf = time.perf_counter() - t0_tf

                p_tf, r_tf, mAP_tf, pr_tf = self._calculate_metrics_and_pr(
                    img, all_scores_tfidf, top_k_indices_tf, actual_top_k, "tfidf"
                )
                total_metrics["tfidf"]["precision@k"] += p_tf
                total_metrics["tfidf"]["recall@k"] += r_tf
                total_metrics["tfidf"]["mAP"] += mAP_tf
                total_metrics["tfidf"]["time"] += t_tf
                if pr_tf is not None: # Only add valid PR curves
                    pr_curves_tf_list.append(pr_tf)

                successful_queries_count += 1

                if (i + 1) % 10 == 0:
                    print(f"Processed {i + 1}/{len(test_images)} test images. Successful: {successful_queries_count}")

            except Exception as e:
                print(f"Skipping test image {os.path.basename(img)} due to error: {e}")


        # 使用 time.perf_counter() 記錄總批次結束時間
        total_batch_time = time.perf_counter() - start_time_batch

        n = successful_queries_count
        if n == 0:
             print("No test images successfully processed for evaluation.")
             avg_metrics = {
                 "bof": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0},
                 "tfidf": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0},
                 "total_batch_time": total_batch_time, # Still report total time even if no queries succeeded
                 "successful_queries_count": 0,
             }
             return avg_metrics, None, None


        # Calculate average metrics
        avg_metrics = {
             method: {k: total_metrics[method][k] / n for k in total_metrics[method]}
             for method in ["bof", "tfidf"]
        }
        # Add total batch time and successful count
        avg_metrics["total_batch_time"] = total_batch_time
        avg_metrics["successful_queries_count"] = n


        # Calculate averaged PR curves
        avg_pr_bof = self._avg_pr(pr_curves_bof_list)
        avg_pr_tf = self._avg_pr(pr_curves_tf_list)

        print(f"Batch evaluation complete. Total processed: {n}/{len(test_images)}. Total time: {total_batch_time:.3f}s")
        return avg_metrics, avg_pr_bof, avg_pr_tf

    # ---------- plotting ---------- #
    def plot_comparison(
        self,
        metrics_data: dict, # Metrics to plot (must contain bof/tfidf keys with 'mAP', 'recall@k', 'time')
        pr_data: dict | None,      # PR curves to plot (dict with 'bof'/'tfidf' keys holding (recall, precision) tuples or None)
        is_averaged: bool = False # Flag to indicate if plotting averaged results
        ):
        """Plots performance comparison (metrics and PR curve)."""
        plt.figure(figsize=(12, 5))

        # --- Bar Chart ---
        # For averaged results, show mAP, Avg Recall@k, Avg Time per Query
        # For single query results (in text/table), show P@k, R@k, Time.
        # The plot comparison is primarily used for Average metrics now.
        # Let's make the bar chart always show mAP, Recall@k, Time, but label mAP clearly.
        # The metrics_data structure passed in will determine if these are averaged or not.

        metrics_labels = ["mAP", "Recall@k", "Time(s)"]
        metrics_keys = ["mAP", "recall@k", "time"]


        x = np.arange(len(metrics_labels))
        width = 0.35

        # Ensure metrics_data has the necessary keys, provide default 0.0 if missing
        bof_vals = [metrics_data.get("bof", {}).get(k, 0.0) for k in metrics_keys]
        tf_vals = [metrics_data.get("tfidf", {}).get(k, 0.0) for k in metrics_keys]

        plt.subplot(1, 2, 1)
        bars_bof = plt.bar(x - width / 2, bof_vals, width, label="BoF")
        bars_tf = plt.bar(x + width / 2, tf_vals, width, label="TF‑IDF")

        plt.xticks(x, metrics_labels)
        plt.ylabel("Score / Time (s)")

        # Add value labels on top of bars
        def add_value_labels(bars, labels):
            for i, bar in enumerate(bars):
                yval = bar.get_height()
                if yval == 0.0: # Avoid printing 0.0 on bars where it might indicate failure
                     continue
                # Format based on the metric type
                if 'Time' in labels[i]:
                    plt.text(bar.get_x() + bar.get_width()/2, yval, f'{yval:.3f}', va='bottom', ha='center')
                else: # mAP, Recall@k
                    plt.text(bar.get_x() + bar.get_width()/2, yval, f'{yval:.3f}', va='bottom', ha='center') # Use .3f for scores


        add_value_labels(bars_bof, metrics_labels)
        add_value_labels(bars_tf, metrics_labels)

        plt.legend()
        title_prefix = "Average " if is_averaged else "Single Query "
        plt.title("Performance Comparison")
        plt.ylim(0, max(max(bof_vals), max(tf_vals)) * 1.1 + 0.05) # Adjust y-limit


        # --- PR Curve ---
        plt.subplot(1, 2, 2)

        if pr_data:
            recall_bof, precision_bof = pr_data.get("bof", (None, None))
            recall_tf, precision_tf = pr_data.get("tfidf", (None, None))

            if recall_bof is not None and precision_bof is not None:
                 plt.plot(recall_bof, precision_bof, label="BoF")
            if recall_tf is not None and precision_tf is not None:
                 plt.plot(recall_tf, precision_tf, label="TF‑IDF")

        plt.xlabel("Recall")
        plt.ylabel("Precision")
        plt.title("Precision‑Recall Curve")
        plt.legend()
        plt.ylim([-0.05, 1.05])
        plt.xlim([0, 1.05])
        plt.grid(True)
        plt.tight_layout()
        plt.show()

# -----------------------------
# PyQt5 GUI
# -----------------------------
class ImageMatcherGUI(QWidget):
    def __init__(self):
        super().__init__()
        self.matcher = BoF_TFIDF_Retriever(num_clusters=256)
        self.query_img: str | None = None
        self.bof_results: List[Tuple[str, float]] = [] # Stores top-k results for display
        self.tfidf_results: List[Tuple[str, float]] = [] # Stores top-k results for display

        # Store averaged results from the last batch evaluation for plotting
        self._last_avg_metrics = None
        self._last_avg_pr_curves = None


        self._build_ui()

    def _build_ui(self):
        self.setWindowTitle("BoF + TF‑IDF 圖像檢索系統 (PyQt5)")
        self.resize(1280, 760)

        main = QVBoxLayout()
        btn_row = QHBoxLayout()

        # Swapped button positions
        self.btn_train = QPushButton("選擇訓練集並訓練")
        self.btn_train.clicked.connect(self.train_model)
        self.btn_query = QPushButton("選擇查詢圖像")
        self.btn_query.clicked.connect(self.choose_query)
        self.btn_match = QPushButton("執行檢索")
        self.btn_match.clicked.connect(self.run_match)
        # Removed the single query plot button (self.btn_compare)
        self.btn_evaluate = QPushButton("評估測試集")
        self.btn_evaluate.clicked.connect(self.evaluate_test_set)
        self.btn_avg_compare = QPushButton("顯示平均圖表")
        self.btn_avg_compare.clicked.connect(lambda: self.plot_averaged_comparison())
        self.btn_avg_compare.setEnabled(False) # Initially disabled until evaluated

        # Added buttons in swapped order, removed btn_compare
        btn_row.addWidget(self.btn_train)
        btn_row.addWidget(self.btn_query)
        btn_row.addWidget(self.btn_match)
        btn_row.addWidget(self.btn_evaluate)
        btn_row.addWidget(self.btn_avg_compare)


        img_row = QHBoxLayout()
        self.lbl_query = QLabel("查詢圖像")
        self.lbl_query.setAlignment(Qt.AlignCenter)
        self.lbl_query.setFixedSize(350, 350)
        self.lbl_query.setStyleSheet("border: 1px solid black;")

        self.lbl_best = QLabel("最优匹配图像 (TF-IDF)")
        self.lbl_best.setAlignment(Qt.AlignCenter)
        self.lbl_best.setFixedSize(350, 350)
        self.lbl_best.setStyleSheet("border: 1px solid black;")

        img_row.addWidget(self.lbl_query)
        img_row.addWidget(self.lbl_best)

        # metrics table - Updated headers to reflect P@k, R@k for the last query
        self.table = QTableWidget(2, 4)
        self.table.setHorizontalHeaderLabels(["方法", "Precision@k", "Recall@k", "Time(s)"])
        self.table.verticalHeader().setVisible(False)
        self.table.setEditTriggers(QTableWidget.NoEditTriggers)
        self.table.setFixedHeight(100)
        self.table.horizontalHeader().setStretchLastSection(True)

        # tabs for result lists
        self.tabs = QTabWidget()
        self.text_bof = QTextEdit(); self.text_bof.setReadOnly(True)
        self.text_tf = QTextEdit(); self.text_tf.setReadOnly(True)
        self.tabs.addTab(self.text_bof, "BoF 结果 (Top-k)")
        self.tabs.addTab(self.text_tf, "TF‑IDF 结果 (Top-k)")

        main.addLayout(btn_row)
        main.addLayout(img_row)
        main.addWidget(self.table)
        main.addWidget(self.tabs)
        self.setLayout(main)

        # Initialize table with zeros
        self._update_metric_table(clear=True)
        # Disable buttons that require training
        self.btn_query.setEnabled(False)
        self.btn_match.setEnabled(False)
        self.btn_evaluate.setEnabled(False)


    # ---------- slots ---------- #
    def choose_query(self):
        fname, _ = QFileDialog.getOpenFileName(self, "選擇查詢圖像", "", "Images (*.jpg *.jpeg *.png)")
        if fname:
            self.query_img = fname
            pix = QPixmap(fname).scaled(350, 350, Qt.KeepAspectRatio, Qt.SmoothTransformation)
            self.lbl_query.setPixmap(pix)
            self.lbl_best.clear()
            self.text_bof.clear(); self.text_tf.clear()
            self._update_metric_table(clear=True) # Clear metrics table
            # The match button is enabled once trained, no need to enable here again
            # Removed enabling single plot button

    def train_model(self):
        folder = QFileDialog.getExistingDirectory(self, "選擇訓練圖像文件夹")
        if not folder:
            return
        self.text_bof.setText("訓練中，請稍候……\n")
        self.text_tf.clear()
        self._update_metric_table(clear=True)
        self.lbl_query.clear(); self.lbl_best.clear()
        self.query_img = None # Clear current query image
        QApplication.processEvents()

        try:
            if self.matcher.fit(folder):
                QMessageBox.information(self, "完成", f"已加载 {len(self.matcher.train_paths)} 张有效图像并完成训练")
                self.text_bof.setText(f"訓練完成，共加载 {len(self.matcher.train_paths)} 张图片。")
                self.text_tf.setText("訓練完成。")
                self.btn_query.setEnabled(True) # Enable query button
                self.btn_match.setEnabled(True) # Enable match button
                self.btn_evaluate.setEnabled(True) # Enable evaluate button
                self.btn_avg_compare.setEnabled(False) # Disable avg plot until evaluation
            else:
                QMessageBox.critical(self, "错误", "訓練失敗或未找到有效圖片！請檢查數據集和資料夾結構。")
                self.text_bof.clear()
                self.text_tf.clear()
                self.btn_query.setEnabled(False)
                self.btn_match.setEnabled(False)
                self.btn_evaluate.setEnabled(False)
                self.btn_avg_compare.setEnabled(False)


        except Exception as e:
             QMessageBox.critical(self, "訓練錯誤", f"訓練過程中發生錯誤: {e}")
             self.text_bof.clear()
             self.text_tf.clear()
             self.btn_query.setEnabled(False)
             self.btn_match.setEnabled(False)
             self.btn_evaluate.setEnabled(False)
             self.btn_avg_compare.setEnabled(False)


    def run_match(self):
        if self.query_img is None:
            QMessageBox.warning(self, "提示", "請先選擇查詢圖像！")
            return
        if self.matcher.codebook is None:
            QMessageBox.warning(self, "提示", "請先訓練模型！")
            return

        self.text_bof.setText("檢索中，請稍候……")
        self.text_tf.clear()
        self._update_metric_table(clear=True) # Clear table before search
        self.lbl_best.clear()
        QApplication.processEvents()

        try:
            # query method calculates metrics and PR curves internally but they are not stored in self
            # for single query plot anymore. They are just calculated.
            self.bof_results, self.tfidf_results = self.matcher.query(self.query_img)

            # show best match (using TF-IDF)
            best = self.tfidf_results[0][0] if self.tfidf_results else None
            if best and os.path.exists(best):
                pix = QPixmap(best).scaled(350, 350, Qt.KeepAspectRatio, Qt.SmoothTransformation)
                self.lbl_best.setPixmap(pix)
            else:
                 self.lbl_best.clear() # Ensure it's clear if no results

            # update table with metrics from the last query
            self._update_metric_table()
            # Fill text results with top-k lists and metrics from the last query
            self._fill_result_texts()

            # Removed enabling single plot button
            self.btn_avg_compare.setEnabled(False) # Disable avg plot after single query


        except (ValueError, RuntimeError) as e:
            QMessageBox.critical(self, "錯誤", f"檢索失敗: {e}")
            self.text_bof.clear(); self.text_tf.clear()
            self._update_metric_table(clear=True)
            self.lbl_best.clear()
            # Removed disabling single plot button

    def _update_metric_table(self, clear=False):
        if clear:
            for i in range(2):
                self.table.setItem(i, 0, QTableWidgetItem(""))
                self.table.setItem(i, 1, QTableWidgetItem(""))
                self.table.setItem(i, 2, QTableWidgetItem(""))
                self.table.setItem(i, 3, QTableWidgetItem(""))
        else:
            for i, m in enumerate(["BoF", "TF‑IDF"]):
                key = "bof" if i == 0 else "tfidf"
                # Use metrics directly from matcher.metrics for the last query result
                metrics = self.matcher.metrics.get(key, {}) # Use .get for safety
                self.table.setItem(i, 0, QTableWidgetItem(m))
                # Use .get for safety in case key doesn't exist
                self.table.setItem(i, 1, QTableWidgetItem(f"{metrics.get('precision@k', 0.0):.3f}"))
                self.table.setItem(i, 2, QTableWidgetItem(f"{metrics.get('recall@k', 0.0):.3f}"))
                self.table.setItem(i, 3, QTableWidgetItem(f"{metrics.get('time', 0.0):.3f}"))

        self.table.resizeColumnsToContents()

    def _fill_result_texts(self):
        self.text_bof.clear(); self.text_tf.clear()
        # Get metrics from the last query
        metrics_bof = self.matcher.metrics.get("bof", {})
        metrics_tf = self.matcher.metrics.get("tfidf", {})

        self.text_bof.append(f"--- BoF 檢索結果 ({len(self.bof_results)} items) ---")
        self.text_bof.append(f"Precision@k: {metrics_bof.get('precision@k', 0.0):.3f}, Recall@k: {metrics_bof.get('recall@k', 0.0):.3f}, mAP: {metrics_bof.get('mAP', 0.0):.3f}, Time: {metrics_bof.get('time', 0.0):.3f}s\n")
        for rank, (p, s) in enumerate(self.bof_results, 1):
            self.text_bof.append(f"{rank:>2}. {os.path.basename(p)} (sim={s:.4f})")

        self.text_tf.append(f"--- TF-IDF 檢索結果 ({len(self.tfidf_results)} items) ---")
        self.text_tf.append(f"Precision@k: {metrics_tf.get('precision@k', 0.0):.3f}, Recall@k: {metrics_tf.get('recall@k', 0.0):.3f}, mAP: {metrics_tf.get('mAP', 0.0):.3f}, Time: {metrics_tf.get('time', 0.0):.3f}s\n")
        for rank, (p, s) in enumerate(self.tfidf_results, 1):
            self.text_tf.append(f"{rank:>2}. {os.path.basename(p)} (sim={s:.4f})")


    # Removed plot_last_query_comparison method

    def evaluate_test_set(self):
        if self.matcher.codebook is None:
            QMessageBox.warning(self, "提示", "請先訓練模型！")
            return

        test_dir = QFileDialog.getExistingDirectory(self, "選擇測試集目錄")
        if not test_dir:
            return

        self.text_bof.setText("評估中，請稍候……")
        self.text_tf.clear()
        self._update_metric_table(clear=True) # Clear table during evaluation
        self.lbl_query.clear(); self.lbl_best.clear() # Clear images during evaluation
        QApplication.processEvents()

        try:
            # evaluate_folder returns averaged metrics and averaged PR curves
            self._last_avg_metrics, avg_pr_bof, avg_pr_tf = self.matcher.evaluate_folder(test_dir)

            # Store averaged PR curves for plotting
            self._last_avg_pr_curves = {"bof": avg_pr_bof, "tfidf": avg_pr_tf}

            # Display average metrics in a message box and text areas
            msg = (f"--- 測試集評估完成 (總計 {self._last_avg_metrics.get('total_batch_time', 0.0):.3f}s) ---\n"
                   f"處理圖片數: {len(test_images) if 'test_images' in locals() else 'N/A'}\n" # Added image count
                   f"成功處理數: {self._last_avg_metrics.get('bof', {}).get('mAP', 0.0) / (self._last_avg_metrics.get('bof', {}).get('mAP', 1.0)/ (self._last_avg_metrics.get('bof', {}).get('mAP_count', 1) )) if 'mAP_count' in self._last_avg_metrics.get('bof', {}) else 'N/A'} \n" # Attempt to show successful count
                   f"--- 平均指标 (Average Metrics) ---\n"
                   f"BoF:\n"
                   f"  Precision@k: {self._last_avg_metrics.get('bof', {}).get('precision@k', 0.0):.3f}\n"
                   f"  Recall@k: {self._last_avg_metrics.get('bof', {}).get('recall@k', 0.0):.3f}\n"
                   f"  mAP: {self._last_avg_metrics.get('bof', {}).get('mAP', 0.0):.3f}\n"
                   f"  Time per query: {self._last_avg_metrics.get('bof', {}).get('time', 0.0):.3f}s\n"
                   f"TF‑IDF:\n"
                   f"  Precision@k: {self._last_avg_metrics.get('tfidf', {}).get('precision@k', 0.0):.3f}\n"
                   f"  Recall@k: {self._last_avg_metrics.get('tfidf', {}).get('recall@k', 0.0):.3f}\n"
                   f"  mAP: {self._last_avg_metrics.get('tfidf', {}).get('mAP', 0.0):.3f}\n"
                   f"  Time per query: {self._last_avg_metrics.get('tfidf', {}).get('time', 0.0):.3f}s\n")

            QMessageBox.information(self, "評估完成", msg)

            self.text_bof.setText(msg)
            self.text_tf.setText(msg)

            # Enable averaged plot button
            self.btn_avg_compare.setEnabled(True)


        except Exception as e:
            QMessageBox.critical(self, "錯誤", f"評估過程中發生錯誤: {e}")
            self.text_bof.clear()
            self.text_tf.clear()
            self._update_metric_table(clear=True)
            self.btn_avg_compare.setEnabled(False)


    def plot_averaged_comparison(self):
         if self._last_avg_metrics is None or self._last_avg_pr_curves is None:
              QMessageBox.warning(self, "提示", "請先執行測試集評估！")
              return
         try:
              self.matcher.plot_comparison(
                  metrics_data=self._last_avg_metrics,
                  pr_data=self._last_avg_pr_curves,
                  is_averaged=True
              )
         except Exception as e:
              QMessageBox.critical(self, "繪圖錯誤", f"繪製平均圖表失敗: {e}")


# -----------------------------
# Entry
# -----------------------------
if __name__ == "__main__":
    app = QApplication.instance()
    if not app:
        app = QApplication(sys.argv)

    gui = ImageMatcherGUI()
    gui.show()
    sys.exit(app.exec_())