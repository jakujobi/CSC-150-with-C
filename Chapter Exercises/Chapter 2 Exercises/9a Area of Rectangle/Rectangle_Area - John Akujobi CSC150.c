//This program calculates the area of a rectangle of any given length and width provides by the user.
//Created by: John Akujobi on 9/11/2022
//CSC 150 - S01

#include <stdio.h>
int main (void)
{
//define the variables
    float r_breadth, r_length, r_area;
//ask the user for the rectangle's length and width
    printf("Type the length of the rectangle: \n");
    scanf("%f", &r_length);
    printf("Enter the breadth of the rectangle: \n");
    scanf("%f", &r_breadth);

//calculate the rectangles area
//Area of the rectangle = length * width
    r_area = r_length * r_breadth;

//print the area of the rectangle by returning the variable r_area to the user
    printf("The area of the rectangle is %f", r_area);
    printf("\n");
    return (0);
}
