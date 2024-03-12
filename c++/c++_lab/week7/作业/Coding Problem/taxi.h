
// taxi.h
#ifndef TAXI_H
#define TAXI_H

#include <iostream>

#include "vehicle.h"

// class Taxi definition
class Taxi : public Vehicle {
   friend ostream& operator<<( ostream &, const Taxi & );

public:
   Taxi( double );
   /* Write prototype for hasCustomers */
   /* Write prototype for setCustomers */

private:
   bool customers;

}; // end class Taxi

#endif // TAXI_H



