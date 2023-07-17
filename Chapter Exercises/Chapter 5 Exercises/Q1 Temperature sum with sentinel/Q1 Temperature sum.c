/*
Program that computes and displays the sum of a collection of Celsius temperatures entered at the terminal
until a sentinel value of -275 is entered.

Created by: John Akujobi
Date: 30th October 2022
CSC 150 S03
*/

#include <stdio.h>

void ProgramGreeting(void);//Function prototype of the greetings function

int main ()
{
    //Variable declaration
    int temp, temp_sum = 0;

    //Call the greetings function
    ProgramGreeting();
    

    //it checks and makes sure that the temp is not the sentinel value of -275 is entered.
    while (temp != -275)
    {
        //Asks the user to enter a temperature
        printf("\nEnter a temperature in Celsius --->: ");
        scanf("%d", &temp);

        //Tried to apply input validation but it didn't work
        //while (temp/temp != 1 && check = 1)
        //{
        //    printf("Invalid input. Please enter a valid temperature: ");
        //}

        //increments temp_sum by the value of temp
        temp_sum += temp;
        printf("The sum so far is %5d\n",temp_sum);
    }

    //prints the final sum
    printf("\nThe total sum of the temperatures is %8d\n\n", temp_sum);

    return 0;
}

//Greets the user and tells them what the program does
void ProgramGreeting()
{
    printf("\nHello\nThis program computes the sum of a collection of Celsius temperatures entered at the terminal\n");
    printf("Until a value of -275 is entered.\nAnd it gives you the total sum\n\n");
    return 0;
}