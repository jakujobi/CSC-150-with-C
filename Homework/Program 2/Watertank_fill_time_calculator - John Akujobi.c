//This program calculates the time it takes to fill a water tank of any given height and diameter provided by the user.
//Created by: John Akujobi on 9/11/2022
//CSC 150 - S01

#include <stdio.h>

//define PI as a constant
#define PI 3.14159265

int main (void)
{

//tell user the purpose of the program
    printf("This program calculates how long it would take to fill a cylindrical tank with a hose\n");
    printf("\n");
    
//define the variables
    float average_hose_fill_rate, tank_height, tank_diameter, tank_radius;
    float tank_volume_ft, tank_volume_gallons, tank_fill_time;
    int  tank_fill_time_hrs, tank_fill_time_minutes_left, tank_fill_time_mins;

//ask the user for the height and diameter of the tank
    printf("What is the height of your tank in feet? \n");
    scanf("%f", &tank_height);

    printf("What is the diameter of your tank in feet: \n");
    scanf("%f", &tank_diameter);

//calculate the average fill rate of the hose
//fill rate is between 7 and 15 gallon per minute
    average_hose_fill_rate = (15 + 7) / 2;

//calculate the radius of the tank
    tank_radius = tank_diameter / 2;

//calculate the volume of the tank in cubic feet
//Volume of a cylinder = PI * radius^2 * height
    tank_volume_ft = PI * (tank_radius * tank_radius) * tank_height;

//convert the volume of the tank from cubic feet to gallons
//1 cubic foot = 7.48 gallons
    tank_volume_gallons = tank_volume_ft * 7.48;

//calculate the time it takes to fill the tank
//time_fill_time = tank_volume_gallons / fill rate
    tank_fill_time = tank_volume_gallons / average_hose_fill_rate;

//tank_fill_time is the fill time in integer minutes
    tank_fill_time_mins= (int)(tank_fill_time);

/*
Convert the time it takes to fill the tank from minutes to hours and minutes
tank_fill_time_hrs are the number of hours it takes to fill the tank
tank_fill_time_minutes_left are the number of minutes left after the hours are calculated
*/
    tank_fill_time_hrs = tank_fill_time / 60;
 //   tank_fill_time_minutes_left = ((tank_fill_time_hrs*60) - ((int)(tank_fill_time_mins) / 60))%60; 
    tank_fill_time_minutes_left = (tank_fill_time_mins)%60; 

//print the volume of the users tank in both cubic feet and gallons
    printf("The volume of your tank is %f cubic feet \n", tank_volume_ft);
    printf("It can hold %f gallons of water \n", tank_volume_gallons);
    printf("\n");

//print the time it takes to fill the tank by returning the variable tank_fill_time_hrs to the user
    printf("It would take %f minutes to fill the tank. \n", tank_fill_time);
    printf("That's about %d hour(s), and %d minutes. \n", tank_fill_time_hrs, tank_fill_time_minutes_left);
    printf("\n");
    return (0);
}