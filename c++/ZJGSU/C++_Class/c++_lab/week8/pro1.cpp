#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//多组输入

class MyString {
public:
    MyString(const char *str = NULL); 
    MyString(const MyString &other); 
    ~MyString(void); 
    friend MyString operator+(const MyString& str1, const MyString& str2);
    char& operator[](int a);
    friend istream& operator>>(istream& is, MyString &str);         
    friend ostream& operator<<(ostream& os, const MyString &str);
private:
    char * m_data; // 指向在堆上分配的用于存储字符串的内存空间
};

MyString::MyString(const char *str) {
    if(str) {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    } 
    else {
        m_data = nullptr;
    }
}
MyString::MyString(const MyString &other) {
    if(other.m_data) {
        m_data = new char[strlen(other.m_data) + 1];
        strcpy(m_data, other.m_data);
    } 
    else {
        m_data = nullptr;
    }
}
MyString::~MyString(void) {
    cout << "MyString destructor" << "\n";
}
MyString operator+(const MyString& str1, const MyString& str2) {
    MyString result;
    result.m_data = new char[strlen(str1.m_data) + strlen(str2.m_data) + 1];
    strcpy(result.m_data, str1.m_data);
    strcat(result.m_data, str2.m_data);
    return result;
}
char& MyString::operator[] (int a) {
    return m_data[a];
}
istream& operator>>(istream& is, MyString &str) {
    char buffer[1000];
    is >> buffer;
    str.m_data = new char[strlen(buffer) + 1];
    strcpy(str.m_data, buffer);
    return is;
}
ostream& operator<<(ostream& os, const MyString &str) {
    os << str.m_data;
    return os;
}
void Solve() {
    MyString s1, s2;
    cout << "string s1: "; cin >> s1;
    cout << "string s1: " << s1 << "\n";
    cout << "string s2: "; cin >> s2;
    cout << "string s2: " << s2 << "\n";
    cout << "s1 + s2 = " << s1 + s2 << "\n";
    cout << "s1[1] = " << s1[1] << "\n";
}


signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}
