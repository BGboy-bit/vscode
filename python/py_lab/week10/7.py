import re

s = "hi69@qq.com, werksdf@163.com, sdf@sina.com"

def add_212(match):
    num = int(match.group())
    return str(num + 212)

replaced_text = re.sub(r'\d+', add_212, s)

print(replaced_text)
