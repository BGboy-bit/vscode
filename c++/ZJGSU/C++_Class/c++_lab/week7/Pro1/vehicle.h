
// vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

using std::ostream;

#include <string>

using std::string;

// class Vehicle definition
class Vehicle {
   friend ostream& operator<<( ostream &, const Vehicle & );

public:
   Vehicle( const int, const int, string, double, const int ); 
   
   void setColor( string );
   string getColor() const;

   void setFuelLevel( double );
   double getFuelLevel() const;

   void setClassName( string );
   string getClassName() const;

   int getTransmissionType() const;
   int getNumberOfDoors() const;
   int getNumberOfCylinders() const; 

private:
   const int numberOfDoors;
   const int numberOfCylinders;
   string vehicleColor;
   double fuelLevel;
   const int transmissionType;
   string className;

}; // end class Vehicle

#endif // VEHICLE_H




