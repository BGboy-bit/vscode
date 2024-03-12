

#include <iostream>

using std::cout;
using std::endl;

// default constructor
void Card::Card() 
{
   suit = 4; 
   value = 1;

} // end class Card constructor

// constructor
Card::Card( int s, int v ) 
{
   suit = s; value = v;

} // end class Card constructor

// destructor
Card::~Card() 
{
   cout << "The destructor has been invoked\n";

} // end class Card destructor

// set suit
void Card::setSuit( int s ) 
{
   suit = s;

} // end function setSuit

// set value
void Card::setValue( int v ) 
{
   value = v;

} // end function setValue

// function print definition
void print()
{
   // is card valid
   if ( !validCard() ) {
      cout << "This card is not valid\n";
      return;

   } // end if

   cout << "This is the: ";

   // determine face of card
   switch ( value ) {
      case 1:
         cout << "Ace ";
         break;

      case 11:
         cout << "Jack ";
         break;

      case 12:
         cout << "Queen ";
         break;

      case 13:
         cout << "King ";
         break;

      default:
         cout << value << " ";

   } // end switch

   // determine suit
   switch ( suit ) {
      case 1:
         cout << "of clubs\n";
         break;

      case 2:
         cout << "of diamonds\n";
         break;

      case 3:
         cout << "of hearts\n";
         break;

      case 4:
         cout << "of spades\n";
         break;

      default:
         cout << "\ninvalid suit\n";

   } // end switch

} // end function print

// return suit
int Card::getSuit() 
{
   return suit; 

} // end function getSuit

// return value
int Card::getValue() 
{
   return value;

} // end function getValue

// function validCard definition
bool validCard()
{
   return value >= 1 && value <= 13 && suit >= 1 && suit <= 4;

} // end function validCard

