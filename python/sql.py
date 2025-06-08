
'''
CREATE TABLE departments (id, name);
CREATE TABLE employees   (id, name, dept_id, salary);

INSERT INTO departments (id, name) VALUES (10, 'R&D');
INSERT INTO departments (id, name) VALUES (20, 'Sales');
INSERT INTO employees   (id, name, dept_id, salary) VALUES (1, 'Alice', 10, 8000);
INSERT INTO employees   (id, name, dept_id, salary) VALUES (2, 'Bob',   20, 6500);
INSERT INTO employees   (id, name, dept_id, salary) VALUES (3, 'Cathy', 10, 7200);

SELECT * FROM employees;

SELECT id, name, salary FROM employees WHERE salary = 6500;

SELECT employees.name, departments.name
FROM employees
JOIN departments ON employees.dept_id = departments.id;

UPDATE employees SET salary = 7000 WHERE name = 'Bob';

DELETE FROM employees WHERE id = 3;

ALTER TABLE employees ADD COLUMN age;

UPDATE employees SET age = 30 WHERE id = 1;
SELECT * FROM employees;

DROP TABLE departments;
'''

import re
from enum import Enum

# --- 1. 词法分析器 (Lexer) ---
# 定义词汇单元 (Token) 的类型
class TokenType(Enum):
    KEYWORD = 'KEYWORD'      
    IDENTIFIER = 'IDENTIFIER'
    LITERAL = 'LITERAL'      
    OPERATOR = 'OPERATOR'    
    DOT = 'DOT'              # .
    SEMICOLON = 'SEMICOLON'  # ; 
    EOF = 'EOF'              

# 词汇单元 (Token) 的数据结构
class Token:
    def __init__(self, type, value):
        self.type = type
        self.value = value

    def __repr__(self):
        return f"Token({self.type.name}, '{self.value}')"

# 词法分析器实现
class Lexer:
    def __init__(self, text):
        self.text = text
        self.pos = 0
        self.current_char = self.text[self.pos] if self.pos < len(self.text) else None
        self.keywords = {
            'CREATE', 'TABLE', 'INSERT', 'INTO', 'VALUES', 'SELECT', 'FROM', 'WHERE', 'DELETE',
            'UPDATE', 'SET', 'ALTER', 'ADD', 'COLUMN', 'DROP', 'JOIN', 'ON'
        }

    def advance(self):
        """移动指针到下一个字符"""
        self.pos += 1
        self.current_char = self.text[self.pos] if self.pos < len(self.text) else None

    def skip_whitespace(self):
        """跳过空白字符"""
        while self.current_char is not None and self.current_char.isspace():
            self.advance()

    def get_identifier(self):
        """获取识别字或关键字"""
        result = ''
        while self.current_char is not None and (self.current_char.isalnum() or self.current_char == '_'):
            result += self.current_char
            self.advance()
        
        token_value = result.upper()
        if token_value in self.keywords:
            return Token(TokenType.KEYWORD, token_value)
        return Token(TokenType.IDENTIFIER, result)

    def get_literal(self):
        """获取字面值"""
        if self.current_char == "'":
            self.advance()
            result = ''
            while self.current_char is not None and self.current_char != "'":
                result += self.current_char
                self.advance()
            self.advance() 
            return Token(TokenType.LITERAL, result)
        elif self.current_char.isdigit():
            result = ''
            while self.current_char is not None and self.current_char.isdigit():
                result += self.current_char
                self.advance()
            return Token(TokenType.LITERAL, int(result))
        else:
            raise ValueError(f"无效的字面值起始字符 {self.current_char}")

    def get_next_token(self):
        """从输入字符串中获取下一个词汇单元"""
        while self.current_char is not None:
            if self.current_char.isspace():
                self.skip_whitespace()
                continue
            
            if self.current_char.isalpha():
                return self.get_identifier()

            if self.current_char.isdigit() or self.current_char == "'":
                return self.get_literal()
            
            # 处理点号
            if self.current_char == '.':
                self.advance()
                return Token(TokenType.DOT, '.')

            # 处理分号
            if self.current_char == ';':
                self.advance()
                return Token(TokenType.SEMICOLON, ';')

            operators = {'=': 'ASSIGN', ',': 'COMMA', '(': 'LPAREN', ')': 'RPAREN', '*': 'ASTERISK'}
            if self.current_char in operators:
                op_char = self.current_char
                self.advance()
                return Token(TokenType.OPERATOR, op_char)

            raise ValueError(f"无效字符: {self.current_char}")
        
        return Token(TokenType.EOF, None)

