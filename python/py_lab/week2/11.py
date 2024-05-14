people = [
    {"name": "xiaoming", "age": 25},
    {"name": "xiaohong", "age": 10},
    {"name": "xiaohua", "age": 18}
]

young_people = filter(lambda person: person['age'] < 20, people)

young_names = [person['name'] for person in young_people]

print(young_names)
