import sys
import cv2
import os
import numpy as np
import time
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QLabel, QFileDialog, QVBoxLayout, QHBoxLayout, QTextEdit
from PyQt5.QtGui import QPixmap, QImage
from PyQt5.QtCore import Qt

class ImageMatcher(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
        self.query_img_folder = None

    def initUI(self):
        self.setWindowTitle("图像匹配比较 - SIFT vs ORB")
        self.resize(1200, 700)

        layout = QVBoxLayout()

        btn_layout = QHBoxLayout()
        self.load_btn = QPushButton("选择待匹配图像")
        self.load_btn.clicked.connect(self.load_image)
        self.match_btn = QPushButton("匹配图像")
        self.match_btn.clicked.connect(self.match_images)
        btn_layout.addWidget(self.load_btn)
        btn_layout.addWidget(self.match_btn)
        
        img_layout = QHBoxLayout()
        self.query_label = QLabel("待匹配图像")
        self.query_label.setAlignment(Qt.AlignCenter)
        self.query_label.setFixedSize(350, 350)
        
        self.sift_result_label = QLabel("SIFT匹配图像")
        self.sift_result_label.setAlignment(Qt.AlignCenter)
        self.sift_result_label.setFixedSize(350, 350)
        
        self.orb_result_label = QLabel("ORB匹配图像")
        self.orb_result_label.setAlignment(Qt.AlignCenter)
        self.orb_result_label.setFixedSize(350, 350)
        
        img_layout.addWidget(self.query_label)
        img_layout.addWidget(self.sift_result_label)
        img_layout.addWidget(self.orb_result_label)
        
        self.result_text = QTextEdit()
        self.result_text.setReadOnly(True)
        
        layout.addLayout(btn_layout)
        layout.addLayout(img_layout)
        layout.addWidget(self.result_text)
        
        self.setLayout(layout)
        self.query_img_path = None

    def load_image(self):
        fname, _ = QFileDialog.getOpenFileName(self, "选择图像", "", "Images (*.png *.jpg *.jpeg)")
        if fname:
            self.query_img_path = fname
            self.query_img_folder = os.path.dirname(fname)
            pixmap = QPixmap(fname).scaled(350, 350, Qt.KeepAspectRatio)
            self.query_label.setPixmap(pixmap)
            self.match_images()

    def match_images(self):
        if not self.query_img_path:
            self.result_text.setText("请先选择一张待匹配图像！")
            return
        if not self.query_img_folder:
            self.result_text.setText("未能确定图像所在文件夹！")
            return

        best_match = None
        best_score = 0
        best_sift_img = None
        best_orb_img = None
        best_sift_time = 0
        best_orb_time = 0

        query_img = cv2.imread(self.query_img_path, cv2.IMREAD_GRAYSCALE)
        if query_img is None:
            self.result_text.setText("无法加载待匹配图像！")
            return

        sift = cv2.SIFT_create()
        orb = cv2.ORB_create()

        for file in os.listdir(self.query_img_folder):
            file_path = os.path.join(self.query_img_folder, file)
            if os.path.normpath(file_path) == os.path.normpath(self.query_img_path):
                continue

            target_img = cv2.imread(file_path, cv2.IMREAD_GRAYSCALE)
            if target_img is None:
                continue

            # SIFT匹配
            start = time.time()
            kp1_sift, des1_sift = sift.detectAndCompute(query_img, None)
            kp2_sift, des2_sift = sift.detectAndCompute(target_img, None)
            bf_sift = cv2.BFMatcher(cv2.NORM_L2)
            matches_sift = bf_sift.knnMatch(des1_sift, des2_sift, k=2)
            good_sift = [m for m, n in matches_sift if m.distance < 0.75 * n.distance]
            sift_time = time.time() - start

            # ORB匹配
            start = time.time()
            kp1_orb, des1_orb = orb.detectAndCompute(query_img, None)
            kp2_orb, des2_orb = orb.detectAndCompute(target_img, None)
            bf_orb = cv2.BFMatcher(cv2.NORM_HAMMING)
            matches_orb = bf_orb.match(des1_orb, des2_orb)
            matches_orb = sorted(matches_orb, key=lambda x: x.distance)
            orb_time = time.time() - start

            score = len(good_sift)
            if score > best_score:
                best_score = score
                best_match = file_path
                best_sift_time = sift_time
                best_orb_time = orb_time
                best_sift_img = cv2.drawMatches(query_img, kp1_sift, target_img, kp2_sift, good_sift, None, flags=cv2.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS)
                best_orb_img = cv2.drawMatches(query_img, kp1_orb, target_img, kp2_orb, matches_orb, None, flags=cv2.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS)

        if best_match and best_sift_img is not None and best_orb_img is not None:
            best_sift_img_rgb = cv2.cvtColor(best_sift_img, cv2.COLOR_BGR2RGB)
            h, w, ch = best_sift_img_rgb.shape
            bytes_per_line = ch * w
            qimg_sift = QImage(best_sift_img_rgb.data, w, h, bytes_per_line, QImage.Format_RGB888)
            pixmap_sift = QPixmap.fromImage(qimg_sift).scaled(350, 350, Qt.KeepAspectRatio)
            self.sift_result_label.setPixmap(pixmap_sift)

            best_orb_img_rgb = cv2.cvtColor(best_orb_img, cv2.COLOR_BGR2RGB)
            h, w, ch = best_orb_img_rgb.shape
            bytes_per_line = ch * w
            qimg_orb = QImage(best_orb_img_rgb.data, w, h, bytes_per_line, QImage.Format_RGB888)
            pixmap_orb = QPixmap.fromImage(qimg_orb).scaled(350, 350, Qt.KeepAspectRatio)
            self.orb_result_label.setPixmap(pixmap_orb)

            result = f"最匹配图像: {os.path.basename(best_match)}\nSIFT匹配时间: {best_sift_time:.4f} 秒\nORB匹配时间: {best_orb_time:.4f} 秒\nSIFT匹配点数: {best_score}\n"
        else:
            result = "未找到匹配图像！"

        self.result_text.setText(result)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    matcher = ImageMatcher()
    matcher.show()
    sys.exit(app.exec_())
