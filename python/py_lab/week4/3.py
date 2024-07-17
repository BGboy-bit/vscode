class Listinfo:
    def __init__(self, init_list):
        self.lst = init_list
        
    def add_elem(self, elename):
        if isinstance(elename, int) or isinstance(elename, str):
            self.lst.append(elename)
        else:
            raise ValueError("Element must be an integer or a string")
    
    def get_elem(self, num):
        if 0 <= num < len(self.lst):
            return self.lst[num]
        else:
            raise IndexError("List index out of range")
    
    def merge_list(self, ls):
        if isinstance(ls, list):
            self.lst.extend(ls)
        else:
            raise ValueError("Argument must be a list")
        
    def del_lastone(self):
        if self.lst:
            return self.lst.pop()
        else:
            raise IndexError("Delete from empty list")

list_info = Listinfo([44,222,111,333,454,'sss','333'])

list_info.add_elem(777)
list_info.add_elem("new_element")
#list_info.add_elem(list_info)
print(list_info.lst)

get_element = list_info.get_elem(2)
print(get_element)

merged_list = [1, 2, 3]
list_info.merge_list(merged_list)
#list_info.merge_list("merged_list")
print(list_info.lst)

deleted_element = list_info.del_lastone()

print(list_info.lst)
print(deleted_element)