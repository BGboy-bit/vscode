#include"Client.h"
#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;

Client::Client() {
	ServerName = "default";
	ClientNum = 1;
}

void Client::ChangeServerName(string& name) {
	
	ServerName = name;
}


