def isPal(str):
    str1 = str[::-1]
    if(str == str1):
        return True
    else:
        return False
def Solve(str):

    if isPal(str) == True:
        print(f"{str} is a palindrome")
    else:
        print(f"{str} is not a palindrome")
    return

str = input("请输入一个整数：")
while str != '0':
    Solve(str)
    str = input("请输入一个整数：")