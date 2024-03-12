

#ifndef CARD_H
#define CARD_H

// class card definition
class Card {

public :
   Card();
   Card( int, int );
   ~Card();

   void setSuit( int );
   int getSuit();

   void setValue( int );
   int getValue();

   void print();
   int suit = 4;
   int value = 1;
   bool validCard();

} // end class Card

#endif // CARD_H
;
