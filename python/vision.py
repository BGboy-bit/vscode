import sys
import time
import os
import pickle
import pathlib
from typing import List, Tuple
from time import perf_counter

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
    QCheckBox,
    QSpinBox,
)

class BoF_TFIDF_Retriever:
    """
    基于视觉单词袋（BoF）和 TF-IDF 的图像检索器
    1. 使用 SIFT 提取特征
    2. 使用 KMeans 生成视觉词典
    3. 计算图像的 BoF 直方图和 TF-IDF 特征
    4. 支持单张查询、批量评估和线性重排序
    5. 新增查询扩展（Query Expansion）功能
    """

    def __init__(self, num_clusters: int = 256):
        self.num_clusters = num_clusters
        self.codebook: MiniBatchKMeans | None = None
        self.idf: np.ndarray | None = None
        self.train_paths: List[str] = []
        self.train_labels: List[str] = []

        self.train_hist_bof_norm: np.ndarray | None = None
        self.train_hist_tfidf_norm: np.ndarray | None = None

        self.metrics = {
            "bof":    {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0},
            "tfidf":  {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0},
            "rerank": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0},
        }
    @staticmethod
    def _sift(img_path: str) -> np.ndarray | None:
        """
        使用 SIFT 提取图像的局部特征描述符
        :param img_path: 图像文件路径
        :return: 描述符数组或 None
        """
        img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
        if img is None:
            return None
        sift = cv2.SIFT_create()
        _kp, desc = sift.detectAndCompute(img, None)
        return desc

    # 缓存训练集
    def _save_train_cache(self, cache_path: str):
        pkg = dict(
            num_clusters=self.num_clusters,
            codebook=self.codebook,
            idf=self.idf,
            train_paths=self.train_paths,
            train_labels=self.train_labels,
            hist_bof=self.train_hist_bof_norm,
            hist_tfidf=self.train_hist_tfidf_norm,
        )
        with open(cache_path, "wb") as f:
            pickle.dump(pkg, f, protocol=pickle.HIGHEST_PROTOCOL)
        print(f"[Cache] training data saved → {cache_path}")

    # 加载缓存训练集
    def _load_train_cache(self, cache_path: str) -> bool:
        if not os.path.exists(cache_path):
            return False
        with open(cache_path, "rb") as f:
            pkg = pickle.load(f)
        if pkg.get("num_clusters") != self.num_clusters:
            print("[Cache] num_clusters mismatch, ignore cache.")
            return False

        self.codebook            = pkg["codebook"]
        self.idf                 = pkg["idf"]
        self.train_paths         = pkg["train_paths"]
        self.train_labels        = pkg["train_labels"]
        self.train_hist_bof_norm = pkg["hist_bof"]
        self.train_hist_tfidf_norm = pkg["hist_tfidf"]
        print(f"[Cache] training data loaded ← {cache_path}")
        return True

    def _compute_hist(self, descriptors: np.ndarray) -> np.ndarray:
        """
        根据视觉词典将描述符映射到词袋直方图
        :param descriptors: 特征描述符矩阵
        :return: 长度为 num_clusters 的直方图
        """
        if self.codebook is None:
             return np.zeros(self.num_clusters)

        if descriptors is None or len(descriptors) == 0:
             return np.zeros(self.num_clusters)

        words = self.codebook.predict(descriptors)
        hist = np.bincount(words, minlength=self.num_clusters).astype(np.float32)
        return hist


    def fit(self, folder: str, cache_path: str | None = None, rebuild_cache: bool = False) -> bool:
        """
        训练模型：
        1. 遍历文件夹，提取所有图像的 SIFT 描述符
        2. 使用部分描述符训练 KMeans 视觉词典
        3. 计算 BoF 和 TF-IDF 特征，并归一化
        4. 计算 IDF
        :param folder: 包含子目录（类别）的训练图像根目录
        :return: 是否成功
        """

        # 加载 cache_path
        if cache_path and not rebuild_cache:
            if self._load_train_cache(cache_path):
                return True

        descriptors: List[np.ndarray] = []
        self.train_paths.clear()
        self.train_labels.clear()

        # 收集所有图像路径及其标签（父目录名）
        print(f"Scanning folder: {folder}")
        image_paths = []
        for root, _dirs, files in os.walk(folder):
            label = os.path.basename(root)
            for f in files:
                if f.lower().endswith((".jpg", ".jpeg", ".png")):
                    p = os.path.join(root, f)
                    image_paths.append((p, label))

        print(f"Found {len(image_paths)} potential images.")

        # 提取描述符，用于构建词典
        desc_list_for_vocab: List[np.ndarray] = []
        print("Extracting descriptors for vocabulary...")
        for i, (p, label) in enumerate(image_paths):
            desc = self._sift(p)
            if desc is not None and len(desc) > 0:
                desc_list_for_vocab.append(desc)
                self.train_paths.append(p)
                self.train_labels.append(label)
            if (i + 1) % 100 == 0:
                 print(f"Processed {i + 1}/{len(image_paths)} images for vocabulary.")

        if not desc_list_for_vocab:
            print("No images found with extractable descriptors.")
            return False

        print(f"Aggregating {sum(len(d) for d in desc_list_for_vocab)} descriptors...")

        # 聚合所有描述符并随机采样训练 KMeans
        all_desc = np.vstack(desc_list_for_vocab)
        print("Building codebook...")
        sample_size = min(len(all_desc), 200000)
        sample_indices = np.random.choice(len(all_desc), sample_size, replace=False)
        sample_desc = all_desc[sample_indices]
        self.codebook = MiniBatchKMeans(
            n_clusters=self.num_clusters, random_state=42, batch_size=100, n_init=3
        )
        self.codebook.fit(sample_desc)
        print("Codebook built.")

        # 计算 BoF 直方图和 TF（词频）
        hists_bof: List[np.ndarray] = []
        tf: List[np.ndarray] = []
        print("Computing image histograms and IDF...")
        for i, p in enumerate(self.train_paths):
            d = self._sift(p)
            if d is None or len(d) == 0:
                 h = np.zeros(self.num_clusters)
            else:
                 h = self._compute_hist(d)
            h_norm_bof = h / (np.linalg.norm(h) + 1e-8)
            hists_bof.append(h_norm_bof)
            h_tf = h / (h.sum() + 1e-8)
            tf.append(h_tf)
            if (i + 1) % 100 == 0:
                print(f"Processed {i + 1}/{len(self.train_paths)} images.")
        self.train_hist_bof_norm = np.stack(hists_bof)
        tf = np.stack(tf)
        print("Histograms computed.")

        # 计算 IDF 并生成 TF-IDF 特征，再归一化
        df = np.count_nonzero(tf > 0, axis=0)
        self.idf = np.log((len(tf) + 1) / (df + 1)) + 1.0
        train_hist_tfidf = tf * self.idf
        self.train_hist_tfidf_norm = train_hist_tfidf / (np.linalg.norm(train_hist_tfidf, axis=1, keepdims=True) + 1e-8)
        print("TF-IDF computed and normalized.")
        print("Training complete.")

        # 缓存训练集
        if cache_path:
            self._save_train_cache(cache_path)
        return True

    def _category_of(self, path: str) -> str:
        """获取图像所属类别（父目录名）"""
        return os.path.basename(os.path.dirname(path))

    def _calculate_metrics_and_pr(
        self,
        query_path: str,
        all_scores: np.ndarray,
        top_k_indices: np.ndarray,
        top_k: int
    ) -> Tuple[float, float, float, Tuple[np.ndarray, np.ndarray] | None]:
        """
        计算 Precision@k, Recall@k, mAP 及 PR 曲线
        :return: p@k, r@k, mAP, (recall, precision)
        """
        n_train_images = len(self.train_paths)
        if n_train_images == 0 or not self.train_labels:
             print("Warning: Train data or labels are empty. Cannot calculate metrics.")
             return 0.0, 0.0, 0.0, (np.array([0.0, 1.0]), np.array([1.0, 0.0]))
        try:
            query_cat = self._category_of(query_path)
            relevant_indices = [i for i, label in enumerate(self.train_labels) if label == query_cat]
        except Exception as e:
            print(f"Error determining query category or relevant indices for {query_path}: {e}")

            return 0.0, 0.0, 0.0, (np.array([0.0, 1.0]), np.array([1.0, 0.0]))
        p_at_k = 0.0
        r_at_k = 0.0
        if len(top_k_indices) > 0:
            y_true_topk = [1 if i in relevant_indices else 0 for i in top_k_indices]
            p_at_k = sum(y_true_topk) / len(y_true_topk)
            num_retrieved_relevant = sum(y_true_topk)   # TP
            total_relevant = len(relevant_indices)      # TP + FN
            r_at_k = num_retrieved_relevant / total_relevant if total_relevant > 0 else 0.0

        # 全局 mAP 和 PR 曲线
        y_true_all = [1 if i in relevant_indices else 0 for i in range(n_train_images)]

        if len(all_scores) != len(y_true_all) or total_relevant == 0:
             if len(all_scores) != len(y_true_all):
                 print(f"Error: Score length ({len(all_scores)}) mismatch with true label length ({len(y_true_all)})")
             if total_relevant == 0:
                 print(f"Warning: No relevant items found for query category '{query_cat}'. Cannot calculate mAP/PR curve.")

             return p_at_k, r_at_k, 0.0, (np.array([0.0, 1.0]), np.array([1.0, 0.0]))

        mAP = average_precision_score(y_true_all, all_scores)

        precision, recall, _ = precision_recall_curve(y_true_all, all_scores)
        pr_curve = (recall, precision)


        return p_at_k, r_at_k, mAP, pr_curve

    def rerank(self, scores_bof: np.ndarray, scores_tfidf: np.ndarray, alpha: float = 0.5) -> np.ndarray:
        """
        使用 BoF 和 TF-IDF 分数的线性组合进行重排序
        :param scores_bof: BoF 分数
        :param scores_tfidf: TF-IDF 分数
        :param alpha: BoF 分数的权重 (0.0 to 1.0)
        :return: 组合后的分数
        """
        # 归一化分数以确保它们在相似的范围内
        norm_scores_bof = (scores_bof - np.min(scores_bof)) / (np.max(scores_bof) - np.min(scores_bof) + 1e-8)
        norm_scores_tfidf = (scores_tfidf - np.min(scores_tfidf)) / (np.max(scores_tfidf) - np.min(scores_tfidf) + 1e-8)
        
        combined_scores = alpha * norm_scores_bof + (1 - alpha) * norm_scores_tfidf
        return combined_scores


    def query(self, img_path: str, top_k: int = 10) -> Tuple[List[Tuple[str, float]], List[Tuple[str, float]], List[Tuple[str, float]]]:
        """
        对单张图像进行检索，返回 BoF, TF-IDF 和重排序的 Top-k 结果
        :param img_path: 查询图像路径
        :return: BoF 结果, TF-IDF 结果, 重排序结果，每项为 (路径, 相似度)
        """
        if self.codebook is None:
            raise RuntimeError("模型未訓練")
        desc = self._sift(img_path)
        if desc is None:
            raise ValueError("无法提取查询图像特征")

        hist = self._compute_hist(desc)
        # 计算 BoF 得分
        t0 = perf_counter()
        q_norm_bof = hist / (np.linalg.norm(hist) + 1e-8)
        scores_bof = self.train_hist_bof_norm @ q_norm_bof
        top_idx_bof = np.argsort(scores_bof)[::-1][:top_k]
        self.metrics["bof"]["time"] = perf_counter() - t0

        results_bof = [(self.train_paths[i], float(scores_bof[i])) for i in top_idx_bof]
        p, r, ap, pr_bof = self._calculate_metrics_and_pr(img_path, scores_bof, top_idx_bof, top_k)
        self.metrics["bof"].update({"precision@k": p, "recall@k": r, "mAP": ap})

        # 计算 TF-IDF 得分
        t0 = perf_counter()
        tf = hist / (hist.sum() + 1e-8)
        tfidf_q = tf * self.idf
        q_norm_tfidf = tfidf_q / (np.linalg.norm(tfidf_q) + 1e-8)
        scores_tfidf = self.train_hist_tfidf_norm @ q_norm_tfidf
        top_idx_tfidf = np.argsort(scores_tfidf)[::-1][:top_k]
        self.metrics["tfidf"]["time"] = perf_counter() - t0

        results_tfidf = [(self.train_paths[i], float(scores_tfidf[i])) for i in top_idx_tfidf]
        p, r, ap, pr_tfidf = self._calculate_metrics_and_pr(img_path, scores_tfidf, top_idx_tfidf, top_k)
        self.metrics["tfidf"].update({"precision@k": p, "recall@k": r, "mAP": ap})

        # 重排序
        t0 = perf_counter()
        scores_rerank = self.rerank(scores_bof, scores_tfidf)
        top_idx_rerank = np.argsort(scores_rerank)[::-1][:top_k]
        self.metrics["rerank"]["time"] = self.metrics["bof"]["time"] + self.metrics["tfidf"]["time"] + (perf_counter() - t0)

        results_rerank = [(self.train_paths[i], float(scores_rerank[i])) for i in top_idx_rerank]
        p, r, ap, pr_rerank = self._calculate_metrics_and_pr(img_path, scores_rerank, top_idx_rerank, top_k)
        self.metrics["rerank"].update({"precision@k": p, "recall@k": r, "mAP": ap})

        return results_bof, results_tfidf, results_rerank

    def query_with_expansion(self, img_path: str, top_k: int = 10, qe_top_n: int = 5):
        """
        對單張圖像進行檢索，並使用查詢擴展（QE）優化結果。
        1. 執行初始檢索
        2. 使用 Top-N 結果的特徵向量來創建一個新的、擴展後的查詢向量 (AQE)
        3. 使用擴展後的查詢向量執行第二次檢索
        :param img_path: 查詢圖像路徑
        :param top_k: 返回的最終結果數量
        :param qe_top_n: 用於擴展的初始檢索結果數量
        :return: 擴展後的 BoF, TF-IDF 和重排序的 Top-k 結果
        """
        if self.codebook is None:
            raise RuntimeError("模型未訓練")

        desc = self._sift(img_path)
        if desc is None:
            raise ValueError("无法提取查询图像特征")

        # 1. 計算原始查詢特徵
        hist = self._compute_hist(desc)
        q_norm_bof_orig = hist / (np.linalg.norm(hist) + 1e-8)
        tf = hist / (hist.sum() + 1e-8)
        tfidf_q_orig = tf * self.idf
        q_norm_tfidf_orig = tfidf_q_orig / (np.linalg.norm(tfidf_q_orig) + 1e-8)

        # 2. 執行初始檢索以找到用於擴展的圖像
        scores_bof_initial = self.train_hist_bof_norm @ q_norm_bof_orig
        top_indices_for_qe_bof = np.argsort(scores_bof_initial)[::-1][:qe_top_n]

        scores_tfidf_initial = self.train_hist_tfidf_norm @ q_norm_tfidf_orig
        top_indices_for_qe_tfidf = np.argsort(scores_tfidf_initial)[::-1][:qe_top_n]

        # 3. 創建擴展查詢向量 (平均查詢擴展 - AQE)
        # -- 擴展 BoF --
        qe_features_bof = self.train_hist_bof_norm[top_indices_for_qe_bof]
        expanded_vector_bof = np.vstack([q_norm_bof_orig, qe_features_bof])
        q_expanded_bof = np.mean(expanded_vector_bof, axis=0)
        q_expanded_bof_norm = q_expanded_bof / (np.linalg.norm(q_expanded_bof) + 1e-8)

        # -- 擴展 TF-IDF --
        qe_features_tfidf = self.train_hist_tfidf_norm[top_indices_for_qe_tfidf]
        expanded_vector_tfidf = np.vstack([q_norm_tfidf_orig, qe_features_tfidf])
        q_expanded_tfidf = np.mean(expanded_vector_tfidf, axis=0)
        q_expanded_tfidf_norm = q_expanded_tfidf / (np.linalg.norm(q_expanded_tfidf) + 1e-8)

        # 4. 使用擴展後的查詢向量執行第二次檢索並計算指標
        # -- BoF (QE) --
        t0_bof = perf_counter()
        scores_bof_qe = self.train_hist_bof_norm @ q_expanded_bof_norm
        top_idx_bof_qe = np.argsort(scores_bof_qe)[::-1][:top_k]
        self.metrics["bof"]["time"] = perf_counter() - t0_bof

        results_bof_qe = [(self.train_paths[i], float(scores_bof_qe[i])) for i in top_idx_bof_qe]
        p_bof, r_bof, ap_bof, _ = self._calculate_metrics_and_pr(img_path, scores_bof_qe, top_idx_bof_qe, top_k)
        self.metrics["bof"].update({"precision@k": p_bof, "recall@k": r_bof, "mAP": ap_bof})

        # -- TF-IDF (QE) --
        t0_tfidf = perf_counter()
        scores_tfidf_qe = self.train_hist_tfidf_norm @ q_expanded_tfidf_norm
        top_idx_tfidf_qe = np.argsort(scores_tfidf_qe)[::-1][:top_k]
        self.metrics["tfidf"]["time"] = perf_counter() - t0_tfidf

        results_tfidf_qe = [(self.train_paths[i], float(scores_tfidf_qe[i])) for i in top_idx_tfidf_qe]
        p_tfidf, r_tfidf, ap_tfidf, _ = self._calculate_metrics_and_pr(img_path, scores_tfidf_qe, top_idx_tfidf_qe, top_k)
        self.metrics["tfidf"].update({"precision@k": p_tfidf, "recall@k": r_tfidf, "mAP": ap_tfidf})

        # -- 重排序 (QE) --
        t0_rerank = perf_counter()
        scores_rerank_qe = self.rerank(scores_bof_qe, scores_tfidf_qe)
        top_idx_rerank_qe = np.argsort(scores_rerank_qe)[::-1][:top_k]
        self.metrics["rerank"]["time"] = self.metrics["bof"]["time"] + self.metrics["tfidf"]["time"] + (perf_counter() - t0_rerank)

        results_rerank_qe = [(self.train_paths[i], float(scores_rerank_qe[i])) for i in top_idx_rerank_qe]
        p_rerank, r_rerank, ap_rerank, _ = self._calculate_metrics_and_pr(img_path, scores_rerank_qe, top_idx_rerank_qe, top_k)
        self.metrics["rerank"].update({"precision@k": p_rerank, "recall@k": r_rerank, "mAP": ap_rerank})

        return results_bof_qe, results_tfidf_qe, results_rerank_qe

    def _avg_pr(self, pr_curves: List[Tuple[np.ndarray, np.ndarray]]) -> Tuple[np.ndarray, np.ndarray] | None:
        """
        对多个 PR 曲线进行平均
        :param pr_curves: PR 曲线列表
        :return: 平均后的 (recall_grid, precision_grid)
        """
        if not pr_curves:
            return None
        recall_grid = np.linspace(0.0, 1.0, 101)
        interpolated_precisions = []

        for recall, precision in pr_curves:
            # 确保 precision 和 recall 是反向排序的，以用于插值
            sort_indices = np.argsort(recall)
            recall_sorted = recall[sort_indices]
            precision_sorted = precision[sort_indices]

            if len(recall_sorted) < 2:
                 print(f"Warning: Skipping PR curve with less than 2 points (recall shape: {recall.shape})")
                 continue
            # 创建插值函数
            interp_func = interp1d(recall_sorted, precision_sorted, bounds_error=False, fill_value=(precision_sorted[0], 0.0))
            interpolated_p = interp_func(recall_grid)
            interpolated_precisions.append(interpolated_p)

        if not interpolated_precisions:
             print("No valid PR curves to average.")
             return None
        averaged_precision = np.mean(interpolated_precisions, axis=0)
        return recall_grid, averaged_precision

    def evaluate_folder(self, test_dir: str, top_k: int = 10) -> Tuple[dict, dict | None]:
        """
        批量评估测试集，返回各指标平均值和平均 PR 曲线
        :param test_dir: 测试图像目录
        :return: (平均指标, 平均 PR 曲线字典)
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

        total_metrics = {
             "bof": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0},
             "tfidf": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0},
             "rerank": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0},
        }
        pr_curves_bof_list = []
        pr_curves_tf_list = []
        pr_curves_rerank_list = []
        successful_queries_count = 0
        print(f"Evaluating {len(test_images)} test images (Top-k={top_k})...")

        start_time_batch = perf_counter()
        for i, img in enumerate(test_images):
            try:
                actual_top_k = min(top_k, len(self.train_paths))
                desc = self._sift(img)
                if desc is None:
                    continue
                hist = self._compute_hist(desc)

                # BoF
                t0_bof = perf_counter()
                norm_bof = hist / (np.linalg.norm(hist)+1e-8)
                scores_bof = self.train_hist_bof_norm @ norm_bof
                top_k_indices_bof = np.argsort(scores_bof)[::-1][:actual_top_k]
                t_bof_full = perf_counter() - t0_bof

                p_bof, r_bof, mAP_bof, pr_bof = self._calculate_metrics_and_pr(img, scores_bof, top_k_indices_bof, actual_top_k)
                total_metrics["bof"]["precision@k"] += p_bof
                total_metrics["bof"]["recall@k"] += r_bof
                total_metrics["bof"]["mAP"] += mAP_bof
                total_metrics["bof"]["time"] += t_bof_full
                if pr_bof is not None:
                    pr_curves_bof_list.append(pr_bof)

                # TF-IDF
                t0_tfidf = perf_counter()
                tf = hist / (hist.sum() + 1e-8)
                tfidf_q = tf * self.idf
                norm_tfidf = tfidf_q / (np.linalg.norm(tfidf_q) + 1e-8)
                scores_tfidf = self.train_hist_tfidf_norm @ norm_tfidf
                top_k_indices_tf = np.argsort(scores_tfidf)[::-1][:actual_top_k]
                t_tfidf_full = perf_counter() - t0_tfidf

                p_tf, r_tf, mAP_tf, pr_tf = self._calculate_metrics_and_pr(img, scores_tfidf, top_k_indices_tf, actual_top_k)
                total_metrics["tfidf"]["precision@k"] += p_tf
                total_metrics["tfidf"]["recall@k"] += r_tf
                total_metrics["tfidf"]["mAP"] += mAP_tf
                total_metrics["tfidf"]["time"] += t_tfidf_full
                if pr_tf is not None:
                    pr_curves_tf_list.append(pr_tf)

                # Rerank
                t0_rerank = perf_counter()
                scores_rerank = self.rerank(scores_bof, scores_tfidf)
                top_k_indices_rerank = np.argsort(scores_rerank)[::-1][:actual_top_k]
                t_rerank_full = perf_counter() - t0_rerank

                p_rerank, r_rerank, mAP_rerank, pr_rerank = self._calculate_metrics_and_pr(img, scores_rerank, top_k_indices_rerank, actual_top_k)
                total_metrics["rerank"]["precision@k"] += p_rerank
                total_metrics["rerank"]["recall@k"] += r_rerank
                total_metrics["rerank"]["mAP"] += mAP_rerank
                total_metrics["rerank"]["time"] += t_bof_full + t_tfidf_full + t_rerank_full
                if pr_rerank is not None:
                    pr_curves_rerank_list.append(pr_rerank)

                successful_queries_count += 1
                if (i + 1) % 10 == 0:
                    print(f"Processed {i + 1}/{len(test_images)} test images successfully: {successful_queries_count}")

            except Exception as e:
                print(f"Skipping test image {img} due to error: {e}")

        total_batch_time = perf_counter() - start_time_batch
        n = successful_queries_count
        if n == 0:
             print("No test images successfully processed.")
             avg_metrics = {
                 method: {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0}
                 for method in ["bof", "tfidf", "rerank"]
             }
             return avg_metrics, None
        avg_metrics = {
             method: {k: total_metrics[method][k] / n for k in total_metrics[method]}
             for method in ["bof", "tfidf", "rerank"]
        }
        avg_metrics["total_batch_time"] = total_batch_time
        avg_pr_curves = {
            "bof": self._avg_pr(pr_curves_bof_list),
            "tfidf": self._avg_pr(pr_curves_tf_list),
            "rerank": self._avg_pr(pr_curves_rerank_list),
        }
        print(f"Batch evaluation complete. Total processed: {n}/{len(test_images)}. Total time: {total_batch_time:.3f}s")
        return avg_metrics, avg_pr_curves


    def plot_comparison(
        self,
        metrics_data: dict,
        pr_data: dict | None,
        is_averaged: bool = False
        ):
        """
        绘制性能对比图：柱状图 + PR 曲线
        :param metrics_data: 指标数据
        :param pr_data: PR 曲线数据
        :param is_averaged: 是否为平均指标
        """
        plt.figure(figsize=(12, 5))
        metrics_labels = ["Precision@k", "Recall@k", "mAP", "Time(s)"]
        metrics_keys = ["precision@k", "recall@k", "mAP", "time"]
        x = np.arange(len(metrics_labels))
        width = 0.25

        bof_vals = [metrics_data.get("bof", {}).get(k, 0.0) for k in metrics_keys]
        tf_vals = [metrics_data.get("tfidf", {}).get(k, 0.0) for k in metrics_keys]
        rerank_vals = [metrics_data.get("rerank", {}).get(k, 0.0) for k in metrics_keys]

        plt.subplot(1, 2, 1)
        bars_bof = plt.bar(x - width, bof_vals, width, label="BoF")
        bars_tf = plt.bar(x, tf_vals, width, label="TF-IDF")
        bars_rerank = plt.bar(x + width, rerank_vals, width, label="Re-ranking")

        plt.xticks(x, metrics_labels)
        plt.ylabel("Score / Time (s)")

        def add_value_labels(bars):
            for bar in bars:
                yval = bar.get_height()
                plt.text(bar.get_x() + bar.get_width()/2, yval, f'{yval:.3f}', va='bottom', ha='center', fontsize=8)

        add_value_labels(bars_bof)
        add_value_labels(bars_tf)
        add_value_labels(bars_rerank)
        plt.legend()
        title_prefix = "Average " if is_averaged else "Single Query "
        plt.title(f"{title_prefix}Performance Comparison")
        all_vals = bof_vals + tf_vals + rerank_vals
        plt.ylim(0, max(all_vals) * 1.15 + 0.05)

        plt.subplot(1, 2, 2)
        if pr_data:
            for method, label in [("bof", "BoF"), ("tfidf", "TF-IDF"), ("rerank", "Re-ranking")]:
                pr_curve = pr_data.get(method)
                if pr_curve and pr_curve[0] is not None and pr_curve[1] is not None:
                    recall, precision = pr_curve
                    plt.plot(recall[1:], precision[1:], label=label)

        plt.xlabel("Recall")
        plt.ylabel("Precision")
        plt.title(f"{title_prefix}Precision-Recall Curve")
        plt.legend()
        plt.ylim([-0.05, 1.05])
        plt.xlim([-0.05, 1.05])
        plt.grid(True)
        plt.tight_layout()
        plt.show()

class ImageMatcherGUI(QWidget):
    """
    PyQt5 GUI 界面，用于训练、查询、评估和可视化检索结果
    """
    def __init__(self):
        super().__init__()
        self.matcher = BoF_TFIDF_Retriever(num_clusters=256)
        self.query_img: str | None = None
        self.bof_results: List[Tuple[str, float]] = []
        self.tfidf_results: List[Tuple[str, float]] = []
        self.rerank_results: List[Tuple[str, float]] = []

        self._last_avg_metrics = None
        self._last_avg_pr_curves = None
        self._qe_enabled_for_last_run = False # Track if QE was used

        self._build_ui()

    def _build_ui(self):
        self.setWindowTitle("BoF + TF-IDF + Re-ranking 圖像檢索系統 (PyQt5)")
        self.resize(1280, 800)
        main_layout = QVBoxLayout()
        
        # --- Top control row ---
        top_controls = QHBoxLayout()
        self.btn_train = QPushButton("選擇訓練集並訓練")
        self.btn_train.clicked.connect(self.train_model)
        self.btn_query = QPushButton("選擇查詢圖像")
        self.btn_query.clicked.connect(self.choose_query)
        self.btn_match = QPushButton("執行檢索")
        self.btn_match.clicked.connect(self.run_match)
        top_controls.addWidget(self.btn_train)
        top_controls.addWidget(self.btn_query)
        top_controls.addWidget(self.btn_match)

        # --- QE Controls ---
        qe_controls = QHBoxLayout()
        self.chk_qe = QCheckBox("啟用查詢擴展 (QE)")
        qe_label = QLabel("用於擴展的Top-N結果:")
        self.spin_qe_top_n = QSpinBox()
        self.spin_qe_top_n.setRange(1, 20)
        self.spin_qe_top_n.setValue(5)
        qe_controls.addStretch()
        qe_controls.addWidget(self.chk_qe)
        qe_controls.addWidget(qe_label)
        qe_controls.addWidget(self.spin_qe_top_n)

        # --- Evaluation row ---
        eval_controls = QHBoxLayout()
        self.btn_evaluate = QPushButton("評估測試集")
        self.btn_evaluate.clicked.connect(self.evaluate_test_set)
        self.btn_avg_compare = QPushButton("顯示平均圖表")
        self.btn_avg_compare.clicked.connect(self.plot_averaged_comparison)
        self.btn_avg_compare.setEnabled(False)
        eval_controls.addWidget(self.btn_evaluate)
        eval_controls.addWidget(self.btn_avg_compare)
        eval_controls.addStretch()

        # Image display row
        img_row = QHBoxLayout()
        self.lbl_query = QLabel("查詢圖像")
        self.lbl_query.setAlignment(Qt.AlignCenter)
        self.lbl_query.setFixedSize(350, 350)
        self.lbl_query.setStyleSheet("border: 1px solid black;")

        self.lbl_best = QLabel("最优匹配图像 (Re-ranking)")
        self.lbl_best.setAlignment(Qt.AlignCenter)
        self.lbl_best.setFixedSize(350, 350)
        self.lbl_best.setStyleSheet("border: 1px solid black;")

        img_row.addWidget(self.lbl_query)
        img_row.addWidget(self.lbl_best)

        # Metrics table
        self.table = QTableWidget(3, 5) 
        self.table.setHorizontalHeaderLabels(["方法", "Precision@k", "Recall@k", "mAP", "Time(s)"])
        self.table.verticalHeader().setVisible(False)
        self.table.setEditTriggers(QTableWidget.NoEditTriggers)
        self.table.setFixedHeight(125) 
        self.table.horizontalHeader().setStretchLastSection(True)

        # Results tabs
        self.tabs = QTabWidget()
        self.text_bof = QTextEdit(); self.text_bof.setReadOnly(True)
        self.text_tf = QTextEdit(); self.text_tf.setReadOnly(True)
        self.text_rerank = QTextEdit(); self.text_rerank.setReadOnly(True) 
        self.tabs.addTab(self.text_bof, "BoF 结果")
        self.tabs.addTab(self.text_tf, "TF-IDF 结果")
        self.tabs.addTab(self.text_rerank, "Re-ranking 结果")

        # Add all layouts and widgets to main layout
        main_layout.addLayout(top_controls)
        main_layout.addLayout(qe_controls)
        main_layout.addLayout(eval_controls)
        main_layout.addLayout(img_row)
        main_layout.addWidget(self.table)
        main_layout.addWidget(self.tabs)
        self.setLayout(main_layout)

        self._update_metric_table(clear=True)

        self.btn_query.setEnabled(False)
        self.btn_match.setEnabled(False)
        self.btn_evaluate.setEnabled(False)

    def choose_query(self):
        fname, _ = QFileDialog.getOpenFileName(self, "選擇查詢圖像", "", "Images (*.jpg *.jpeg *.png)")
        if fname:
            self.query_img = fname
            pix = QPixmap(fname).scaled(350, 350, Qt.KeepAspectRatio, Qt.SmoothTransformation)
            self.lbl_query.setPixmap(pix)
            self.lbl_best.clear()
            self.text_bof.clear(); self.text_tf.clear(); self.text_rerank.clear()
            self._update_metric_table(clear=True)

    def train_model(self):
        folder = QFileDialog.getExistingDirectory(self, "選擇訓練圖像文件夹")
        if not folder:
            return

        cache_file = os.path.join(folder, f"{os.path.basename(folder)}_train_k{self.matcher.num_clusters}.pkl")
        self.text_bof.setText("訓練中，請稍候……\n")
        self.text_tf.clear()
        self.text_rerank.clear()
        self._update_metric_table(clear=True)
        self.lbl_query.clear()
        self.lbl_best.clear()
        self.query_img = None
        QApplication.processEvents()

        try:
            if self.matcher.fit(folder, cache_path=cache_file):
                loaded_from_cache = os.path.exists(cache_file) and self.matcher._load_train_cache(cache_file)
                info_msg = ("已從緩存載入訓練數據"
                            if loaded_from_cache
                            else f"已加载 {len(self.matcher.train_paths)} 张有效图像并完成训练")
                QMessageBox.information(self, "完成", info_msg)

                self.text_bof.setText("訓練完成。")
                self.text_tf.setText("訓練完成。")
                self.text_rerank.setText("訓練完成。")
                self.btn_query.setEnabled(True)
                self.btn_match.setEnabled(True)
                self.btn_evaluate.setEnabled(True)
                self.btn_avg_compare.setEnabled(False)
            else:
                QMessageBox.critical(self, "错误", "訓練失敗或未找到有效圖片！請檢查數據集和資料夾結構。")
                self.text_bof.clear(); self.text_tf.clear(); self.text_rerank.clear()
                self.btn_query.setEnabled(False)
                self.btn_match.setEnabled(False)
                self.btn_evaluate.setEnabled(False)
                self.btn_avg_compare.setEnabled(False)

        except Exception as e:
            QMessageBox.critical(self, "訓練錯誤", f"訓練過程中發生錯誤: {e}")
            self.text_bof.clear(); self.text_tf.clear(); self.text_rerank.clear()
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
        self.text_rerank.clear()
        self._update_metric_table(clear=True)
        self.lbl_best.clear()
        QApplication.processEvents()

        use_qe = self.chk_qe.isChecked()
        self._qe_enabled_for_last_run = use_qe # Store state for display
        
        # Dynamically change tab titles based on QE state
        self.tabs.setTabText(0, "BoF (QE) 结果" if use_qe else "BoF 结果")
        self.tabs.setTabText(1, "TF-IDF (QE) 结果" if use_qe else "TF-IDF 结果")
        self.tabs.setTabText(2, "Re-ranking (QE) 结果" if use_qe else "Re-ranking 结果")

        try:
            if use_qe:
                qe_top_n = self.spin_qe_top_n.value()
                self.bof_results, self.tfidf_results, self.rerank_results = self.matcher.query_with_expansion(
                    self.query_img, qe_top_n=qe_top_n
                )
            else:
                self.bof_results, self.tfidf_results, self.rerank_results = self.matcher.query(self.query_img)

            best = self.rerank_results[0][0] if self.rerank_results else None
            if best and os.path.exists(best):
                pix = QPixmap(best).scaled(350, 350, Qt.KeepAspectRatio, Qt.SmoothTransformation)
                self.lbl_best.setPixmap(pix)
            else:
                 self.lbl_best.clear()
            self._update_metric_table()
            self._fill_result_texts()
            self.btn_avg_compare.setEnabled(False)
        except (ValueError, RuntimeError) as e:
            QMessageBox.critical(self, "錯誤", f"檢索失敗: {e}")
            self.text_bof.clear(); self.text_tf.clear(); self.text_rerank.clear()
            self._update_metric_table(clear=True)
            self.lbl_best.clear()

    def _update_metric_table(self, clear=False):
        if clear:
            for i in range(3):
                for j in range(5):
                    self.table.setItem(i, j, QTableWidgetItem(""))
        else:
            qe_suffix = " (QE)" if self._qe_enabled_for_last_run else ""
            for i, method_key in enumerate(["bof", "tfidf", "rerank"]):
                method_name_map = {"bof": "BoF", "tfidf": "TF-IDF", "rerank": "Re-ranking"}
                method_name = f"{method_name_map[method_key]}{qe_suffix}"
                metrics = self.matcher.metrics.get(method_key, {})
                self.table.setItem(i, 0, QTableWidgetItem(method_name))
                self.table.setItem(i, 1, QTableWidgetItem(f"{metrics.get('precision@k', 0.0):.3f}"))
                self.table.setItem(i, 2, QTableWidgetItem(f"{metrics.get('recall@k', 0.0):.3f}"))
                self.table.setItem(i, 3, QTableWidgetItem(f"{metrics.get('mAP', 0.0):.3f}"))
                self.table.setItem(i, 4, QTableWidgetItem(f"{metrics.get('time', 0.0):.3f}"))
        self.table.resizeColumnsToContents()

    def _fill_result_texts(self):
        self.text_bof.clear(); self.text_tf.clear(); self.text_rerank.clear()
        qe_suffix = " (QE)" if self._qe_enabled_for_last_run else ""
        results = {
            "bof": (self.text_bof, self.bof_results, f"BoF{qe_suffix}"),
            "tfidf": (self.text_tf, self.tfidf_results, f"TF-IDF{qe_suffix}"),
            "rerank": (self.text_rerank, self.rerank_results, f"Re-ranking{qe_suffix}"),
        }
        for key, (text_widget, result_list, name) in results.items():
            metrics = self.matcher.metrics.get(key, {})
            text_widget.append(f"--- {name} 檢索結果 ({len(result_list)} items) ---")
            text_widget.append(
                f"Precision@k: {metrics.get('precision@k', 0.0):.3f}, "
                f"Recall@k: {metrics.get('recall@k', 0.0):.3f}, "
                f"mAP: {metrics.get('mAP', 0.0):.3f}, "
                f"Time: {metrics.get('time', 0.0):.3f}s\n"
            )
            for rank, (p, s) in enumerate(result_list, 1):
                text_widget.append(f"{rank:>2}. {os.path.basename(p)} (sim={s:.4f})")


    def evaluate_test_set(self):
        if self.matcher.codebook is None:
            QMessageBox.warning(self, "提示", "請先訓練模型！")
            return
        test_dir = QFileDialog.getExistingDirectory(self, "選擇測試集目錄")
        if not test_dir:
            return
        self.text_bof.setText("評估中，請稍候……")
        self.text_tf.clear()
        self.text_rerank.clear()
        self._update_metric_table(clear=True)
        self.lbl_query.clear(); self.lbl_best.clear()
        QApplication.processEvents()
        try:
            self._last_avg_metrics, self._last_avg_pr_curves = self.matcher.evaluate_folder(test_dir)
            msg_lines = [
                f"--- 測試集評估完成 (總計 {self._last_avg_metrics.get('total_batch_time', 0.0):.3f}s) ---",
                "--- 平均指标 (Average Metrics) ---"
            ]
            for key, name in [("bof", "BoF"), ("tfidf", "TF-IDF"), ("rerank", "Re-ranking")]:
                metrics = self._last_avg_metrics.get(key, {})
                msg_lines.append(f"{name}:")
                msg_lines.append(f"  mAP: {metrics.get('mAP', 0.0):.4f}")
                msg_lines.append(f"  Precision@k: {metrics.get('precision@k', 0.0):.4f}")
                msg_lines.append(f"  Recall@k: {metrics.get('recall@k', 0.0):.4f}")
                msg_lines.append(f"  Time per query: {metrics.get('time', 0.0):.4f}s")

            msg = "\n".join(msg_lines)
            QMessageBox.information(self, "評估完成", msg)
            self.text_bof.setText(msg); self.text_tf.setText(msg); self.text_rerank.setText(msg)
            self.btn_avg_compare.setEnabled(True)

        except Exception as e:
            QMessageBox.critical(self, "錯誤", f"評估過程中發生錯誤: {e}")
            self.text_bof.clear(); self.text_tf.clear(); self.text_rerank.clear()
            self._update_metric_table(clear=True)
            self.btn_avg_compare.setEnabled(False)

    def plot_averaged_comparison(self):
         if self._last_avg_metrics is None or self._last_avg_pr_curves is None:
              QMessageBox.warning(self, "提示", "請先執行測試集評估！")
              return
         try:
              # 传递包含所有方法的指标和PR曲线
              self.matcher.plot_comparison(
                  metrics_data=self._last_avg_metrics,
                  pr_data=self._last_avg_pr_curves,
                  is_averaged=True
              )
         except Exception as e:
              QMessageBox.critical(self, "繪圖錯誤", f"繪製平均圖表失敗: {e}")

if __name__ == "__main__":
    app = QApplication.instance()
    if not app:
        app = QApplication(sys.argv)

    gui = ImageMatcherGUI()
    gui.show()
    sys.exit(app.exec_())