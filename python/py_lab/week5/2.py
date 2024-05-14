import numpy as np

A = np.round(np.random.uniform(-1, 1, size = 10000), 2)
B = np.round(np.random.uniform(-1, 1, size = 10000), 2)

print(f"A = {A}")
print(f"B = {B}")
print(f"A + B = {A + B}")
print(f"A * B = {A * B}")
if 0 in B:
    print("B中有0, 无法计算A / B")
else:
    print(f"A / B = {A / B}")
print(f"exp(A) + exp(B) = {np.exp(A) + np.exp(B)}")
print(f"A · B = {np.dot(A, B)}")
print(f"B的平均值 = {np.mean(B)}")
print(f"B的最大值 = {np.max(B)}")
print(f"B的最小值 = {np.min(B)}")