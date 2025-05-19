import sys
import time
import os
import pickle
import pathlib
from typing import List, Tuple, Dict, Any
from time import perf_counter

import cv2
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import MiniBatchKMeans
from sklearn.metrics import precision_recall_curve, precision_score, recall_score, average_precision_score
# from sklearn.metrics.pairwise import cosine_similarity # 未直接用于最终评分，但概念存在
from scipy.interpolate import interp1d
from PyQt5.QtCore import Qt, pyqtSignal
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
    QInputDialog,
    QCheckBox, # 已添加
    QSpinBox,  # 已添加
    QFormLayout # 已添加，用于查询扩展选项
)

class BoF_TFIDF_Retriever:
    """
    基于视觉单词袋（BoF）和 TF-IDF 的图像检索器
    1. 使用 SIFT 提取特征
    2. 使用 KMeans 生成视觉词典
    3. 计算图像的 BoF 直方图和 TF-IDF 特征
    4. 支持单张查询和批量评估
    5. 支持查询扩展 (QE)
    """

    def __init__(self, num_clusters: int = 256):
        self.num_clusters = num_clusters # 聚类数量/视觉单词数量
        self.codebook: MiniBatchKMeans | None = None # KMeans模型，即视觉词典
        self.idf: np.ndarray | None = None # 训练集的逆文档频率（IDF）权重
        self.train_paths: List[str] = [] # 训练图像的路径列表
        self.train_labels: List[str] = [] # 训练图像的标签列表

        self.train_hist_bof_norm: np.ndarray | None = None # 归一化后的训练集BoF直方图
        self.train_hist_tfidf_norm: np.ndarray | None = None # 归一化后的训练集TF-IDF直方图

        # 存储各项评估指标的字典
        self.metrics: Dict[str, Dict[str, Any]] = {
            "bof": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0, "pr_curve": None},
            "tfidf": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0, "pr_curve": None},
            "linear_combination": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0, "pr_curve": None},
            "bof_qe": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0, "pr_curve": None}, # BoF 查询扩展
            "tfidf_qe": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0, "pr_curve": None}, # TF-IDF 查询扩展
            "linear_combination_qe": {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0, "pr_curve": None}, # 线性组合 查询扩展
        }
        self.query_desc_cache: np.ndarray | None = None # 查询图像的SIFT描述符缓存


    @staticmethod
    def _sift(img_path: str) -> np.ndarray | None:
        """
        使用SIFT提取图像的局部特征描述符。
        :param img_path: 图像文件路径。
        :return: SIFT描述符数组，如果无法读取图像或提取特征，则返回None。
        """
        img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE) # 以灰度模式读取图像
        if img is None:
            # print(f"警告：无法读取图像 {img_path}")
            return None
        sift = cv2.SIFT_create() # 创建SIFT对象
        _kp, desc = sift.detectAndCompute(img, None) # _kp 是关键点列表, desc 是描述符
        return desc

    def _save_train_cache(self, cache_path: str):
        """将训练好的模型数据（词典、IDF、特征等）保存到缓存文件。"""
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
            pickle.dump(pkg, f, protocol=pickle.HIGHEST_PROTOCOL) # 使用最高协议版本进行序列化
        print(f"[缓存] 训练数据已保存 → {cache_path}")

    def _load_train_cache(self, cache_path: str) -> bool:
        """从缓存文件加载训练好的模型数据。"""
        if not os.path.exists(cache_path): # 检查缓存文件是否存在
            return False
        try:
            with open(cache_path, "rb") as f:
                pkg = pickle.load(f) # 从文件加载数据
            if pkg.get("num_clusters") != self.num_clusters: # 检查聚类数是否匹配
                print("[缓存] 聚类数量不匹配，忽略缓存。")
                return False

            # 加载各项数据
            self.codebook = pkg["codebook"]
            self.idf = pkg["idf"]
            self.train_paths = pkg["train_paths"]
            self.train_labels = pkg["train_labels"]
            self.train_hist_bof_norm = pkg["hist_bof"]
            self.train_hist_tfidf_norm = pkg["hist_tfidf"]
            print(f"[缓存] 训练数据已加载 ← {cache_path}")
            return True
        except Exception as e:
            print(f"[缓存] 加载缓存时出错: {e}")
            return False

    def _compute_hist(self, descriptors: np.ndarray | None) -> np.ndarray:
        """
        根据视觉词典将SIFT描述符映射到词袋（BoF）直方图。
        :param descriptors: SIFT特征描述符矩阵。
        :return: 长度为 num_clusters 的直方图。
        """
        if self.codebook is None: # 检查词典是否存在
            # print("警告：视觉词典不可用，无法计算直方图。")
            return np.zeros(self.num_clusters, dtype=np.float32)
        if descriptors is None or len(descriptors) == 0: # 检查描述符是否为空
            return np.zeros(self.num_clusters, dtype=np.float32) # 如果没有描述符，返回零直方图
        
        words = self.codebook.predict(descriptors) # 将每个描述符分配给最近的视觉单词（聚类中心）
        hist = np.bincount(words, minlength=self.num_clusters).astype(np.float32) # 计算视觉单词的频率（即直方图）
        return hist

    def fit(self, folder: str, cache_path: str | None = None, rebuild_cache: bool = False) -> bool:
        """
        训练模型：
        1. 遍历文件夹，提取所有图像的SIFT描述符。
        2. 使用部分描述符训练KMeans视觉词典。
        3. 计算所有训练图像的BoF直方图和TF-IDF特征，并进行归一化。
        4. 计算IDF值。
        :param folder: 包含子目录（类别）的训练图像根目录。
        :param cache_path: 缓存文件的路径。
        :param rebuild_cache: 是否强制重新构建缓存，即使缓存文件存在。
        :return: 如果训练成功，返回True，否则返回False。
        """
        if cache_path and not rebuild_cache: # 如果提供了缓存路径且不强制重建
            if self._load_train_cache(cache_path): # 尝试加载缓存
                return True # 加载成功，直接返回

        descriptors_list_for_vocab: List[np.ndarray] = [] # 用于构建词典的描述符列表
        self.train_paths.clear() # 清空旧的训练路径
        self.train_labels.clear() # 清空旧的训练标签

        print(f"扫描文件夹: {folder}")
        image_paths_with_labels = [] # 存储图像路径及其对应标签
        for root, _dirs, files in os.walk(folder): # 遍历文件夹及其子文件夹
            label = os.path.basename(root) # 使用子目录名作为类别标签
            for f in files: # 遍历当前目录下的文件
                if f.lower().endswith((".jpg", ".jpeg", ".png")): # 检查文件是否为指定格式的图像
                    p = os.path.join(root, f) # 获取图像的完整路径
                    image_paths_with_labels.append((p, label)) # 添加路径和标签

        if not image_paths_with_labels:
            print("在指定文件夹中未找到图像。")
            return False
        print(f"找到 {len(image_paths_with_labels)} 张潜在图像。")

        print("为构建词典提取SIFT描述符...")
        valid_image_count = 0 # 记录有效图像（能成功提取描述符的图像）的数量
        for i, (p, label) in enumerate(image_paths_with_labels):
            desc = self._sift(p) # 提取描述符
            if desc is not None and len(desc) > 0: # 如果成功提取到描述符
                descriptors_list_for_vocab.append(desc) # 添加到词典构建列表
                self.train_paths.append(p) # 添加有效图像的路径
                self.train_labels.append(label) # 添加对应标签
                valid_image_count +=1
            if (i + 1) % 100 == 0 or (i + 1) == len(image_paths_with_labels): # 每处理100张或最后一张时打印进度
                print(f"已为词典处理 {i + 1}/{len(image_paths_with_labels)} 张图像。有效图像数量: {valid_image_count}")

        if not descriptors_list_for_vocab: # 如果没有提取到任何描述符
            print("未找到可提取SIFT描述符的图像。")
            return False
        
        print(f"聚合来自 {len(self.train_paths)} 张图像的 {sum(len(d) for d in descriptors_list_for_vocab)} 个SIFT描述符...")
        all_desc = np.vstack(descriptors_list_for_vocab) # 将所有描述符垂直堆叠成一个大矩阵
        
        print("使用KMeans构建视觉词典...")
        sample_size = min(len(all_desc), 200000) # 限制用于KMeans的样本大小，防止内存不足和过长训练时间
        sample_indices = np.random.choice(len(all_desc), sample_size, replace=False) # 从所有描述符中随机无放回采样
        sample_desc = all_desc[sample_indices] # 获取采样后的描述符
        
        self.codebook = MiniBatchKMeans( # 使用MiniBatchKMeans以提高大规模数据聚类的效率
            n_clusters=self.num_clusters, random_state=42, batch_size=256, n_init='auto', max_iter=100
        )
        self.codebook.fit(sample_desc) # 训练KMeans模型，得到聚类中心即视觉单词
        print("视觉词典构建完成。")

        hists_bof_list: List[np.ndarray] = [] # 存储所有训练图像的BoF直方图
        tf_list: List[np.ndarray] = [] # 存储所有训练图像的词频（TF）向量
        print("为训练图像计算BoF直方图和词频（TF）...")
        for i, p_train in enumerate(self.train_paths):
            d_train = self._sift(p_train) # 此处为简化，重新提取描述符；实践中可考虑缓存或优化
            h = self._compute_hist(d_train) # 计算当前图像的BoF直方图
            
            h_norm_bof = h / (np.linalg.norm(h) + 1e-8) # 对BoF直方图进行L2归一化，避免因特征数量不同导致偏差
            hists_bof_list.append(h_norm_bof)
            
            h_tf = h / (h.sum() + 1e-8) # 计算词频（视觉单词在当前图像中的频率）
            tf_list.append(h_tf)
            if (i + 1) % 100 == 0 or (i+1) == len(self.train_paths): # 打印进度
                print(f"已为 {i + 1}/{len(self.train_paths)} 张训练图像计算直方图。")

        self.train_hist_bof_norm = np.stack(hists_bof_list) # 将BoF直方图列表转换为numpy数组
        tf_matrix = np.stack(tf_list) # 将TF向量列表转换为numpy数组
        print("BoF直方图计算并归一化完成。")

        print("计算IDF和TF-IDF特征...")
        df = np.count_nonzero(tf_matrix > 0, axis=0) # 计算包含每个视觉单词的文档数量（文档频率）
        self.idf = np.log((len(tf_matrix) + 1.0) / (df + 1.0)) + 1.0 # 计算平滑后的IDF值，加1防止除零和取对数问题
        
        train_hist_tfidf_raw = tf_matrix * self.idf # 计算原始TF-IDF特征 (TF * IDF)
        # 对TF-IDF特征进行L2归一化
        norms_tfidf = np.linalg.norm(train_hist_tfidf_raw, axis=1, keepdims=True) # 计算每个TF-IDF向量的L2范数
        self.train_hist_tfidf_norm = train_hist_tfidf_raw / (norms_tfidf + 1e-8) # 归一化
        print("TF-IDF特征计算并归一化完成。")
        print("训练完成。")

        if cache_path: # 如果指定了缓存路径
            self._save_train_cache(cache_path) # 保存训练数据到缓存
        return True

    def _category_of(self, path: str) -> str:
        """获取图像所属的类别（即其父目录的名称）。"""
        return os.path.basename(os.path.dirname(path)) # 父目录名作为类别

    def _calculate_metrics_and_pr(
        self,
        query_path: str,
        all_scores: np.ndarray,
        top_k_indices: np.ndarray,
        top_k: int
    ) -> Tuple[float, float, float, Tuple[np.ndarray, np.ndarray] | None]:
        """
        计算 Precision@k, Recall@k, mAP 及 PR 曲线数据点。
        PR曲线数据将直接使用sklearn的输出，不强制添加(0,1)点。
        :param query_path: 查询图像的路径。
        :param all_scores: 查询图像与所有训练图像的相似度得分数组。
        :param top_k_indices: Top-k检索结果在训练集中的索引。
        :param top_k: k值。
        :return: (p@k, r@k, mAP, (recall_curve_points, precision_curve_points)|None )
        """
        n_train_images = len(self.train_paths)
        # 默认PR曲线：当无法计算时，精确率为0的直线。
        default_pr_curve = (np.array([0.0, 1.0]), np.array([0.0, 0.0])) 

        if n_train_images == 0 or not self.train_labels: # 检查训练数据和标签是否有效
            # print("警告：训练数据或标签为空，无法计算指标。")
            return 0.0, 0.0, 0.0, default_pr_curve

        try:
            query_cat = self._category_of(query_path) # 获取查询图像的真实类别
            # 获取训练集中所有与查询图像同类的图像的索引 (真实相关项)
            relevant_indices = [i for i, label in enumerate(self.train_labels) if label == query_cat]
            total_relevant = len(relevant_indices) # 数据集中与查询相关的项目总数
        except Exception as e: # 处理获取类别或相关索引时可能发生的错误
            # print(f"确定查询类别或相关索引时出错 ({query_path}): {e}")
            return 0.0, 0.0, 0.0, default_pr_curve
        
        p_at_k = 0.0 # Precision@k 初始化
        r_at_k = 0.0 # Recall@k 初始化

        if len(top_k_indices) > 0: # 如果有检索结果
            # 计算Top-k结果中真正相关的项目数量
            retrieved_relevant_indices_at_k = [i for i in top_k_indices if i in relevant_indices]
            num_retrieved_relevant_at_k = len(retrieved_relevant_indices_at_k)
            
            p_at_k = num_retrieved_relevant_at_k / len(top_k_indices) if len(top_k_indices) > 0 else 0.0
            r_at_k = num_retrieved_relevant_at_k / total_relevant if total_relevant > 0 else 0.0
        
        # 为计算mAP和PR曲线准备真实标签向量 (y_true_all)，标记所有相关图像为1，其余为0
        y_true_all = np.zeros(n_train_images, dtype=int)
        if total_relevant > 0:
            y_true_all[relevant_indices] = 1
        
        mAP = 0.0 # 初始化mAP
        pr_curve_data = default_pr_curve # 初始化PR曲线数据

        if len(all_scores) != n_train_images: # 检查分数数组长度是否与训练集大小匹配
            # print(f"警告：分数数组长度 ({len(all_scores)}) 与训练集大小 ({n_train_images}) 不匹配。无法准确计算mAP/PR曲线。")
            pass # mAP和pr_curve_data保持默认值
        elif total_relevant == 0: # 如果数据集中没有与查询相关的项目
            # print(f"警告：训练集中没有与查询类别 '{query_cat}' 相关的项目。mAP为0。")
            mAP = 0.0 # 根据定义，如果没有相关文档，Average Precision (AP) 为0
            # 此时的PR曲线通常未定义或显示为P=0。我们的default_pr_curve适用。
        else:
            mAP = average_precision_score(y_true_all, all_scores) # 计算平均精度均值(mAP)
            
            # 直接从sklearn获取PR曲线点
            precision_from_sklearn, recall_from_sklearn, _ = precision_recall_curve(y_true_all, all_scores)

            if len(recall_from_sklearn) > 0 and len(precision_from_sklearn) > 0:
                # 直接使用sklearn返回的数据点
                # sklearn的precision_recall_curve输出通常是合理的，
                # 它会包含多个阈值下的(recall, precision)对。
                # 第一个点可能是 (0, P_first) 或者 (R_first_small, P_first_small)。
                # 最后一个点可能是 (R_max, P_at_R_max)。
                # 为了AUC计算，average_precision_score会正确处理。
                # 为了绘图和平均，我们直接使用这些原始点。
                pr_curve_data = (recall_from_sklearn, precision_from_sklearn)
            # else 部分保持不变，使用 default_pr_curve (如果sklearn未返回有效点)

        return p_at_k, r_at_k, mAP, pr_curve_data

    def query(self, img_path: str, top_k: int = 10, alpha: float = 0.5,
              use_expansion: bool = False, expansion_top_n: int = 3) -> \
              Tuple[List[Tuple[str, float]], List[Tuple[str, float]], List[Tuple[str, float]], # 原始结果
                    List[Tuple[str, float]] | None, List[Tuple[str, float]] | None, List[Tuple[str, float]] | None]: # 查询扩展结果
        """
        对单张图像进行检索，返回BoF、TF-IDF和线性组合的Top-k结果。
        支持查询扩展 (QE) - 基于初始TF-IDF结果的top-N进行扩展。
        :param img_path: 查询图像路径。
        :param top_k: 返回结果数量。
        :param alpha: 线性组合中BoF分数的权重 (0 <= alpha <= 1)。
        :param use_expansion: 是否使用查询扩展。
        :param expansion_top_n: 查询扩展时使用的top-N个反馈文档 (基于初始TF-IDF结果)。
        :return: (BoF结果, TF-IDF结果, LC结果, BoF QE结果, TF-IDF QE结果, LC QE结果)
                 如果 use_expansion 为 False，则 QE 结果为 None。
        """
        if self.codebook is None or self.idf is None or \
           self.train_hist_bof_norm is None or self.train_hist_tfidf_norm is None or not self.train_paths:
            raise RuntimeError("模型未训练或训练数据不完整。")

        # --- 1. 初始查询 ---
        desc_query_initial = self._sift(img_path) # 提取查询图像的SIFT描述符
        if desc_query_initial is None or len(desc_query_initial) == 0: # 检查是否成功提取
            print(f"警告：未找到查询图像 {img_path} 的SIFT描述符。")
            empty_res = ([], [], [], None, None, None) # 返回空结果
            # 如果查询提前失败，重置本次查询的指标为默认无性能状态
            for method_key in self.metrics:
                self.metrics[method_key].update({"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0, "pr_curve": (np.array([0.0,1.0]), np.array([0.0,0.0]))})
            return empty_res

        hist_query_initial = self._compute_hist(desc_query_initial) # 计算初始查询直方图

        # BoF (初始)
        t0_bof = perf_counter() # 开始计时
        q_norm_bof_initial = hist_query_initial / (np.linalg.norm(hist_query_initial) + 1e-8) # L2归一化查询直方图
        scores_bof_initial = self.train_hist_bof_norm @ q_norm_bof_initial # 计算与训练集的余弦相似度 (通过归一化向量的点积)
        time_bof_initial = perf_counter() - t0_bof # 结束计时
        top_idx_bof_initial = np.argsort(scores_bof_initial)[::-1][:top_k] # 获取Top-k结果的索引 (降序)
        results_bof_initial = [(self.train_paths[i], float(scores_bof_initial[i])) for i in top_idx_bof_initial] # 格式化结果
        p, r, ap, pr = self._calculate_metrics_and_pr(img_path, scores_bof_initial, top_idx_bof_initial, top_k) # 计算指标
        self.metrics["bof"].update({"precision@k": p, "recall@k": r, "mAP": ap, "time": time_bof_initial, "pr_curve": pr}) # 更新指标字典

        # TF-IDF (初始)
        t0_tfidf = perf_counter()
        tf_initial = hist_query_initial / (hist_query_initial.sum() + 1e-8) # 计算查询图像的TF (词频)
        tfidf_q_initial = tf_initial * self.idf # 计算查询图像的TF-IDF向量
        q_norm_tfidf_initial = tfidf_q_initial / (np.linalg.norm(tfidf_q_initial) + 1e-8) # L2归一化
        scores_tfidf_initial = self.train_hist_tfidf_norm @ q_norm_tfidf_initial # 计算与训练集的相似度
        time_tfidf_initial = perf_counter() - t0_tfidf
        top_idx_tfidf_initial = np.argsort(scores_tfidf_initial)[::-1][:top_k]
        results_tfidf_initial = [(self.train_paths[i], float(scores_tfidf_initial[i])) for i in top_idx_tfidf_initial]
        p, r, ap, pr = self._calculate_metrics_and_pr(img_path, scores_tfidf_initial, top_idx_tfidf_initial, top_k)
        self.metrics["tfidf"].update({"precision@k": p, "recall@k": r, "mAP": ap, "time": time_tfidf_initial, "pr_curve": pr})

        # 线性组合 (初始)
        t0_lc = perf_counter()
        # 为了更好地组合，将BoF和TF-IDF分数进行min-max归一化到[0,1]区间
        s_bof_norm = (scores_bof_initial - np.min(scores_bof_initial)) / (np.max(scores_bof_initial) - np.min(scores_bof_initial) + 1e-8)
        s_tfidf_norm = (scores_tfidf_initial - np.min(scores_tfidf_initial)) / (np.max(scores_tfidf_initial) - np.min(scores_tfidf_initial) + 1e-8)
        scores_combined_initial = alpha * s_bof_norm + (1 - alpha) * s_tfidf_norm # 按alpha权重线性加权组合
        time_lc_calc = perf_counter() - t0_lc # 仅组合计算的时间
        time_lc_initial = time_bof_initial + time_tfidf_initial + time_lc_calc # 线性组合总时间
        top_idx_combined_initial = np.argsort(scores_combined_initial)[::-1][:top_k]
        results_combined_initial = [(self.train_paths[i], float(scores_combined_initial[i])) for i in top_idx_combined_initial]
        p, r, ap, pr = self._calculate_metrics_and_pr(img_path, scores_combined_initial, top_idx_combined_initial, top_k)
        self.metrics["linear_combination"].update({"precision@k": p, "recall@k": r, "mAP": ap, "time": time_lc_initial, "pr_curve": pr})

        results_bof_qe, results_tfidf_qe, results_combined_qe = None, None, None # 初始化查询扩展结果为None

        if use_expansion and expansion_top_n > 0: # 如果启用查询扩展且N>0
            print(f"执行查询扩展，使用前 {expansion_top_n} 个初始TF-IDF结果...")
            t_start_qe_process = perf_counter() # 查询扩展过程开始计时

            # 使用初始TF-IDF结果中分数最高的 expansion_top_n 个图像进行反馈
            # feedback_indices_global 是基于 all_scores (即 scores_tfidf_initial) 排序后的全局索引
            feedback_indices_global = np.argsort(scores_tfidf_initial)[::-1][:expansion_top_n]

            expanded_descriptors_list = [desc_query_initial.copy()] # 从原始查询描述符开始构建扩展描述符列表
            sift_time_feedback = 0 # 记录反馈文档SIFT提取的总时间
            for i_feedback in feedback_indices_global: # 遍历选定的反馈图像索引
                feedback_img_path = self.train_paths[i_feedback] # 获取反馈图像路径
                t_sift_fb_start = perf_counter()
                desc_feedback = self._sift(feedback_img_path) # 提取反馈图像的SIFT描述符
                sift_time_feedback += (perf_counter() - t_sift_fb_start)
                if desc_feedback is not None and len(desc_feedback) > 0: # 如果成功提取
                    expanded_descriptors_list.append(desc_feedback) # 添加到列表中
            
            if len(expanded_descriptors_list) > 0: # 如果列表中有描述符（至少有原始查询的）
                final_expanded_descriptors = np.vstack(expanded_descriptors_list) # 将所有描述符合并为一个大矩阵
            else: # 理论上不会发生，因为原始查询描述符有效
                final_expanded_descriptors = desc_query_initial # 备用方案
            
            t_hist_qe_start = perf_counter()
            hist_query_expanded = self._compute_hist(final_expanded_descriptors) # 基于合并的描述符计算新的（扩展的）查询直方图
            time_hist_qe_calc = perf_counter() - t_hist_qe_start # 计算新直方图的时间

            # BoF (查询扩展)
            t0_bof_qe = perf_counter()
            q_norm_bof_expanded = hist_query_expanded / (np.linalg.norm(hist_query_expanded) + 1e-8)
            scores_bof_qe = self.train_hist_bof_norm @ q_norm_bof_expanded
            time_bof_qe_calc = perf_counter() - t0_bof_qe
            top_idx_bof_qe = np.argsort(scores_bof_qe)[::-1][:top_k]
            results_bof_qe = [(self.train_paths[i], float(scores_bof_qe[i])) for i in top_idx_bof_qe]
            p_qe, r_qe, ap_qe, pr_qe = self._calculate_metrics_and_pr(img_path, scores_bof_qe, top_idx_bof_qe, top_k)
            # BoF_QE 的总时间 = 反馈图像SIFT提取时间 + 新直方图计算时间 + QE的BoF评分时间
            time_bof_qe_total = sift_time_feedback + time_hist_qe_calc + time_bof_qe_calc
            self.metrics["bof_qe"].update({"precision@k": p_qe, "recall@k": r_qe, "mAP": ap_qe, "time": time_bof_qe_total, "pr_curve": pr_qe})

            # TF-IDF (查询扩展)
            t0_tfidf_qe = perf_counter()
            tf_expanded = hist_query_expanded / (hist_query_expanded.sum() + 1e-8)
            tfidf_q_expanded = tf_expanded * self.idf
            q_norm_tfidf_expanded = tfidf_q_expanded / (np.linalg.norm(tfidf_q_expanded) + 1e-8)
            scores_tfidf_qe = self.train_hist_tfidf_norm @ q_norm_tfidf_expanded
            time_tfidf_qe_calc = perf_counter() - t0_tfidf_qe
            top_idx_tfidf_qe = np.argsort(scores_tfidf_qe)[::-1][:top_k]
            results_tfidf_qe = [(self.train_paths[i], float(scores_tfidf_qe[i])) for i in top_idx_tfidf_qe]
            p_qe, r_qe, ap_qe, pr_qe = self._calculate_metrics_and_pr(img_path, scores_tfidf_qe, top_idx_tfidf_qe, top_k)
            time_tfidf_qe_total = sift_time_feedback + time_hist_qe_calc + time_tfidf_qe_calc
            self.metrics["tfidf_qe"].update({"precision@k": p_qe, "recall@k": r_qe, "mAP": ap_qe, "time": time_tfidf_qe_total, "pr_curve": pr_qe})

            # 线性组合 (查询扩展)
            t0_lc_qe = perf_counter()
            s_bof_qe_norm = (scores_bof_qe - np.min(scores_bof_qe)) / (np.max(scores_bof_qe) - np.min(scores_bof_qe) + 1e-8)
            s_tfidf_qe_norm = (scores_tfidf_qe - np.min(scores_tfidf_qe)) / (np.max(scores_tfidf_qe) - np.min(scores_tfidf_qe) + 1e-8)
            scores_combined_qe = alpha * s_bof_qe_norm + (1 - alpha) * s_tfidf_qe_norm # 使用与初始查询相同的alpha值
            time_lc_qe_calc = perf_counter() - t0_lc_qe
            top_idx_combined_qe = np.argsort(scores_combined_qe)[::-1][:top_k]
            results_combined_qe = [(self.train_paths[i], float(scores_combined_qe[i])) for i in top_idx_combined_qe]
            p_qe, r_qe, ap_qe, pr_qe = self._calculate_metrics_and_pr(img_path, scores_combined_qe, top_idx_combined_qe, top_k)
            
            # 查询扩展的总处理时间，从反馈图像的SIFT提取开始计时，直到所有QE评分完成
            total_qe_duration = perf_counter() - t_start_qe_process 
            self.metrics["linear_combination_qe"].update({"precision@k": p_qe, "recall@k": r_qe, "mAP": ap_qe, "time": total_qe_duration, "pr_curve": pr_qe})

            print(f"查询扩展完成。总QE处理时长 (反馈SIFT + 新直方图 + 评分): {total_qe_duration:.3f}s")

        return results_bof_initial, results_tfidf_initial, results_combined_initial, \
               results_bof_qe, results_tfidf_qe, results_combined_qe

    def _avg_pr(self, pr_curves_list: List[Tuple[np.ndarray, np.ndarray] | None]) -> Tuple[np.ndarray, np.ndarray] | None:
        """ 
        对多条PR曲线进行平均化处理。
        :param pr_curves_list: 包含多个PR曲线数据点的列表，每个元素是(召回率数组, 精确率数组)或None。
        :return: 平均后的 (召回率网格, 平均精确率数组) 或 None。
        """
        if not pr_curves_list: # 检查列表是否为空
            return None # 如果没有曲线可平均，返回None
        
        # 过滤掉无效的曲线 (None或数据点少于2的，无法插值)
        valid_curves = [pr for pr in pr_curves_list if pr is not None and len(pr[0]) > 1 and len(pr[1]) > 1]
        if not valid_curves:
            print("没有有效的PR曲线可供平均。")
            return (np.array([0.0, 1.0]), np.array([0.0, 0.0])) # 返回表示精确率为0的默认曲线

        recall_grid = np.linspace(0.0, 1.0, 101) # 创建标准的召回率网格点 (0到1之间101个点)
        interpolated_precisions = [] # 用于存储每条曲线在recall_grid上插值后的精确率

        for recall, precision in valid_curves: # 遍历所有有效的PR曲线
            # 确保召回率是单调递增的，以便插值 (排序)
            sort_indices = np.argsort(recall)
            recall_sorted = recall[sort_indices]
            precision_sorted = precision[sort_indices]
            
            # interp1d 需要唯一的 x 值 (召回率)。如果存在重复的召回率值，通常取其对应精确率的平均值或第一次出现的值。
            # 这里简单地通过np.unique取第一次出现的值对应的索引。
            unique_recall, unique_indices = np.unique(recall_sorted, return_index=True)
            precision_at_unique_recall = precision_sorted[unique_indices] # 获取在唯一召回率点上的精确率

            if len(unique_recall) < 2: # 插值至少需要两个不同的点
                # print(f"警告：跳过处理后唯一召回率点少于2个的PR曲线。")
                # 以零精确率填充或跳过此曲线，以避免影响平均结果
                interpolated_precisions.append(np.zeros_like(recall_grid)) 
                continue
            
            # 使用线性插值。bounds_error=False 允许外插，fill_value处理边界情况。
            # fill_value 使用第一个和最后一个有效精确率值进行边界填充。
            # 这意味着，在 recall_grid[0]=0 时，如果 unique_recall[0] > 0, 
            # 插值结果会使用 precision_at_unique_recall[0] (即在最小实际召回率点的精确率) 作为填充。
            # 如果 unique_recall[0] == 0, 则使用该点的精确率。
            interp_func = interp1d(unique_recall, precision_at_unique_recall, kind='linear', 
                                   bounds_error=False, 
                                   fill_value=(precision_at_unique_recall[0], precision_at_unique_recall[-1]))
            interpolated_p = interp_func(recall_grid) # 在标准召回率网格上插值得到对应的精确率
            interpolated_precisions.append(interpolated_p)
        
        if not interpolated_precisions: # 如果没有曲线可以成功插值
            print("没有PR曲线可以成功插值。")
            return (np.array([0.0, 1.0]), np.array([0.0, 0.0])) # 返回默认曲线

        averaged_precision = np.mean(interpolated_precisions, axis=0) # 按列（即每个召回率点）计算平均精确率
        return recall_grid, averaged_precision # 返回召回率网格和对应的平均精确率


    def evaluate_folder(self, test_dir: str, top_k: int = 10, alpha: float = 0.5,
                        use_expansion: bool = False, expansion_top_n: int = 3) -> \
                        Tuple[Dict[str, Dict[str, float]], # 平均指标字典
                              Dict[str, Tuple[np.ndarray, np.ndarray] | None]]: # 平均PR曲线字典
        """
        批量评估模型在测试集上的性能。
        :param test_dir: 测试图像目录。
        :param top_k: 返回结果数量。
        :param alpha: 线性组合中BoF分数的权重。
        :param use_expansion: 是否在评估中使用查询扩展。
        :param expansion_top_n: 查询扩展时使用的反馈文档数。
        :return: 一个元组，包含两个字典：
                 1. 平均指标字典：键为方法名，值为包含precision@k, recall@k, mAP, time的字典。
                 2. 平均PR曲线字典：键为方法名，值为(召回率数组, 精确率数组)元组或None。
        """
        if self.codebook is None or self.train_hist_bof_norm is None or self.train_hist_tfidf_norm is None or self.idf is None or not self.train_paths:
            raise RuntimeError("模型未训练或训练数据不完整，请先训练模型。")
        
        test_images: List[str] = [] # 用于存储测试图像的路径
        for root, _dirs, files in os.walk(test_dir): # 遍历测试集文件夹
            for f in files:
                if f.lower().endswith((".jpg", ".jpeg", ".png")): # 检查是否为图像文件
                    test_images.append(os.path.join(root, f))
        if not test_images: # 如果没有找到测试图像
            raise ValueError(f"在 {test_dir} 中未找到测试图像。")

        metric_keys_all = list(self.metrics.keys()) # 获取所有定义的方法键（包括原始和QE）
        # 初始化用于累加各项指标的总和的字典
        total_metrics_sum: Dict[str, Dict[str, float]] = {
            method: {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0} for method in metric_keys_all
        }
        # 初始化用于存储每次查询的PR曲线的列表的字典
        pr_curves_all_methods: Dict[str, List[Tuple[np.ndarray, np.ndarray] | None]] = {
             method: [] for method in metric_keys_all
        }
        
        successful_queries_count = 0 # 记录成功处理的查询（测试图像）数量
        print(f"评估 {len(test_images)} 张测试图像 (Top-k={top_k}, Alpha={alpha}, QE={use_expansion}, QE_N={expansion_top_n})...")
        batch_start_time = perf_counter() # 记录批量评估的开始时间

        for i, img_path in enumerate(test_images): # 遍历每张测试图像
            try:
                # 对于批量评估中的每个测试图像，调用 query 方法。
                # query 方法现在会内部处理查询扩展（如果启用），并更新 self.metrics 字典。
                # 我们需要确保评估时使用的 top_k 参数与 query 方法的 top_k 一致。
                self.query(img_path, top_k=top_k, alpha=alpha, use_expansion=use_expansion, expansion_top_n=expansion_top_n)
                
                # 从 self.metrics (已被当前的 query 调用更新) 中累积各项指标
                for method_key in metric_keys_all: # 遍历所有方法键
                    if method_key in self.metrics: # 确保该方法的指标已被计算
                        total_metrics_sum[method_key]["precision@k"] += self.metrics[method_key].get("precision@k", 0.0)
                        total_metrics_sum[method_key]["recall@k"] += self.metrics[method_key].get("recall@k", 0.0)
                        total_metrics_sum[method_key]["mAP"] += self.metrics[method_key].get("mAP", 0.0)
                        total_metrics_sum[method_key]["time"] += self.metrics[method_key].get("time", 0.0)
                        pr_curves_all_methods[method_key].append(self.metrics[method_key].get("pr_curve")) # 存储PR曲线数据
                
                successful_queries_count += 1 # 成功处理的查询计数增加
                if (i + 1) % 10 == 0 or (i+1) == len(test_images): # 每处理10张或最后一张时打印进度
                    print(f"已成功处理 {successful_queries_count}/{len(test_images)} 张测试图像。")

            except Exception as e: # 处理查询过程中可能发生的错误
                print(f"处理测试图像 {img_path} 时出错，已跳过：{e}")

        batch_total_time = perf_counter() - batch_start_time # 计算批量评估总耗时
        
        if successful_queries_count == 0: # 如果没有成功处理任何测试图像
            print("没有成功处理的测试图像。")
            # 返回全零的平均指标和默认的PR曲线（例如，精确率为0的直线）
            avg_metrics_final: Dict[str, Dict[str, float]] = {
                method: {"precision@k": 0.0, "recall@k": 0.0, "mAP": 0.0, "time": 0.0} for method in metric_keys_all
            }
            avg_pr_curves_final: Dict[str, Tuple[np.ndarray, np.ndarray] | None] = {
                method: (np.array([0.,1.]), np.array([0.,0.])) for method in metric_keys_all 
            }
            avg_metrics_final["batch_total_time"] = {"value": batch_total_time} # 以字典形式存储总时间，与其他指标格式一致
            return avg_metrics_final, avg_pr_curves_final

        # 计算各项指标的平均值
        avg_metrics_final: Dict[str, Dict[str, float]] = {}
        for method_key in metric_keys_all:
            avg_metrics_final[method_key] = {
                k: total_metrics_sum[method_key][k] / successful_queries_count for k in total_metrics_sum[method_key]
            }
        
        # 计算平均PR曲线
        avg_pr_curves_final: Dict[str, Tuple[np.ndarray, np.ndarray] | None] = {}
        for method_key in metric_keys_all:
            avg_pr_curves_final[method_key] = self._avg_pr(pr_curves_all_methods[method_key])

        avg_metrics_final["batch_total_time"] = {"value": batch_total_time} # 添加总批处理时间信息到平均指标字典中
        print(f"批量评估完成。总处理图像数: {successful_queries_count}/{len(test_images)}。总耗时: {batch_total_time:.3f}s")
        return avg_metrics_final, avg_pr_curves_final


    def plot_comparison(
        self,
        metrics_data: Dict[str, Dict[str, Any]], # 期望的结构类似于 self.metrics 或 evaluate_folder 返回的 avg_metrics_final
        pr_data: Dict[str, Tuple[np.ndarray, np.ndarray] | None], # 期望的结构类似于 evaluate_folder 返回的 avg_pr_curves_final
        is_averaged: bool = False # 指示当前绘制的是否为平均指标（影响标题和部分标签）
        ):
        """
        绘制性能对比图：包含各项指标的柱状图和精确率-召回率（PR）曲线。
        """
        
        plt.style.use('seaborn-v0_8-darkgrid') # 使用seaborn的暗色网格风格以美化绘图
        fig, axes = plt.subplots(1, 2, figsize=(18, 7)) # 创建一个包含两个子图的图表，并调整整体大小

        # 定义要绘制的方法及其在图例中显示的名称
        method_display_names = {
            "bof": "BoF", "tfidf": "TF-IDF", "linear_combination": "LC", # 原始方法
            "bof_qe": "BoF-QE", "tfidf_qe": "TF-IDF-QE", "linear_combination_qe": "LC-QE" # 查询扩展方法
        }
        # 过滤出实际有数据的方法（特别是当查询扩展未运行时，QE方法的指标可能不存在）
        # 通过检查mAP指标是否存在且不为占位符-1来判断（这是一种粗略的检查方式，可根据实际情况调整）
        available_methods = [m for m in method_display_names if metrics_data.get(m) and metrics_data[m].get("mAP", -1) != -1] 
        if not available_methods: # 如果没有可供绘制的数据
            print("没有可用于绘图的数据。")
            plt.show() # 显示一个空图或不显示
            return

        # --- 绘制指标柱状图 (例如 mAP, Recall@k, Time) ---
        ax_bar = axes[0] # 获取第一个子图对象
        # 根据是平均指标还是单次查询指标，选择要绘制的具体指标类型
        metrics_to_plot = ["mAP", "recall@k", "time"] if is_averaged else ["precision@k", "recall@k", "mAP", "time"] # 单次查询时也显示mAP
        metric_labels_display = ["mAP", "Recall@k", "Time (s)"] if is_averaged else ["P@k", "R@k", "mAP", "Time (s)"] # X轴标签
        
        num_metrics = len(metrics_to_plot) # 要绘制的指标数量
        num_methods = len(available_methods) # 要比较的方法数量
        x = np.arange(num_metrics) # 为每个指标组生成X轴位置
        bar_width = 0.8 / num_methods # 根据方法数量动态调整每个柱子的宽度，使其总宽度不超过0.8

        for i, method_key in enumerate(available_methods): # 遍历每种可用的方法
            method_metrics = metrics_data.get(method_key, {}) # 获取该方法的指标数据
            values = [method_metrics.get(m_key, 0.0) for m_key in metrics_to_plot] # 获取对应指标的值
            
            # 特殊处理 batch_total_time，它通常不适合在此类柱状图中与其他指标一起比较
            if method_key == "batch_total_time" and "value" in method_metrics: 
                continue # 跳过 batch_total_time

            # 计算当前方法柱子组的中心位置，实现并列柱状图效果
            current_bar_positions = x + i * bar_width - (num_methods - 1) * bar_width / 2.0
            bars = ax_bar.bar(current_bar_positions, values, bar_width, label=method_display_names[method_key]) # 绘制柱子
            # 在每个柱子的顶端显示其数值
            for bar_idx, bar in enumerate(bars):
                yval = bar.get_height() # 获取柱子高度
                text_format = '.3f' if metrics_to_plot[bar_idx] == "time" else '.2f' # 时间保留3位小数，其他分数保留2位
                ax_bar.text(bar.get_x() + bar.get_width()/2, yval + 0.01, f'{yval:{text_format}}', 
                            ha='center', va='bottom', fontsize=8, rotation=0) # 设置文本位置、对齐、大小等

        ax_bar.set_ylabel("分数 / 时间 (秒)") # Y轴标签
        ax_bar.set_xticks(x) # 设置X轴主要刻度位置（对应每个指标组的中心）
        ax_bar.set_xticklabels(metric_labels_display) # 设置X轴刻度标签
        ax_bar.legend(title="方法", loc='upper right', fontsize='small') # 显示图例
        title_prefix = "平均 " if is_averaged else "单次查询 " # 根据是否平均指标设置图表标题前缀
        ax_bar.set_title(f"{title_prefix}性能比较", fontsize=14) # 设置图表标题
        ax_bar.grid(True, axis='y', linestyle='--') # 添加Y轴的网格线


        # --- 绘制PR曲线图 ---
        ax_pr = axes[1] # 获取第二个子图对象
        
        # 获取颜色映射表，为不同的方法曲线分配不同的颜色
        # 'tab10' 是一个常用的、视觉上区分度较好的颜色表，包含10种颜色
        # 如果方法数量超过10，颜色会开始循环。可以按需选择其他颜色映射表。
        try:
            colors = plt.get_cmap('tab10', num_methods if num_methods <=10 else 20) # 尝试获取指定数量的颜色
        except ValueError: # 如果num_methods为0或1，get_cmap的行为可能不同，使用默认tab10
            colors = plt.get_cmap('tab10')


        for i, method_key in enumerate(available_methods): # 遍历每种可用的方法
            if method_key == "batch_total_time": continue # 总评估时间不适用于PR曲线，跳过

            pr_curve = pr_data.get(method_key) # 获取该方法的PR曲线数据 (召回率数组, 精确率数组)
            if pr_curve:
                recall, precision = pr_curve[0], pr_curve[1] # 直接使用，假设数据已在_calculate_metrics_and_pr中预处理好
                if recall is not None and precision is not None and len(recall) > 1: # 确保数据有效且点数足够绘图
                    
                    plot_r, plot_p = recall, precision # 默认使用原始的召回率和精确率数据
                    # **尝试去除绘图中的(0,0)点，如果它后面有更有意义的点**
                    # 这个逻辑检查曲线的第一个点是否为(0,0)，并且它不是曲线中唯一的点，
                    # 或者后续的点具有非零的召回率或精确率。
                    # 目的是避免绘制一个可能由数据处理或插值意外产生的、并非模型真实性能反映的(0,0)起点。
                    if recall[0] == 0 and precision[0] == 0 and len(recall) > 1 and (recall[1] > 0 or precision[1] > 0):
                        # 如果满足上述条件，则跳过第一个(0,0)点进行绘图
                        plot_r = recall[1:]
                        plot_p = precision[1:]
                    
                    if len(plot_r) > 1 : # 再次检查处理后是否仍有足够的数据点用于绘图
                        # 为了绘图线条清晰，按召回率对数据点进行排序
                        sort_idx = np.argsort(plot_r)
                        ax_pr.plot(plot_r[sort_idx], plot_p[sort_idx], 
                                   label=method_display_names[method_key], # 设置曲线标签
                                   color=colors(i % colors.N), linewidth=1.5) # 设置颜色和线宽；colors.N确保索引有效
            else: # 如果PR曲线数据缺失，在图例中添加一个虚拟条目以保持一致性
                 ax_pr.plot([],[], label=f"{method_display_names[method_key]} (无PR数据)", 
                            color=colors(i % colors.N), linestyle=':') # 使用虚线表示数据缺失


        ax_pr.set_xlabel("召回率 (Recall)", fontsize=12) # X轴标签
        ax_pr.set_ylabel("精确率 (Precision)", fontsize=12) # Y轴标签
        ax_pr.set_title(f"{title_prefix}精确率-召回率曲线", fontsize=14) # 图表标题
        ax_pr.legend(loc='lower left', fontsize='small') # 图例，放在左下角
        ax_pr.set_ylim([-0.05, 1.05]) # 设置Y轴的显示范围，略大于[0,1]以完整显示曲线
        ax_pr.set_xlim([-0.05, 1.05]) # 设置X轴的显示范围
        ax_pr.grid(True, linestyle='--') # 添加网格线

        fig.tight_layout(pad=2.0) # 自动调整子图布局，增加填充以防止标签重叠
        plt.show() # 显示图表


class ImageMatcherGUI(QWidget):
    """
    PyQt5 GUI 界面，用于训练、查询、评估和可视化检索结果。
    """
    # 定义一个信号，用于从其他线程（例如长时间运行的训练或评估任务）向GUI主线程发送进度更新消息
    progress_signal = pyqtSignal(str)

    def __init__(self):
        super().__init__()
        self.matcher = BoF_TFIDF_Retriever(num_clusters=256) # 初始化核心检索器类，默认聚类数为256
        self.query_img: str | None = None # 当前选择的查询图像的路径，初始为None
        
        # 用于缓存每种检索方法（包括原始和QE）的结果列表
        self.results_cache: Dict[str, List[Tuple[str, float]]] = {}

        # 存储上一次批量评估计算得到的平均指标和平均PR曲线数据
        self._last_avg_metrics: Dict[str, Dict[str, Any]] | None = None
        self._last_avg_pr_curves: Dict[str, Tuple[np.ndarray, np.ndarray] | None] | None = None

        self._build_ui() # 调用方法构建用户界面元素
        self.progress_signal.connect(self._append_to_main_log) # 将progress_signal连接到日志追加槽函数

    def _append_to_main_log(self, message: str):
        """将消息追加到主日志区域（通常是结果标签页中的第一个文本框）。"""
        # 假设第一个标签页 (例如BoF结果页) 可以用作训练/评估期间的通用日志输出区域
        if self.tabs.count() > 0: # 检查是否有标签页存在
            log_widget = self.tabs.widget(0) # 获取第一个标签页的控件
            if isinstance(log_widget, QTextEdit): # 确认它是QTextEdit类型
                log_widget.append(message) # 追加消息
        else: # 如果标签页尚未准备好（理论上不应发生在此流程中），则回退到标准输出打印
            print(message)


    def _build_ui(self):
        """构建用户界面的所有元素和布局。"""
        self.setWindowTitle("BoF + TF‑IDF 图像检索系统 (含查询扩展)") # 设置窗口标题
        self.resize(1350, 800) # 设置窗口初始大小，增大以容纳更多元素
        main_layout = QVBoxLayout() # 主垂直布局管理器

        # --- 顶部控制按钮行 (训练, 选择查询图像, 执行检索, 评估测试集, 显示平均图表) ---
        controls_row = QHBoxLayout() # 水平布局用于放置按钮
        self.btn_train = QPushButton("选择训练集并训练")
        self.btn_train.clicked.connect(self.train_model) # 连接训练按钮的点击事件
        self.btn_query = QPushButton("选择查询图像")
        self.btn_query.clicked.connect(self.choose_query) # 连接选择查询图像按钮的点击事件
        self.btn_match = QPushButton("执行检索")
        self.btn_match.clicked.connect(self.run_match) # 连接执行检索按钮的点击事件
        self.btn_evaluate = QPushButton("评估测试集")
        self.btn_evaluate.clicked.connect(self.evaluate_test_set) # 连接评估测试集按钮的点击事件
        self.btn_avg_compare = QPushButton("显示平均图表")
        self.btn_avg_compare.clicked.connect(self.plot_averaged_comparison) # 连接显示平均图表按钮的点击事件
        
        # 将按钮添加到水平布局中
        controls_row.addWidget(self.btn_train)
        controls_row.addWidget(self.btn_query)
        controls_row.addWidget(self.btn_match)
        controls_row.addWidget(self.btn_evaluate)
        controls_row.addWidget(self.btn_avg_compare)
        main_layout.addLayout(controls_row) # 将按钮行布局添加到主布局

        # --- 查询扩展 (QE) 选项 ---
        qe_options_layout = QFormLayout() # 使用表单布局以更好地对齐标签和输入控件
        self.chk_use_qe = QCheckBox("启用查询扩展 (QE)") # 复选框，用于启用/禁用QE
        self.chk_use_qe.setChecked(False) # 默认不启用QE
        self.spin_qe_top_n = QSpinBox() # 数字输入框，用于设置QE时使用的Top-N反馈文档数量
        self.spin_qe_top_n.setMinimum(1) # 最小反馈文档数
        self.spin_qe_top_n.setMaximum(20) # 最大反馈文档数 (可按需调整)
        self.spin_qe_top_n.setValue(3)    # 默认反馈文档数
        qe_options_layout.addRow(self.chk_use_qe, self.spin_qe_top_n) # 将QE选项添加到表单布局
        main_layout.addLayout(qe_options_layout) # 将QE选项布局添加到主布局


        # --- 图像显示区域 (查询图像 和 最佳匹配图像) ---
        img_row = QHBoxLayout() # 水平布局用于并排显示两张图像
        self.lbl_query = QLabel("查询图像") # 用于显示查询图像的标签控件
        self.lbl_query.setAlignment(Qt.AlignCenter) # 文本和图像居中对齐
        self.lbl_query.setFixedSize(350, 350) # 设置固定大小
        self.lbl_query.setStyleSheet("border: 1px solid black; background-color: #f0f0f0;") # 设置边框和背景色

        self.lbl_best_match = QLabel("最优匹配图像 (待定)") # 用于显示最佳匹配图像的标签控件
        self.lbl_best_match.setAlignment(Qt.AlignCenter)
        self.lbl_best_match.setFixedSize(350, 350)
        self.lbl_best_match.setStyleSheet("border: 1px solid black; background-color: #f0f0f0;")
        
        img_row.addWidget(self.lbl_query) # 添加到图像行布局
        img_row.addWidget(self.lbl_best_match)
        main_layout.addLayout(img_row) # 将图像行布局添加到主布局

        # --- 指标表格 (显示Precision@k, Recall@k, mAP, Time等) ---
        # 更新为最多6种方法 (原始方法 + 它们各自的QE版本)
        self.table_metrics = QTableWidget(6, 5) # 6行 (方法数) x 5列 (方法名, P@k, R@k, mAP, 时间)
        self.table_metrics.setHorizontalHeaderLabels(["方法", "Precision@k", "Recall@k", "mAP", "Time(s)"]) # 设置列标题
        self.table_metrics.verticalHeader().setVisible(False) # 隐藏垂直方向的行号表头
        self.table_metrics.setEditTriggers(QTableWidget.NoEditTriggers) # 设置表格内容不可编辑
        self.table_metrics.setFixedHeight(180) # 调整表格的固定高度
        self.table_metrics.horizontalHeader().setStretchLastSection(True) # 让最后一列自动填充剩余宽度
        main_layout.addWidget(self.table_metrics) # 将指标表格添加到主布局

        # --- 结果标签页 (用于显示不同方法的检索结果列表) ---
        self.tabs = QTabWidget() # 创建标签页控件
        self.method_tabs: Dict[str, QTextEdit] = {} # 字典，用于存储每种方法的QTextEdit控件，键为方法标识符

        # 定义要为其创建标签页的方法键和显示名称
        method_keys_for_tabs = ["bof", "tfidf", "linear_combination", "bof_qe", "tfidf_qe", "linear_combination_qe"]
        method_display_names_for_tabs = {
            "bof": "BoF 结果", "tfidf": "TF-IDF 结果", "linear_combination": "线性组合结果",
            "bof_qe": "BoF (QE) 结果", "tfidf_qe": "TF-IDF (QE) 结果", "linear_combination_qe": "线性组合 (QE) 结果"
        }

        for key in method_keys_for_tabs: # 遍历方法键
            text_edit = QTextEdit() # 为每个方法创建一个QTextEdit控件
            text_edit.setReadOnly(True) # 设置为只读，用户不能修改结果
            self.method_tabs[key] = text_edit # 存入字典
            self.tabs.addTab(text_edit, method_display_names_for_tabs[key]) # 将QTextEdit作为新标签页添加到QTabWidget
        
        main_layout.addWidget(self.tabs) # 将标签页控件添加到主布局
        self.setLayout(main_layout) # 设置窗口的主布局

        self._update_metric_table(clear_all=True) # 初始化时清空并格式化指标表格
        # 初始化时禁用部分按钮，因为模型尚未训练或无查询图像
        self.btn_query.setEnabled(False)
        self.btn_match.setEnabled(False)
        self.btn_evaluate.setEnabled(False)
        self.btn_avg_compare.setEnabled(False)

    def choose_query(self):
        """处理用户选择查询图像的动作。"""
        # 打开文件对话框让用户选择图像文件
        fname, _ = QFileDialog.getOpenFileName(self, "选择查询图像", "", "图像文件 (*.jpg *.jpeg *.png)")
        if fname: # 如果用户成功选择了一个文件
            self.query_img = fname # 保存查询图像的路径
            # 加载图像并将其缩放以适应显示标签的大小，保持宽高比，使用平滑变换
            pix = QPixmap(fname).scaled(350, 350, Qt.KeepAspectRatio, Qt.SmoothTransformation) 
            self.lbl_query.setPixmap(pix) # 在查询图像标签中显示图像
            self.lbl_best_match.clear() # 清空上一次的最佳匹配图像显示
            self.lbl_best_match.setText("最优匹配图像 (待定)") # 重置最佳匹配标签的文本
            for key in self.method_tabs: self.method_tabs[key].clear() # 清空所有结果文本区域
            self._update_metric_table(clear_all=True) # 清空指标表格

    def train_model(self):
        """处理模型训练的逻辑，包括用户交互和调用核心训练方法。"""
        folder = QFileDialog.getExistingDirectory(self, "选择训练图像文件夹") # 提示用户选择包含训练图像的文件夹
        if not folder: return # 如果用户未选择文件夹，则直接返回

        # 允许用户通过输入对话框设置视觉词典的聚类数量 (K)
        num_clusters, ok = QInputDialog.getInt(self, "设置聚类数", "输入视觉词典的聚类数 (K):", 
                                               self.matcher.num_clusters, 32, 2048, 64) # 当前值, 最小值, 最大值, 步长
        if not ok: return # 如果用户取消输入，则返回
        self.matcher.num_clusters = num_clusters # 更新模型配置中的聚类数量


        # 构建缓存文件的路径，文件名中包含聚类数量K，以便不同K值使用不同缓存
        cache_file = os.path.join(folder, f"{os.path.basename(folder)}_train_k{num_clusters}.pkl") 
        
        # 询问用户是否希望使用或重新构建已存在的缓存文件
        rebuild_cache_reply = QMessageBox.question(self, "使用缓存", 
                                                   f"找到缓存文件: {cache_file}\n是否重新构建缓存?", # 提示信息
                                                   QMessageBox.Yes | QMessageBox.No | QMessageBox.Cancel, # 按钮选项
                                                   QMessageBox.No if os.path.exists(cache_file) else QMessageBox.Yes) # 默认选项

        if rebuild_cache_reply == QMessageBox.Cancel: return # 用户选择取消
        rebuild_cache = (rebuild_cache_reply == QMessageBox.Yes) # 判断是否需要重建缓存


        self._append_to_main_log("训练中，请稍候...\n") # 在日志区域显示训练开始信息
        QApplication.processEvents() # 处理Qt事件队列，保持UI响应，防止界面冻结

        try:
            if self.matcher.fit(folder, cache_path=cache_file, rebuild_cache=rebuild_cache): # 调用核心的fit方法进行训练
                loaded_from_cache = os.path.exists(cache_file) and not rebuild_cache # 判断训练数据是否从缓存加载
                info_msg = ("已从缓存加载训练数据" if loaded_from_cache
                            else f"已加载 {len(self.matcher.train_paths)} 张有效图像并完成训练 (K={self.matcher.num_clusters})")
                QMessageBox.information(self, "训练完成", info_msg) # 弹出消息框提示训练完成
                self._append_to_main_log(info_msg) # 在日志区域显示完成信息
                # 训练完成后，启用查询、匹配、评估等相关按钮
                self.btn_query.setEnabled(True)
                self.btn_match.setEnabled(True)
                self.btn_evaluate.setEnabled(True)
                self.btn_avg_compare.setEnabled(False) # 重新训练后，之前的平均评估结果失效，禁用此按钮
                self._last_avg_metrics = None # 清除上一次的平均评估结果
                self._last_avg_pr_curves = None
            else: # 如果fit方法返回False，表示训练失败
                err_msg = "训练失败或未找到有效图片！请检查数据集和文件夹结构。"
                QMessageBox.critical(self, "错误", err_msg) # 弹出错误消息框
                self._append_to_main_log(err_msg) # 在日志区域显示错误信息
                # 训练失败时，禁用相关按钮
                self.btn_query.setEnabled(False); self.btn_match.setEnabled(False); self.btn_evaluate.setEnabled(False)

        except Exception as e: # 捕获训练过程中可能发生的其他异常
            QMessageBox.critical(self, "训练错误", f"训练过程中发生错误: {e}") # 弹出错误消息框
            self._append_to_main_log(f"训练错误: {e}") # 在日志区域显示错误信息
            self.btn_query.setEnabled(False); self.btn_match.setEnabled(False); self.btn_evaluate.setEnabled(False)

    def run_match(self):
        """执行单张图像的检索操作。"""
        if self.query_img is None: # 检查是否已选择查询图像
            QMessageBox.warning(self, "提示", "请先选择查询图像！")
            return
        if self.matcher.codebook is None: # 检查模型是否已训练（词典是否存在）
            QMessageBox.warning(self, "提示", "请先训练模型！")
            return

        # 获取用户输入的线性组合权重alpha值
        alpha_value, ok = QInputDialog.getDouble(self, "线性组合权重 (Alpha)",
                                                 "输入 BoF 分数的权重 (alpha, 0-1) 用于线性组合:",
                                                 0.5, 0, 1, 2) # 默认0.5, 范围0-1, 2位小数
        if not ok: return # 如果用户取消输入，则返回

        # 获取查询扩展 (QE) 的相关设置
        use_qe = self.chk_use_qe.isChecked() # 是否启用QE
        qe_top_n = self.spin_qe_top_n.value() if use_qe else 0 # 如果启用QE，获取Top-N值，否则为0

        self._append_to_main_log(f"检索中 (QE={'启用' if use_qe else '禁用'}, N={qe_top_n})...") # 在日志中显示检索状态
        for key in self.method_tabs: self.method_tabs[key].clear() # 清空所有结果显示区域
        self._update_metric_table(clear_all=True) # 清空指标表格
        self.lbl_best_match.clear() # 清空最佳匹配图像的显示
        QApplication.processEvents() # 保持UI响应

        try:
            # 调用核心的query方法执行检索，传入QE参数
            results = self.matcher.query(self.query_img, alpha=alpha_value, 
                                         use_expansion=use_qe, expansion_top_n=qe_top_n)
            
            # 解包返回的检索结果 (包括原始方法的和QE方法的，QE方法的结果可能为None)
            (self.results_cache["bof"], self.results_cache["tfidf"], self.results_cache["linear_combination"],
             self.results_cache["bof_qe"], self.results_cache["tfidf_qe"], self.results_cache["linear_combination_qe"]) = results

            # 确定要在GUI中显示的“最优”匹配图像，并指明是由哪种方法得到的
            # 优先顺序：如果启用了QE，则优先显示QE方法的结果；否则显示原始方法的结果。
            # 在QE或原始方法内部，优先顺序通常是 线性组合 > TF-IDF > BoF。
            best_match_path = None # 最佳匹配图像的路径
            best_method_for_display = "未知" # 用于显示的方法名称

            # 定义方法检索结果的检查优先级顺序
            priority_order = []
            if use_qe: # 如果启用了查询扩展
                priority_order.extend(["linear_combination_qe", "tfidf_qe", "bof_qe"]) # QE方法的优先级
            priority_order.extend(["linear_combination", "tfidf", "bof"]) # 总是包括原始方法作为备选
            
            method_display_names = { # 方法键到显示名称的映射
                "bof": "BoF", "tfidf": "TF-IDF", "linear_combination": "LC",
                "bof_qe": "BoF-QE", "tfidf_qe": "TF-IDF-QE", "linear_combination_qe": "LC-QE"
            }

            for method_key in priority_order: # 按照定义的优先级顺序检查结果
                res_list = self.results_cache.get(method_key) # 获取该方法的结果列表
                if res_list and len(res_list) > 0: # 如果该方法有结果且结果列表不为空
                    best_match_path = res_list[0][0] # 取第一个结果（得分最高的）的路径
                    best_method_for_display = method_display_names.get(method_key, method_key) # 获取显示名称
                    break # 找到第一个有结果的方法后即停止搜索
            
            if best_match_path and os.path.exists(best_match_path): # 如果成功找到最佳匹配图像且文件存在
                pix = QPixmap(best_match_path).scaled(350, 350, Qt.KeepAspectRatio, Qt.SmoothTransformation) # 加载并显示
                self.lbl_best_match.setPixmap(pix)
                self.lbl_best_match.setText(f"最优匹配 ({best_method_for_display})") # 更新标签文本
            else: # 如果未找到任何匹配图像
                self.lbl_best_match.setText("未找到匹配图像")

            self._update_metric_table() # 根据 self.matcher.metrics 更新指标表格的显示
            self._fill_result_texts()   # 根据 self.results_cache 填充各个结果标签页的文本
            self.btn_avg_compare.setEnabled(False) # 单次查询后，平均图表按钮应禁用，因无平均数据

        except Exception as e: # 捕获检索过程中可能发生的异常
            QMessageBox.critical(self, "检索错误", f"检索失败: {e}")
            self._append_to_main_log(f"检索错误: {e}")
            self._update_metric_table(clear_all=True) # 清空指标表
            self.lbl_best_match.clear() # 清空图像显示


    def _update_metric_table(self, clear_all: bool = False):
        """更新GUI中的指标表格以显示最新的性能数据。"""
        method_keys = ["bof", "tfidf", "linear_combination", "bof_qe", "tfidf_qe", "linear_combination_qe"]
        method_display_names = {
            "bof": "BoF", "tfidf": "TF-IDF", "linear_combination": "LC",
            "bof_qe": "BoF-QE", "tfidf_qe": "TF-IDF-QE", "linear_combination_qe": "LC-QE"
        }
        
        for i, key in enumerate(method_keys): # 遍历所有定义的方法键
            self.table_metrics.setItem(i, 0, QTableWidgetItem(method_display_names[key])) # 在第一列设置方法名
            # 如果 clear_all 为True，或者当前方法的指标不在 self.matcher.metrics 中
            # (例如，QE未运行时，QE相关的指标就不存在，或者pr_curve不存在说明未成功计算)
            if clear_all or key not in self.matcher.metrics or not self.matcher.metrics[key].get("pr_curve"): 
                for j in range(1, 5): # 清空该方法对应的 P@k, R@k, mAP, Time 列
                     self.table_metrics.setItem(i, j, QTableWidgetItem(""))
            else: # 否则，从 self.matcher.metrics 中获取并填充指标数据
                metrics = self.matcher.metrics.get(key, {}) # 安全地获取指标字典
                # 对于单次查询，也显示mAP，因为它是在 _calculate_metrics_and_pr 中计算的
                self.table_metrics.setItem(i, 1, QTableWidgetItem(f"{metrics.get('precision@k', 0.0):.3f}"))
                self.table_metrics.setItem(i, 2, QTableWidgetItem(f"{metrics.get('recall@k', 0.0):.3f}"))
                self.table_metrics.setItem(i, 3, QTableWidgetItem(f"{metrics.get('mAP', 0.0):.3f}"))
                self.table_metrics.setItem(i, 4, QTableWidgetItem(f"{metrics.get('time', 0.0):.3f}"))
        
        self.table_metrics.resizeColumnsToContents() # 自动调整列宽以适应内容


    def _fill_result_texts(self):
        """填充各个标签页中的文本区域以显示详细的检索结果列表。"""
        method_keys_for_tabs = ["bof", "tfidf", "linear_combination", "bof_qe", "tfidf_qe", "linear_combination_qe"]
        
        for key in method_keys_for_tabs: # 遍历所有方法
            text_edit_widget = self.method_tabs.get(key) # 获取该方法对应的QTextEdit控件
            if not text_edit_widget: continue # 如果控件不存在（理论上不应发生），则跳过
            text_edit_widget.clear() # 清空该文本区域的旧内容

            results_list = self.results_cache.get(key) # 从缓存中获取该方法的检索结果列表
            metrics = self.matcher.metrics.get(key, {}) # 从matcher获取该方法的性能指标

            # 处理特殊情况：QE方法但QE未启用，或QE已启用但该QE方法无结果（可能由于错误）
            if results_list is None and "qe" in key and not self.chk_use_qe.isChecked(): # QE方法且QE复选框未选中
                 text_edit_widget.append("查询扩展未启用。")
                 continue # 跳到下一个方法
            if results_list is None and "qe" in key and self.chk_use_qe.isChecked(): # QE方法且QE已启用，但结果仍为None (可能在query方法中出错)
                 text_edit_widget.append("查询扩展执行但无结果。") # 可以考虑显示更具体的错误或状态信息
                 continue
            if not results_list: # 对于原始方法，或者已运行的QE方法，如果结果列表为空
                 text_edit_widget.append("无检索结果。")
                 continue

            # 构建并显示结果的头部信息（包含方法名、结果数量和主要性能指标）
            tab_index = self.tabs.indexOf(text_edit_widget) # 获取当前QTextEdit控件在QTabWidget中的索引
            tab_title = self.tabs.tabText(tab_index) if tab_index != -1 else key # 获取标签页的标题作为方法显示名

            header = f"--- {tab_title} ({len(results_list)} 项) ---\n" # 结果头部
            header += f"P@k: {metrics.get('precision@k', 0.0):.3f}, R@k: {metrics.get('recall@k', 0.0):.3f}, "
            header += f"mAP: {metrics.get('mAP', 0.0):.3f}, Time: {metrics.get('time', 0.0):.3f}s\n" # 指标信息
            text_edit_widget.append(header) # 添加头部信息到文本区域

            # 逐条显示Top-k检索结果（排名、文件名、相似度得分）
            for rank, (path, score) in enumerate(results_list, 1): # rank从1开始
                text_edit_widget.append(f"{rank:>2}. {os.path.basename(path)} (score={score:.4f})")


    def evaluate_test_set(self):
        """处理在测试集上批量评估模型性能的逻辑。"""
        if self.matcher.codebook is None: # 确保模型已训练
            QMessageBox.warning(self, "提示", "请先训练模型！")
            return
        test_dir = QFileDialog.getExistingDirectory(self, "选择测试集文件夹") # 用户选择测试集所在的文件夹
        if not test_dir: return # 如果未选择，则返回

        # 获取评估时使用的alpha值 (用于线性组合)
        alpha_value, ok_alpha = QInputDialog.getDouble(self, "线性组合权重 (Alpha) - 评估",
                                                 "输入 BoF 分数的权重 (alpha, 0-1):", 0.5, 0, 1, 2)
        if not ok_alpha: return # 用户取消

        # 获取评估时是否使用查询扩展 (QE) 及其相关参数
        use_qe_eval = self.chk_use_qe.isChecked()
        qe_top_n_eval = self.spin_qe_top_n.value() if use_qe_eval else 0 # 如果不使用QE，N为0
        
        self._append_to_main_log(f"评估中 (Alpha={alpha_value}, QE={'启用' if use_qe_eval else '禁用'}, N={qe_top_n_eval})...") # 日志记录
        for key in self.method_tabs: self.method_tabs[key].clear() # 清空结果显示区域
        self._update_metric_table(clear_all=True) # 清空指标表格
        self.lbl_query.clear(); self.lbl_best_match.clear() # 清空图像显示区域
        QApplication.processEvents() # 保持UI响应

        try:
            # 调用核心的 evaluate_folder 方法进行批量评估
            avg_metrics, avg_pr_curves = self.matcher.evaluate_folder(
                test_dir, alpha=alpha_value, 
                use_expansion=use_qe_eval, expansion_top_n=qe_top_n_eval
            )
            self._last_avg_metrics = avg_metrics # 存储平均指标结果，用于后续绘图
            self._last_avg_pr_curves = avg_pr_curves # 存储平均PR曲线数据，用于后续绘图

            # 构建要在消息框和日志中显示的评估结果摘要信息
            msg = f"--- 测试集评估完成 ---\n"
            if "batch_total_time" in avg_metrics and "value" in avg_metrics["batch_total_time"]: # 检查是否有总评估时间
                 msg += f"总评估时间: {avg_metrics['batch_total_time']['value']:.3f}s\n"
            
            msg += "--- 平均指标 (Average Metrics) ---\n"
            method_display_names = { # 方法键到显示名称的映射
                "bof": "BoF", "tfidf": "TF-IDF", "linear_combination": "LC",
                "bof_qe": "BoF-QE", "tfidf_qe": "TF-IDF-QE", "linear_combination_qe": "LC-QE"
            }
            for method_key, display_name in method_display_names.items(): # 遍历所有方法
                if method_key in avg_metrics: # 如果该方法的平均指标存在
                    metrics = avg_metrics[method_key]
                    msg += f"{display_name}:\n"
                    msg += f"  mAP: {metrics.get('mAP', 0.0):.3f}\n" # mAP 是批量评估中的关键平均指标
                    msg += f"  Precision@k: {metrics.get('precision@k', 0.0):.3f}\n"
                    msg += f"  Recall@k: {metrics.get('recall@k', 0.0):.3f}\n"
                    msg += f"  Avg. Time per query: {metrics.get('time', 0.0):.3f}s\n" # 平均每次查询的耗时
            
            QMessageBox.information(self, "评估完成", msg) # 通过消息框向用户显示评估结果摘要
            self._append_to_main_log(msg) # 同时将结果摘要追加到GUI的日志区域
            self.btn_avg_compare.setEnabled(True) # 评估完成后，启用“显示平均图表”按钮

        except Exception as e: # 捕获评估过程中可能发生的异常
            QMessageBox.critical(self, "评估错误", f"评估过程中发生错误: {e}")
            self._append_to_main_log(f"评估错误: {e}")
            self.btn_avg_compare.setEnabled(False) # 如果发生错误，禁用“显示平均图表”按钮


    def plot_averaged_comparison(self):
        """绘制批量评估完成后得到的平均性能对比图表（包括柱状图和PR曲线）。"""
        if self._last_avg_metrics is None or self._last_avg_pr_curves is None: # 检查是否已有评估结果数据
            QMessageBox.warning(self, "提示", "请先执行测试集评估！")
            return
        try:
            # 确保所有预期的指标键都存在于传递给绘图函数的数据中，即使其值为默认值。
            # （更好的做法可能是在 plot_comparison 方法内部通过检查键是否存在来更灵活地处理）
            metrics_to_plot = self._last_avg_metrics.copy() # 创建指标数据的副本以传递给绘图函数
            
            self.matcher.plot_comparison( # 调用核心的绘图方法
                metrics_data=metrics_to_plot,
                pr_data=self._last_avg_pr_curves,
                is_averaged=True # 指明当前绘制的是平均指标的图表
            )
        except Exception as e: # 捕获绘图过程中可能发生的异常
            QMessageBox.critical(self, "绘图错误", f"绘制平均图表失败: {e}")
            print(f"绘图错误: {e}") # 同时在控制台打印错误信息，便于调试


if __name__ == "__main__":
    app = QApplication.instance() # 尝试获取已存在的QApplication实例（例如在IPython等交互式环境中运行时）
    if not app: # 如果不存在实例，则创建一个新的QApplication实例
        app = QApplication(sys.argv)

    gui = ImageMatcherGUI() # 创建GUI主窗口的实例
    gui.show() # 显示主窗口
    sys.exit(app.exec_()) # 进入Qt应用程序的事件循环，直到窗口关闭