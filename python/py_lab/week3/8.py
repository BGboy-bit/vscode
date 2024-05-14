# 读取 stu_grade.txt 文件
with open("stu_grade.txt", "r") as file:
    lines = file.readlines()

# 解析文件内容，并根据成绩排序
grades = []
for line in lines:
    student_id, name, grade = line.strip().split(',')
    grades.append((student_id, name, int(grade)))

sorted_grades = sorted(grades, key=lambda x: x[2], reverse=True)

# 将排序后的内容写入到新文件 stu_grade_output.txt 中
output_path = "stu_grade_output.txt"
with open(output_path, "w") as file:
    for student in sorted_grades:
        file.write(f"{student[0]},{student[1]},{student[2]}\n")