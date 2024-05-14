import random
import numpy as np

class HDPoints:
    def __init__(self, points):
        self.points = points
    
    def centerpoint(self):
        # 计算每个维度的均值
        return [np.mean([point[dim] for point in self.points]) for dim in range(len(self.points[0]))]

    def minkowski(self, x, y, p):
        if p == 0:  # 切比雪夫距离
            return max(abs(a - b) for a, b in zip(x, y))
        else:  # p-闵氏距离
            return sum(abs(a - b) ** p for a, b in zip(x, y)) ** (1/p)

    def farthestpoint(self, p):
        center = self.centerpoint()
        max_distance = 0
        farthest_point_index = 0
        for i, point in enumerate(self.points):
            distance = self.minkowski(center, point, p)
            if distance > max_distance:
                max_distance = distance
                farthest_point_index = i
        return farthest_point_index, max_distance

    def farthest2points(self, p):
        max_distance = 0
        point1_index, point2_index = 0, 0
        for i in range(len(self.points)):
            for j in range(i+1, len(self.points)):
                distance = self.minkowski(self.points[i], self.points[j], p)
                if distance > max_distance:
                    max_distance = distance
                    point1_index, point2_index = i, j
        return (point1_index, point2_index, max_distance)

# 生成随机点
num_points = 50
dim = random.randint(5, 10)  # 随机维度在5到10之间
points = [[random.uniform(0, 1) for _ in range(dim)] for _ in range(num_points)]

# 实例化HDPoints类
hd_points = HDPoints(points)

# 随机生成p
p = random.randint(0, 5)

# 测试方法
center = hd_points.centerpoint()
farthest_point_index, max_distance = hd_points.farthestpoint(p)
point1_index, point2_index, max_2points_distance = hd_points.farthest2points(p)

print(center, farthest_point_index, max_distance, point1_index, point2_index, max_2points_distance, p)
