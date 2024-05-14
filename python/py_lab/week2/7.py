a = int(input("a = "))
b = int(input("b = "))
d = int(input("d = "))

summ = a + b
list1 = []
while(summ % d != summ):
    list1.append(summ % d)
    summ //= d
list1.append(summ)
for i in list1[::-1]:
    print(i, end = '')