# --- 2. 语法分析器 (Parser) ---
class ASTNode: pass
class CreateTableNode(ASTNode):
    def __init__(self, table_name, columns):
        self.table_name = table_name; self.columns = columns
class DropTableNode(ASTNode):
    def __init__(self, table_name):
        self.table_name = table_name
class AlterTableNode(ASTNode):
    def __init__(self, table_name, action):
        self.table_name = table_name; self.action = action
class AddColumnNode(ASTNode):
    def __init__(self, column_name):
        self.column_name = column_name
class InsertNode(ASTNode):
    def __init__(self, table_name, columns, values):
        self.table_name = table_name; self.columns = columns; self.values = values
class UpdateNode(ASTNode):
    def __init__(self, table_name, assignments, where_clause):
        self.table_name = table_name; self.assignments = assignments; self.where_clause = where_clause
class SelectNode(ASTNode):
    def __init__(self, columns, from_clause, where_clause=None):
        self.columns = columns; self.from_clause = from_clause; self.where_clause = where_clause
class DeleteNode(ASTNode):
    def __init__(self, table_name, where_clause=None):
        self.table_name = table_name; self.where_clause = where_clause
class ConditionNode(ASTNode):
    def __init__(self, left, op, right):
        self.left = left; self.op = op; self.right = right
class JoinNode(ASTNode):
    def __init__(self, left_table, right_table, join_condition):
        self.left_table = left_table; self.right_table = right_table; self.join_condition = join_condition
class QualifiedIdentifier(ASTNode):
    def __init__(self, table_name, column_name):
        self.table_name = table_name; self.column_name = column_name

