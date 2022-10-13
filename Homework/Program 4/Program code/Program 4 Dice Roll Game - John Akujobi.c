/*
This program is a dice roll game
The user will roll a dice and the computer will roll a dice
The following rules determine the winner
Closest to 12 wins
Lucky 7 (sum of 7) beats closest to 12
Snake eyes beat Lucky 7.
First Snake Eyes, then Lucky 7, then closest to 12

Created by John Akujobi
On 10th October 2022
CSC 150 S01

*/


//BUG#1: All the dice rolls are the same
//Fixed BUG#1: by using the PressEnter function to reset the time seed for the random number generator in the dice roll function
            //This makes sure that the random number generator is not using the same seed everytime the program is run


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void WelcomeStatement (); 
//Prints a welcome statement
//And Tells the user how to play the game

int DiceRoll ();
//This function performs a dice roll by randomly selecting a number and limiting its range to 1-6
//It returns the integer diceRolled

void PressEnter (); 
//This function pauses the game then continues after the user presses enter

int UserX (int userR1, int userR2); 
//It sums the two dice rolled numbers userR1 and userR2
//It prints this information to the user
//It returns an integer userRoll

int CompX (int compR1, int compR2); 
//It sums the two dice rolled numbers compR1 and compR2
//It prints this information to the user
//It returns an integer compRoll

char CheckWinner (int compRoll, int userRoll); 
//This function receives the added dice rolls for both the computer and human
//Then it checks the winner using the game rules and utilizes if and else statements
//Assigns a value to winner either ‘U’ for User or ‘C’ for Computer

void PrintWinner (char winner); 
//This function prints the winner of the game


int main ()
{

    //Declaring variables
    int userR1, userR2, userRoll, compR1, compR2, compRoll;
    char winner;

    //Calling the WelcomeStatement function
    WelcomeStatement ();

    //Calling the DiceRoll function
    //And assigning comp1 to the returned value
    compR1 = DiceRoll ();

    //This resets the time for the dice roll function
    PressEnter ();
    printf ("\nThe computer's first roll is %d", compR1);

    //Calling the DiceRoll function
    //And assigning comp2 to the returned value
    compR2 = DiceRoll ();
    printf ("\nThe computer's second roll is %d\n", compR2);

    //Calling the CompX function
    //Its tells the user the sum of the two dice rolls by the computer
    compRoll = CompX (compR1, compR2);

    //Tells the user that its time for them to roll their dice
    printf ("\nNow, It\'s your turn to roll the dice");


    PressEnter ();

    //Calling the DiceRoll function
    //And assigning user1 to the returned value
    userR1 = DiceRoll ();
    printf ("Your first roll is %d", userR1);

    //Pauses the game giving the impression that the game is about to roll the user's dice
    //Meanwhile the time is actually reset for the dice roll function in order to get a different number
    PressEnter ();

    userR2 = DiceRoll ();
    printf ("Your second roll is %d\n", userR2);

    //Calling the UserX function
    userRoll = UserX (userR1, userR2);

    PressEnter ();

    //Calling the CheckWinner function
    winner = CheckWinner (compRoll, userRoll);

    //Calling the PrintWinner function
    PrintWinner (winner);

    return 0;
}


//Prints a welcome statement
//And Tells the user how to play the game
void WelcomeStatement ()
{
    printf ("\nWelcome to the dice roll game\n");
    printf ("\nYou and the computer will roll a dice.\nTwice each");
    printf ("\nThe following rules determine the winner\n");
    printf ("First:    Snake eyes (A roll of two 1s)\n");
    printf ("Second:   Lucky 7 (sum of 7) beats closest to 12\n");
    printf ("Third:    Closest to 12 wins\n");
}


//This function performs a dice roll by randomly selecting a number and limiting its range to 1-6
//It returns the integer diceRolled
int DiceRoll ()
{
    int diceRolled;
    srand (time (NULL));
    diceRolled = rand () % 6 + 1;
    return diceRolled;
}


