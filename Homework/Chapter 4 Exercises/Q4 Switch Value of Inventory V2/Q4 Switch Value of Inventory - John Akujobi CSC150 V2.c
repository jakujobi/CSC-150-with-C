/*
Write a switch statement to select an operation based on the value of inventory.

Increment total_paper by paper_order if inventory is 'B' or 'C' ;
Increment total_ribbon by ribbon_order if inventory is 'E' , 'F' , or 'D' ;
increment total_label by label_order if inventory is 'A' or 'X' .

Do nothing if inventory is 'M' .

Display an error message if the value of inventory is not one of these eight letters.

Created by John Akujobi
On 10th October 2022
CSC 150 S01
*/

#include <stdio.h>

int main ()
{
    char inventoryValue, key;
    int total_paper, paper_order, total_ribbon, ribbon_order, total_label, label_order;

    printf ("What's the inventory value (A,B,C,D,E,F,M,X) --->:");
    scanf ("%c", &inventoryValue);

    switch (inventoryValue)
    {
        //Check if inventory value is equal to B or C
        //If it is, increment total_paper by paper_order
        case 'B':
        case 'C':
            total_paper += paper_order;
            break;

        //Check if inventory value is equal to E, F or D
        //If it is, increment total_ribbon by ribbon_order
        case 'E':
        case 'F':
        case 'D':
            total_ribbon += ribbon_order;
            break;

        //Check if inventory value is equal to A or X
        //If it is, increment total_label by label_order
        case 'A':
        case 'X':
            total_label += label_order;
            break;

        //Check if inventory value is equal to M
        //If it is, do nothing
        case 'M':
            break;
        default:
            printf ("\nInvalid Input\nPlease use on of these letters (A,B,C,D,E,F,M,X)");
            break;


    }
    

/*
    //Check if inventory value is A,B,C,D,E,F,M or X

    //Check if inventory value is equal to B or C
    //If it is, increment total_paper by paper_order
    if (inventoryValue == 'B' || 'C')
    {
        total_paper= total_paper + paper_order;
        //printf ("B or C");
    }

    //Check if inventory value is equal to E, F or D
    //increment total_ribbon by ribbon_order
    else if (inventoryValue == 'E' || 'F' || 'D')
    {
        total_ribbon = total_ribbon + ribbon_order;
        //printf ("E, F or D");
    }

    //Check if inventory value is equal to A or X
    //Increase total_label by label_order
    else if (inventoryValue == 'A' || 'X')
    {
        total_label = total_label + label_order;
        //printf ("A or X");
    }

    //Check if inventory value is equal to M
    //Do nothing
    else if (inventoryValue == 'M')
    {
        //printf ("M");
    }

    else
    {
        printf ("\nInvalid Input\nPlease use on of these letters (A,B,C,D,E,F,M,X)");
    }
*/

    return 0;
}