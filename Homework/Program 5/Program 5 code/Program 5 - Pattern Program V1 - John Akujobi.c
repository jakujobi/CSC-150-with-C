/*
This program prints a pattern of asterisks based on the user's input.

Program Design, Copied from submitted homework
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

On the 27th of October 2022
Finished on the 1st of November 2022

CSC 150 S01

BUG #1: FIXED
    Bug:Code not executing properly
    Fix: Hidden syntax error caused by missing }

BUG #2: FIXED
    Bug: Pattern 4 gives a whole row full of the size value
    Fix: Changed the if expression
        from if ( row == (size-row+1) || col == (size-col+1))
        to if ( row == (size-col+1))

BUG #3: FIXED
    Bug: The program gives the same pattern for all input
    Fix: Removed choice = choice - 1; from the Get_choice function
         Defined all the options in the type def enum for the choice variable
         Replaced Get_Choice(choice); from the Get_choice function
            with int choice = Get_Choice(choice); //Didn't work
            Then tried choice = Get_Choice(choice); //Worked

BUG #4: FIXED
    Bug: Nearly 14 syntax errors
    Fix: Most of them were missing semicolons and unpaired brackets

*/


#include <stdio.h>
#include <stdlib.h>

//This defines the function type option for Get_Choice
//typedef enum {Pattern_1, Pattern_2, Pattern_3, Pattern_4, Exit} option; //Found a more efficient way to do this

typedef enum //The method i learned from StackOverflow in which the options are assigned a value
{ 
    Pattern_1 = 1,
    Pattern_2 = 2,
    Pattern_3 = 3,
    Pattern_4 = 4 ,
    Exit = 5
} option;


//Function prototypes
void Welcome ();    //Prints a welcome statement to the user
void Main_Menu ();  //Prints the main menu
void Pick_Pattern (option choice);  //Picks a pattern based on the user's choice gotten in Get_Choice. Will use switch statement
int Get_Size (int size);    //This function gets the size of the pattern
option Get_Choice (option choice);  //This function gets the choice of the pattern

//Functions to draw the patterns
void Draw_Pattern_1 (int size); //Pattern_1
void Draw_Pattern_2 (int size); //Pattern_2
void Draw_Pattern_3 (int size); //Pattern_3
void Draw_Pattern_4 (int size); //Pattern_4


int main ()
{
    //Declaring variables
    int choice;
    int size;

    //Calling the Welcome function
    Welcome();

    //Do while loop to repeat the program
    do
    {
        //Calling the Pick_Pattern function
        Pick_Pattern(choice);
        printf("\n");
        printf("Nice work!\nYou've completed a pattern!\n\n\n");

    } while (choice != Exit); //checks if the user wants to exit the program

    return 0;
}


//This function prints a welcome statement
void Welcome ()
{
    printf("\n\n"); //To give space before the welcome statement
    printf("Welcome to the Pattern Program!\n");
    printf("This program prints a pattern of asterisks and a number based on the user's input.\n");
    printf("It will ask you for the size and one of 4 patterns you want to print.\n");
    printf("\n");

    //Showing an example of the patterns
    printf("Here is an example of patterns of size 7\n");
    printf (" Pattern 1       Pattern 2          Pattern 3         Pattern 4   \n");
    printf ("* 7 7 7 7 7 7     * * * * * * *     7 7 7 7 7 7 7     * * * * * * 7 \n");
    printf ("7 * 7 7 7 7 7     * 7 7 7 7 7 *     7 * * * * * 7     * * * * * 7 * \n");
    printf ("7 7 * 7 7 7 7     * 7 7 7 7 7 *     7 * * * * * 7     * * * * 7 * * \n");
    printf ("7 7 7 * 7 7 7     * 7 7 7 7 7 *     7 * * * * * 7     * * * 7 * * * \n");
    printf ("7 7 7 7 * 7 7     * 7 7 7 7 7 *     7 * * * * * 7     * * 7 * * * * \n");
    printf ("7 7 7 7 7 * 7     * 7 7 7 7 7 *     7 * * * * * 7     * 7 * * * * * \n");
    printf ("7 7 7 7 7 7 *     * * * * * * *     7 7 7 7 7 7 7     7 * * * * * * \n");
    printf("\n"); //To give space after the welcome statement

    /*
    //Tried to add a pause statement but later decided that it wouldn't add much to user experience
    printf("Press Enter to continue-->");
    while (getchar()!='\n'); //To pause the program until the user presses enter
    printf("\n\n");
    */

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
    printf("\n");

    return;
}


//This function calls the Get_Size function and the Get_Choice function
//It uses the choice variable to determine which pattern will be executed
void Pick_Pattern (option choice)
{
    //Calling the Get_Choice function
    choice = Get_Choice(choice);

    //Calling the Get_Size function and storing the value in the variable size
    int size = Get_Size(size);
    
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
            exit(0);
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
    printf("Please enter the size of the pattern (up to 40)---->:");
    scanf("%d", &size);
    printf("\n");

    //Validating the input for incompatible values
    while (size < 1 || size > 40)
    {
        printf("Oops! Invalid size.\nPlease try again---->:");
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
    printf("Please enter your choice---->:");
    scanf("%d", &choice);

    //choice = choice - 1; //Not needed anymore   

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
    int row, col;

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

    return;
}


//This function prints pattern 2
void Draw_Pattern_2 (int size)
{
    //Declaring variables
    int row, col;

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
    return;
}


//This function prints pattern 3
void Draw_Pattern_3 (int size)
{
    //Declaring variables
    int row, col;

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

    return;
}


//This function prints pattern 4
void Draw_Pattern_4 (int size)
{
    //Declaring variables
    int row, col;

    //Pattern 4
    for (row = 1; row <= size; row++)
    {
        for (col = 1; col <= size; col++)
        {
            //checks for where to print the number size
            if ( row == (size-col+1))
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

    //Printing a blank line to give space between outputs
    printf("\n\n");

    return;
}
