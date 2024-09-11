#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

stack<char> sk;
stack<double> ct;
string s1,s2,s3;
double ans;

//判断�?否为数字
int isdight(char c)
{
	if(c >= '0' && c <= '9')
	return 1;
	else
	return 0;
}

void Translate()
{
	int n = s1.length();
	for(int i = 0;i < n;i++)
	{
		
		//判断�?否为负数符号 
		if(s1[i] == '-')
		{
			if(i == 0 || s1[i - 1] == '(')
			s2 += s1[i];
			continue;
		}
		
		//输入数字或�?'.'直接放入字�?�串 
		while(isdight(s1[i]) || s1[i] == '.')
		{
			s2 += s1[i++];
			if(!isdight(s1[i]) && s1[i] != '.')
			s2 += ' ';
		}
		
		//遇到左括号直接压入栈 
		if(s1[i] == '(')
		sk.push(s1[i]);
		
		// 遇到右括号就出栈到上一�?左括�?(左括号不进字符串) 
		if(s1[i] == ')')
		{
			while(sk.top() != '(')
			{
				s2 += sk.top();
				s2 += ' '; 
				sk.pop();
			}
			sk.pop();//弹出左括�? 
		}
		
		//遇到+或�?
        //1.栈空/栈顶为左�?�?:直接入栈
        //2.否则一直出�?,直到栈空/栈顶为左�?�?,再入�?
        if(s1[i] == '+' || s1[i] == '-')
        {
        	while(!sk.empty() && sk.top() != '(')
        	{
        		s2 += sk.top();
				s2 += ' '; 	
				sk.pop();
			}
			sk.push(s1[i]);
		}
		//遇到*�?/�?% 
        //1.栈空/栈顶为左�?�?/栈顶操作符为'+'or'-':直接入栈
        //2.否则一直出�?,直到满足1,再入�?
		if(s1[i] == '*' || s1[i] == '/' || s1[i] == '%')
		{
			while(!sk.empty() && sk.top() != '(' && sk.top() != '+' && sk.top() != '-')
			{
				s2 += sk.top();
				s2 += ' ';	
				sk.pop();
			}
			sk.push(s1[i]);	
		}	
	}
	//�?缀表达式遍历完�?,还需检查栈�?�?否有�?输出字�??
    //判断栈空,非空则直接出栈并输出(左括号不用输�?)
    while(!sk.empty())
    {
    	if(sk.top() != '(')
    	{
			s2 += sk.top();
    		s2 += ' ';
    	}
		sk.pop();
	}
	
}

int main()
{
	getline(cin,s1);
	Translate();
    for(ll i = 0;i < s2.length() - 1;i++) cout << s2[i];
    if(*(s2.end() - 1) != ' ') cout << *(s2.end() - 1);
	return 0;
}