/*
This program is a menu driven coffee program that allows the user to select a coffee size and type.


Created by John Akujobi
On 13th October 2022
CSC 150 S01

*/

#include <stdio.h>
#include <stdlib.h>

//This defines the function type drink_t for getChoice
//It limits the number of choices
typedef enum {Hot_Chocolate, Black_Coffee, Cappuccino, Latte, Espresso, Mocha, Pumpkin_Spice, Hot_Tea, Exit} drink_t;

drink_t getChoice();


int main ()
{
    //Declaring variables
    int choice;

    //get the menu choice
    choice = getChoice();

    //switch statement to determine the coffee size and type
    switch (choice)
    {
        case Hot_Chocolate:
            printf("Dark and Yummy!\n");
            break;
        case Black_Coffee:
            printf("Strong and Bold!\n");
            break;
        case Cappuccino:
            printf("A little bit of everything!\n");
            break;
        case Latte:
            printf("A blend of textures!\n");
            break;
        case Mocha:
            printf("Mocha! Kocha!! Pocha!!!\n");
            break;
        case Espresso:
            printf("Get some work done!\n");
            break;
        case Pumpkin_Spice:
            printf("The taste of fall!\n");
            break;
        case Hot_Tea:
            printf("Back to the classics!\n");
            break;
        default:
            printf("Uh Oh! Invalid choice!\n");
            break;
    }

}



/*
This getChoice function
1. Prints the menu
2. Prompts the user to enter a choice
3. Returns the choice
*/
drink_t getChoice ()
{
    //Declaring variables
    int choice;

    //Printing the menu
    printf ("1. Hot_Chocolate\n");
    printf ("2. Black_Coffee\n");
    printf ("3. Cappuccino\n");
    printf ("4. Latte\n");
    printf ("5. Espresso\n");
    printf ("7. Pumpkin_Spice\n");
    printf ("8. Mocha\n");
    printf ("9. Hot_Tea\n");
    printf ("10. Exit\n");

    //Asking the user for their choice
    printf ("Please enter your choice: ");
    scanf ("%d", &choice);
    
    //This is to zero base the choice
    choice = choice - 1;

    if (choice < Hot_Chocolate || choice > Exit)
    {
        printf ("UH OH!\n Invalid choice!\n");
        exit (1);
    }

    //Returning the choice
    return choice;
    
}
