#include <stdio.h>
#include <string.h>
#include "MyLibrary.h"

void strcopy(char source[], char* destination){
    int size = strlen(source);
    printf("Source size:%d\n",size);
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
    printf(*destination);
}

int main(){
    printf("Hello:%d\n",getMyDamnNumber());
    char name[50];
    name[49] = 'A';
    strcopy("Muammer",&name);
    return 0;
}