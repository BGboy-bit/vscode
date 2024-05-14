import pandas as pd

data = {'Sex':['男', '女', '女', '男', '男'],
        'Name':['小明', '小红', '小芳', '大黑', '张三'],
        'Age':[20, 21, 25, 24, 29]}
df = pd.DataFrame(data)
print(df,"\n")
x = df.iloc[0, 0]
print("数据结构第零排第零列([0, 0])的元素: ", x, "\n")
line = df.head(3)
print("数据结构前3行\n", line, "\n")
print("数据按列的统计信息\n", df.describe(), "\n")
print("转换成ndarray类型的数据\n", df.values)