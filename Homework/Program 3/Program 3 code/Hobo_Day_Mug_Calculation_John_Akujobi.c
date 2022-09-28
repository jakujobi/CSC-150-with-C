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

//This constant helps with converting from inches cube to ounces
const float ToOunces = 0.554113;

//This constant helps with converting from ounces to litres
const float ToLitres = 0.02841306;



//Define all the function Prototypes
// This function prints a welcome message to the screen
void printWelcome ();

float getDiameter ();        // reads the diameter from the users input
float calculateArea (float c_radius);     // calculates the area of the circle, then returns the value
float calculateCircumference (float c_radius);     // calculates the circumference of the circle, then returns the value
void printResults (float a, float); // prints the results of the area calculation and circumference calculation

int main(void)
{
    //declare variables
    float diameter, volOunces, volLit, radius;


    // print welcome message
    printWelcome();

    // read radius from user and print to screen
    diameter = getDiameter();
    printf("diameter: %f\n", diameter);

    // calculate the area of circle and print to screen
    area = calculateArea(radius);
    printf("area: %f\n", area);

    // calculate the circumference of the circle and print to screen
    circumference = calculateCircumference(radius);
    printf("circumference: %f\n", circumference);

    return 0;
}


// prints welcome message to the screen
void printWelcome ()
{
    printf("\n\n\n");
    printf("Hello Fellow Jackrabbit! \n Welcome to the Hobo Day Mug program.\n;
    printf("It calculates how much beverage can be held in your hemisphere shaped mug can\n");");
    printf("\n\n");
    return;
}


/* readRadius:
 * It reads the radius from the user's input then returns the value
 * The value
 * returns the radius
 */
float readRadius ()
{
    float r_radius;
    printf("Enter the radius of the circle of the circle: ");
    scanf("%f", &r_radius);
    return r_radius;
}

// calculates the area of the circle, then returns the value
float calculateArea (float c_radius)
{
    float c_area;
//   c_area = PI * c_radius * c_radius;
    c_area = PI * pow(c_radius, 2);
    return c_area;
}

// calculates the circumference of the circle, then returns the value
float calculateCircumference (float c_radius)
{
    float c_circumference;
    c_circumference = 2.0 * PI * c_radius;
    return c_circumference;
}

//print the area and circumference of the circle
void printArea (float c_radius)
{
    printf("area:                %8.2f", calculateArea);
    printf("circumference:       %8.2f", calculateCircumference);
    printf("\n");
    return;
}
