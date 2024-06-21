import re
s = "I like Python programming 123 because it is 456 simple and elegant."
pattern = r'\b[^\W\d_]*o[^\W\d_]*\b'
res = re.findall(pattern, s)
print(res)