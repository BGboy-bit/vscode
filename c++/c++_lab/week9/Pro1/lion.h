
// Debugging Problem (lion.h)

#ifndef LION_H
#define LION_H

#include "animal.h"

// class Lion definition
class Lion : public Animal {

public:
   Lion( int = 0, int = 0 );

   void print() const;
   int getHeight() const;
   int getWeight() const;

}; // end class Lion

#endif // LION_H

