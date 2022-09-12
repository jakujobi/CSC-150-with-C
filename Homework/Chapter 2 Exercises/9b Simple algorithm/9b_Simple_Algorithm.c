//This program takes an integer from the user, doubles it, subtracts 10 from it, and displays the result.
//Created by: John Akujobi on 9/11/2022
//CSC 150 - S01

#include <stdio.h>
int main (void)
{
//define the variables
//number is the integer being calculated on
//result is the result of the calculation
//both are integers
    int number, result;

//ask the user for an integer number
    printf("Type a number (no decimal points): \n");
    scanf("%d", &number);
   
//Perform the calculation
//result = (number *2)-10
    result = ((number *2)-10);

//print result to the user
    printf("The result of the calculation is %d", result);
    printf("\n");
    return (0);
}
