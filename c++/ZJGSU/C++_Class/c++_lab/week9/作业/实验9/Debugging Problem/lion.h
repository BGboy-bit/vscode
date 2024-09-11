
// Debugging Problem (lion.h)

#ifndef LION_H
#define LION_H

#include "animal.h"

// class Lion definition
class Lion : public Animal {

public:
   Lion( int = 0, int = 0 );
   int getWeight() const;
   int getHeight() const;
   void print() const;

}; // end class Lion

#endif // LION_H

