/*
This program calculates the slope of a line given 4 numbers and prints the slope
until the user enters 4 numbers where the first two are the same.

Created by: John Akujobi
Date: 30th October 2022
CSC 150 S03
*/

#include <stdio.h>
#define SPECIAL_SLOPE 0.0

int main(void)
{
	//Variable declaration
	double slope, y2, y1, x2, x1;

	//Tells the user what the program does and how to use it
	printf("Enter 4 numbers separated by spaces.\n");
	printf("E.g 2 4 6 8 which represents y2 y1 x2 x1\n");
	printf("\nThe last two numbers cannot be the same,");
	printf("\nbut the program terminates if the first two are.\n");

	//Asks the user to enter 4 numbers
	printf("\nEnter four numbers --> ");
	scanf("%lf%lf%lf%lf", &y2, &y1, &x2, &x1);

	//calculates the slope
	slope = (y2 - y1) / (x2 - x1);

	while (slope != SPECIAL_SLOPE)
	{
		//prints the slope from the last numbers entered
		printf("Slope is %5.2f.\n", slope); //Slope is  0.50.

		//asks the user to enter 4 more numbers to calculate another slope
		printf("\nEnter four more numbers> ");
		scanf("%lf%lf%lf%lf", &y2, &y1, &x2, &x1);

		//calculates the slope
		slope = (y2 - y1) / (x2 - x1);
	}

	return (0);
}