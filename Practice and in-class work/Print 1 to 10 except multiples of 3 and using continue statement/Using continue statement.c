/*
This program prints numbers from 1 to 20 except those that are divisible by 3
*/

#include <stdio.h>

int main ()
{
	//declare the integer i
	int i = 0;

	printf("%x\n\n", &i);

	while (i < 20)
	{
        //increments the value of i with every loop
		i = i + 1;

        //if i is not divisible by 3, it will print it, but will skip the rest of the loop if it is divisible by 3
		if (i%3 != 0)
		{
            //prints i
			printf ("%d\n", i);
		}
		else
		{
			continue; //skip the rest of the loop
		}
	}

	return 0;
}