/*
Program to learn if...else if constructs
Read a score from 0 to 100
Assign and print the corresponding grade using the straight A-F scale
90, 100 = A
80, 89 = B
70, 79 = C
60, 69 = D
0, 59 = F

Language: c
Created by John Akujobi
11th of October 2022
CSC 150 S03
*/

#include <stdio.h>
#include <stdlib.h>

char scoreToGrade (float score);

int main ()
{
    float score;
    char grade;

    printf ("\n\nEnter a score from 0 to 100 --->:");
    scanf ("%f", &score);

    grade = scoreToGrade (score);

    printf ("The grade is %c", grade);

    return 0;
}

char scoreToGrade (float score)
{
    char grade;

    if (score >= 0 && score <= 100)
    {
        if (score >= 90)
        {
            grade = 'A';
        }


        else if (score >= 80)
        {
            grade = 'B';
        }


        else if (score >= 70)
        {
            grade = 'C';
        }


        else if (score >= 60)
        {
            grade = 'D';
        }


        else
        {
            grade = 'F';
        }
    }


    else
    {
        grade = 'X';
        printf ("\nBad data\nMake sure the score is in range 0 to 100\n\n");
    }
    return grade;
}
