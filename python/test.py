def err(msg):
    raise Exception(msg)

def eval(exp):
    if type(exp) in [int, bool, float]:
        return exp
    
    if type(exp) == list and len(exp) == 3 and exp[1] in ['+', '-', '*', '/']:
        e1, op, e2 = exp
        v1 = eval(e1)
        v2 = eval(e2)
        if op == '+':
            return v1 + v2
        

    err(f'error{exp}')

print(eval([1, '+', [2, '+', 3]]))