//This function pauses the game then continues after the user presses enter
//It is used to give the impression that the computer is rolling the dice
//It is also used to reset the time for the dice roll function
void PressEnter ()
{
  printf("\nPress Enter to continue...\n");
  while (getchar()!='\n');
}


//It sums the two dice rolled numbers userR1 and userR2
//It prints this information to the user
//It returns an integer userRoll
int UserX (int userR1, int userR2)
{
    int userRoll;
    userRoll = userR1 + userR2;
    printf ("\nYou rolled a %d and a %d\n", userR1, userR2);
    printf ("So Your total is %d\n", userRoll);
    return userRoll;
}


//It sums the two dice rolled numbers compR1 and compR2
//It prints this information to the user
//It returns an integer compRoll
int CompX (int compR1, int compR2)
{
    int compRoll;
    compRoll = compR1 + compR2;
    printf ("\nThe computer rolled a %d and a %d\n", compR1, compR2);
    printf ("So, the computer's total is %d\n", compRoll);
    return compRoll;
}


//This function receives the added dice rolls for both the computer and human
//Then it checks the winner using the game rules and utilizes if and else statements
//Assigns a value to winner either ‘U’ for User or ‘C’ for Computer
char CheckWinner (int compRoll, int userRoll)
{
    char winner;

    //checks for a snake eyes
    if (compRoll == 2 && userRoll == 2)
    {
        winner = 'U';
    }

    else if (compRoll == 2 && userRoll != 2)
    {
        winner = 'C';
    }

    else if (compRoll != 2 && userRoll == 2)
    {
        winner = 'U';
    }

    //checks for a lucky 7 or a sum of 7
    else if (compRoll == 7 && userRoll == 7)
    {
        winner = 'U';
    }

    else if (compRoll == 7 && userRoll != 7)
    {
        winner = 'C';
    }

    else if (compRoll != 7 && userRoll == 7)
    {
        winner = 'U';
    }

    //checks for the closest to 12
    //if the computer's roll is greater than the user's roll
    else if (compRoll > userRoll)
    {
        winner = 'C';
    }

    //if the computer's roll is lesser than the user's roll
    else if (compRoll < userRoll)
    {
        winner = 'U';
    }

    //checks if the computer's roll is equal to the user's roll
    //creates a tie
    else if (compRoll == userRoll)
    {
        winner = 'T';
    }

    return winner;
}


/*
//This function determines the winner of the game based on the value of winner
//Then it prints the winner
void PrintWinner (char winner)
{
    //checks if the winner of the game is the user
    if (winner == 'U')
    {
        printf ("Woohoo!!!\nYou win!\n\n");
    }

    //checks if the winner of the game is the computer
    else if (winner == 'C')
    {
        printf ("\nWhoops\nThe computer wins!\n\n");
    }

    //checks if the game is a tie
    else if (winner == 'T')
    {
        printf ("\nBadoom\nIt's a tie!\n\n");
    }

    //prints an error message if the winner is not determined
    else
    {
        printf ("\nError\nThe winner is not determined\n\n");
    }

}

*/


//This function determines the winner of the game based on the value of winner
//Then it prints the winner
void PrintWinner (char winner)
{
    //checks if the winner of the game is the user
    switch (winner)
    {
        case 'U':
            printf ("Woohoo!!!\nYou win!\n\n");
            break;

        //checks if the winner of the game is the computer
        case 'C':
            printf ("\nWhoops\nThe computer wins!\n\n");
            break;

        //checks if the game is a tie
        case 'T':
            printf ("\nBadoom\nIt's a tie!\n\n");
            break;

        //prints an error message if the winner is not determined
        default:
            printf ("\nError\nThe winner is not determined\n\n");
    }
    printf ("Thank you for playing!\nSee ya!\n"); 
}