# 语法分析器实现
class Parser:
    def __init__(self, lexer):
        self.lexer = lexer
        self.current_token = self.lexer.get_next_token()

    def eat(self, token_type, token_value=None):
        """消耗一个词汇单元，如果符合预期则前进，否则报错"""
        if self.current_token.type == token_type and \
           (token_value is None or self.current_token.value == token_value):
            self.current_token = self.lexer.get_next_token()
        else:
            expected = f"{token_type.name}:{token_value}" if token_value else token_type.name
            raise SyntaxError(f"语法错误: 期望得到 {expected}, 但实际为 {self.current_token}")

    def parse(self):
        """
        解析一个完整的语句，要求它以分号结尾
        """
        ast = self.parse_statement()
        # 语句解析完成后，必须是一个分号
        self.eat(TokenType.SEMICOLON)
        # 分号后应该是输入的结尾
        if self.current_token.type != TokenType.EOF:
            raise SyntaxError(f"语法错误: 分号后出现多余的字符 '{self.current_token.value}'")
        return ast

    def parse_statement(self):
        """解析单个SQL语句的核心逻辑 """
        token_value = self.current_token.value
        if self.current_token.type != TokenType.KEYWORD:
             raise SyntaxError(f"语法错误: SQL语句必须以关键字开头, 而不是 '{token_value}'")

        if token_value == 'CREATE': return self.parse_create_table()
        if token_value == 'DROP':   return self.parse_drop_table()
        if token_value == 'ALTER':  return self.parse_alter_table()
        if token_value == 'INSERT': return self.parse_insert()
        if token_value == 'UPDATE': return self.parse_update()
        if token_value == 'SELECT': return self.parse_select()
        if token_value == 'DELETE': return self.parse_delete()
        raise SyntaxError(f"不支持的 SQL 语句: {token_value}")
    
    def parse_identifier_or_star(self):
        """解析一个标识符或者一个星号"""
        token = self.current_token
        if token.type == TokenType.OPERATOR and token.value == '*':
            self.eat(TokenType.OPERATOR, '*')
            return token
        return self.parse_qualified_identifier()

    def parse_qualified_identifier(self):
        """解析 table.column 或 table"""
        part1 = self.current_token
        self.eat(TokenType.IDENTIFIER)
        if self.current_token.type == TokenType.DOT:
            self.eat(TokenType.DOT)
            part2 = self.current_token
            self.eat(TokenType.IDENTIFIER)
            return QualifiedIdentifier(part1.value, part2.value)
        return part1

    def parse_create_table(self):
        '''
        创建表
        CREATE TABLE database_name.table_name(
		column1, column2, column3, ......);
        '''
        self.eat(TokenType.KEYWORD, 'CREATE')
        self.eat(TokenType.KEYWORD, 'TABLE')
        table_name = self.current_token
        self.eat(TokenType.IDENTIFIER)
        self.eat(TokenType.OPERATOR, '(')
        columns = [self.current_token]
        self.eat(TokenType.IDENTIFIER)
        while self.current_token.value == ',':
            self.eat(TokenType.OPERATOR, ',')
            columns.append(self.current_token)
            self.eat(TokenType.IDENTIFIER)
        self.eat(TokenType.OPERATOR, ')')
        return CreateTableNode(table_name, columns)

    def parse_drop_table(self):
        '''
        删除表
        DROP TABLE database_name.table_name;
        '''
        self.eat(TokenType.KEYWORD, 'DROP')
        self.eat(TokenType.KEYWORD, 'TABLE')
        table_name = self.current_token
        self.eat(TokenType.IDENTIFIER)
        return DropTableNode(table_name)
    
    def parse_alter_table(self):
        '''
        新增列
        ALTER TABLE database_name.table_name 
        ADD COLUMN column_def...;
        '''
        self.eat(TokenType.KEYWORD, 'ALTER')
        self.eat(TokenType.KEYWORD, 'TABLE')
        table_name = self.current_token
        self.eat(TokenType.IDENTIFIER)
        self.eat(TokenType.KEYWORD, 'ADD')
        self.eat(TokenType.KEYWORD, 'COLUMN')
        column_name = self.current_token
        self.eat(TokenType.IDENTIFIER)
        return AlterTableNode(table_name, AddColumnNode(column_name))

    def parse_insert(self):
        '''
        新增行
        INSERT INTO table_name (column1,column2,column3,...)
        VALUES (value1,value2,value3,...);
        '''
        self.eat(TokenType.KEYWORD, 'INSERT')
        self.eat(TokenType.KEYWORD, 'INTO')
        table_name = self.current_token
        self.eat(TokenType.IDENTIFIER)
        self.eat(TokenType.OPERATOR, '(')
        columns = [self.current_token]
        self.eat(TokenType.IDENTIFIER)
        while self.current_token.value == ',':
            self.eat(TokenType.OPERATOR, ',')
            columns.append(self.current_token)
            self.eat(TokenType.IDENTIFIER)
        self.eat(TokenType.OPERATOR, ')')
        self.eat(TokenType.KEYWORD, 'VALUES')
        self.eat(TokenType.OPERATOR, '(')
        values = [self.current_token]
        self.eat(TokenType.LITERAL)
        while self.current_token.value == ',':
            self.eat(TokenType.OPERATOR, ',')
            values.append(self.current_token)
            self.eat(TokenType.LITERAL)
        self.eat(TokenType.OPERATOR, ')')
        return InsertNode(table_name, columns, values)

    def parse_update(self):
        '''
        修改值
        UPDATE table_name
        SET column1 = value1, column2 = value2, ...
        WHERE condition;
        '''
        self.eat(TokenType.KEYWORD, 'UPDATE')
        table_name = self.current_token
        self.eat(TokenType.IDENTIFIER)
        self.eat(TokenType.KEYWORD, 'SET')
        assignments = {}
        col = self.current_token
        self.eat(TokenType.IDENTIFIER)
        self.eat(TokenType.OPERATOR, '=')
        val = self.current_token
        self.eat(TokenType.LITERAL)
        assignments[col.value] = val
        while self.current_token.value == ',':
            self.eat(TokenType.OPERATOR, ',')
            col = self.current_token
            self.eat(TokenType.IDENTIFIER)
            self.eat(TokenType.OPERATOR, '=')
            val = self.current_token
            self.eat(TokenType.LITERAL)
            assignments[col.value] = val
        where_clause = self.parse_where_clause()
        return UpdateNode(table_name, assignments, where_clause)
    
    def parse_delete(self):
        '''
        删除记录
        DELETE FROM table_name
        WHERE condition;
        '''
        self.eat(TokenType.KEYWORD, 'DELETE')
        self.eat(TokenType.KEYWORD, 'FROM')
        table_name = self.current_token
        self.eat(TokenType.IDENTIFIER)
        where_clause = None
        if self.current_token.value == 'WHERE':
            where_clause = self.parse_where_clause()
        return DeleteNode(table_name, where_clause)

    def parse_condition(self):
        """解析布尔条件"""
        left = self.parse_qualified_identifier()
        op = self.current_token
        self.eat(TokenType.OPERATOR, '=')
        
        if self.current_token.type == TokenType.IDENTIFIER:
            right = self.parse_qualified_identifier()
        else:
            right = self.current_token
            self.eat(TokenType.LITERAL)
        
        return ConditionNode(left, op, right)

    def parse_where_clause(self):
        """解析 WHERE 关键字"""
        self.eat(TokenType.KEYWORD, 'WHERE')
        return self.parse_condition()
    
    def parse_select(self):
        '''
        解析 select 关键字
		SELECT column1, column2, …
		FROM   table_name
		[JOIN  another_table ON join_condition]
		[WHERE condition]
        '''
        self.eat(TokenType.KEYWORD, 'SELECT')
        
        columns = [self.parse_identifier_or_star()]
        while self.current_token.value == ',':
            self.eat(TokenType.OPERATOR, ',')
            columns.append(self.parse_identifier_or_star())
        
        self.eat(TokenType.KEYWORD, 'FROM')
        from_clause = self.parse_qualified_identifier()

        if self.current_token.value == 'JOIN':
            self.eat(TokenType.KEYWORD, 'JOIN')
            right_table = self.parse_qualified_identifier()
            self.eat(TokenType.KEYWORD, 'ON')
            join_condition = self.parse_condition()
            from_clause = JoinNode(from_clause, right_table, join_condition)

        where_clause = None
        if self.current_token.value == 'WHERE':
            where_clause = self.parse_where_clause()
        
        return SelectNode(columns, from_clause, where_clause)

