/*
This program is a practice play with loops

Created by John Akujobi
On 18th October 2022
CSC 150 S01

*/

#include <stdio.h>

int main ()
{
    //loop control variable
    int num;

    //write a loop to print the numbers 1-100
    num = 0;    //initialize the loop control variable
    printf ("\n");
    printf ("%d", num);

    //while num is less than 10, add 1 to num and print it
    while (num <= 100) //check the variable state

    {
        num++; //change the variable state
        printf ("%3d", num);
    }

    //add an empty line after the printed 
    printf ("\n\n");



    //write a loop to print the numbers 100-0
    num = 100;    //initialize the loop control variable

    //while num is greater than 1, subtract 1 from num and print it
    while (num >= 0) //check the variable state

    {
        printf ("%3d", num);
        num--; //change the variable state
    }


    return 0;
}