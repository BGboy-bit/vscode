import pandas as pd
from sklearn.model_selection import GridSearchCV
from sklearn.svm import SVC

AMINO_ACIDS = 'ARNDCQEGHILKMFPSTWYV'

def amino_acid_composition(sequence):
    composition = {aa: 0 for aa in AMINO_ACIDS}
    total = len(sequence)
    for aa in sequence:
        if aa in composition:
            composition[aa] += 1
    return [composition[aa] / total for aa in AMINO_ACIDS]

def load_data(filename):
    data = []
    try:
        with open(filename, 'r') as file:
            for line in file:
                parts = line.strip().split()
                if len(parts) == 3:  
                    seq_id, label, sequence = parts
                elif len(parts) == 2:
                    seq_id, sequence = parts
                    label = None
                features = amino_acid_composition(sequence)
                data.append((seq_id, label, features))
    except FileNotFoundError:
        print(f"Error: The file '{filename}' does not exist.")
        return []
    return data

def prepare_data(train_data, test_data):
    train_df = pd.DataFrame(train_data, columns=['Seq_ID', 'Label', 'Features'])
    test_df = pd.DataFrame(test_data, columns=['Seq_ID', 'Label', 'Features'])
    
    X_train = pd.DataFrame(train_df['Features'].tolist())
    y_train = train_df['Label'].astype(int)
    
    X_test = pd.DataFrame(test_df['Features'].tolist())
    return X_train, y_train, X_test

def optimize_parameters(X_train, y_train):
    param_grid = {
        'C': [0.1, 1, 10, 100],
        'gamma': ['scale', 'auto', 0.1, 0.01, 0.001],
        'kernel': ['linear', 'rbf', 'poly']
    }
    model = SVC()
    grid_search = GridSearchCV(model, param_grid, cv=5, scoring='accuracy')
    grid_search.fit(X_train, y_train)
    print("Best parameters:", grid_search.best_params_)
    print("Best cross-validation score: {:.2f}".format(grid_search.best_score_))
    return grid_search.best_estimator_

if __name__ == "__main__":
    train_data = load_data('ProSeqs_Train.txt')
    test_data = load_data('ProSeqs_Test.txt')
    
    X_train, y_train, X_test = prepare_data(train_data, test_data)
    optimized_model = optimize_parameters(X_train, y_train)
    
    predictions = optimized_model.predict(X_test)
    with open('preds.txt', 'w') as f:
        for pred in predictions:
            f.write(f"{pred}\n")
    print("Predictions saved to preds.txt.")