# --- 3. 转译器 (Translator) ---
class Translator:
    def translate(self, node):
        '''动态单分发入口'''
        method_name = f'translate_{type(node).__name__}'
        visitor = getattr(self, method_name, self.generic_translator)
        return visitor(node)

    def generic_translator(self, node):
        '''抛出异常'''
        raise Exception(f'未找到方法: translate_{type(node).__name__}')

    def translate_CreateTableNode(self, node):
        '''
        创建表 
        db.create_table('emp')
        '''
        table_name = node.table_name.value
        columns_str = ", ".join([col.value for col in node.columns])
        return f"# 创建表 '{table_name}'，包含列: {columns_str}\ndb.create_table('{table_name}')"

    def translate_DropTableNode(self, node):
        '''
        删除表
        db.drop_table('emp')
        '''
        return f"db.drop_table('{node.table_name.value}')"
        
    def translate_AlterTableNode(self, node):
        '''
        新增表
        db.alter_add_column('emp','age')
        '''
        if isinstance(node.action, AddColumnNode):
            col_name = node.action.column_name.value
            return f"db.alter_add_column('{node.table_name.value}', '{col_name}')"
        raise TypeError("不支持的 ALTER TABLE 操作")

    def translate_InsertNode(self, node):
        '''
        插入表
        db.insert('emp',{'id':1,'name':'Bob'})
        '''
        table_name = node.table_name.value
        row_dict_str = ", ".join([f"'{col.value}': {repr(val.value)}" for col, val in zip(node.columns, node.values)])
        return f"db.insert('{table_name}', {{ {row_dict_str} }})"

    def translate_UpdateNode(self, node):
        '''
        修改值
        db.update('emp',{'age':30},lambda row: …)
        '''
        table_name = node.table_name.value
        assignments_str = ", ".join([f"'{col}': {repr(val.value)}" for col, val in node.assignments.items()])
        condition_py = self._translate_where_condition(node.where_clause, 'row')
        return f"db.update('{table_name}', {{ {assignments_str} }}, lambda row: {condition_py})"

    def translate_DeleteNode(self, node):
        '''
        删除记录
        db.delete('emp',λ) / db.delete('emp')
        '''
        table_name = node.table_name.value
        if node.where_clause:
            condition_py = self._translate_where_condition(node.where_clause, 'row')
            return f"db.delete('{table_name}', lambda row: {condition_py})"
        return f"db.delete('{table_name}')"

    def _translate_on_condition(self, node, join_node):
        '''
        处理 JOIN … ON
        r1.get('id') == r2.get('id')
        '''
        t1_name = join_node.left_table.value
        t2_name = join_node.right_table.value
        left_table = node.left.table_name
        left_col = node.left.column_name
        if left_table not in [t1_name, t2_name]: raise NameError(f"ON子句中未知的表: {left_table}")
        left_var = 'r1' if left_table == t1_name else 'r2'
        left_str = f"{left_var}.get('{left_col}')"
        right_table = node.right.table_name
        right_col = node.right.column_name
        if right_table not in [t1_name, t2_name]: raise NameError(f"ON子句中未知的表: {right_table}")
        right_var = 'r1' if right_table == t1_name else 'r2'
        right_str = f"{right_var}.get('{right_col}')"
        return f"{left_str} == {right_str}"
        
    def _translate_where_condition(self, node, row_var, is_join=False):
        '''
        处理 WHERE
        row.get('table.col')
        '''
        def get_val(item):
            if isinstance(item, Token) and item.type == TokenType.LITERAL:
                return repr(item.value)
            if isinstance(item, QualifiedIdentifier):
                key = f"{item.table_name}.{item.column_name}" if is_join else item.column_name
                return f"{row_var}.get('{key}')"
            if isinstance(item, Token) and item.type == TokenType.IDENTIFIER:
                if is_join: raise TypeError(f"JOIN查询中的列必须指明表名: '{item.value}'")
                return f"{row_var}.get('{item.value}')"
            raise TypeError(f"不支持的条件部分: {item}")
            
        left_str = get_val(node.left)
        right_str = get_val(node.right)
        return f"{left_str} == {right_str}"

    def translate_SelectNode(self, node):
        '''
        处理 select
        
        无 JOIN
        一行 source_data = db.get_table('emp')
        
        JOIN
		t1_data = db.get_table('emp')
		t2_data = db.get_table('dept')
		source_data = [{...前缀列...}|{...}]  # 双层推导+ON过滤
        
        WHERE 过滤
        filtered_data = [row for row in source_data if <expr>]
        '''
        is_join = isinstance(node.from_clause, JoinNode)
        source_data_code = ""
        if is_join:
            join = node.from_clause
            t1_name, t2_name = join.left_table.value, join.right_table.value
            on_condition_py = self._translate_on_condition(join.join_condition, join)
            source_data_code = (
                f"t1_data = db.get_table('{t1_name}')\n"
                f"t2_data = db.get_table('{t2_name}')\n"
                f"source_data = [{{'{t1_name}.'+k: v for k, v in r1.items()}} | {{'{t2_name}.'+k: v for k, v in r2.items()}} "
                f"for r1 in t1_data for r2 in t2_data if {on_condition_py}]"
            )
        else:
            table_name = node.from_clause.value
            source_data_code = f"source_data = db.get_table('{table_name}')"

        filter_code = ""
        if node.where_clause:
            condition_py = self._translate_where_condition(node.where_clause, 'row', is_join)
            filter_code = f"filtered_data = [row for row in source_data if {condition_py}]"
        else:
            filter_code = "filtered_data = source_data"
        
        final_select_code = ""
        is_select_star = (len(node.columns) == 1 and isinstance(node.columns[0], Token) and node.columns[0].value == '*')

        if is_select_star:
            final_select_code = "result = filtered_data"
        else:
            cols_str = []
            for c in node.columns:
                if isinstance(c, QualifiedIdentifier):
                    key = f"{c.table_name}.{c.column_name}"
                    cols_str.append(f"'{key}': row.get('{key}')")
                elif isinstance(c, Token):
                    if is_join: raise TypeError(f"JOIN查询中的列必须指明表名: '{c.value}'")
                    cols_str.append(f"'{c.value}': row.get('{c.value}')")
            
            selected_cols_str = ", ".join(cols_str)
            final_select_code = f"result = [{{ {selected_cols_str} }} for row in filtered_data]"

        return f"{source_data_code}\n{filter_code}\n{final_select_code}"


