import os

filename = 'oldfilename.txt'

if os.path.exists(filename):
    with open(filename, 'r') as file:
        for line in file:
            print(line, end='')
else:
    open(filename, 'w').close()
    print(f"'{filename}' 文件已创建。")
