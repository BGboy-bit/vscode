class Staff:
    def __init__(self, name, salary):
        self.__name = name
        self.__salary = salary

    def get_name(self):
        return self.__name

    def get_salary(self):
        return self.__salary

    def increase_salary(self, amount):
        self.__salary += amount

# 创建Staff实例
staff1 = Staff("Alice", 3000)
staff2 = Staff("Bob", 3500)
staff3 = Staff("Charlie", 3200)

# 每个员工工资增加100
staff1.increase_salary(100)
staff2.increase_salary(100)
staff3.increase_salary(100)

# 对涨后的工资进行排序（降序）
staff_list = [staff1, staff2, staff3]
sorted_staff_list = sorted(staff_list, key=lambda x: x.get_salary(), reverse=True)

# 输出排序后的工资及姓名
sorted_salaries_names = [(staff.get_name(), staff.get_salary()) for staff in sorted_staff_list]
print(sorted_salaries_names)
