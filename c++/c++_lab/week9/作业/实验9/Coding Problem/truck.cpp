
// truck.cpp
#include <iostream>

using std::cout;
using std::endl;
#include "truck.h"

// constructor
Truck::Truck( double fuel )
   : Vehicle( 2, 16, 8 )
{
   setFuelLevel(fuel);
   setColor("black");
   cargo = false;
  
} // end class Truck constructor

// function hasCargo definition
bool Truck::hasCargo() const 
{
   return cargo;

} // end function hasCargo

// function setCargo definition
void Truck::setCargo( bool cargoValue ) 
{
   cargo = cargoValue;

} // end function setCargo

// function print definition
void Truck::print() const
{
    cout << "\tNumber of doors: " << getNumberOfDoors()
        << "\n\tNumber of cylinders: " << getNumberOfCylinders()
        << "\n\tTransmission type: " << getTransmissionType()
        << "\n\tColor: " << getColor()
        << "\n\tFuel level: " << getFuelLevel() << endl;
   
   if ( cargo )
      cout << "\tThe truck is currently carrying cargo.\n";

   else
      cout << "\tThe truck is currently not carrying cargo.\n";

   cout << "class name: " << getClassName() << "\n";

} // end function print

// function horn definition
void Truck::horn() const
{
   cout << "HOOOONK!"; 

} // end function horn

// return class name
string Truck::getClassName() const
{
   return "Truck";

} // end function getClassName

void Truck::setColor(string color)
{
    vehicleColor = color;

} // end function setColor

// function setFuelLevel definition
void Truck::setFuelLevel(double amount)
{
    // assume 20 gallons is a full tank
    if (amount > 0.0 && amount <= 20.0)
        fuelLevel = amount;
    else
        fuelLevel = 5.0;

} // end function setFuelLevel

// return color
string Truck::getColor() const
{
    return vehicleColor;

} // end function getColor

// return fuelLevel 
double Truck::getFuelLevel() const
{
    return fuelLevel;

} // end function getFuelLevel

// return transmissionType
int Truck::getTransmissionType() const
{
    return transmissionType;

} // end function getTransmissionType

// return numberOfDoors
int Truck::getNumberOfDoors() const
{
    return numberOfDoors;

} // end function getNumberOfDoors

// return numberOfCylinders
int Truck::getNumberOfCylinders() const
{
    return numberOfCylinders;

} // end function getNumberOfCylinders 



