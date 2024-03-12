
// vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

#include <string>

using std::string;

// class Vehicle definition
class Vehicle {

public:
	// constructor
	Vehicle(const int doors, const int cylinders,
		string color, double initialFuel,
		const int transmission)
		: numberOfDoors(doors), numberOfCylinders(cylinders),
		transmissionType(transmission)
	{

	} // end class Vehicle constructor

   virtual void setColor( string color ) = 0; 
   virtual string getColor() const = 0;

   virtual void setFuelLevel( double amount ) = 0;
   virtual double getFuelLevel() const = 0;

   virtual int getTransmissionType() const = 0;
   virtual int getNumberOfDoors() const = 0;
   virtual int getNumberOfCylinders() const = 0; 

   virtual string getClassName() const = 0;
   
   /* Write prototype for pure virtual function horn */ 
   virtual void horn() const = 0;
   /* Write prototype for virtual function print     */ 
   virtual void print() const = 0;

   const int numberOfDoors;
   const int numberOfCylinders;
   string vehicleColor;
   double fuelLevel;
   const int transmissionType;

}; // end class Vehicle

#endif // VEHICLE_H




