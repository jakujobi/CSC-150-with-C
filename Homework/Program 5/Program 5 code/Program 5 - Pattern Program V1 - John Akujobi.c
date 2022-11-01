/*
This program prints a pattern of asterisks based on the user's input.


### **Data Storage (defined in main)**

- int choice
    - It holds the value for the choice picked by the user
- int size
    - It holds the value for the pattern size picked by the user

### **Function Design (for each function, give the function’s prototype and 1 or 2 lines describing how the function works.)**

- Welcome
    - void Welcome ();
    - It just prints a welcome statement telling the user about the program and its purpose and how to use it
    - Doesn’t return or take any value
- Main_Menu
    - void Main_Menu ();
    - It prints the Main_Menu, letting the user see the options.
    - Doesn’t return or take any value
- Pick_Pattern
    - void Pick_Pattern (option choice);
    - Function
        - Calls the Get_Size function
        - Calls the Get_Choice function
        - It uses the choice variable to determine which pattern will be executed
    - It comprises of switch statements
    - It takes the value from the option variable “choice”
    - It doesn’t return any value
- Get_Size
    - int Get_Size (int size);
    - It receives the size from the user and validates the input, repeating until the input is compatible
    - It doesn’t take any value
    - It returns a value in the integer variable “size”
- Get_Choice
    - option Get_Choice (option choice);
    - It receives the choice from the user and validates the input for errors
    - It doesn’t take any value
    - It returns a value in the option variable “choice”
- Pattern_1
    - void Pattern_1 (int size)
    - It prints pattern 1
    - Takes the integer variable “size”
    - It doesn’t return any value
- Pattern_2
    - void Pattern_2 (int size)
    - It prints pattern 2
    - Takes the integer variable “size”
    - It doesn’t return any value
- Pattern_3
    - void Pattern_3 (int size)
    - It prints pattern 3
    - Takes the integer variable “size”
    - It doesn’t return any value
- Pattern_4
    - void Pattern_4 (int size)
    - It prints pattern 4
    - Takes the integer variable “size”
    - It doesn’t return any value

Created by John Akujobi
On the 30th of October 2022
CSC 150 S01

*/

#include <stdio.h>
#include <stdlib.h>

//This defines the function type option for Get_Choice
//It limits the number of choices
typedef enum {Pattern_1, Pattern_2, Pattern_3, Pattern_4, Exit} option;

//Function prototypes
void Welcome ();
void Main_Menu ();
void Pick_Pattern (option choice);
int Get_Size (int size);
option Get_Choice (option choice);
void Draw_Pattern_1 (int size);
void Draw_Pattern_2 (int size);
void Draw_Pattern_3 (int size);
void Draw_Pattern_4 (int size);


int main ()
{
    //Declaring variables
    int choice;
    int size;

    //Calling the Welcome function
    Welcome();

    //Calling the Main_Menu function
    //Main_Menu();

    //Do while loop to repeat the program
    do
    {
        //Calling the Pick_Pattern function
        Pick_Pattern(choice);

        printf("Nice work! You've completed a pattern!\n\n");

    } while (choice != Exit); //checks if the user wants to exit the program

    return 0;
}


