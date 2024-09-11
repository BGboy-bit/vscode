def normalize_newlines(filename):
    with open(filename, 'r', encoding='utf-8', newline='') as file:
        content = file.read()
    # 替换 CRLF 为 LF
    content = content.replace('\r\n', '\n')
    with open(filename, 'w', encoding='utf-8', newline='') as file:
        file.write(content)

def compare_files(file1, file2):
    # 将 code.out 的行结束符标准化为 LF
    normalize_newlines(file1)

    with open(file1, 'r', encoding='utf-8') as f1, open(file2, 'r', encoding='utf-8') as f2:
        line_number = 1
        differences_found = False

        while True:
            line1 = f1.readline()
            line2 = f2.readline()

            # 如果两行都是空，意味着文件结束
            if not line1 and not line2:
                break

            # 去除行尾空白符进行比较
            line1 = line1.rstrip()
            line2 = line2.rstrip()

            # 如果两行不同
            if line1 != line2:
                if not differences_found:
                    print("wa")  # 发现第一个差异时输出
                    differences_found = True

                # 使用zip最长匹配方法找出第一个不同的字符
                for i, (c1, c2) in enumerate(zip(line1, line2)):
                    if c1 != c2:
                        print(f'Difference at line {line_number}, column {i + 1}: code="{c1}" test="{c2}"')
                        break
                else:
                    # 检查是否由于长度不同导致
                    if len(line1) != len(line2):
                        longer = line1 if len(line1) > len(line2) else line2
                        print(f'Difference at line {line_number}, column {len(line1) + 1}: longer="{longer[len(line1):]}"')

            line_number += 1

        if not differences_found:
            print("ac")

# 调用函数比较文件，注意替换路径以匹配你的系统设置
compare_files('code.out', 'test.out')