# --- 4. 执行引擎 ---
class Database:
    def __init__(self):
        self._tables = {}
        print("数据库引擎已初始化。")

    def create_table(self, table_name):
        if table_name in self._tables:
            print(f"警告：数据表 '{table_name}' 已存在，正在重新创建。")
        self._tables[table_name] = []
        print(f"数据表 '{table_name}' 创建成功。")

    def drop_table(self, table_name):
        if table_name not in self._tables:
            raise NameError(f"数据表 '{table_name}' 不存在。")
        del self._tables[table_name]
        print(f"数据表 '{table_name}' 已被删除。")

    def alter_add_column(self, table_name, column_name):
        if table_name not in self._tables:
            raise NameError(f"数据表 '{table_name}' 不存在。")
        for row in self._tables[table_name]:
            row[column_name] = None
        print(f"在数据表 '{table_name}' 中添加新列 '{column_name}' 成功。")

    def insert(self, table_name, row_data):
        if table_name not in self._tables:
            raise NameError(f"数据表 '{table_name}' 不存在。")
        self._tables[table_name].append(row_data)
        print(f"1 行数据已插入 '{table_name}'。")

    def update(self, table_name, assignments, condition_func):
        if table_name not in self._tables:
            raise NameError(f"数据表 '{table_name}' 不存在。")
        update_count = 0
        for row in self._tables[table_name]:
            if condition_func(row):
                row.update(assignments)
                update_count += 1
        print(f"{update_count} 行数据已在 '{table_name}' 中更新。")

    def delete(self, table_name, condition_func=None):
        if table_name not in self._tables:
            raise NameError(f"数据表 '{table_name}' 不存在。")
        if condition_func is None:
            count = len(self._tables[table_name])
            self._tables[table_name] = []
        else:
            original_count = len(self._tables[table_name])
            self._tables[table_name] = [row for row in self._tables[table_name] if not condition_func(row)]
            count = original_count - len(self._tables[table_name])
        print(f"从 '{table_name}' 中删除了 {count} 行数据。")

    def get_table(self, table_name):
        if table_name not in self._tables:
            raise NameError(f"数据表 '{table_name}' 不存在。")
        return self._tables[table_name]

    def display(self):
        print("\n--- 当前数据库状态 ---")
        if not self._tables:
            print("数据库为空。")
        for name, data in self._tables.items():
            print(f"数据表: {name}")
            if not data:
                print("  (空)")
            else:
                headers = set()
                for row in data:
                    headers.update(row.keys())
                sorted_headers = sorted(list(headers))
                
                print("  " + " | ".join(f"{h:<20}" for h in sorted_headers))
                print("  " + "-" * (len(sorted_headers) * 22))
                for row in data:
                    print("  " + " | ".join(f"{str(row.get(h, 'None')):<20}" for h in sorted_headers))
        print("------------------------------\n")


