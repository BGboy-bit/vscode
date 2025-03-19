def mk_tk(tag, val=None):
    return [tag, val]

def tk_tag(t):
    return t[0]

def tk_val(t):
    return t[1]


def lexer(prog):
    tokens = []
    i = 0
    n = len(prog)
    
    def skip_whitespace():
        nonlocal i
        while i < n and prog[i] in ' \t\n\r':
            i += 1

    while i < n:
        skip_whitespace()
        if i >= n:
            break
        ch = prog[i]
        if ch == '"':
            i += 1
            start = i
            while i < n and prog[i] != '"':
                i += 1
            if i >= n:
                raise Exception("少了右引号的字符串")
            val = prog[start:i]
            i += 1 
            tokens.append(mk_tk("string", val))
            continue
        elif ch == '-' or ch.isdigit():
            start = i
            if ch == '-':
                i += 1
                if i >= n or not prog[i].isdigit():
                    raise Exception("数字格式无效")
            if prog[i] == '0':
                i += 1
            else:
                while i < n and prog[i].isdigit():
                    i += 1
            if i < n and prog[i] == '.':
                i += 1
                if i >= n or not prog[i].isdigit():
                    raise Exception("小数部分格式无效")
                while i < n and prog[i].isdigit():
                    i += 1
            if i < n and prog[i] in ['e','E']:
                i += 1
                if i < n and prog[i] in ['+','-']:
                    i += 1
                if i >= n or not prog[i].isdigit():
                    raise Exception("指数部分格式无效")
                while i < n and prog[i].isdigit():
                    i += 1
            num_str = prog[start:i]
            if '.' in num_str or 'e' in num_str or 'E' in num_str:
                num_val = float(num_str)
            else:
                num_val = int(num_str)
            tokens.append(mk_tk("num", num_val))
            continue
        elif ch in ['[', ']', '{', '}', ',', ':']:
            tokens.append(mk_tk(ch))
            i += 1
            continue
        elif prog.startswith("true", i):
            tokens.append(mk_tk("true"))
            i += 4
            continue
        elif prog.startswith("false", i):
            tokens.append(mk_tk("false"))
            i += 5
            continue
        elif prog.startswith("null", i):
            tokens.append(mk_tk("null"))
            i += 4
            continue
        else:
            raise Exception("奇奇怪怪的字符：" + ch)
    
    tokens.append(mk_tk("eof"))
    return tokens

def make_token_reader(tokens):
    index = 0
    def _peek():
        if index < len(tokens):
            return tk_tag(tokens[index])
        return "eof"
    def _next():
        nonlocal index
        token = tokens[index] if index < len(tokens) else mk_tk("eof")
        index += 1
        return token
    def _match(expected):
        token = _next()
        if tk_tag(token) != expected:
            raise Exception(f"希望得到 {expected}, 但是输入为 {token}")
        return token
    return _peek, _match, _next

def parse(tokens):
    peek, match, next_token = make_token_reader(tokens)
    
    def parse_value():
        t = peek()
        if t == "num" or t == "string":
            return tk_val(next_token())
        elif t == "true":
            next_token()
            return True
        elif t == "false":
            next_token()
            return False
        elif t == "null":
            next_token()
            return None
        elif t == "[":
            return parse_array()
        elif t == "{":
            return parse_object()
        else:
            raise Exception("错误: " + t)
    
    def parse_array():
        match("[")
        arr = []
        if peek() != "]":
            arr.append(parse_value())
            while peek() == ",":
                next_token() 
                arr.append(parse_value())
        match("]")
        return arr
    
    def parse_object():
        match("{")
        obj = {}
        if peek() != "}":
            key, value = parse_pair()
            obj[key] = value
            while peek() == ",":
                next_token()  
                key, value = parse_pair()
                obj[key] = value
        match("}")
        return obj
    
    def parse_pair():
        token = match("string")
        key = tk_val(token)
        match(":")
        value = parse_value()
        return key, value
    
    return parse_value()


def json_to_python(json_str):
    tokens = lexer(json_str)
    result = parse(tokens)
    return result

def test():
    print("----- 测试 -----")

    test_array = '[1,2,3]'
    result_array = json_to_python(test_array)
    print("Test Array:", result_array, type(result_array))
    
    test_object = '{"name":"John","age":30,"hobbies":["reading","swimming"]}'
    result_object = json_to_python(test_object)
    print("Test Object:", result_object, type(result_object))
    
    test_string = '"HelloWorld"'
    result_string = json_to_python(test_string)
    print("Test String:", result_string, type(result_string))
    
    test_number = '123'
    result_number = json_to_python(test_number)
    print("Test Number (int):", result_number, type(result_number))
    
    test_float = '123.45'
    result_float = json_to_python(test_float)
    print("Test Number (float):", result_float, type(result_float))
    
    test_true = 'true'
    result_true = json_to_python(test_true)
    print("Test Boolean (true):", result_true, type(result_true))
    
    test_false = 'false'
    result_false = json_to_python(test_false)
    print("Test Boolean (false):", result_false, type(result_false))
    
    test_null = 'null'
    result_null = json_to_python(test_null)
    print("Test Null:", result_null, type(result_null))

    test_nested = '[1,{"a":[2,3],"b":"hello"},false]'
    result_nested = json_to_python(test_nested)
    print("Test Nested:", result_nested, type(result_nested))


if __name__ == "__main__":
    test()
