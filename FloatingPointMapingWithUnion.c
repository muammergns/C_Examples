#include <stdio.h>

union Foo
{
   unsigned short asShorts[2];
   float asFloat;
} foo, bar;

int main()
{
   // Convert a float into two shots
   //Test foo;
   foo.asFloat = 3.14159f;
   printf("For float value %f, the shorts are %u and %u\n", foo.asFloat, foo.asShorts[0], foo.asShorts[1]);

   // [... send the two asShorts values across the serial port here...]


   // Imagine this is the receiving-side code (after having received the two shorts)
   const unsigned short s1 = foo.asShorts[0];
   const unsigned short s2 = foo.asShorts[1];

   // Convert the two shorts back into a float
   //Foo bar;
   bar.asShorts[0] = s1;
   bar.asShorts[1] = s2;
   printf("For shorts %u and %u, the float value is %f\n", s1, s2, bar.asFloat);


   return 0;
}