#include"Client.h"
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

string Client::ServerName;
int Client::ClientNum;

int main() {
	Client client;
	cout << "����������������֣�";
	string str; cin >> str;
	client.ChangeServerName(str);
	cout << "�������������Ա������";
	int num; cin >> num; client.ClientNum = num;
	cout << "��������Ϊ��" << client.ServerName << "\n" << "�����û�����Ϊ��" << client.ClientNum << "\n";
}