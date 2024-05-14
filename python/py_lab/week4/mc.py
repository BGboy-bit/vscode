class person:
    def __init__(self, name, age, sex):
        self.__name = name
        self.__age = age
        self.__sex = sex

class student(person):
    def __init__(self, name, age, sex, grades):
        super().__init__(name, age, sex)
        self.__grades = grades
    def get_avg_grade(self):
        return sum(self.__grades) / len(self.__grades)