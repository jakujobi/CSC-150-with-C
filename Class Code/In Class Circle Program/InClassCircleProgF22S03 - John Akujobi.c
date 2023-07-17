


#include <stdio.h>
#include <math.h>

const float PI = 3.1416;

void printWelcome ();       // prints welcome message to the screen
float readRadius ();        // reads the radius from the users input
float calculateArea (float c_radius);     // calculates the area of the circle, then returns the value
float calculateCircumference (float c_radius);     // calculates the circumference of the circle, then returns the value
void printResults (float a, float); // prints the results of the area calculation and circumference calculation

int main(void)
{

    float radius, area, circumference;

    // print welcome message

    printWelcome();

    radius = readRadius();
    printf("radius: %f\n", radius);

    area = calculateArea(radius);
    printf("area: %f\n", area);

    circumference = calculateCircumference(radius);
    printf("circumference: %f\n", circumference);

    return 0;
}


void printWelcome ()
{
    printf("Welcome to the circle program\n\n");
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


float calculateArea (float c_radius)
{
    float c_area;
//   c_area = PI * c_radius * c_radius;
    c_area = PI * pow(c_radius, 2);
    return c_area;
}


float calculateCircumference (float c_radius)
{
    float c_circumference;
    c_circumference = 2.0 * PI * c_radius;
    return c_circumference;
}

//print the area and circumference of the circle

void printArea (float c_radius)
{
    printf("area:                %8.2f", area);
    printf("circumference:       %8.2f", calculateCircumference);
    printf("\n");
    return;
}