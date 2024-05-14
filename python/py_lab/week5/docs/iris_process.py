import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# 设置默认风格
sns.set(style="darkgrid")

# 读入数据
iris = pd.read_csv('iris.csv')

# 设置中文显示字体为黑体
sns.set(font='SimHei')
# 主题
sns.set_style("whitegrid")  # 白色网格背景
sns.set_style("darkgrid")   # 灰色网格背景
sns.set_style("dark")       # 灰色背景
sns.set_style("white")      # 白色背景
sns.set_style("ticks")      # 四周加边框和刻度

# 查看数据大小
print(iris.shape)

# 查看前十行数据
print(iris.head(10))

# 查看数据信息
print(iris.info())
# 散点图
ax = sns.scatterplot(x='花萼长度', y='花萼宽度', data=iris)
# 折线图
ax = sns.lineplot(x=iris['叶片宽度'], y=iris['叶片长度'])
# 柱状图
sns.barplot(x=iris['品种'].value_counts().index, y=iris['品种'].value_counts().values)
# 直方图
ax = sns.distplot(iris['叶片长度'])
plt.show()