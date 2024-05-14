people = [('牛牛', 'F', 15), ('道长', 'M', 12), ('大师兄','M', 10), ('小师妹','F', 13)]
people = sorted(people, key=lambda people:people[2])
print(people)