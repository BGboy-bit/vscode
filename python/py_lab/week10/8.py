import re

s = input()
pattern = r'\b[a-zA-Z][a-zA-Z0-9_]{0,9}\b'
match = re.search(pattern, s)
if match:
    print(match.group())