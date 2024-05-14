import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['SimHei']  # 设置默认字体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号问题

import time
import random

# 插入排序
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

# 归并排序
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]
        
        merge_sort(L)
        merge_sort(R)
        
        i = j = k = 0
        
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
    return arr

sizes = [10, 20, 50, 100, 200, 500, 1000, 2000, 5000]
insertion_times = []
merge_times = []

for size in sizes:
    arr = [random.randint(1, 1000) for _ in range(size)]
    
    # 插入排序
    start_time = time.time()
    insertion_sort(arr.copy())
    insertion_times.append(time.time() - start_time)
    
    # 归并排序
    start_time = time.time()
    merge_sort(arr.copy())
    merge_times.append(time.time() - start_time)

plt.figure(figsize=(10, 6))
plt.plot(sizes, insertion_times, label= "插入排序", marker='o')
plt.plot(sizes, merge_times, label="归并排序", marker='o')
plt.xlabel("输入规模 n")
plt.ylabel("时间 s")
plt.title("插入排序和归并排序输入规模n变化的时间比较")
plt.legend()
plt.grid(True)
plt.show()