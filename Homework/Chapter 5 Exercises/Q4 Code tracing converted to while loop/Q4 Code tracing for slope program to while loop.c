#include <stdio.h>
#define SPECIAL_SLOPE 0.0

int main(void)
{

	double slope, y2, y1, x2, x1;
	printf("Enter 4 numbers separated by spaces.");
	printf("\nThe last two numbers cannot be the same,");
	printf("\nbut the program terminates if ");
	printf("the first two are.\n");

	printf("\nEnter four numbers> ");
	scanf("%lf%lf%lf%lf", &y2, &y1, &x2, &x1);
	//4 2 8 4
	//y1=4, y2=2, x2=8, x1=4
	slope = (y2 - y1) / (x2 - x1);

	while (slope != SPECIAL_SLOPE)	{
		printf("Slope is %5.2f.\n", slope); //Slope is  0.50.
		printf("\nEnter four more numbers> ");
		scanf("%lf%lf%lf%lf", &y2, &y1, &x2, &x1);
		slope = (y2 - y1) / (x2 - x1);
	}

return (0);
}


/*

4 2 8 4
    y1=4, y2=2, x2=8, x1=4
    (2-4)/(8-4)
	--->	"Slope is  o.50."

1 4 2 1
    y1=1, y2=4, x2=2, x1=1
    (4-1)/(2-1)
	--->	"Slope is -3.00."

9 3 3 1 
    y1=9, y2=3, x2=3, x1=1
    (3-9)/(3-1)
	--->	"Slope is  3.00."

-22 10 8 2
    y1=-22, y2=10, x2=8, x1=2
    (10-(-22))/(8-2)
	--->	"Slope is -5.33."

 3 3 4 5
    y1=3, y2=3, x2=4, x1=5
    (3-3)/(4-5)    //SPECIAL_SLOPE
    [No output because the slope is 0 and the loop ends]

*/