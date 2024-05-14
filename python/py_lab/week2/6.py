from functools import reduce

dot = False
def fn(x, y):
    global dot
    if y == '.':
        dot = True
        return x
    elif not dot:
        return x * 10 + y
    else:
        if '.' in str(x):
            return x + y * (10 ** -(len(str(x)) - str(x).index('.'))) #负指数幂
        else:
            return x + y / 10

def CharToNum(s):
    digits = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, '.': '.'}
    return digits[s]

def str2float(s):
    return reduce(lambda x, y: fn(x, y), map(CharToNum, s))

print(str2float('123.456'))