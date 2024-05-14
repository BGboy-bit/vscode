def isPrime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

a = int(input("正整数: "))
b = a
list1 = []
list2 = []

for i in range(2, b + 1):
    if(a == 1):
        break
    elif isPrime(i) and a % i == 0:
        list1.append(i)
        list2.append(0)
        while a % i == 0:
            a /= i
            list2[-1] += 1

List = [list1, list2]
print(List)
