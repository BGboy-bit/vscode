import re
s = '''see 123, 1987-02-09 07:30:00
    1987-02-15 07:25:00'''
pattern = r'\d{4}-\d{2}-\d{2}\s\d{2}:\d{2}:\d{2}'
res = re.findall(pattern, s)
print(res)