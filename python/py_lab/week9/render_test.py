import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv("images_test.csv", dtype="uint8")
img_data = data.values

# 显示前25张图片
row = 5
col = 5
for i in range(row * col):
    pixels = img_data[i]
    pixels = pixels / 255
    img = np.reshape(pixels, (28, 28))
    plt.subplot(row, col, i + 1)
    plt.axis("off")
    plt.imshow(img, cmap="gray")
plt.show()
