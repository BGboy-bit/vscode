// Chapter 6 of C++ How to Program
// Debugging Problem

#include <iostream>

using std::cout;
using std::endl;

int main()
{
   Card c1;
   Card c2( 3, 4 );
   Card c3( 1, 14 );

   Card *p1 = &c2;

   c1.print();
   c2.print();
   c3.print();
   p1->print();
   cout << endl;

   c1.setSuit( p1->getSuit() );
   c3.value = 12;
   p1->value = 5;
   
   c1.print();
   c2.print();
   c3.print();
   *p1.print();
   cout << endl;

   return 0;

} // end main

