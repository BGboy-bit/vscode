from pathlib import Path
import shutil
import os
from datetime import datetime




file_path = Path("D://vscode//python//py_lab//week3//original_file.txt")
file_path.touch()

copied_file_path = Path("D://vscode//python//py_lab//week3//copied_file.txt")
shutil.copyfile(file_path, copied_file_path)

copied_file_creation_time = os.path.getctime(copied_file_path)

timee = datetime.fromtimestamp(copied_file_creation_time).strftime('%Y-%m-%d %H:%M:%S')

print(timee)
