import os
def list_files_directory(directory):
    for root, dirs, files in os.walk(directory):
        for name in files:
            print(os.path.join(root, name))
        for name in dirs:
            print(os.path.join(root, name))

list_files_directory("D://vscode//python//py_lab//week3//")
