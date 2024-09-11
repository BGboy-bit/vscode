#include<iostream>
#include<string>
using namespace std;

class String {
public :
	string str;
	String();
	String(string s);
	~String();
	void assign(String s);
	void print();
	void add(String s);
};

String::String() {
	str = "deflaut";
}
String::String(string s) {
	str = s;
}
String::~String(){
	cout << str << "�ѱ�����" << "\n";
}
void String::add(String s) {
	str += s.str;
}
void String::assign(String s) {
	str = s.str;
}
void String::print() {
	cout << str << "\n";
}

int main() {
	String s1;
	String s2("hello");

	s1.assign(s2);  // ��ʾ��s2��ֵ��s1
	s1.print();

	String s3("world");

	s1.add(s3); // ��ʾ��s3�ӵ�s1��
	s1.print();

	return 0;
}
