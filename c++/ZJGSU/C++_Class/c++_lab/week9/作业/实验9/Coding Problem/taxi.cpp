
// taxi.cpp
#include <iostream>

using std::cout;
using std::endl;
#include "taxi.h"

// constructor
Taxi::Taxi( double fuel )
   : Vehicle( 4, 6, 5 )
{
   customers = false;

   setFuelLevel(fuel);
   setColor("yellow");
} // end class Taxi constructor

// function setCustomers definition
void Taxi::setCustomers( bool c ) 
{
   customers = c;

} // end function setCustomers

// function hasCustomers definition
bool Taxi::hasCustomers() const 
{
   return customers;

} // end function hasCustomers

// function print definition
void Taxi::print() const
{
        cout << "\tNumber of doors: " << getNumberOfDoors()
            << "\n\tNumber of cylinders: " << getNumberOfCylinders()
            << "\n\tTransmission type: " << getTransmissionType()
            << "\n\tColor: " << getColor()
            << "\n\tFuel level: " << getFuelLevel() << endl;
   if ( customers )
      cout << "\tThe taxi currently has passengers.\n";

   else
      cout << "\tThe taxi currently has no passengers.\n";

   cout << "class name: " << getClassName() << "\n";

} // end function print

// function horn definition
void Taxi::horn() const
{
   cout << "beep beep";

} // end function horn

// return className
string Taxi::getClassName() const
{
   return "Taxi";

} // end function getClassName

// function setColor definition
void Taxi::setColor(string color)
{
    vehicleColor = color;

} // end function setColor

// function setFuelLevel definition
void Taxi::setFuelLevel(double amount)
{
    // assume 20 gallons is a full tank
    if (amount > 0.0 && amount <= 20.0)
        fuelLevel = amount;
    else
        fuelLevel = 5.0;

} // end function setFuelLevel

// return color
string Taxi::getColor() const
{
    return vehicleColor;

} // end function getColor

// return fuelLevel 
double Taxi::getFuelLevel() const
{
    return fuelLevel;

} // end function getFuelLevel

// return transmissionType
int Taxi::getTransmissionType() const
{
    return transmissionType;

} // end function getTransmissionType

// return numberOfDoors
int Taxi::getNumberOfDoors() const
{
    return numberOfDoors;

} // end function getNumberOfDoors

// return numberOfCylinders
int Taxi::getNumberOfCylinders() const
{
    return numberOfCylinders;

} // end function getNumberOfCylinders 






