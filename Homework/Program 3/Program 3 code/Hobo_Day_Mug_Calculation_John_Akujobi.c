//This program helps the user calculate how much of their favorite beverage hey can hold in 
//their “Special Reserve” Hobo Day mug in the shape of a hemi-sphere can hold

/*The program uses functions to:
1. Print a welcome message to the screen
2. Prompt the user to enter the diameter of their Hobo Day Mug
3. Calculates the radius of the Mug
3. Calculates the mug's volume in inches cube
4. Convert the volume to Ounces
5. Convert the volume to Litres
6. Print the diameter and radius of the cup to the screen
7. Print the volume of the mug in inches cube, ounces and litres
*/

//Created by John Akujobi on 9/26/2022
//CSC 151 - S01 - SDState


#include <stdio.h>
#include <math.h>



//Define all the constants used by the program

//Define PI
const float PI = 3.1416;

//This constant helps with converting volume from inches cube to ounces
const float ToOunces = 0.554113;

//This constant helps with converting volume from ounces to litres
const float ToLitres = 0.02841306;



//Define all the function Prototypes
//This function prints a welcome message to the screen telling the user about the program
void printWelcome ();

//This function reads the diameter from the user's input then returns the value
float getDiameter ();

//Calculates the radius from the diameter, then returns the value
float calcRadius (float diameter);

//Calculate the volume in inch cubes using the hemisphere volume formula and radius, then return the value
float calcVolume_inch (float radius);

//Convert the volume from inch cubes to ounces by multiplying by ToOunces
float calcVolume_ounces (float vol_Inches);

//Convert the volume from inch ounces to litres by multiplying by ToLitres
float calcVolume_lit (float vol_Ounces);

//print the diameter and radius, and the volume in inch cubes, ounces and litres
void printResults (float diameter, float radius, float vol_Ounces, float vol_Inches, float vol_Lit);
//Just learnt the hard way that the order of the variables in the function call matters



//The Main
int main(void)
{
    //declare variables
    float diameter, vol_Inches, vol_Ounces, vol_Lit, radius;


    // print welcome message
    printWelcome();

    // read diameter from user and print to screen
    diameter = getDiameter();
   // printf("diameter: %f\n", diameter);

    // calculate radius from diameter
    radius = calcRadius(diameter);
    //printf("radius: %f\n", radius);

    // calculate volume in inches cube
    vol_Inches = calcVolume_inch(radius);
    //printf("volume in inches cube: %f\n", vol_Inches);

    // convert volume from inches cube to ounces
    vol_Ounces = calcVolume_ounces(vol_Inches);
    //printf("volume in ounces: %f\n", vol_Ounces);

    // convert volume from ounces to litres
    vol_Lit = calcVolume_lit(vol_Ounces);
    //printf("volume in litres: %f\n", vol_Lit);

    // print results to the user
    printResults(diameter, radius, vol_Inches, vol_Ounces, vol_Lit);
    
    return 0;
}



// prints welcome message to the screen
void printWelcome ()
{
    printf("\n\n\n");
    printf("Hello Fellow Jackrabbit! \n Welcome to the Hobo Day Mug program.\n");
    printf("It calculates how much beverage can be held in your hemisphere shaped mug can\n");
    printf("\n");
    return;
}

//This function reads the diameter of the mug from the user's input then returns the value
float getDiameter ()
{
    float diameter;
    printf("Type in the diameter of your Hobo Day Mug --->: ");
    scanf("%f", &diameter);
    return diameter;
}

//Calculates the radius from the diameter, then returns the value
float calcRadius (float diameter)
{
    float radius = diameter/2.0;
    return radius;
}

//Calculate the volume in inch cubes using the hemisphere volume formula and radius, then return the value
float calcVolume_inch (float radius)
{
    float vol_Inches = ((2.0/3.0)* PI * pow(radius, 3));
    return vol_Inches;
}

//Convert the volume from inch cubes to ounces by multiplying by ToOunces
float calcVolume_ounces (float vol_Inches)
{
    float vol_Ounces = vol_Inches * ToOunces;
    return vol_Ounces;
}

//Convert the volume from inch ounces to litres by multiplying by ToLitres
float calcVolume_lit (float vol_Ounces)
{
    float vol_Litres = vol_Ounces * ToLitres;
    return vol_Litres;
}

//print the diameter and radius, and the volume in inch cubes, ounces and litres
//and ends the program with a statement
void printResults (float diameter, float radius, float vol_Inches, float vol_Ounces, float vol_Lit)
{
    printf("\n");
    printf("************************************************************\n");
//    printf("\n");
    printf("Your mug has a diameter of:     %9.3f\n", diameter);
    printf("And a radius of:                %9.3f\n", radius);
    printf("\n");
    printf("The volume of your Hobo Day mug is \n");
    printf("In Inches cube:                 %9.3f inches cube\n", vol_Inches);
    printf("In Ounces:                      %9.3f ounces\n", vol_Ounces);
    printf("And in Litres:                  %9.3f litres\n", vol_Lit);
    printf("\n");
    printf("************************************************************\n");

    //Ending statement
    printf("Thank you for using this program\n");
    printf("Go Jacks!!!\n\n");
    return;
}