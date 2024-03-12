
// vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

#include <string>

using std::string;

// class Vehicle definition
class Vehicle {

public:
   Vehicle( const int doors, const int cylinders, 
      string color, double initialFuel, 
		      const int transmission );

   void setColor( string color ); 
   string getColor() const;

   void setFuelLevel( double amount );
   double getFuelLevel() const;

   int getTransmissionType() const;
   int getNumberOfDoors() const;
   int getNumberOfCylinders() const; 

   virtual string getClassName() const;
   
   /* Write prototype for pure virtual function horn */ 
   virtual void horn() const=0;
   /* Write prototype for virtual function print     */ 
   virtual void print() const;

private:
   const int numberOfDoors;
   const int numberOfCylinders;
   string vehicleColor;
   double fuelLevel;
   const int transmissionType;

}; // end class Vehicle

#endif // VEHICLE_H




