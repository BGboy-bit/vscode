with open('out.txt', 'w') as file:
    while True:
        char = input("请输入一个字符: ")
        if char == '@':
            break
        file.write(char)

print("已完成输入。")
