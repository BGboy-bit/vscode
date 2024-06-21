import re
s="see 123, 1987-02-09 07:30:00, 1986-02-15 07:25:00"
fa1=re.findall("\d+-\d+-\d+",s)
fa2=re.findall("(\d+)-\d+-\d+",s)
fa3=re.findall("(\d+)-(\d+)-(\d+)",s)
print(fa1)
print(fa2)
print(fa3)
