
// CEmployee.h

#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H

#include <iostream>
#include <string>
#include "CPerson.h"

// class CEployee definition
class CEmployee : public CPerson {
	friend ostream& operator<<(ostream&, const CEmployee&);

public:
	CEmployee(string n, string i, string s, string a, string d, string sa);
	~CEmployee();
private:
	string department;
	string salary;

}; // end class Truck

#endif // TRUCK_H

/* Write contents of truck.h, which defines class Truck */


