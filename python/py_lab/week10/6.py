import re

s = """hi69@qq.com, werksdf@163.com, sdf@sina.com
    sfjsdf@139.com, soifsdfj@qq.com
    pwoeir23@126.com"""

pattern = r'\b\w+@qq.com\b'

replaced_text = re.sub(pattern, '2827354494@qq.com', s)

print(replaced_text)
