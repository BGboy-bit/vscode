
// Debugging Problem (animal.h)

#ifndef ANIMAL_H
#define ANIMAL_H

// Note: class Animal is an abstract class
// class Animal definition
class Animal {

public:
   Animal( int = 0, int = 0 );

   virtual void setHeight( int );
   virtual int getHeight() const = 0;

   virtual void setWeight( int );
   virtual int getWeight() const = 0;

   virtual void print() const = 0;   

private:
   int height;
   int weight;

}; // end class Animal

#endif // ANIMAL_H


