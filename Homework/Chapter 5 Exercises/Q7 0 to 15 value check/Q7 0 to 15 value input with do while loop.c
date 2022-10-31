/*
Write a do-while loop that repeatedly prompts for and takes input until a value in the range 0 through 15 inclusive is input.
Include code that prevents the loop from executing forever on input of a wrong data type.

Created by: John Akujobi
Date: 30th October 2022
CSC 150 S03
*/

#include <stdio.h>

int main(void)
{
    //Declare my variable
    int num;

    //Checks if the number is in the range 0 to 15
    do
    {
        int num = 0; //initializes num to 0

        //Asks the user to enter a number for the first time
        printf("Enter a number between 0 and 15: ");
        scanf("%d", &num);

        //Checks if the number is in the range 0 to 15
        if (num*1 < 0 || num*1 > 15)
        {
            //Print error message
            //And ask the user to enter a number again
            printf("Whoops! Invalid input.\n");
            printf("Please Enter a number between 0 and 15: ");
            scanf("%d", &num);
        }

        //printf("The number you entered is %d\n", num);

    } while (num*1 < 0 || num*1 > 15);

    return (0);
}