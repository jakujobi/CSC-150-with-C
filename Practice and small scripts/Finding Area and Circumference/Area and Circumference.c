//This program calculates the area and circumference of a circle using functions defined
//Created by John Akujobi on 9/15/22.
//CSC 150 - S01


#include <stdio.h>
#include <math.h>
void area_of_circle (float);
void circumference_of_circle (float);

int main (void)
{
//define PI as a constant
#define PI 3.14159265

//define the variables
float radius, area, circumference;

//define the functions
//float area_of_circle(float radius);
//float circumference_of_circle(float radius);

//ask the user for the radius of the circle
printf(" What is the radius of the circle?\n");
scanf("%f", &radius);

//calculate the area of the circle
area = area_of_circle(radius);

//calculate the circumference of the circle
circumference = circumference_of_circle(radius);

//print the area and circumference of the circle
printf("______________________________________________________________________\n");
printf("\n");
printf("The area of the circle is %f \n", area);
printf("The circumference of the circle is %f \n", circumference);
printf("\n");
printf("______________________________________________________________________\n");

return 0;
}