class MyRectangle:
    def __init__(self, width=100, height=100):
        self.width = width
        self.height = height

    def getArea(self):
        return self.width * self.height

    def getPerimeter(self):
        return 2 * (self.width + self.height)

# 创建几个MyRectangle实例来验证功能
rect1 = MyRectangle()
rect2 = MyRectangle(50, 40)

# 测试这些实例
test_results = {
    "rect1_area": rect1.getArea(),
    "rect1_perimeter": rect1.getPerimeter(),
    "rect2_area": rect2.getArea(),
    "rect2_perimeter": rect2.getPerimeter(),
}

print(test_results)