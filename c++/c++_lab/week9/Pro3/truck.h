
// truck.h
#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>

#include "vehicle.h"

// class Truck definition
class Truck : public Vehicle {

public:
   Truck( double );

   bool hasCargo() const;
   void setCargo( bool );

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
   bool cargo;

}; // end class Truck

#endif // TRUCK_H



