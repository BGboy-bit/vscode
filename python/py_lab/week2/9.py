str_input = input("请输入字符串：")

dic = dict()
for i in str_input:
    dic[i] = dic.get(i, 0) + 1

dic = sorted(dic.items())
print(f"{dic[0][0]} {dic[0][1]}")