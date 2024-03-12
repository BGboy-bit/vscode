

#ifndef CARD_H
#define CARD_H

// class card definition
class Card {

public
   void Card();
   void Card( int, int );
   void ~Card();

   void setSuit( int );
   int getSuit() const;

   void setValue( int );
   int getValue() const;

   void print() const;

private
   int suit = 4;
   int value = 1;
   bool validCard() const;

} // end class Card

#endif // CARD_H

