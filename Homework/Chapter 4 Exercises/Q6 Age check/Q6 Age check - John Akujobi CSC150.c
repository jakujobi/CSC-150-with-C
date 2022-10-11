/*


*/

#include <stdio.h>

void main()
{
    printf("\nWhats your age? --->:");
    int userAge;
    char sts = 'W';
    scanf("%d", &userAge);

    //Checks if the user is older than 59
    if (userAge > 59)
    {
        //Checks if sts is equal to W
        if (sts == 'W')
        {
            printf("\nWorking senior\n");
        }

        //Prints Retired senior if sts is not equal to W
        else
        {
            printf("\nRetired senior\n");
        }
    }

    else
    {   
        //checks if user is younger than 59 but older than 20
        //Then prints Adult
        if (userAge > 20 && userAge < 59)
        {
            printf("\nAdult\n");        
        }
        else
        {
            //checks if user is younger than 20 but older than 12
            //Then prints Teenager
            if (userAge > 12 && userAge < 20)
            {
                printf("\nTeen\n");
            }

            //Prints Child if user is younger than 12
            else
            {
                printf("\nChild\n");
            }

        }
    }

    return;
}