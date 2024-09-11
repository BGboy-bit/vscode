#ifndef CLIENT_H
#define CLIENT_H

#include<string>
#include<stdio.h>
using namespace std;

class Client {
public : 
	static string ServerName ;
	static int ClientNum;
	Client();
	static void ChangeServerName(string& name);

};

#endif // CLIENT_H
;