//program that calculates the square root of a number
//from  
//
//  Created by John Akujobi on 9/10/20.
//  CSC 150 - S01
//
#include <stdio.h>
#include <math.h>

int main (void)
{
    //define the variables
    float number, square_root;
    char end;
    
    //ask the user for the number
    printf("What number would you like to find the square root of? \n");
    scanf("%f", &number);
    
    //calculate the square root of the number
    square_root = sqrt(number);
    
    //print the square root of the number
    printf("The square root of %f is %f \n", number, square_root);
    
    //ask the user to press enter to exit the program
    printf("Press enter to exit the program \n");
    scanf("%c", &end);
    scanf("%c", &end);
    
    return 0;
}