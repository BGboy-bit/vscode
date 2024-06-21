import re

pattern = r'\(\d{3}\)\d{3}-\d{4}|\d{3}-\d{3}-\d{4}'

valid_phone_numbers = []
with open('text.txt', 'r') as file:
    for line in file:
        matches = re.findall(pattern, line)
        valid_phone_numbers.extend(matches)

for number in valid_phone_numbers:
    print(number)