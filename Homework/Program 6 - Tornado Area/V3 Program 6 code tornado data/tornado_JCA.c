/*
This program will read in a file of tornado data and calculate the area affected by each tornado.
The program will then output the data to a file called report.txt.

Created by: John Akujobi
On the 10th of November 2022

CSC 150 - 01
*/

//Program Design

//Overall Psuedocode:
/*  1.  Declare variables
    2.  Open input file
    3.  Open output file
    4.  Read in data from input file
    5.  Calculate the area affected by each tornado
    6.  Output the data to the output file
    7.  Close input file
    8.  Close output file
    9.  End program
*/

//Expectations
/*
Write a program to read the tornado.txt file and create a report.
Store the tornado report in a file named report.txt.

The tornado data contains
- The Fujita scale
- The tornado path length in miles
- The tornado path width in yards
These data are in columns

The report should contain the following data for each part, printed in columns:
EF rating
Path Length (miles)
Path Width (yards)
Affected Area (sq miles)
Below the part table, print the total area affected.

*/

//Data Storage (Defined in Main)
/*
File *infile_tornado
- The Input tornado.txt file

File *outfile_report
- The Output Report.txt file

int fujita_scale
- first data on each line
- has to be between 0 - 6

float path_length_miles
- Path length of the tornado

float path_width_yards
- path_width of the tornado in yards

float affected_area
- calculated area affected by each tornado

float running_total
- the running total of the affected area
*/

//Functions (for each function, give the function’s prototype and 1 or 2 lines describing how the function works.)
/*
1.	void Welcome ();
        Prints a welcome statements and tells the user the purpose of the program

2.	int Open_File (File *infile_tornado);
        Opens the tornado file and reads from it
        Prints error or success message to the terminal
        Returns 404 if unsuccessful
3.	int Get_Data (File *infile_tornado, int *fujita_scale, float *path_length_miles, float *path_width_yards);
        It reads a line of data from the tornado.txt
        Stores them into the pointers
        Uses a local variable [data_fetched]
4.	void Calc_Area (float *affected_area, float *path_length_miles, float *path_width_yards);
        Calculates the area affected for each tornado and keeps a running total of the areas
        Uses the formula [path_width_miles * path_length_yards /1760]
            Divided by 1760 to convert the yards to miles
5.	int Open_OutFile (File *outfile_report);
        Creates/ Opens the Repot.txt file
        Tells the terminal if file is successfully opened or not
        Returns 404 if unsuccessful

6.	int Print_Line (File *outfile_report, int *fujita_scale, float *path_length_miles, float *path_width_yards, float *affected_area););
        Prints one line into the report file

7.	void Print_Report (File *outfile_report, float *running_total);
        Prints all the lines to the report and then prints the total area affected
        While Get_Data ==1,
        it uses Calc_Area to calculate the area
        then calls Print_Line to print the information to the file
        After this loop ends, it prints the Total Area to the file using variable running_total
        Then prints a success message to the terminal
        Prints each line to the terminal to let user know the progress

8.	void End_Program  (File *infile_tornado, File *outfile_report);
        Closes the files
        Prints a success message to the terminal
*/

//Timeline
/*
Created On the 10th of November 2022
    Collected the files
    Planned teh functions
Updated on the 12th of November 2022 - V2
Updated on the 14th of November 2022 - V3
    Filled in more comments
Updated on the 15th of November 2022 - V3
    Ran into BUG #2 - Segmentation Error
    Created some test print statements into the functions
Updated on the 16th of November 2022 - V4
    Created multiple print statements for testing purposes 
    Fixed BUG #2 - Segmentation Error
    Made changes to fit into the format expected by the professor
*/

//Bugs
/*
BUG #1 - Segmentation Error - #Fixed
    - First, i added multiple test print statements to the program to try to monitor the flow of the program
        - It also helped me to see what was going on in the program
        - And narrow down the problem
    - Relocated the contents of Open_File to the main function
    - Relocated the contents of Open_OutFile to the main function
    - After these changes, the program ran successfully
BUG #2 - Program would not run - #Fixed
    - Fixed by changing the variable [data_fetched] to a pointer
    - The variable was being used in the function Get_Data
    - After this change, the program ran successfully
BUG #3 - The data in the report file was not being printed correctly - #Fixed
    - Fixed by adding a new line character to the end of the Print_Line function
    - Then added tab spaces using \t
    - After this change, the program printed the file correctly
BUG #4 - Program could only accept integers for the path_width_yards - #Fixed
    - Fixed by changing the variable [path_width_yards] to a float
    - Repeated this for all instances of the variable
    - After this change, the program could accept floats for the path_width_yards
*/



