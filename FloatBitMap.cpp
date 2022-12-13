#include <iostream>
#include <cstdint>
union Foo
{
   uint16_t asShorts[2];
   float asFloat;
} foo, bar;
int main()
{
    foo.asFloat = 3.14159f;
    printf("For float value %f, the shorts are %u and %u\n", foo.asFloat, foo.asShorts[0], foo.asShorts[1]);

    const unsigned short s1 = foo.asShorts[0];
    const unsigned short s2 = foo.asShorts[1];

    // Convert the two shorts back into a float
    //Foo bar;
    bar.asShorts[0] = s1;
    bar.asShorts[1] = s2;
    //std::cout << "For float value " << foo.asFloat << " the shorts are " << foo.asShorts[0] << " and " << foo.asShorts[1] << '\n';
    printf("For shorts %u and %u, the float value is %f\n", s1, s2, bar.asFloat);
}