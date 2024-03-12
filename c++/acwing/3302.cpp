#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

stack<ll> num;
stack<char> op;
unordered_map<char, ll> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval() {
    //a是第二操作数，b是第一操作数，它是反着的啊啊啊啊啊啊啊啊啊啊
    //算减法与除法时要注意！！！
    int a = num.top(); num.pop();
    int b = num.top(); num.pop();
    char c = op.top(); op.pop();
    if(c == '+') num.push(a + b);
    else if(c == '-') num.push(b - a);
    else if(c == '*') num.push(a * b);
    else if(c == '/') num.push(b / a);
}

int main() {
    string str;
    cin >> str;
    for(ll i = 0; i < str.size(); i ++ ) {
        char c = str[i];
        if(isdigit(c)) {
            ll x = 0, j = i;
            while(isdigit(str[j]) && j < str.size()) {
                x = x * 10 + str[j ++ ] - '0';
            }
            num.push(x);
            i = j - 1;
        }
        
        else if(c == '(') op.push(c);
        else if(c == ')') {
            while(op.top() != '(') eval();
            op.pop();
        } 
        else {
            while(!op.empty() && pr[op.top()] >= pr[c]) eval();
            op.push(c);
        }
    } 
    
    while(!op.empty()) eval();
    cout << num.top() << "\n";
    return 0;
}