data_list = []
def price_above_80(stock):
    return stock["price"] > 80

with open('info_stocks.txt', 'r') as file: 
    for line in file:
        parts = line.strip().split(', ')
        #print(parts)
        name = parts[0].split(': ')[1].strip("'") #split根据冒号和一个空格将part[0]分割为两部分，strip去除两边的单引号
        shares = int(parts[1].split(': ')[1]) 
        price = float(parts[2].split(': ')[1])
        data_list.append({"name": name, "price": price, "prices": float(shares * price)})

sorted_list = sorted(data_list, key=lambda x: x['prices'], reverse=True)
print("按价格排序后的股票信息为：")
for item in sorted_list:
    print(f"'name': '{item['name']:5}', 'price': {item['price']:6}, 'prices': {item['prices']}")

print("单价大于80的股票有: ")
#filtered_stocks = filter(price_above_80, sorted_list)
filtered_stocks = filter(lambda stock : stock["price"] > 80, sorted_list)
for item in sorted_list:
    print(f"'name': '{item['name']:5}', 'price': {item['price']:6}, 'prices': {item['prices']}")