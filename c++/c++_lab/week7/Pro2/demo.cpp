#include<iostream>
#include<string>
#include"CEmployee.h"
#include"CPerson.h"
using namespace std;

int main() {
    string name, id, department, sex, age, salary;
    cout << "input employee's name: ";
    cin >> name;
    cout << "input employee's id: ";
    cin >> id;
    cout << "input employee's sex: ";
    cin >> sex;
    cout << "input employee's age: ";
    cin >> age;
    cout << "input employee's department: ";
    cin >> department;
    cout << "input employee's salary: ";
    cin >> salary;
    CEmployee employee1(name, id, sex, age, department, salary);
    cout << employee1;
}