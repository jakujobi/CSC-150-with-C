/*

Write a function called letter_grade that has a type int input parameter called points
and returns through an output parameter gradep the appropriate letter grade using a straight scale (90–100 is an A, 80–89 is a B, and so on).
Return through a second output parameter ( just_missedp ) an indication of whether the student just missed the next higher grade (true for 89, 79, and so on).

*/

#include <stdio.h>
#include <stdlib.h>

void letter_grade (int points, char *gradep, int *just_missedp);

int main ()
{
    //declare variables
    int points, just_missed;
    char grade;

    //prompt user for input
    printf ("Enter points: ");
    scanf ("%d", &points);

    //call letter_grade function
    letter_grade (points, &grade, &just_missed);

    printf ("Grade: %c\n", grade);
    if (just_missed == 1)
    {
        printf ("(Just missed)\n");
    }
    
    return 0;
}


void letter_grade (int points, char *gradep, int *just_missedp)
{
    //In the straight scale, 90–100 is an A, 80–89 is a B, 70–79 is a C, 60–69 is a D, and 0–59 is an F.
    //Use the else statement to check for invalid input.

    *just_missedp = 0;

    //checks for A grade (90-100)
    if (points >= 90 && points <= 100)
    {
        *gradep = 'A';
    }

    //checks for B grade (80 - 89)
    else if (points >= 80 && points <= 89)
    {
        *gradep = 'B';
    }

    //checks for C grade (70 - 79)
    else if (points >= 70 && points <= 79)
    {
        *gradep = 'C';
    }

    //checks for D grade (60 - 69)
    else if (points >= 60 && points <= 69)
    {
        *gradep = 'D';
    }

    //checks for F grade (0 - 59)
    else if (points >= 0 && points <= 59)
    {
        *gradep = 'F';
    }

    //Catches grades above 100
    //Accepts the grade (for cases of extra points)
    //But also informs the user about it
    else if (points > 100)
    {
        *gradep = 'A';
        printf ("This student has a grade above 100 (Points = %d)\n", points);
    }

    //Using this to catch any other values that are not in the range of 0-100
    else
    {
        *gradep = 'X';
        printf("\nOops!Invalid input.\nPlease enter a number between 0 and 100.\n");
        exit (101);
    }

    //checks if the student just missed the next higher grade
    //Didn't use (points % 10 == 9) in the case the student had 109 points brought by extra-points or 99 points
    if (points == 89 || points == 79 || points == 69 || points == 59)
    {
        *just_missedp = 1;
    }

    return;
}