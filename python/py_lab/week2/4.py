def func(*list_args):
    all_list = []
    for i in list_args:
        if isinstance(i, list):
            all_list.extend(i)
        else:
            return '列表参数有错误，请重新输入列表: '
    all_list.sort()
    return all_list[-1]

print(func([678,29,579,13],[900,454,65,445],[12,54,2980,72]))