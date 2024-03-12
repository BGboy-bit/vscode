
// CPerson.h
#ifndef CPERSON_H
#define CPERSON_H

#include<iostream>
#include <string>
using namespace std;

// class CPerson definition
class CPerson {
    friend ostream& operator<<(ostream& output, const CPerson& p);
private:
    string name;
    string idNumber;
    string sex;
    string age;
public:
    CPerson(string n, string  i, string s, string a);
    ~CPerson();
    string getName() const;
    string getidNumber() const;
    string getSex() const;
    string getAge() const;
    // function operator<< definition
    
}; // end class CPerson

#endif // CPERSON_H
