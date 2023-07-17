

#include <stdio.h>

//define the functions
void menu();
int getChoice();


//define the choices inputs
//typedef enum for menu choices
typedef enum
{
    Choice_1 = 1,
    Choice_2 = 2,
    Choice_3 = 3,
    Choice_4 = 4,
    Choice_5 = 5,
    Exit = 6
} choice_t;

int main
{
    int choice;

    do
    {
        /* code */

        choice = getChoice();

        if( choice != Exit)
        {
            //read the size

            //process the choice with a switch case
        }
    } while (choice != Exit);
    
    return 0;
}