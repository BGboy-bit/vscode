import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

iris_data_path = 'D:/vscode/python/py_lab/week5/docs/iris.csv'
iris = pd.read_csv(iris_data_path)

sns.set(style = "darkgrid")

plt.figure(figsize=(10, 6))
ax = sns.lineplot(x='花萼长度', y='花萼宽度', data=iris, marker='o')
plt.title('Line Plot of Sepal Length vs Sepal Width')
plt.xlabel('Sepal Length (cm)')
plt.ylabel('Sepal Width (cm)')

plt.show()
