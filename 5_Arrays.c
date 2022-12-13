#include <stdio.h>

int array1[10];
int array2[] = {0,1,2,3,4,5,6,7,8,9};
int array3[10] = {0,1,2,3,4,5,6,7,8,9};
int array4[3][3] = {{0,1,2},{3,4,5},{6,7,8}};

int getAverage(){
    int average = 0;
    for (int i = 0; i < 10; i++)
    {
        average += array1[i];
    }
    return average/10;
}

const int CITY = 2;
const int WEEK = 7;
void printCityTempreture(){
    int temperature[CITY][WEEK];
    for (int i = 0; i < CITY; ++i) {
        for(int j = 0; j < WEEK; ++j) {
            printf("Şehir %d, Gün %d: ", i+1, j+1);
            //scanf("%d", &temperature[i][j]);
        }
    }

    printf("\nGösterilen Değer : \n\n");
    for (int i = 0; i < CITY; ++i) {
        for(int j = 0; j < WEEK; ++j)
        {
            printf("Şehir %d, Gün %d = %d\n", i+1, j+1, temperature[i][j]);
        }
    }
}

int main(){
    for (int i = 0; i < 10; i++)
    {
        array1[i] = i;
    }
    printf("array1 average: %d\n\n",getAverage());
    for (int j = 0; j < 10; j++)
    { 
        printf("array1 %d: %d\n",j,array1[j]);
    }
    printf("\n");
    for (int k = 0; k < 10; k++)
    {
        printf("array2 %d: %d\n",k,array1[k]);  
    }
    printf("\n");
    for (int l = 0; l < 10; l++)
    {
        printf("array3 %d: %d\n",l,array1[l]);
    }
    printf("\n");
    for (int m = 0; m < 3; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            printf("2D array4 m:%d n:%d number:%d\n",m,n,array4[m][n]);
        }
        
    }
    printCityTempreture();
}

