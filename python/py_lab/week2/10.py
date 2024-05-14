from functools import cmp_to_key

def cmp(a, b):
    if a[1] > b[1]:
        return -1
    elif a[1] < b[1]:
        return 1
    else:
        if a[0] < b[0]:
            return -1
        else:
            return 1

str = input("请输入字符串：").lower() 
print(str)
dic = {i: str.count(i) for i in str}
sorted_items = sorted(dic.items(), key=cmp_to_key(cmp))

print(f"{sorted_items[0][0]} {sorted_items[0][1]}")
