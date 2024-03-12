
// driver for inheritance hierarchy
//#include <iostream>
#include <bits/stdc++.h>
using std::cout;
using std::endl;

#include "vehicle.h"
#include "taxi.h"
#include "truck.h"

int main()
{
   Vehicle car( 2, 6, "blue", 14.6, 3 );
   Taxi cab( 3.3 );
   Truck mack( 7.54 );

   /* Write code to indicate that mack is carrying cargo */
   mack.setCargo(true);
   
   /* Write code to print all objects in the Vehicle hierarchy */
   cout << car << cab << mack;
   return 0;

} // end main



