
// truck.h

#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>

#include "vehicle.h"

// class Truck definition
class Truck : public Vehicle {
	friend ostream& operator<<( ostream &, const Truck &);

public:
	Truck(double);
	bool hasCargo() const;
	void setCargo(bool);

private:
	bool cargo;

}; // end class Truck

#endif // TRUCK_H

/* Write contents of truck.h, which defines class Truck */


