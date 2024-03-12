
// taxi.cpp
#include <iostream>

using std::cout;

#include "taxi.h"

// constructor
Taxi::Taxi( double fuel )
   : Vehicle( 4, 6, "yellow", fuel, 5 )
{
   customers = false;

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

   Vehicle::print();

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




