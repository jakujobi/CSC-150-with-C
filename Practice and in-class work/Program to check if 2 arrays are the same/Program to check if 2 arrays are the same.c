/*
This program checks two arrays to see if they are the same.
    array1 contains 2, 4, 6, 8
    array2 contains 1, 4, 5, 6
It also prints the elements and shows the ones that are the same or not the same
The size of the arrays is defined as a constant

Created by John Akujobi
On the 4rd of December 2022
*/

/* Bugs
Bug #1:
    The program does not want to accept the size of the arrays as a constant.
    I defined SIZE as a constant and using it in the code but it did not work.

    I received these errors:
        error: variable-sized object may not be initialized
        note: (near initialization for 'array1')
        warning: excess elements in array initializer

    Attempt 0; (Failed)
        The constant i defined at first was "size"
        I thought C preffered the names of constants to be capitalized
        So i changed it to "SIZE", but didn't work

    Attempt 1; (Failed)
        I thought it was a problem with my compiler,
        so I tried to use different compilers online and on other machines
        but I still got the same errors.

    Attempt 2;  Failed)
        Thought that the problem came from how i defined the constant
        so I tried to define it in different ways but I still got the same errors.
            using #define SIZE 4
            and cont int SIZE = 4;
    
    Attempt 3 (Working)
        After trying multiple compilers, i searched for the error online
        ANd found some related posts on StackOverflow.
        One of which was this one:

            https://stackoverflow.com/questions/3082914/c-compile-error-variable-sized-object-may-not-be-initialized
            Here, most of the responses suggested that C does not allow variable sized arrays
            even if they were defined as a constant.
            And that it is one of the improvements added to C++
        So I decided to use a different approach.

        I commented out the code that defined SIZE as a constant
        Then initialized the arrays with a fixed number 4

Alongsides this, i reffered to the code on page 22 in the CSC150 Unit 7 SU12 presentation file
It also did'nt compile in the compilers i tried
Until the size of the arrays was changed to a fixed number instead of a constant
        const int SIZE = 5;

        int firstArray[SIZE] = { 5, 10, 15, 20, 25 };
        int secondArray[SIZE] = { 5, 10, 15, 20, 25 };

        bool arraysEqual = true;   // Flag variable
        int count = 0;             // Loop counter

        // Compare the two arrays.
        while (arraysEqual && count < SIZE)
        {
        if (firstArray[count] != secondArray[count])
            arraysEqual = false;
        count++;
        }
        if (arraysEqual)
        printf("The arrays are equal.\n“);
        else
        printf("The arrays are not equal.\n“);

QUESTION ##
    Is this a normal issue with arrays defined with a constant as its size?
    And is this more of a problem is C than C++?

    What other methods should would work better?
    WHat methods do you recommend we use in our work?

Thank you!!!
*/




#include <stdio.h>

//#define int SIZE 4
//FAILED CODE related to Bug#1 (see above)

int main ()
{
    //FAILED CODE related to Bug#1 (see above)
    //const int SIZE = 4;
    //int array1 [SIZE] = {2, 4, 6, 8};
    //int array2 [SIZE] = {1, 4, 5, 6};

    int SIZE = 4;   //Defined SIZE as a variable instead of a constant
                    //But didnt use it in the initialization of the arrays

    //Declaring the arrays
    int array1 [4] = {2, 4, 6, 8};
    int array2 [4] = {1, 4, 5, 6};

    int same = 0; //same is the number of elements in the arrays that are the same

    int i = 0;  //i is the index of the array


	for (i = 0 ; i < SIZE; i++)
	{
        //check if the elements in the arrays are the same
        //And increments the index same if they are
		if (array1[i] == array2[i])
		{
			same++;
			printf("%d == %d\tSame\n", array1[i], array2[i]);
		}
		else
		{
			printf("%d != %d\tNot same\n", array1[i], array2[i]);
		}
	}

	printf ("\nThe arrays had %d elements that were the same", same);
	printf ("\nAnd %d elements that were not the same", (SIZE - same));
	
    //Check if the arrays are the same or not
    //And prints a message to the user
	if (SIZE == same)
	{
		printf("\nThe arrays were the same");
	}
	else
	{
		printf("\nThe arrays were different");
	}
	
return 0;
}