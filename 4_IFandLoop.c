#include <stdio.h>

int number = 0;

int main()
{
    //if örneği
    if (number == 0)
    {
        //for örneği
        for (int i = 0; i < 10; i++)
        {
            if (i==5)
            {
                number++;
                continue;
            }
            printf("Number for loop: %d\n",number);
            number++;
        }
        //while örneği
        while (number > 0)
        {
            printf("Number while loop: %d\n",number);
            if (number == 1)
            {
                break;
            }
            number--;
        }
        //do while örneği
        do
        {
            number--;
            printf("Number do while loop: %d\n",number);
        } while (number == 0);
        //switch örneği
        switch (number)
        {
        case 0:
            printf("Number for case 0: %d\n",number);
            break;
        
        default:
            printf("Number for case default: %d\n",number);
            break;
        }

    }
    


}