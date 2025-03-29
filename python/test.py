import sys
import cv2
import os
import numpy as np
import time
from sklearn.cluster import KMeans
from sklearn.neighbors import NearestNeighbors
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QLabel, QFileDialog, QVBoxLayout, QHBoxLayout, QTextEdit
from PyQt5.QtGui import QPixmap, QImage
from PyQt5.QtCore import Qt
import pickle

class ImageMatcherBoF(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
        self.query_img_folder = None
        self.bof_model = None
        self.train_features = None
        self.train_image_paths = []

    def initUI(self):
        self.setWindowTitle("BoF+KNN 图像检索")
        self.resize(1200, 700)

        layout = QVBoxLayout()

        btn_layout = QHBoxLayout()
        self.load_btn = QPushButton("选择待匹配图像")
        self.load_btn.clicked.connect(self.load_image)
        self.train_btn = QPushButton("训练BoF模型")
        self.train_btn.clicked.connect(self.train_bof_model)
        self.match_btn = QPushButton("匹配图像")
        self.match_btn.clicked.connect(self.match_images)
        btn_layout.addWidget(self.load_btn)
        btn_layout.addWidget(self.train_btn)
        btn_layout.addWidget(self.match_btn)
        
        img_layout = QHBoxLayout()
        self.query_label = QLabel("待匹配图像")
        self.query_label.setAlignment(Qt.AlignCenter)
        self.query_label.setFixedSize(350, 350)
        
        self.result_label = QLabel("匹配结果")
        self.result_label.setAlignment(Qt.AlignCenter)
        self.result_label.setFixedSize(350, 350)
        
        img_layout.addWidget(self.query_label)
        img_layout.addWidget(self.result_label)
        
        self.result_text = QTextEdit()
        self.result_text.setReadOnly(True)
        
        layout.addLayout(btn_layout)
        layout.addLayout(img_layout)
        layout.addWidget(self.result_text)
        
        self.setLayout(layout)
        self.query_img_path = None

    def extract_sift_features(self, img_path):
        image = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
        if image is None:
            return None
        sift = cv2.SIFT_create()
        keypoints, descriptors = sift.detectAndCompute(image, None)
        return descriptors
    
    def train_bof_model(self):
        folder = QFileDialog.getExistingDirectory(self, "选择训练图像文件夹")
        if not folder:
            return
        
        descriptors_list = []
        self.train_image_paths = []
        
        for file in os.listdir(folder):
            file_path = os.path.join(folder, file)
            desc = self.extract_sift_features(file_path)
            if desc is not None:
                descriptors_list.append(desc)
                self.train_image_paths.append(file_path)
        
        descriptors = np.vstack(descriptors_list)
        num_clusters = 100  # 设定词汇大小
        kmeans = KMeans(n_clusters=num_clusters, random_state=42)
        kmeans.fit(descriptors)
        self.bof_model = kmeans
        
        image_bof_features = np.zeros((len(self.train_image_paths), num_clusters))
        for i, img_path in enumerate(self.train_image_paths):
            desc = self.extract_sift_features(img_path)
            if desc is not None:
                words = kmeans.predict(desc)
                for w in words:
                    image_bof_features[i][w] += 1
        
        self.train_features = image_bof_features
        
        with open("bof_model.pkl", "wb") as f:
            pickle.dump((kmeans, self.train_features, self.train_image_paths), f)
        
        self.result_text.setText("BoF模型训练完成，已保存！")

    def load_image(self):
        fname, _ = QFileDialog.getOpenFileName(self, "选择测试图像", "", "Images (*.png *.jpg *.jpeg)")
        if fname:
            self.query_img_path = fname
            pixmap = QPixmap(fname).scaled(350, 350, Qt.KeepAspectRatio)
            self.query_label.setPixmap(pixmap)
            self.match_images()

    def match_images(self):
        if not self.query_img_path or self.bof_model is None:
            self.result_text.setText("请先选择图像并训练BoF模型！")
            return
        
        desc = self.extract_sift_features(self.query_img_path)
        if desc is None:
            self.result_text.setText("无法提取特征！")
            return
        
        words = self.bof_model.predict(desc)
        query_feature = np.zeros((self.bof_model.n_clusters,))
        for w in words:
            query_feature[w] += 1
        
        knn = NearestNeighbors(n_neighbors=10)
        knn.fit(self.train_features)
        distances, indices = knn.kneighbors([query_feature])
        
        results = []
        for i, idx in enumerate(indices[0]):
            results.append(f"{i+1}. {os.path.basename(self.train_image_paths[idx])} (距离: {distances[0][i]:.4f})")
        
        best_match_img = self.train_image_paths[indices[0][0]]
        pixmap = QPixmap(best_match_img).scaled(350, 350, Qt.KeepAspectRatio)
        self.result_label.setPixmap(pixmap)
        
        self.result_text.setText("\n".join(results))

if __name__ == '__main__':
    app = QApplication(sys.argv)
    matcher = ImageMatcherBoF()
    matcher.show()
    sys.exit(app.exec_())