//Get Libraries
#include <stdio.h>
#include <stdlib.h> //for exit() function
                    //but was not used in this program

//Function Prototypes
void Welcome ();
    //Prints welcome statements and tells the user the purpose of the program
    
int Open_File (FILE *infile_tornado);
    //Opens the tornado file and reads from it
    //Prints error or success message to the terminal

int Open_OutFile (FILE *outfile_report);
    //Creates/ Opens the Repot.txt file
    //Tells the terminal if file is successfully opened or not
    //Returns 404 if unsuccessful

int Get_Data (FILE *infile_tornado, int *fujita_scale, float *path_length_miles, float *path_width_yards);   
    //It reads a line of data from the tornado.txt
    //Stores them into the pointers
    //Uses a local variable [data_fetched]

void Calc_Area (float *affected_area, float *path_length_miles, float *path_width_yards);
    //Calculates the area affected for each tornado and keeps a running total of the areas
    //Uses the formula [path_width_miles * path_length_yards /1760]
    //Divided by 1760 to convert the yards to miles

int Print_Line (FILE *outfile_report, int *fujita_scale, float *path_length_miles, float *path_width_yards, float *affected_area);
    //Prints one line into the report file

//void Print_Report (FILE *outfile_report, float *running_total);
    //Prints all the lines to the report and then prints the total area affected
    //Was Not Needed

void End_Program (FILE *infile_tornado, FILE *outfile_report);
    //Closes the files
    //Prints a success message to the terminal

//Main Function
int main ()
{
    //Declare Variables

    //The files used by the program
    FILE *infile_tornado;   //The Input tornado.txt file
    FILE *outfile_report;   //The Output Report.txt file

    int fujita_scale;   //first data on each line

    float path_length_miles;    //Path length of the tornado

    float path_width_yards;   //path_width of the tornado in yards

    float affected_area;    //calculated area affected by each tornado

    float running_total;    //the running total of the affected area

    int data_fetched;   //used to check if data was fetched from the file

    //Function Calls
    Welcome (); //Prints a welcome statement and tells the user the purpose of the program

    Open_File (infile_tornado); //Opens the tornado file and reads from it
    //printf("\nTest - Called Open_File\n"); //testing the open function

        //Open the file
    infile_tornado = fopen("tornado.txt", "r");

    //Check if file is opened
    if (!(infile_tornado))
    {
        printf("Error opening Report.txt file.\nPlease check if the file exists.\n");
        //return 404;
    }
    else //prints a success message to the terminal
    {
        printf("tornado.txt file opened successfully.\n");
        //return 0;
    }


    Open_OutFile (outfile_report);  //Creates or Opens the Report.txt file
    //printf("\nTest - Called Open_OutFile\n"); //testing to check if it ran successfully

    //Creates/Opens the Report.txt file
    outfile_report = fopen("Report.txt", "w");
    //printf("Test - outfile report ran\n");

    //Check if file is opened successfully and prints a message to the terminal
    if (!(outfile_report))
    {
        printf("Error opening Report.txt file.\nPlease check if the file exists.\n");
        //return 404;
    }
    //Else it prints an error message to the terminal
    else
    {
        printf("Report.txt File opened successfully.");
        //return 0;
    }

    //prints the first column to the Report.txt file
    fprintf(outfile_report, "EF Rating\t\tPath Length\t\tPath Width\t\tAffected Area\n");
    fprintf(outfile_report, "Fujita Scale\t(Miles)\t\tYards\t\t\tSquare Miles\n");

    //Prints the data to the Report.txt file
    while (Get_Data (infile_tornado, &fujita_scale, &path_length_miles, &path_width_yards))
    {
        //printf("\nTest - Entered the while loop\n"); //testing to check when the while loop starts

        //Calculates the area affected for each tornado and keeps a running total of the areas
        Calc_Area (&affected_area, &path_length_miles, &path_width_yards);
        //printf("\nTest - Called Calc_Area\n");

        //Prints one line into the report file
        Print_Line (outfile_report, &fujita_scale, &path_length_miles, &path_width_yards, &affected_area);
        //printf("\nTest - Called Print_Line\n");

        //Adds the affected area to the running total
        running_total += affected_area;
        //printf("\nTest - Added the affected area to the running total\n");
    }

    //prints the total area affected to the report file
    float total_area = running_total;
    //printf("\nTest - Created a local variable to store the running total\n");
    fprintf(outfile_report, "\nTotal Area Affected: %.4f square miles", total_area);
    printf("Report printed successfully.");

    //Calls the End_Program function to close the files and print a success message to the terminal
    End_Program (infile_tornado, outfile_report);
    //printf("\nTest - Called End_Program\n"); //testing to check if it ran successfully

    printf("\nThe program ran successfully!\n");

    return 0;
}


