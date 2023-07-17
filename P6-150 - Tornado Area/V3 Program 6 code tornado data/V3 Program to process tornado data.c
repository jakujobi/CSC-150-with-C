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

Data Storage (Defined in Main)
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


Functions
The main function
        Calls the necessary functions
        Uses a while loop to print the report
        - It uses Calc_Area to calculate the area
        - Then calls Print_Line to print the information to the file
        - After this loop ends, it prints the Total Area to the report file using the variable running_total
        - Then prints a success message to the terminal
        - Prints each line to the terminal to let the user know the progress


1.	void Welcome (); 
        Prints a welcome statement and tells the user the purpose of the program

2.	Open_File
        Opens the tornado file and reads from it
        Prints error or success message to the terminal

3.	Get_Data
        It reads a line of data from the tornado.txt
        The line of data read includes the fujita_scale integer, 

4.	Calc_Area 
        Calculates the area affected for each tornado and keeps a running total of the areas
        Uses the formula [path_width_miles * path_length_yards /1760] 
            Divided by 1760 to convert the yards to miles

5.	Open_OutFile
        Creates/ Opens the Repot.txt file
        Tells the terminal if the file is successfully opened or not
        
6.	Print_Line
        Prints one line into the report file


8.	End_Program
        Closes the files
        Prints a success message to the terminal
*/

#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void Welcome ();
int Open_File (FILE *infile_tornado);
int Get_Data (FILE *infile_tornado, int *fujita_scale, float *path_length_miles, float *path_width_yards);
void Calc_Area (float path_length_miles, float path_width_yards, float *affected_area, float *running_total);
int Open_OutFile (FILE *outfile_report);
int Print_Line (FILE *outfile_report, int fujita_scale, float path_length_miles, float path_width_yards, float affected_area);
void End_Program (FILE *infile_tornado, FILE *outfile_report);

int main ()
{
        // Local Declarations
        FILE *infile_tornado;
        FILE *outfile_report;
        int fujita_scale;
        float path_length_miles;
        float path_width_yards;
        float affected_area;
        float running_total = 0;

        // Statements
        Welcome ();
        if (Open_File (infile_tornado))
        {
                while (Get_Data (infile_tornado, &fujita_scale, &path_length_miles, &path_width_yards))
                {
                Calc_Area (path_length_miles, path_width_yards, &affected_area, &running_total);
                Print_Line (outfile_report, fujita_scale, path_length_miles, path_width_yards, affected_area);
                }
                printf("Total Area Affected: %f", running_total);
                printf("\n");
                printf("Success! The report has been created.");
                printf(" ");
                printf("Please check the report.txt file.");
                printf(" ");

                End_Program (infile_tornado, outfile_report);
                }
                else
                {
                printf("Error! The file could not be opened.");
                printf(" ");
                printf("Please check the file name and try again.");
                printf(" ");
                }
        return 0;
}

void Welcome ()
{
        printf("Welcome to the Tornado Report Program!");
        printf(" ");
        printf("This program will read the tornado.txt file and create a report.");
        printf(" ");
        printf("The report will be stored in a file named report.txt.");
        printf(" ");
        printf("The tornado data contains the Fujita scale, the tornado path length in miles, and the tornado path width in yards.");
        printf(" ");
        printf("The report will contain the following data for each part, printed in columns:");
        printf(" ");
        printf("EF rating, Path Length (miles), Path Width (yards), Affected Area (sq miles).");
        printf(" ");
        printf("Below the part table, the total area affected will be printed.");
        printf(" ");
        printf(" ");
}

int Open_File (FILE *infile_tornado)
{
        infile_tornado = fopen("tornado.txt", "r");
        if (infile_tornado == NULL)
        {
                return 0;
        }
        else
        {
                printf("Success! The file has been opened.");
                printf(" ");
                return 1;
        }
}

int Get_Data (FILE *infile_tornado, int *fujita_scale, float *path_length_miles, float *path_width_yards)
{
        fscanf(infile_tornado, "%d %f %f", fujita_scale, path_length_miles, path_width_yards);
        if (feof(infile_tornado))
        {
                return 0;
        }
        else
        {
                return 1;
        }
}

void Calc_Area (float path_length_miles, float path_width_yards, float *affected_area, float *running_total)
{
        *affected_area = (path_length_miles * path_width_yards) / 1760;
        *running_total = *running_total + *affected_area;
}

int Open_OutFile (FILE *outfile_report)
{
        outfile_report = fopen("report.txt", "w");
        if (outfile_report == NULL)
        {
                return 0;
        }
        else
        {
                printf("Success! The report file has been created.");
                printf(" ");
                return 1;
        }
}

int Print_Line (FILE *outfile_report, int fujita_scale, float path_length_miles, float path_width_yards, float affected_area)
{
        fprintf(outfile_report, "%d %f %f %f", fujita_scale, path_length_miles, path_width_yards, affected_area);
        printf("EF Rating: %d", fujita_scale);
        printf(" ");
        printf("Path Length: %f", path_length_miles);
        printf(" ");
        printf("Path Width: %f", path_width_yards);
        printf(" ");
        printf("Affected Area: %f", affected_area);
        printf(" ");
        printf(" ");
}

void End_Program (FILE *infile_tornado, FILE *outfile_report)
{
        fclose(infile_tornado);
        fclose(outfile_report);
}

//Thank you for your help!