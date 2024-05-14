dict = [{'id':'4','name':'b'}, {'id':'6','name':'c'}, 
             {'id':'3','name':'a'}, {'id':'1','name':'g'}, 
             {'id':'8','name':'f'}]
sorted_data = sorted(dict, key=lambda x: x['id'])
print(sorted_data)
