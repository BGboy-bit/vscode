'''
Data:2025.4.15
Author: ACatWithoutFish
Attention:图片文件需要放置在全英文路径名下，方可运行！！！
'''

import cv2
import numpy as np
import os
from sklearn.cluster import MiniBatchKMeans
from sklearn.neighbors import NearestNeighbors
from sklearn.metrics import precision_recall_curve, precision_score, recall_score, average_precision_score
import tkinter as tk
from tkinter import filedialog, messagebox, ttk
from PIL import Image, ImageTk
import time
import matplotlib.pyplot as plt

class ImageRetrievalSystem:
    def __init__(self):
        self.train_features_bof = []
        self.train_features_tfidf = []
        self.codebook = None
        self.knn_model_bof = None
        self.knn_model_tfidf = None
        self.train_images = []
        self.train_labels = []  # 存储每个训练图像的类别
        self.test_image = None
        self.results = {'bof': [], 'tfidf': []}
        self.metrics = {
            'bof': {'precision': 0, 'recall': 0, 'map': 0, 'time': 0},
            'tfidf': {'precision': 0, 'recall': 0, 'map': 0, 'time': 0}
        }

        self.pr_curves = {'bof': None, 'tfidf': None}  # 存储PR曲线数据

    def extract_sift_features(self, image_path):
        '''
        提取SIFT特征
        '''
        img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
        if img is None:
            return None
        sift = cv2.SIFT_create()
        keypoints, descriptors = sift.detectAndCompute(img, None)
        return descriptors

    def build_codebook(self, train_descriptors, num_clusters=512):
        '''
        构建视觉词典
        '''
        all_descriptors = np.concatenate(train_descriptors) #融合成一个大数组
        kmeans = MiniBatchKMeans(n_clusters=num_clusters, random_state=42)
        kmeans.fit(all_descriptors)
        return kmeans

    def encode_features(self, descriptors, use_tfidf=True):
        '''
        特征编码
        '''
        if descriptors is None or self.codebook is None:
            return None
        
        labels = self.codebook.predict(descriptors)
        histogram = np.bincount(labels, minlength=self.codebook.n_clusters)
        
        if use_tfidf:
            tf = histogram / np.sum(histogram)
            return tf
        else:
            return histogram / np.linalg.norm(histogram) # 归一化处理 将向量缩放到单位长度

    def compute_idf(self, train_features):
        '''
        计算IDF的值
        '''
        doc_count = len(train_features)
        word_doc_counts = np.zeros(self.codebook.n_clusters)
        
        for hist in train_features:
            word_doc_counts += (hist > 0).astype(int)
        
        idf = np.log((doc_count + 1) / (word_doc_counts + 1)) + 1
        return idf

    def load_train_set(self, train_dir):
        '''
        加载训练集
        '''
        self.train_images = []
        self.train_labels = []
        train_descriptors = []
        
        for category in os.listdir(train_dir):
            category_dir = os.path.join(train_dir, category)
            if not os.path.isdir(category_dir):
                continue
                
            for img_file in os.listdir(category_dir):
                if img_file.lower().endswith(('.jpg', '.png', '.jpeg')):
                    img_path = os.path.join(category_dir, img_file)
                    self.train_images.append(img_path)
                    self.train_labels.append(category)
                    
                    descriptors = self.extract_sift_features(img_path)
                    if descriptors is not None:
                        train_descriptors.append(descriptors)
        
        if not train_descriptors:
            raise ValueError("没有找到有效的训练图像或无法提取特征")
        
        self.codebook = self.build_codebook(train_descriptors)
        
        # 编码训练集特征
        self.train_features_bof = []
        self.train_features_tfidf = []
        
        for desc in train_descriptors:
            hist_bof = self.encode_features(desc, use_tfidf=False)
            if hist_bof is not None:
                self.train_features_bof.append(hist_bof)
            
            hist_tf = self.encode_features(desc, use_tfidf=True)
            if hist_tf is not None:
                self.train_features_tfidf.append(hist_tf)
        
        # 计算和应用TF-IDF
        idf = self.compute_idf(self.train_features_tfidf)
        self.train_features_tfidf = [tf * idf for tf in self.train_features_tfidf]
        
        # 构建KNN模型
        self.knn_model_bof = NearestNeighbors(n_neighbors=min(10, len(self.train_images)), metric='cosine')
        self.knn_model_bof.fit(np.array(self.train_features_bof))
        
        self.knn_model_tfidf = NearestNeighbors(n_neighbors=min(10, len(self.train_images)), metric='cosine')
        self.knn_model_tfidf.fit(np.array(self.train_features_tfidf))

    def calculate_recall(self, retrieved_indices, relevant_indices):
        """
        召回率计算函数
        """
        if not relevant_indices:
            return 0.0
        
        # 计算检索结果中相关图像的数量
        retrieved_relevant = len(set(retrieved_indices) & set(relevant_indices))
        # 召回率 = 检索到的相关图像数 / 训练集中所有相关图像数
        return retrieved_relevant / len(relevant_indices)

    def evaluate_retrieval(self, retrieved_indices, relevant_indices, retrieval_time, distances):
        """
        评估检索结果
        """
        metrics = {}
        
        # 计算相关图像数量
        #num_relevant = len(relevant_indices)
        num_retrieved = len(retrieved_indices)
        
        # 计算二值标签和置信度（使用1/(1+distance)作为置信度）
        y_true = [1 if idx in relevant_indices else 0 for idx in retrieved_indices]
        y_scores = [1/(1+d) for d in distances[0]]  # 使用距离的倒数作为置信度 距离越小 意味着相似度越高 置信度也应该越高
        
        # 计算指标
        metrics['precision'] = precision_score(y_true, [1]*num_retrieved, zero_division=0)
        metrics['recall'] = self.calculate_recall(retrieved_indices, relevant_indices)
        metrics['map'] = average_precision_score(y_true, y_scores)
        metrics['time'] = retrieval_time
        
        # 计算PR曲线数据
        precision, recall, _ = precision_recall_curve(y_true, y_scores)
        
        # 存储PR曲线数据
        return metrics, (precision, recall)
    
    def retrieve_with_bof(self, test_image_path):
        '''
        使用BoF方法进行图像检索
        '''
        # 开始计时 从特征提取开始
        start_time = time.time()
        
        # 提取测试图像特征
        test_desc = self.extract_sift_features(test_image_path)
        if test_desc is None:
            return False
        
        # 编码测试图像
        test_hist_bof = self.encode_features(test_desc, use_tfidf=False)
        if test_hist_bof is None:
            return False
        
        # 执行KNN检索
        distances, indices = self.knn_model_bof.kneighbors([test_hist_bof])
        retrieval_time = time.time() - start_time
        
        # 获取测试图像的类别
        test_category = None
        for part in os.path.normpath(test_image_path).split(os.sep):
            if part in set(self.train_labels):
                test_category = part
                break
        
        # 获取真实相关图像索引
        relevant_indices = [i for i, label in enumerate(self.train_labels) if label == test_category] if test_category else []
        
        # 存储检索结果
        self.results['bof'] = [self.train_images[idx] for idx in indices[0]]
        self.results['bof_similarity'] = [1/(1+d) for d in distances[0]]
        
        # 评估检索结果
        self.metrics['bof'], self.pr_curves['bof'] = self.evaluate_retrieval(
            indices[0], relevant_indices, retrieval_time, distances
        )
        
        return True

    def retrieve_with_tfidf(self, test_image_path):
        '''
        使用TF-IDF方法进行图像检索
        '''
        # 开始计时 从特征提取开始
        start_time = time.time()
        
        # 提取测试图像特征
        test_desc = self.extract_sift_features(test_image_path)
        if test_desc is None:
            return False
        
        # 编码测试图像
        test_hist_tfidf = self.encode_features(test_desc, use_tfidf=True)
        if test_hist_tfidf is None:
            return False
        
        # 执行KNN检索
        distances, indices = self.knn_model_tfidf.kneighbors([test_hist_tfidf])
        retrieval_time = time.time() - start_time
        
        # 获取测试图像的类别
        test_category = None
        for part in os.path.normpath(test_image_path).split(os.sep):
            if part in set(self.train_labels):
                test_category = part
                break
        
        # 获取真实相关图像索引
        relevant_indices = [i for i, label in enumerate(self.train_labels) if label == test_category] if test_category else []
        
        # 存储检索结果
        self.results['tfidf'] = [self.train_images[idx] for idx in indices[0]]
        self.results['tfidf_similarity'] = [1/(1+d) for d in distances[0]]
        
        # 评估检索结果
        self.metrics['tfidf'], self.pr_curves['tfidf'] = self.evaluate_retrieval(
            indices[0], relevant_indices, retrieval_time, distances
        )
        
        return True

    def retrieve_images(self, test_image_path):
        '''
        图像检索
        '''
        self.test_image = test_image_path
        
        # 分别执行两种检索方法
        bof_success = self.retrieve_with_bof(test_image_path)
        tfidf_success = self.retrieve_with_tfidf(test_image_path)

        return True

    def plot_comparison_charts(self, avg_metrics, is_test_set=False):
        """
        绘制对比图表
        """
        plt.figure(figsize=(12, 5) if not is_test_set else (15, 5))
        
        # 指标对比
        plt.subplot(1, 2, 1)
        metrics = ['Precision', 'Recall', 'Time(s)'] if not is_test_set else ['mAP', 'Avg Recall', 'Total Time(s)']
        x = np.arange(len(metrics))
        width = 0.35
        
        # 区分是单次检索还是测试集评估
        bof_values = [
            self.metrics['bof']['precision'] if not is_test_set else avg_metrics['bof']['map'],
            self.metrics['bof']['recall'] if not is_test_set else avg_metrics['bof']['avg_recall'],
            self.metrics['bof']['time'] if not is_test_set else avg_metrics['bof']['total_time']
        ]

        tfidf_values = [
            self.metrics['tfidf']['precision'] if not is_test_set else avg_metrics['tfidf']['map'],
            self.metrics['tfidf']['recall'] if not is_test_set else avg_metrics['tfidf']['avg_recall'],
            self.metrics['tfidf']['time'] if not is_test_set else avg_metrics['tfidf']['total_time']
        ]
        
        plt.bar(x - width/2, bof_values, width, label='BoF', color='blue')
        plt.bar(x + width/2, tfidf_values, width, label='TF-IDF', color='orange')
        plt.xticks(x, metrics)
        plt.xlabel('Metrics')
        plt.ylabel('Score')
        plt.title('Performance Comparison')
        plt.legend(loc='upper right', framealpha=0.5)
        
        # PR曲线
        plt.subplot(1, 2, 2)
        if not is_test_set:
            if self.pr_curves['bof'] is not None:
                precision, recall = self.pr_curves['bof']
                plt.plot(recall, precision, 'b-', label='BoF')
            if self.pr_curves['tfidf'] is not None:
                precision, recall = self.pr_curves['tfidf']
                plt.plot(recall, precision, 'r--', label='TF-IDF')
        else:
            # 测试集评估时使用平均PR曲线
            plt.plot([0, 1], [0.5, 0.5], 'k--', label='Baseline')
            if hasattr(self, 'avg_pr_bof'):
                plt.plot(self.avg_pr_bof[1], self.avg_pr_bof[0], 'b-', label='BoF')
            if hasattr(self, 'avg_pr_tfidf'):
                plt.plot(self.avg_pr_tfidf[1], self.avg_pr_tfidf[0], 'r--', label='TF-IDF')
        
        plt.xlabel('Recall')
        plt.ylabel('Precision')
        plt.title('Precision-Recall Curve')
        plt.legend(loc='upper right')
        plt.grid(True)
        plt.ylim([0.0, 1.05])
        plt.xlim([0.0, 1.0])
        
        plt.tight_layout()
        plt.show()

    def evaluate_on_test_set(self, test_dir):
        """
        在测试集上评估模型性能
        """

        if not hasattr(self, 'train_images') or not self.train_images:
            raise ValueError("请先加载训练集！")
        
        # 收集所有测试图像
        test_images = []
        test_categories = []
        
        for category in os.listdir(test_dir):
            category_dir = os.path.join(test_dir, category)
            if not os.path.isdir(category_dir):
                continue
                
            for img_file in os.listdir(category_dir):
                if img_file.lower().endswith(('.jpg', '.png', '.jpeg')):
                    img_path = os.path.join(category_dir, img_file)
                    test_images.append(img_path)
                    test_categories.append(category)
        
        if not test_images:
            raise ValueError("没有找到有效的测试图像")
        
        # 初始化累计指标
        total_metrics = {
            'bof': {'precision': 0, 'recall': 0, 'map': 0, 'time': 0},
            'tfidf': {'precision': 0, 'recall': 0, 'map': 0, 'time': 0}
        }
        
        # 初始化PR曲线数据
        all_precisions_bof = []
        all_recalls_bof = []
        all_precisions_tfidf = []
        all_recalls_tfidf = []
        
        # 对每个测试图像进行检索
        for test_img in test_images:
            self.test_image = test_img
            
            self.retrieve_with_bof(test_img)
            self.retrieve_with_tfidf(test_img)
            
            # 累计指标
            for method in ['bof', 'tfidf']:
                for metric in ['precision', 'recall', 'map', 'time']:
                    total_metrics[method][metric] += self.metrics[method][metric]
            
            # 收集PR曲线数据
            if self.pr_curves['bof'] is not None:
                all_precisions_bof.append(self.pr_curves['bof'][0])
                all_recalls_bof.append(self.pr_curves['bof'][1])
            if self.pr_curves['tfidf'] is not None:
                all_precisions_tfidf.append(self.pr_curves['tfidf'][0])
                all_recalls_tfidf.append(self.pr_curves['tfidf'][1])
        
        # 计算平均PR曲线
        if all_precisions_bof:
            # 找到所有PR曲线中最长的长度
            max_len = max(len(p) for p in all_precisions_bof)
            # 对齐所有曲线到相同长度
            aligned_precisions = []
            aligned_recalls = []
            for p, r in zip(all_precisions_bof, all_recalls_bof): # 使用 np.interp 将每条曲线的Precision和Recall数组插值到相同的长度 max_len。 插值区间为 [0, 1]（Recall的范围），确保所有曲线在相同的Recall点上对齐
                aligned_precisions.append(np.interp(np.linspace(0, 1, max_len), np.linspace(0, 1, len(p)), p))
                aligned_recalls.append(np.interp(np.linspace(0, 1, max_len), np.linspace(0, 1, len(r)), r))
            self.avg_pr_bof = (np.mean(aligned_precisions, axis=0), np.mean(aligned_recalls, axis=0))
        
        if all_precisions_tfidf:
            # 找到所有PR曲线中最长的长度
            max_len = max(len(p) for p in all_precisions_tfidf)
            # 对齐所有曲线到相同长度
            aligned_precisions = []
            aligned_recalls = []
            for p, r in zip(all_precisions_tfidf, all_recalls_tfidf):
                aligned_precisions.append(np.interp(np.linspace(0, 1, max_len), np.linspace(0, 1, len(p)), p))
                aligned_recalls.append(np.interp(np.linspace(0, 1, max_len), np.linspace(0, 1, len(r)), r))
            self.avg_pr_tfidf = (np.mean(aligned_precisions, axis=0), np.mean(aligned_recalls, axis=0))
        
        # 计算平均指标
        num_test = len(test_images)
        avg_metrics = {
            'bof': {
                'map': total_metrics['bof']['precision'] / num_test,
                'avg_recall': total_metrics['bof']['recall'] / num_test,
                'total_time': total_metrics['bof']['time']
            },
            'tfidf': {
                'map': total_metrics['tfidf']['precision'] / num_test,
                'avg_recall': total_metrics['tfidf']['recall'] / num_test,
                'total_time': total_metrics['tfidf']['time']
            }
        }
        
        # 绘制对比图表
        self.plot_comparison_charts(avg_metrics, is_test_set=True)
        
        return avg_metrics

class ImageRetrievalGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("图像检索系统")
        self.root.geometry("1200x800")
        self.retrieval_system = ImageRetrievalSystem()
        self.create_widgets()

    def create_widgets(self):
        # 左侧控制面板
        control_frame = tk.Frame(self.root, width=300, bg="#f0f0f0")
        control_frame.pack(side=tk.LEFT, fill=tk.Y, padx=10, pady=10)
        
        # 训练集部分
        train_frame = tk.LabelFrame(control_frame, text="训练集设置", padx=5, pady=5)
        train_frame.pack(fill=tk.X, pady=5)
        
        tk.Button(train_frame, text="加载训练集", command=self.load_train_set).pack(fill=tk.X, pady=5)
        
        self.train_info = tk.Label(train_frame, text="未加载训练集", justify=tk.LEFT)
        self.train_info.pack(fill=tk.X)
        
        # 测试图像部分
        test_frame = tk.LabelFrame(control_frame, text="测试图像", padx=5, pady=5)
        test_frame.pack(fill=tk.X, pady=5)
        
        tk.Button(test_frame, text="选择测试图像", command=self.select_test_image).pack(fill=tk.X, pady=5)
        
        self.test_image_label = tk.Label(test_frame)
        self.test_image_label.pack()
        
        self.test_info = tk.Label(test_frame, text="未选择测试图像", justify=tk.LEFT)
        self.test_info.pack(fill=tk.X)
        
        # 操作按钮
        action_frame = tk.LabelFrame(control_frame, text="操作", padx=5, pady=5)
        action_frame.pack(fill=tk.X, pady=5)
        
        tk.Button(action_frame, text="开始检索", command=self.start_retrieval, bg="#4CAF50", fg="white").pack(fill=tk.X, pady=5)
        tk.Button(action_frame, text="显示对比", command=self.show_comparison, bg="#2196F3", fg="white").pack(fill=tk.X, pady=5)
        tk.Button(action_frame, text="评估测试集", command=self.evaluate_test_set, bg="#FF9800", fg="white").pack(fill=tk.X, pady=5)
        
        # 右侧结果显示
        result_frame = tk.Frame(self.root)
        result_frame.pack(side=tk.RIGHT, expand=True, fill=tk.BOTH, padx=10, pady=10)
        
        # 指标显示
        metric_frame = tk.LabelFrame(result_frame, text="评估指标", padx=5, pady=5)
        metric_frame.pack(fill=tk.X)
        
        self.metric_table = ttk.Treeview(metric_frame, columns=('Method', 'Precision', 'Recall', 'Time(s)'), show='headings')
        self.metric_table.heading('Method', text='方法')
        self.metric_table.heading('Precision', text='精度')
        self.metric_table.heading('Recall', text='召回率')
        self.metric_table.heading('Time(s)', text='时间(s)')
        
        for col in ('Method', 'Precision', 'Recall', 'Time(s)'):
            self.metric_table.column(col, width=80, anchor=tk.CENTER)
        
        self.metric_table.pack(fill=tk.BOTH, expand=True)
        
        # 结果标签页
        self.notebook = ttk.Notebook(result_frame)
        self.notebook.pack(expand=True, fill=tk.BOTH)
        
        # BoF结果标签页
        bof_tab = ttk.Frame(self.notebook)
        self.notebook.add(bof_tab, text='BoF结果')
        self.create_result_tab(bof_tab, 'bof')
        
        # TF-IDF结果标签页
        tfidf_tab = ttk.Frame(self.notebook)
        self.notebook.add(tfidf_tab, text='TF-IDF结果')
        self.create_result_tab(tfidf_tab, 'tfidf')
    
    def create_result_tab(self, parent, method):
        canvas = tk.Canvas(parent)
        scrollbar = ttk.Scrollbar(parent, orient="vertical", command=canvas.yview)
        scrollable_frame = ttk.Frame(canvas)
        
        scrollable_frame.bind(
            "<Configure>",
            lambda e: canvas.configure(scrollregion=canvas.bbox("all"))
        )
        
        canvas.create_window((0, 0), window=scrollable_frame, anchor="nw")
        canvas.configure(yscrollcommand=scrollbar.set)
        
        canvas.pack(side="left", fill="both", expand=True)
        scrollbar.pack(side="right", fill="y")
        
        # 存储引用
        setattr(self, f"{method}_canvas", canvas)
        setattr(self, f"{method}_frame", scrollable_frame)

    def load_train_set(self):
        train_dir = filedialog.askdirectory(title="选择训练集目录")
        if not train_dir:
            return
        
        try:
            self.retrieval_system.load_train_set(train_dir)
            categories = set(self.retrieval_system.train_labels)
            info_text = f"训练集已加载:\n路径: {train_dir}\n图像数量: {len(self.retrieval_system.train_images)}\n类别数: {len(categories)}"
            self.train_info.config(text=info_text)
            messagebox.showinfo("成功", "训练集加载成功！")
        except Exception as e:
            messagebox.showerror("错误", f"加载训练集失败: {str(e)}")

    def select_test_image(self):
        test_image = filedialog.askopenfilename(
            title="选择测试图像",
            filetypes=[("Image files", "*.jpg *.jpeg *.png")]
        )
        if test_image:
            self.retrieval_system.test_image = test_image
            
            # 显示测试图像
            img = Image.open(test_image)
            img.thumbnail((200, 200))
            photo = ImageTk.PhotoImage(img)
            
            self.test_image_label.config(image=photo)
            self.test_image_label.image = photo
            
            # 显示测试图像信息
            test_category = "未知"
            for part in os.path.normpath(test_image).split(os.sep):
                if part in set(self.retrieval_system.train_labels):
                    test_category = part
                    break
            
            self.test_info.config(text=f"测试图像:\n路径: {test_image}\n类别: {test_category}")

    def start_retrieval(self):
        if not hasattr(self.retrieval_system, 'train_images') or not self.retrieval_system.train_images:
            messagebox.showerror("错误", "请先加载训练集！")
            return
        
        if not self.retrieval_system.test_image:
            messagebox.showerror("错误", "请先选择测试图像！")
            return
        
        # 清空之前的结果
        for method in ['bof', 'tfidf']:
            frame = getattr(self, f"{method}_frame")
            for widget in frame.winfo_children():
                widget.destroy()
        
        # 执行检索
        if self.retrieval_system.retrieve_images(self.retrieval_system.test_image):
            self.display_results()
        else:
            messagebox.showerror("错误", "检索失败！")
    
    def evaluate_test_set(self):
        if not hasattr(self, 'retrieval_system') or not hasattr(self.retrieval_system, 'train_images') or not self.retrieval_system.train_images:
            messagebox.showerror("错误", "请先加载训练集！")
            return
        
        test_dir = filedialog.askdirectory(title="选择测试集目录")
        if not test_dir:
            return
        
        try:
            # 执行评估
            avg_metrics = self.retrieval_system.evaluate_on_test_set(test_dir)
            
            # 显示结果
            result_window = tk.Toplevel(self.root)
            result_window.title("测试集评估结果")
            result_window.geometry("600x400")
            
            # 创建表格显示结果
            tree = ttk.Treeview(result_window, columns=('Method', 'mAP', 'Avg Recall', 'Total Time'), show='headings')
            tree.heading('Method', text='方法')
            tree.heading('mAP', text='平均精度')
            tree.heading('Avg Recall', text='平均召回率')
            tree.heading('Total Time', text='总时间(s)')
            
            for col in ('Method', 'mAP', 'Avg Recall', 'Total Time'):
                tree.column(col, width=100, anchor=tk.CENTER)
            
            tree.pack(fill=tk.BOTH, expand=True)
            
            # 插入数据
            for method in ['bof', 'tfidf']:
                tree.insert('', 'end', values=(
                    method.upper(),
                    f"{avg_metrics[method]['map']:.3f}",
                    f"{avg_metrics[method]['avg_recall']:.3f}",
                    f"{avg_metrics[method]['total_time']:.3f}"
                ))
            
            # 添加总结信息
            test_count = len([name for name in os.listdir(test_dir) if os.path.isdir(os.path.join(test_dir, name))])
            summary = tk.Label(result_window, text=f"测试集评估完成，共评估了 {test_count} 个类别的图像", pady=10)
            summary.pack()
            
        except Exception as e:
            messagebox.showerror("错误", f"评估测试集失败: {str(e)}")
    
    def display_results(self):
        # 更新指标表格
        self.metric_table.delete(*self.metric_table.get_children())
        
        for method in ['bof', 'tfidf']:
            self.metric_table.insert('', 'end', values=(
                method.upper(),
                f"{self.retrieval_system.metrics[method]['precision']:.3f}",
                f"{self.retrieval_system.metrics[method]['recall']:.3f}",
                f"{self.retrieval_system.metrics[method]['time']:.3f}"
            ))
        
        # 显示结果图像
        for method in ['bof', 'tfidf']:
            frame = getattr(self, f"{method}_frame")
            
            for i, (img_path, sim) in enumerate(zip(
                self.retrieval_system.results[method],
                self.retrieval_system.results[f"{method}_similarity"]
            )):
                # 获取图像类别
                img_category = "未知"
                for part in os.path.normpath(img_path).split(os.sep):
                    if part in set(self.retrieval_system.train_labels):
                        img_category = part
                        break
                
                # 创建结果项
                item_frame = tk.Frame(frame, bd=1, relief=tk.SOLID, padx=5, pady=5)
                item_frame.pack(fill=tk.X, pady=2)
                
                # 排名和相似度
                header = tk.Frame(item_frame)
                header.pack(fill=tk.X)
                
                tk.Label(header, text=f"第{i+1}名", font=('Arial', 10, 'bold')).pack(side=tk.LEFT)
                tk.Label(header, text=f"相似度: {sim:.3f}", font=('Arial', 10)).pack(side=tk.LEFT, padx=10)
                tk.Label(header, text=f"类别: {img_category}", font=('Arial', 10)).pack(side=tk.RIGHT)
                
                # 图像和路径
                content = tk.Frame(item_frame)
                content.pack(fill=tk.X)
                
                # 显示图像
                img = Image.open(img_path)
                img.thumbnail((150, 150))
                photo = ImageTk.PhotoImage(img)
                
                img_label = tk.Label(content, image=photo)
                img_label.image = photo
                img_label.pack(side=tk.LEFT, padx=5)
                
                # 显示路径
                tk.Label(content, text=os.path.basename(img_path), wraplength=300, justify=tk.LEFT).pack(side=tk.LEFT, padx=10)
    
    def show_comparison(self):
        if not self.retrieval_system.results['bof']:
            messagebox.showerror("错误", "请先执行检索操作！")
            return
        
        self.retrieval_system.plot_comparison_charts(None)

if __name__ == "__main__":
    root = tk.Tk()
    app = ImageRetrievalGUI(root)
    root.mainloop()