
// driver for vehicle
#include <iostream>

using std::cout;
using std::endl;

#include <vector>

using std::vector;

#include "vehicle.h"
#include "taxi.h"
#include "truck.h"

int main()
{
   Taxi cab( 3.3 );
   Truck mack( 7.54 );

   /* Write code to indicate that truck is carrying cargo */

   /* Declare a vector, parkingLot, of base-class pointers */
   vector<Vehicle*> parkingLot(2);
   parkingLot[ 0 ] = &cab;
   parkingLot[ 1 ] = &mack;

   cout << "\nThe vehicles cannot get out of their parking spaces because of "
        << "traffic,\nso they respond: \n";

   for ( int i = 0; i < parkingLot.size(); i++ ) {

      /* Write code to call member function horn */
        parkingLot[i]->horn();
        cout << endl;

      /* Write code to display information about the vehicle honking its horn */
        parkingLot[i]->print();
        cout << endl;

   } // end for

   return 0;

} // end main



