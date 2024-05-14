import pandas as pd
from sklearn.utils import Bunch

# 优化方法
from sklearn.model_selection import train_test_split    # 数据分割
from sklearn.preprocessing import StandardScaler        # 特征缩放
from sklearn.model_selection import cross_val_score     # 交叉验证

# 机器学习模型
from sklearn.neighbors import KNeighborsClassifier      # K最近邻算法
from sklearn.ensemble import RandomForestClassifier     # 随机森林
from sklearn.ensemble import GradientBoostingClassifier # 梯度提升
from sklearn.svm import SVC                             # 向量机

# scv转为bunch
def csv_to_bunch(csv_file_path):
    df = pd.read_csv(csv_file_path)
    data = df.drop(columns = ['target'])
    target = df['target']
    data_bunch = Bunch(data = data, target = target)
    return data_bunch

wine_train = csv_to_bunch('D:/vscode/python/py_lab/week6/data-train.csv')
wine_test  = csv_to_bunch('D:/vscode/python/py_lab/week6/data-test.csv')

# 特征缩放
scaler = StandardScaler()
train_data = scaler.fit_transform(wine_train.data)
test_data = scaler.transform(wine_test.data)

# 最佳模型参数
best_score = 0
best_model = ""
best_params = {}

# 数据分割
X_train, X_test, y_train, y_test = train_test_split(
    train_data, wine_train.target, test_size = 0.2, random_state = 42)

for cv in range(3, 11):
    # K最近邻
    for n_neighbors in range(3, 8): 
        knn = KNeighborsClassifier(n_neighbors = n_neighbors)
        knn_score = cross_val_score(knn, X_train, y_train, cv = cv).mean() # 交叉验证
        if knn_score > best_score:
            best_score = knn_score
            best_model = "KNN"
            best_params = {'n_neighbors': n_neighbors, 'cvs_cv': cv}

    # 随机森林
    for n_estimators in range(100, 200, 5):
        rf = RandomForestClassifier(n_estimators = n_estimators, random_state = 42)
        rf_score = cross_val_score(rf, X_train, y_train, cv = cv).mean() # 交叉验证
        if rf_score > best_score:
            best_score = rf_score
            best_model = "Random Forest"
            best_params = {'n_estimators': n_estimators, 'cvs_cv': cv}

    # 梯度提升
    for n_estimators in range(50, 101, 5):
        gbm = GradientBoostingClassifier(n_estimators = n_estimators, random_state = 42)
        gbm_score = cross_val_score(gbm, X_train, y_train, cv = cv).mean() # 交叉验证
        if gbm_score > best_score:
            best_score = gbm_score
            best_model = "Gradient Boosting"
            best_params = {'n_estimators': n_estimators, 'cvs_cv': cv}

    # 支持向量机
    for C in range(1, 101, 5):
        svm = SVC(C = C, random_state = 42)
        svm_score = cross_val_score(svm, X_train, y_train, cv = cv).mean() # 交叉验证
        if svm_score > best_score:
            best_score = svm_score
            best_model = "SVM"
            best_params = {'C': C, 'cvs_cv': cv}

print('=============================')
print('最佳模型:', best_model)
print('最佳参数:', best_params)
print('最佳分数:', best_score)
print('=============================')

# 根据最佳模型名初始化和训练模型
model = None
if best_model == "KNN":
    model = KNeighborsClassifier(n_neighbors = best_params['n_neighbors'])
elif best_model == "Random Forest":
    model = RandomForestClassifier(n_estimators = best_params['n_estimators'], random_state = 42)
elif best_model == "Gradient Boosting":
    model = GradientBoostingClassifier(n_estimators = best_params['n_estimators'], random_state = 42)
elif best_model == "SVM":
    model = SVC(C = best_params['C'], random_state = 42, probability = True)
model.fit(train_data, wine_train.target)

# 预测
predictions = model.predict(test_data)
predictions_path = 'D:/vscode/python/py_lab/week6/predictions.txt'
with open(predictions_path, 'w') as file:
    for index, prediction in enumerate(predictions):
        if index == len(predictions) - 1:
            file.write(prediction)
        else:
            file.write(prediction + '\n')