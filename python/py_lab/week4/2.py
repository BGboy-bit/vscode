import os
import random

def fs(dirname,s):
    txtt = [f for f in os.listdir(dirname) if f.endswith('.txt')]
    if not txtt:
        new_file_path = os.path.join(dirname, "new.txt")
        with open(new_file_path, 'w') as f:
            f.write(s)
            output = "s is written to new.txt"
    else:
        filee = random.choice(txtt)
        filee_path = os.path.join(dirname, filee)
        with open(filee_path, 'a') as f:
            f.write(s)
            output = f"s is written to {filee}"
    return output

s = "I am the new one"
dirr = "D:/vscode/python/py_lab/week4"
print(fs(dirr,s))
