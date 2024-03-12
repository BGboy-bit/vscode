
// truck.cpp
#include <iostream>

using std::cout;

#include "truck.h"

// constructor
Truck::Truck( double fuel )
   : Vehicle( 2, 16, "black", fuel, 8 )
{
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
   Vehicle::print();
   
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


