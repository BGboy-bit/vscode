import numpy as np

a = np.random.rand(8, 8)

maxx = a.max()
minn = a.min()

for i in range(8):
    for j in range(8):
        a[i][j] = (a[i][j] - minn) * (maxx - minn)
maxx = a.max()
minn = a.min()
print(f"最大值为:{maxx}, 最小值为:{minn}")