# --- 主程序 ---
def main():
    db = Database()
    translator = Translator()
    
    print("欢迎使用 SQL 到 Python 转译器 (支持多行输入)！")
    print("请输入 SQL 命令，以分号 (;) 结尾。输入 'exit' 退出。")
    
    sql_buffer = ""
    prompt = "sql> "
    
    while True:
        try:
            line_input = input(prompt)
            
            if line_input.lower() == 'exit':
                break
            
            # 将当前行输入添加到缓冲区
            sql_buffer += line_input + " "

            # 只有当输入行以分号结尾时，才处理整个缓冲区
            if line_input.strip().endswith(';'):
                if not sql_buffer.strip():
                    sql_buffer = ""
                    prompt = "sql> "
                    continue

                lexer = Lexer(sql_buffer)
                parser = Parser(lexer)
                ast = parser.parse()
                python_code = translator.translate(ast)
                
                print(f"\n[转译后的 Python 代码]:\n---\n{python_code}\n---")

                local_scope = {'db': db, 'result': None}
                exec(python_code, local_scope)
                
                if local_scope['result'] is not None:
                    print("\n[查询结果]:")
                    if not local_scope['result']:
                        print("  (未找到任何行)")
                    else:
                        for item in local_scope['result']:
                            print(f"  {item}")
                
                db.display()

                # 处理完成后，重置缓冲区和提示符
                sql_buffer = ""
                prompt = "sql> "
            else:
                # 如果不以分号结尾，则继续等待输入
                prompt = "  -> "

        except (ValueError, SyntaxError, NameError, TypeError) as e:
            print(f"错误: {e}")
            # 出错后重置缓冲区
            sql_buffer = ""
            prompt = "sql> "
        except Exception as e:
            print(f"发生意外错误: {e}")
            sql_buffer = ""
            prompt = "sql> "

if __name__ == '__main__':
    main()
