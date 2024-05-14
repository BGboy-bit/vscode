import datetime

def login():
    valid_username = "张三"
    valid_password = "123456"

    username = input("请输入用户名: ")
    password = input("请输入密码: ")

    now = datetime.datetime.now()
    timestamp = now.strftime("%Y-%m-%d %H:%M:%S")

    if username == valid_username and password == valid_password:
        with open("login_log.txt", "a") as log_file:
            log_file.write(f"登录成功: 用户名 {username}, 登录时间 {timestamp}\n")
        print("登录成功!")
    else:
        with open("login_log.txt", "a") as log_file:
            log_file.write(f"登录失败: 用户名 {username}, 登录时间 {timestamp}\n")
        print("用户名或密码错误, 登录失败!")

def look_log():
    try:
        with open("login_log.txt", "r") as log_file:
            print(log_file.read())
    except FileNotFoundError:
        print("登录日志文件不存在。")

if __name__ == "__main__":
    while True:
        sel = input("请选择你的操作：1-登录, 2-查看日志, 其他-退出")
        if sel == str(1):
            login()
        elif sel == str(2):
            look_log()
        else:
            break
 