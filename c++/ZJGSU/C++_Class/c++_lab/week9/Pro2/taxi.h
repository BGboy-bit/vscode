
// taxi.h
#ifndef TAXI_H
#define TAXI_H

#include <iostream>

#include "vehicle.h"

// class Taxi definition
class Taxi : public Vehicle {

public:
   Taxi( double );

   bool hasCustomers() const;
   void setCustomers( bool );

   /* Write prototype for virtual function horn */

   virtual void print() const;
   void horn() const;
   virtual string getClassName() const;

private:
   bool customers;

}; // end class Taxi

#endif // TAXI_H


