
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

   void setColor(string color);
   string getColor() const;

   void setFuelLevel(double amount);
   double getFuelLevel() const;

   int getTransmissionType() const;
   int getNumberOfDoors() const;
   int getNumberOfCylinders() const;

   string getClassName() const;
   void horn() const;
   void print() const;

private:
   bool customers;

}; // end class Taxi

#endif // TAXI_H


