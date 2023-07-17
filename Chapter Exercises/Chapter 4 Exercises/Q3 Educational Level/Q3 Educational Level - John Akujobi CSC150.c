/*
Write a multiple-alternative if statement to display a message indicating the educational level of a student
based on the student’s number of years of schooling
(0, none; 1–5,
Elementary school;
6–8, middle school;
9–12, high school;
more than 12, college).

Print a message to indicate bad data as well.

Created by John Akujobi
10th of October 2022
CSC 150 S03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int main ()
{

//Ask the user to enter the number of years of schooling

int numSchool;

printf ("\nType the number of years of schooling: ");
scanf ("%d", &numSchool);
//Prints None if the user has 0 years of schooling
if (numSchool == 0)
{
    printf ("None - There's no Educational level");
}

//Prints Elementary school if the user has 1-5 years of schooling
else if (numSchool >= 1 && numSchool <= 5)
{
    printf ("\nYou're at a Elementary school level");
}

//Prints Middle school if the user has 6-8years of schooling
else if (numSchool >= 6 && numSchool <= 8)
{
    printf ("\nYou're at a Middle school level");
}

//Prints High school if the user has between 9 - 12 years of schooling
else if (numSchool >= 9 && numSchool <= 12)
{
    printf ("\nYou're at a High school level");
}

//Prints you're in college if the user has 
else if (numSchool > 12)
{
    printf ("\nYou're at a College level");
}

//Prints Bad data
else
{
    printf ("Whoops, Bad data");
}

return 0;

}
