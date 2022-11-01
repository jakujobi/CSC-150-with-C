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
void Pattern_1 (int size);
void Pattern_2 (int size);
void Pattern_3 (int size);
void Pattern_4 (int size);


int main ()
{
    //Declaring variables
    int choice;
    int size;

    //Calling the Welcome function
    Welcome();

    //Calling the Main_Menu function
    Main_Menu();

    do
    {
        //Calling the Pick_Pattern function
        Pick_Pattern(choice);

    } while (choice != Exit);

    return 0;
}

//This function prints a welcome statement
void Welcome ()
{
    printf("Welcome to the Pattern Program!\n");
    printf("This program prints a pattern of asterisks based on the user's input.\n");
    printf("\n");

    return;
}


//This function prints the Main_Menu
void Main_Menu ()
{
    printf("Please select a pattern to print:\n");
    printf("1. Pattern 1");
    printf("2. Pattern 2");
    printf("3. Pattern 3");
    printf("4. Pattern 4");
    printf("5. Exit");

    return;
}


//This function calls the Get_Size function and the Get_Choice function
//It uses the choice variable to determine which pattern will be executed
void Pick_Pattern (option choice)
{
    //Declaring variables
    int size;

    //Calling the Get_Size function
    Get_Size(size);

    //Calling the Get_Choice function
    Get_Choice(choice);

    //Switch statement to determine which pattern to print
    switch (choice)
    {
        case Pattern_1:
            Pattern_1(size);
            break;

        case Pattern_2:
            Pattern_2(size);
            break;

        case Pattern_3:
            Pattern_3(size);
            break;

        case Pattern_4:
            Pattern_4(size);
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
    int i;

    //Receiving the size from the user
    printf("Please enter the size of the pattern: ");
    scanf("%d", &size);

    //Validating the input
    while (size < 1 || size > 20)
    {
        printf("Invalid size. Please try again: ");
        scanf("%d", &size);
    }

    return size;
}


