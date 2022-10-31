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

    //Asks the user to enter a number
    printf("Enter a number between 0 and 15: ");
    scanf("%d", &num);

    //Checks if the number is in the range 0 to 15
    do
    {
        if (num < 0 || num > 15 || num != num)
        {
            printf("Whoops! Invalid input.\n Please enter a number between 0 and 15: ");
            scanf("%d", &num);
        }

        printf("The number you entered is %d\n", num);
        
    } while (num < 0 || num > 15);

    return (0);
}