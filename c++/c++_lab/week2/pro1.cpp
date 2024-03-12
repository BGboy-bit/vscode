// Debugging Problem

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cstring>

/// @brief 
/// @param  
/// @param  
void initialize( char [], int * );
void input( char [], int & );
void print( const char *, const int );
void growOlder( const char [], int * );
int comparePeople( const char *, const int *,
                    const char *, const int * );
void add(int &, int num = 5);

int main()
{
   char name1[ 25 ]; 
   char name2[ 25 ];
   int age1;
   int age2;

   initialize( name1, &age1 );
   initialize( name2, &age2 );

   print( name1, age1 );
   print( name2, age2 );

   input( name1, age1 );
   input( name2, age2 );

   print( name1, age1 );
   print( name2, age2 );

   while(comparePeople( name1, &age1, name2, &age2 ) != 0) {
      if ( comparePeople( name1, &age1, name2, &age2 ) == 0)
         break;
      else if(comparePeople( name1, &age1, name2, &age2 ) == 1) 
         growOlder( name2, &age2 );
      else growOlder( name1, &age1 );
   }
   if(strcmp(name1, name2)) strcpy(name1, name2);
   cout << "Both people have the same name and age" << endl;
   return 0;

} // end main

// function input definition
void input(char name[], int &age )
{
   cout << "Enter a name: ";
   cin >> name;

   cout << "Enter an age: ";
   cin >> age;
   cout << endl;

} // end function input

// function initialize definition
void initialize( char name[], int *age )
{
   //name = "";
   strcpy(name, "");
   *age = 0;

} // end function initialize

// function print definition
void print( const char name[], const int age )
{
   cout << "The value stored in variable name is: "
        << name << endl
        << "The value stored in variable age is: "
        << age << endl << endl;

} // end function print

// function growOlder definition
void growOlder( const char name[], int *age )
{
   cout << name << " has grown one year older\n\n";
   *age = *age + 1;

} // end function growOlder

// function comparePeople definition
int comparePeople( const char *name1, const int *age1,
                    const char *name2, const int *age2 )
{
   if(*age1 == *age2) return 0;
   else if(*age1 > *age2) return 1;
   else return 2;

} // end function comparePeople

void add(int &a, int num)
{

   a += num;
}