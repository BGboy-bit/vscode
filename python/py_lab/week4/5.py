class Human:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def get_name(self):
        print(self.name)
    def do_homework(self):
        print("There is no homework from the parent!")

class Student(Human):
    def __init__(self, name, age, homework):
        super().__init__(name, age)
        self.homework = homework
    def do_homework(self):
        super().do_homework()
        print("作业为: " + self.homework)

stu = Student('John', 20, 'Python实验')
print(f"stu's name is {stu.name}")
print(f"stu's age is {stu.age}")
print(f"stu's homework is {stu.homework}")
stu.do_homework()
stu.get_name()