/*
This program prints patterns using asterisks and a number based on the user's input.

Pattern 1	Pattern 2	Pattern 3	Pattern 4
* 7 7 7 7 7 7	* * * * * * *	7 7 7 7 7 7 7	* * * * * * 7
7 * 7 7 7 7 7	* 7 7 7 7 7 *	7 * * * * * 7	* * * * * 7 *
7 7 * 7 7 7 7	* 7 7 7 7 7 *	7 * * * * * 7	* * * * 7 * *
7 7 7 * 7 7 7	* 7 7 7 7 7 *	7 * * * * * 7	* * * 7 * * *
7 7 7 7 * 7 7	* 7 7 7 7 7 *	7 * * * * * 7	* * 7 * * * *
7 7 7 7 7 * 7	* 7 7 7 7 7 *	7 * * * * * 7	* 7 * * * * *
7 7 7 7 7 7 *	* * * * * * *	7 7 7 7 7 7 7	7 * * * * * *

printf ("Pattern 1	    Pattern 2	    Pattern 3	    Pattern 4   \n ");
printf ("* 7 7 7 7 7 7	* * * * * * *	7 7 7 7 7 7 7	* * * * * * 7 \n ");
printf ("7 * 7 7 7 7 7	* 7 7 7 7 7 *	7 * * * * * 7	* * * * * 7 * \n ");
printf ("7 7 * 7 7 7 7	* 7 7 7 7 7 *	7 * * * * * 7	* * * * 7 * * \n ");
printf ("7 7 7 * 7 7 7	* 7 7 7 7 7 *	7 * * * * * 7	* * * 7 * * * \n ");
printf ("7 7 7 7 * 7 7	* 7 7 7 7 7 *	7 * * * * * 7	* * 7 * * * * \n ");
printf ("7 7 7 7 7 * 7	* 7 7 7 7 7 *	7 * * * * * 7	* 7 * * * * * \n ");
printf ("7 7 7 7 7 7 *	* * * * * * *	7 7 7 7 7 7 7	7 * * * * * * \n ");

*/

*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int size = 7;
    int row, col;

///*
    //Pattern 4
    int b = size;
    for (row = 1; row <= size; row++)
    {
        for (col = 1; col <= size; col++)
        {
            if ( row == (size-row+1) || col == (size-row+1))
            {
                printf("%3d", size);
            }
            else
            {
                printf("  *");
            }
        }
        printf("\n");
    }
//*/



/*
    //Pattern 1
    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            if (row == col)
            {
                printf("  *");
            }
            else
            {
                printf("%3d", size);
            }
        }
        printf("\n");
    }
*/


/*
    //Pattern 2
    for (row = 1; row <= size; row++)
    {
        for (col = 1; col <= size; col++)
        {
            if (row == 1 || row == size || col == 1 || col == size)
            {
                printf("  *");
            }
            else
            {
                printf("%3d", size);
            }
        }
        printf("\n");
    }
*/


/*
    //Pattern 3
    for (row = 1; row <= size; row++)
    {
        for (col = 1; col <= size; col++)
        {
            if (row == 1 || row == size || col == 1 || col == size)
            {
                printf("%3d", size);
            }
            else
            {
                printf("  *");
            }
        }
        printf("\n");
    }
*/

    return 0;
}