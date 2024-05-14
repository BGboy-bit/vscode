import pandas as pd

file_path = 'D:/vscode/python/py_lab/week5/docs/data.xls'
df = pd.read_excel(file_path)
df['Population Density'] = df['Population'] / df['Area']
most_populous_country = df[df['Population'] == df['Population'].max()]['Country'].iloc[0]
print("人口最多的国家是:", most_populous_country)
