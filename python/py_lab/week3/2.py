prime_list = []
prime_list.append(2)
for i in range(3, 2001, 2):
    for j in prime_list:
        if i % j == 0:
            break
    else:
        prime_list.append(i)

file_path = 'D://vscode//python//py_lab//week3//prime.txt'
with open(file_path, 'w') as file:
    for i in range(1000, 2001):
        factor_list = []
        power_list = []
        original_i = i
        for j in prime_list:
            if i % j == 0:
                factor_list.append(j)
                power = 0
                while i % j == 0:
                    i = i / j
                    power += 1
                power_list.append(power)
            if i == 1:
                break
        output = "{:<8}:{};{}\n".format(original_i, ','.join(map(str, factor_list)), ','.join(map(str, power_list)))
        file.write(output)