import re
s = """xiasd@163.com, sdlfkj@.com sdflkj@180.com solodfdsf@123.com sdlfjxiaori@139.com saldkfj.com oisdfo@.sodf.com.com"""
pattern = r'\w+@\w+\.\w{2,}'
res = re.findall(pattern, s)
print(res)