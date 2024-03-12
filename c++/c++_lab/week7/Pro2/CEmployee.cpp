
// CEmployee.cpp
#include "CEmployee.h"

/* Write definition for class CEployee's constructor */
CEmployee::CEmployee(string n, string i, string s, string a, string d, string sa)
    :CPerson(n, i, s, a) {
    department = d; 
    salary = sa;
}// end class Truck constructor
// function hasCargo definition
CEmployee::~CEmployee() 
{
    cout << "EMployee destroyed";
} // end function hasCargo


// function operator<< definition
ostream& operator<<(ostream& output, const CEmployee& e)
{
    output << "Name: " << e.getName()
        << "\nidNumber: " << e.getidNumber()
        << "\nSex: " << e.getSex()
        << "\nAge: " << e.getAge()
        << "\nDepartment: " << e.department
        << "\nSalary: " << e.salary
        <<"\n";

    return output;

} // end function operator<<



