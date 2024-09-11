
// truck.cpp
#include "truck.h"

/* Write definition for class Truck's constructor */
Truck::Truck(double f) 
    : Vehicle(4, 6, "yellow", f, 5) 
{
    cargo = false;
    setClassName("Truck");
}// end class Truck constructor
// function hasCargo definition
bool Truck::hasCargo() const
{
   return cargo;

} // end function hasCargo

// function setCargo definition
void Truck::setCargo( bool c ) 
{
   cargo = c;

} // end function setCargo

// function operator<< definition
ostream &operator<<( ostream &output, const Truck &t )
{
   output << t.getClassName() << "\n"
          << "\tNumber of doors: " 
          << t.getNumberOfDoors()
          << "\n\tNumber of cylinders: " 
          << t.getNumberOfCylinders()
          << "\n\tTransmission type: " 
          << t.getTransmissionType()
          << "\n\tColor: " << t.getColor()
          << "\n\tFuel level: " 
          << t.getFuelLevel() << "\n";

   if ( t.cargo )
      output << "\tThe truck is carrying cargo.\n";

   else
      output << "\tThe truck is not carrying cargo.\n";

   return output;

} // end function operator<<



