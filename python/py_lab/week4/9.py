class BankAccount:
    def __init__(self, account_name, balance=0):
        self.account_name = account_name
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
        else:
            print("Please enter a positive amount to deposit.")

    def withdraw(self, amount):
        if 0 < amount <= self.balance:
            self.balance -= amount
        elif amount <= 0:
            print("Please enter a positive amount to withdraw.")
        else:
            print("Insufficient balance.")

    def print_info(self):
        print(f"Account Name: {self.account_name}")
        print(f"Balance: {self.balance}")

# 创建BankAccount实例
account = BankAccount("John Doe", 1000)
account.deposit(500)  # 存款500
account.withdraw(200)  # 取款200
account.print_info()  # 打印账户信息

# 返回最终的账户信息以确认
print(account.account_name, account.balance)
