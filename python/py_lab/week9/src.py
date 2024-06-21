import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score

data_csv_path = 'images_train.csv'
label_csv_path = 'labels_train.csv'
total_rows = 60000
step_size = 3000 # 每3000行读取一次数据

all_data = []
all_labels = []

# Scaler标准化数据，Pca降维数据
scaler = StandardScaler()
pca = PCA(n_components = 0.95)

model = RandomForestClassifier(n_estimators = 500, random_state = 42, n_jobs = -1)

# 归一化像素值到[0, 1]
def preprocess_data(data):
    data = data / 255.0  
    return data

def load_and_preprocess_data(data_csv_path, label_csv_path, start_row, num_rows):
    data = pd.read_csv(data_csv_path, skiprows = range(1, start_row + 1), 
                       nrows = num_rows, header = None, dtype = 'uint8')
    labels = pd.read_csv(label_csv_path, skiprows = range(1, start_row + 1), 
                         nrows = num_rows, header = None, dtype = 'uint8')
    data = preprocess_data(data.values)
    labels = labels.values.ravel()
    return data, labels

# 预处理,确保每次PCA降维后的特征数量一致
full_data = pd.read_csv(data_csv_path, header = None, dtype = 'uint8')
full_data = preprocess_data(full_data.values)
scaler.fit(full_data)
pca.fit(scaler.transform(full_data))


for start_row in range(0, total_rows, step_size):

    images_trains, labels_trains = load_and_preprocess_data(
        data_csv_path, label_csv_path, start_row, step_size)
    # Scaler & Pca
    images_trains = scaler.transform(images_trains)
    images_trains = pca.transform(images_trains)
    
    model.fit(images_trains, labels_trains)
    
    all_data.append(images_trains)
    all_labels.append(labels_trains)

all_data = np.vstack(all_data) 
all_labels = np.hstack(all_labels)

train_predictions = model.predict(all_data)
print("Training Accuracy: ", accuracy_score(all_labels, train_predictions))

test_data = pd.read_csv('images_test.csv', header = None, dtype = 'uint8')
test_data = preprocess_data(test_data.values)
test_data = scaler.transform(test_data)
test_data = pca.transform(test_data)
test_predictions = model.predict(test_data)

with open('preds.txt', 'w') as file:
    for prediction in test_predictions:
        file.write(str(prediction) + '\n')
