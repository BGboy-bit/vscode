
// Debugging Problem (dog.h)

#ifndef DOG_H
#define DOG_H

#include "animal.h"
#include <string>
using std::string;
// class Dog definition
class Dog : public Animal {

public:
   Dog( int = 0, int = 0, string = "Toto" );
       
   void print() const;
   int getHeight() const;
   int getWeight() const;
   string getName() const;
   void setName( string );
   void setHeight(int);
   void setWeight(int);

private:
   bool useMetric( string ) const;
   string name;
   int metricHeight;
   int metricWeight;

}; // end class Dog

#endif // DOG_H



