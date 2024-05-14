def Strr(str):
    dig_sum = 0
    sup_sum = 0
    low_sum = 0
    oth_sum = 0
    for i in str:
        if(i.isdigit() == True):
            dig_sum += 1
        elif(i.isupper() == True):
            sup_sum += 1
        elif(i.islower() == True):
            low_sum += 1
        else:
            oth_sum += 1
    return (dig_sum, sup_sum, low_sum, oth_sum)

str = input("input:")
ans = Strr(str)
print(ans)
