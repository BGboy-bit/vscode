def wordcount(w, txtfile):
    try:
        with open(txtfile, 'r', encoding='utf-8') as file:
            content = file.read()
    except UnicodeDecodeError:
        with open(txtfile, 'r', encoding='gbk') as file:
            content = file.read()
    count = content.count(w)
    return count


import os
import shutil
import pickle

dir_name = "mydir"
if not os.path.exists(dir_name):
    os.mkdir(dir_name)

files_moved = []
for file in os.listdir('.'):
    if file.startswith('news_'):
        shutil.move(file, os.path.join(dir_name, file))
        files_moved.append(file)

data_to_save = [wordcount, files_moved]
with open(os.path.join(dir_name, 'wc.pkl'), 'wb') as pkl_file:
    pickle.dump(data_to_save, pkl_file)

with open(os.path.join(dir_name, 'wc.pkl'), 'rb') as pkl_file:
    wordcount_function, files = pickle.load(pkl_file)

keywords = ["中国", "美国", "科技", "芯片"]
results = {}

for file in files:
    file_path = os.path.join(dir_name, file)
    counts = {keyword: wordcount_function(keyword, file_path) for keyword in keywords}
    results[file] = counts

print(f"{'':<20}{'中国':>6}{'美国':>6}{'科技':>6}{'芯片':>6}")

for file, counts in results.items():
    print(f"{file:<17}{counts['中国']:>7}{counts['美国']:>7}{counts['科技']:>7}{counts['芯片']:>8}")