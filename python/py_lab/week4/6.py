from mc import student

stu1 = student('Alice', 22, 'Female', (88, 92, 95))
stu2 = student('Bob', 23, 'Male', (75, 80))
stu3 = student('Charlie', 20, 'Male', (70, 85, 90, 95))

for stu in (stu1, stu2, stu3):
    # 直接打印学生的平均成绩
    print(f"Average Grade: {stu.get_avg_grade()}")
