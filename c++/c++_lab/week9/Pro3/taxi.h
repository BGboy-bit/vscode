
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

   void print() const;
   void horn() const;
   string getClassName() const;

   void setColor(string color);

   void setFuelLevel(double amount);

   string getColor() const;

   double getFuelLevel() const;

   int getTransmissionType() const;

   int getNumberOfDoors() const;

   int getNumberOfCylinders() const;

private:
   bool customers;

}; // end class Taxi

#endif // TAXI_H


