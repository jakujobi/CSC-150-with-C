/*
Write an if statement that displays an acceptance message for an astronaut candidate
if the person’s weight is between the values of opt_min and opt_max inclusive,
if the person’s age is between age_min and age_max inclusive,
and if the person is a nonsmoker (Smoker is false).

Created by John Akujobi on 10th October 2022
CSC 150 S01
*/

#include <stdio.h>

int main ()
{
    int userWeight, userAge;
    int opt_min = 110, opt_max = 170, age_min = 20, age_max = 40;
    int Smoker = 0;

    printf ("Enter your weight in pounds --->:");
    scanf ("%d", &userWeight);

    printf ("Enter your age in years --->:");
    scanf ("%d", &userAge);

    if (userWeight >= opt_min && userWeight <= opt_max)
    {
        if (userAge >= age_min && userAge <= age_max)
        {
            if (Smoker == 0)
            {
                printf ("\nCongratulations!!!\nYou are accepted to be an astronaut\n\n");
            }
            else
            {
                printf ("Sorry, You are not accepted");
            }
        }

        else
        {
            printf ("Sorry, You are not accepted");
        }
    }

    else
    {
        printf ("Sorry, You are not accepted");
    }
    
    return 0;
}