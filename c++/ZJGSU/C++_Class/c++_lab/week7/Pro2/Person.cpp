#include<iostream>
#include <string>
using namespace std;
#include "CPerson.h"

// constructor
CPerson::CPerson(string n, string  i, string s, string a)
		: name(n), idNumber(i), sex(s), age(a) {}
// end class constructor constructor
CPerson::~CPerson() {
    cout << "Person Destroyed" << "\n";
}
string CPerson::getName() const {
    return name;
}
string CPerson::getidNumber() const {
    return idNumber;
}
string CPerson::getSex() const {
    return sex;
}
string CPerson::getAge() const {
    return age;
}
// function operator<< definition
ostream& operator<<(ostream& output, const CPerson& p) {
    output << "Name: " << p.name
        << "\nidNumber: " << p.idNumber
        << "\nSex: " << p.sex
        << "\nAge: " << p.age
        << "\n";
        return output;
} // end function operator<<