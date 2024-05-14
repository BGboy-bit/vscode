import numpy as np
from scipy.optimize import fmin

def f(x):
    return (x - 2) ** 2 + 3

x = fmin(func=f, x0=[0], disp=False)

print(f"Minimum value: {int(f(x)[0])} at x = {int(x[0])}")