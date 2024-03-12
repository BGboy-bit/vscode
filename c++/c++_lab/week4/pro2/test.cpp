#include"Client.h"
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

string Client::ServerName;
int Client::ClientNum;

int main() {
	Client client;
	cout << "请输入服务器的名字：";
	string str; cin >> str;
	client.ChangeServerName(str);
	cout << "请输入服务器成员数量：";
	int num; cin >> num; client.ClientNum = num;
	cout << "服务器名为：" << client.ServerName << "\n" << "现有用户数量为：" << client.ClientNum << "\n";
}