//This function prints a welcome statement and tells the user the purpose of the program
void Welcome ()
{
    printf("\n\nHello World!\nWelcome to the Tornado Report Program\n");
    printf("This program will read the tornado.txt file and create a report [Report.txt]");
    printf("The report will contain the following information:\n");
    printf("EF rating, Path Length (miles), Path Width (yards), Affected Area (sq miles)\n");
    printf("Below this, it will print the total area affected by the tornadoes.\\n");
}

//This function opens the tornado file and reads from it
//It then prints error or success message to the terminal
int Open_File (FILE *infile_tornado)
{
    //Found out that this function is not needed
}

//This function creates or opens the Report.txt file
//It then tells the terminal if file is successfully opened or not
int Open_OutFile (FILE *outfile_report)
{
    //Found out that this function is not needed
}


//This function reads a line of data from the tornado.txt
//Stores them into the pointers
//Uses a local variable [data_fetching]
int Get_Data (FILE *infile_tornado, int *fujita_scale, float *path_length_miles, float *path_width_yards)
{
    //printf("Test - Opened Get_Data\n");

    int data_fetching;
    //printf("Test - Declared data_fetching\n");

    //BUGGGG - This code is leading to a segmentation fault
    data_fetching = fscanf(infile_tornado, "%d %f %f", fujita_scale, path_length_miles, path_width_yards);
    //printf("Test - Data_fetching has been done\n");

    if (data_fetching == EOF)
    {
        printf("End of file reached.\n");
        return 0;
    }

    //checks if we have 3 data fetched from the file
    else if (data_fetching != 3)
    {
        printf("Error reading data from file.\n");
        return 0;
    }

    //else it prints a success message to the terminal
    else
    {
        printf("Data fetched successfully.\n");
        return 1;
    }

    //printf("Test - Get_Data ran successfully.\n");
}

//This function calculates the area affected for each tornado and keeps a running total of the areas
void Calc_Area (float *affected_area, float *path_length_miles, float *path_width_yards)
{
    //printf("Test - Opened Calc_Area\n");
    
    //converts the path_width from yards to miles
    float path_width_miles = *path_width_yards / 1760.0;
    //printf("Test - Converted path_width from yards to miles\n");

    //calculates the affected area for each tornado
    float affectedArea = *path_length_miles * path_width_miles;
    *affected_area = affectedArea;

    //printf("Test - Calculated the affected area\n");
}

//This function prints one line into the report file
int Print_Line (FILE *outfile_report, int *fujita_scale, float *path_length_miles, float *path_width_yards, float *affected_area)
{
    //printf("Test - Opened Print_Line\n");

    fprintf(outfile_report, "%d \t\t\t%8.4f\t\t%7.2f\t\t%8.4f", *fujita_scale, *path_length_miles, *path_width_yards, *affected_area);
    fprintf(outfile_report, "\n");

    //printf("Test - Printed the line\n");
    return 0;
}

//This function closes the files and prints a message to the terminal
void End_Program (FILE *infile_tornado, FILE *outfile_report)
{
    //printf("\nTest - Opened End_Program\n");
    
    fclose(infile_tornado);
    fclose(outfile_report);
    printf("Files closed successfully.\n");
}