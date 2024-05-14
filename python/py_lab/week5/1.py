import numpy as np
x = np.round(np.random.normal(0, 2, size = (9, 10)), 1)

print(x)
print(f"第2行第5列:\n{x[1, 4]}")
print(f"第6行第3列:\n{x[5, 2]}")
print(f"第3行至第5行:\n{x[2:5, :]}")
print(f"第4列至第6列:\n{x[:, 3:6]}")
print(f"第3行至第5行且为第1列、第2列和第4列:\n{x[2:5, [0, 1, 3]]}")
print("重新排列后的数组:")
condition = x > 1
x[condition] = 10
condition = x < -1
x[condition] = -10
print(x)