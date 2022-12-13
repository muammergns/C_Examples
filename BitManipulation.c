#include <stdio.h>

int num[4];

int getBit ( int k, int p )
{
    int i = ( k & ( 1 << p ) ) >> p;
    if (i==0)
    {
        return 0;
    }
    return 1;
}

int setBit ( int k, int p )
{
    k |= 1 << p;
    return k;
}

int resetBit ( int k, int p )
{
    k &= ~ ( 1 << p );
    return k;
}

int toggleBit ( int k, int p )
{
    k ^= 1 << p;
    return k;
}

int main(){
    int position = 94;
    int number = setBit(num[position/32],position%32);
    num[position/32] = number;
    int result = getBit(num[position/32],position%32);
    printf("Number:%d Position:%d Result:%d",number,position,result);
    return 0;
}