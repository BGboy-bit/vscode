
// vehicle.cpp
#include <iostream>

using std::cout;
using std::endl;

#include "vehicle.h"

// constructor
Vehicle::Vehicle( const int doors, const int cylinders, 
   string color, double initialFuel, 
   const int transmission ) 
   /* Write the body for Vehicle's constructor */
 
} // end class Vehicle constructor

// function operator<< definition
ostream &operator<<( ostream &out, const Vehicle &v )
{
   out << v.className << "\n"
	       << "\tNumber of doors: " << v.numberOfDoors
	    << "\n\tNumber of cylinders: " << v.numberOfCylinders
	    << "\n\tTransmission type: " << v.transmissionType
 	   << "\n\tColor: " << v.vehicleColor
	    << "\n\tFuel level: " << v.fuelLevel << endl;

   return out;

} // end function operator<<

/* Write definition for setColor */

// function setFuelLevel definition
void Vehicle::setFuelLevel( double amount )
{
   // assume 20 gallons is full tank
   if ( amount > 0.0 && amount <= 20.0 ) 
      fuelLevel = amount;

   else
      fuelLevel = 5.0;

} // end function setFuelLevel

// return color
string Vehicle::getColor() const
{   
   return vehicleColor;

} // end function getColor
 
// return fuelLevel
double Vehicle::getFuelLevel() const
{
   return fuelLevel;

} // end function getFuelLevel

// return transmissionType
int Vehicle::getTransmissionType() const
{
   return transmissionType;

} // end function getTransmissionType
   
// return numberOfDoors
int Vehicle::getNumberOfDoors() const
{
   return numberOfDoors;

} // end function getNumberOfDoors

// return numberOfCylinders
int Vehicle::getNumberOfCylinders() const
{
   return numberOfCylinders;   

} // end function getNumberOfCylinders

// function setClassName definition
void Vehicle::setClassName( string newName )
{
   className = newName;

} // end function setClassName

// return className
string Vehicle::getClassName() const  
{
   return className;

} // end function getClassName


