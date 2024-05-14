def replace_content(file_path, old_content, new_content):
    # 读取原始文件内容
    with open(file_path, 'r') as file:
        content = file.read()
    
    # 替换内容
    updated_content = content.replace(old_content, new_content)
    
    # 将更新后的内容写回文件
    with open(file_path, 'w') as file:
        file.write(updated_content)

replace_content('example.txt', 'old', 'new')
