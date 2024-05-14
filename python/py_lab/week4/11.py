import random
import string

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def printInfo(self):
        print(f"Name: {self.name}, Age: {self.age}")

class Student(Person):
    def __init__(self, name, age, chinese, math):
        super().__init__(name, age)
        self.chinese = chinese
        self.math = math

    def printInfo(self):
        super().printInfo()
        print(f"Chinese: {self.chinese}, Math: {self.math}")

    def total_score(self):
        return self.chinese + self.math

students = []
for _ in range(30):
    name = ''.join(random.choices(string.ascii_letters, k=random.randint(3, 6)))
    age = random.randint(10, 15)
    chinese = random.randint(50, 100)
    math = random.randint(50, 100)
    students.append(Student(name, age, chinese, math))

students.sort(key=lambda x: x.total_score(), reverse=True)

for student in students:
    student.printInfo()
    
average_chinese = sum(student.chinese for student in students) / len(students)
average_math = sum(student.math for student in students) / len(students)

average_chinese, average_math