//This function prints a welcome statement
void Welcome ()
{
    printf("\n\n"); //To give space before the welcome statement
    printf("Welcome to the Pattern Program!\n");
    printf("This program prints a pattern of asterisks and a number based on the user's input.\n");
    printf("It will ask you for the size of the pattern and the pattern you want to print.\n");
    printf("You can choose from 4 patterns and you can exit the program at any time.\n");
    printf("\n");
    printf("Here is an example of patterns of size 7\n");
    printf ("Pattern 1          Pattern 2	        Pattern 3	        Pattern 4   \n ");
    printf ("* 7 7 7 7 7 7      * * * * * * *	    7 7 7 7 7 7 7	    * * * * * * 7 \n ");
    printf ("7 * 7 7 7 7 7	    * 7 7 7 7 7 *	    7 * * * * * 7	    * * * * * 7 * \n ");
    printf ("7 7 * 7 7 7 7	    * 7 7 7 7 7 *	    7 * * * * * 7	    * * * * 7 * * \n ");
    printf ("7 7 7 * 7 7 7	    * 7 7 7 7 7 *	    7 * * * * * 7	    * * * 7 * * * \n ");
    printf ("7 7 7 7 * 7 7	    * 7 7 7 7 7 *	    7 * * * * * 7	    * * 7 * * * * \n ");
    printf ("7 7 7 7 7 * 7	    * 7 7 7 7 7 *	    7 * * * * * 7	    * 7 * * * * * \n ");
    printf ("7 7 7 7 7 7 *	    * * * * * * *	    7 7 7 7 7 7 7	    7 * * * * * * \n ");
    printf("\n\n"); //To give space after the welcome statement
//  printf("Have fun!\n");
//  printf("\n");

    printf("Press Enter to continue-->");
    while (getchar()!='\n'); //To pause the program until the user presses enter
    printf("\n\n");

    return;
}


//This function prints the Main_Menu
void Main_Menu ()
{
    printf("Please select a pattern to print:\n");
    printf("1. Pattern 1\n");
    printf("2. Pattern 2\n");
    printf("3. Pattern 3\n");
    printf("4. Pattern 4\n");
    printf("5. Exit\n");

    return;
}



//This function calls the Get_Size function and the Get_Choice function
//It uses the choice variable to determine which pattern will be executed
void Pick_Pattern (option choice)
{

    //Calling the Get_Size function and storing the value in the variable size
    int size = Get_Size(size);

    //Calling the Get_Choice function
    Get_Choice(choice);
    

    //Switch statement to determine which pattern to print
    switch (choice)
    {
        case Pattern_1:
            Draw_Pattern_1(size);
            break;

        case Pattern_2:
            Draw_Pattern_2(size);
            break;

        case Pattern_3:
            Draw_Pattern_3(size);
            break;

        case Pattern_4:
            Draw_Pattern_4(size);
            break;

        case Exit:
            printf("Thank you for using the Pattern Program!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return;
}


//This function receives the size from the user and validates the input, repeating until the input is compatible
int Get_Size (int size)
{
    //Declaring variables
    //int i;

    //Receiving the size from the user
    printf("Please enter the size of the pattern: ");
    scanf("%d", &size);
    printf("\n");

    //Validating the input for incompatible values
    while (size < 1 || size > 20)
    {
        printf("Invalid size. Please try again: ");
        scanf("%d", &size);
    }

    return size;
}


//This function receives the choice from the user and validates the input for errors
option Get_Choice (option choice)
{
    //Declaring variables
    //int i;

    Main_Menu();

    //Receiving the choice from the user
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    //Validating the input
    while (choice < 1 || choice > 5)
    {
        printf("Invalid choice. Please try again: ");
        scanf("%d", &choice);
    }

    return choice;
}


//This function prints pattern 1
void Draw_Pattern_1 (int size)
{
    //Declaring variables
    int i;
    int j;

    //Printing the pattern
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    //Printing a blank line to give space between outputs
    printf("\n\n");

    return;
}


//This function prints pattern 2
void Draw_Pattern_2 (int size)
{
    //Declaring variables
    int i;
    int j;

    //Printing the pattern
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    //Printing a blank line to give space between outputs
    printf("\n\n");

    return;
}


//This function prints pattern 3
void Draw_Pattern_3 (int size)
{
    //Declaring variables
    int i;
    int j;

    //Printing the pattern
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {
            if (i == 1 || i == size || j == 1 || j == size)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    //Printing a blank line to give space between outputs
    printf("\n\n");

    return;
}


//This function prints pattern 4
void Draw_Pattern_4 (int size)
{
    //Declaring variables
    int i;
    int j;

    //Printing the pattern
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {
            if (i == 1 || i == size || j == 1 || j == size || i == j || i + j == size + 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    //Printing a blank line to give space between outputs
    printf("\n\n");

    return;
}
