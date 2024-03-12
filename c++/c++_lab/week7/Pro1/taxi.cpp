
// taxi.cpp
#include "taxi.h"

// constructor
Taxi::Taxi( double f )
   : Vehicle( 4, 6, "yellow", f, 5 )
{
   customers = false;
   setClassName( "Taxi" );

} // end class Taxi constructor

/* Write definition for setCustomers */
void Taxi::setCustomers(bool f) {
    customers = f;
}
/* Write definition for hasCustomers */
bool Taxi::hasCustomers() const{
    return customers;
}

// function operator<< definition
ostream &operator<<( ostream &output, const Taxi &t )
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

   if (t.customers)
      output << "\tThe taxi has passengers.\n";

   else
      output << "\tThe taxi has no passengers.\n";

   return output;

} // end function operator


