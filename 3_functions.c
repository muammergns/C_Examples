#include <stdio.h>

void print();// function prototype
void print_number(int number);
int get_number();

int main(){
    print();// function call
    print_number(100);
    printf("Get Number: %d\n",get_number());
    return 0;
}

void print(){// function definition   
    printf("Hello World!\n");
    // return statement
}

void print_number(int number){
    printf("Number: %d\n",number);
}

int get_number(){
    return 150;
}