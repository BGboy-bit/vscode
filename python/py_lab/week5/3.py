import numpy as np

x = np.round(np.random.uniform(10, 20, size = [10, 5]), 2)
print(f"原始矩阵为:\n{x}")

y = x.copy()

for i in range(0, 10):
    avg = np.sum(y[i]) / 5
    for j in range(0, 5):
        y[i][j] = y[i][j] - avg

np.savetxt("dat.csv", y, fmt = "%.3f", delimiter = ",")

index = np.argsort(x[:, 1])
sort_x = x[index]
print(f"排序后的矩阵为:\n{sort_x}")
