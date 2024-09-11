
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
   bool hasCustomers() const;
   /* Write prototype for setCustomers */
   void setCustomers(bool);

private:
   bool customers;

}; // end class Taxi

#endif // TAXI_H



