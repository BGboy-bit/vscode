from mypack.subpack import bb
from mypack import aa
from mypack import a, b

m = 4
n = 3

re1 = bb.sub(m, n)
re2 = aa.add(m, n)
re3 = aa.add(a, b)

print(f"{m} - {n} = {re1}")
print(f"{m} + {n} = {re2}")
print(f"{a} + {b} = {re3}")