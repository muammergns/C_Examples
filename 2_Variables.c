#include <stdio.h>

char char_var = 'A';
int int_var = 10;
float float_var = 1.3f;
double double_var = 1.4;

enum suit { club, diamonds, hearts, spades};
enum suit clothes = club;

void long_variables()
{
    short a;
    long b;
    long long c;
    long double d;

    printf("size of short = %d bytes\n", sizeof(a));
    printf("size of long = %d bytes\n", sizeof(b));
    printf("size of long long = %d bytes\n", sizeof(c));
    printf("size of long double= %d bytes\n", sizeof(d));
}

int main()
{
    printf("char value: %c \n",char_var);
    printf("int value: %d \n", int_var);
    printf("float value: %f \n",float_var);
    printf("double value: %f \n",double_var);

    printf("enum value: %d \n",clothes);

    long_variables();
    return 0;
}



