/*

Write a program to read the tornado.txt file and create a report. 
Store the tornado report into a file named report.txt.  
The report should contain the following data for each part, printed in columns:
EF rating 
Path Length (miles)
Path Width (yards)
Affected Area (sq miles)
Below the part table, print the total area affected.

Data Storage (Defined in Main)
File *infile_tornado
•	Pointer to Input file that holds the tornado.txt file
File *outfile_report
•	Pointer to Output file that connects to Report.txt file
int fujita_scale
•	first data on each line
•	scale of 0 - 6
float path_length_miles
•	Path length of tornado
int path_width_yards
•	path_width of the tornado in yards
float affected_area
•	calculated area affected by each tornado
float running_total
•	the running total of affected area









 

Functions (for each function, give the function’s prototype and 1 or 2 lines describing how the function works.)
1.	void Welcome (); 
        Prints a welcome statements and tells the user the purpose of the program
2.	int Open_File (infile_tornado); 
        Opens the tornado file and reads from it
        Prints error or success message to the terminal
        Returns 404 if unsuccessful
3.	int Get_Data (File *infile_tornado, int *fujita_scale, float *path_length_miles, int *path_width_yards); 
        It reads a line of data from the tornado.txt
        Stores them into the pointers
        Uses a local variable [data_fetched]
4.	void Calc_Area (float path_length_miles, int path_width_yards, float *affected_area, float *running_total); 
        Calculates the area affected for each tornado and keeps a running total of the areas
        Uses the formula [path_width_miles * path_length_yards /1760] 
            Divided by 1760 to convert the yards to miles
5.	int Open_OutFile (outfile_report); 
        Creates/ Opens the Repot.txt file
        Tells the terminal if file is successfully opened or not
        Returns 404 if unsuccessful
6.	int Print_Line (File *outfile_report, int fujita_scale, float path_length_miles, int path_width_yards, float affected_area, float running_total); 
        Prints one line into the report file
7.	void Print_Report (); 
        Prints all the lines to the report and then prints the total area affected 
        While Get_Data ==1,
        it uses Calc_Area to calculate the area
        then calls Print_Line to print the information to the file
        After this loop ends, it prints the Total Area to the file using variable running_total
        Then prints a success message to the terminal
        Prints each line to the terminal to let user know the progress
9.	void End_Program (); 
        Closes the two files
        Prints an exit message to the terminal to signify the end of the program

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function Prototypes
void Welcome ();

int Open_File (FILE *infile_tornado);

int Get_Data (FILE *infile_tornado, int *fujita_scale, float *path_length_miles, int *path_width_yards);

void Calc_Area (float path_length_miles, int path_width_yards, float *affected_area, float *running_total);

int Open_OutFile (FILE *outfile_report);

int Print_Line (FILE *outfile_report, int fujita_scale, float path_length_miles, int path_width_yards, float affected_area, float running_total);

void Print_Report ();

void End_Program ();

int main()
{
    //Data Storage
    FILE *infile_tornado;

    FILE *outfile_report;
    int fujita_scale;
    float path_length_miles;
    int path_width_yards;
    float affected_area;
    float running_total;
    
    //Function Calls
    Welcome ();
    Open_File (infile_tornado);
    Open_OutFile (outfile_report);
    Print_Report ();
    End_Program ();
    
    system("PAUSE");
    return 0;
}

void Welcome ()
{
     printf("Welcome to the Tornado Report Program");
        printf("This program will read the tornado.txt file and create a report");
        printf("The report will contain the following data for each part, printed in columns:");
        printf("EF rating");
        printf("Path Length (miles)");
        printf("Path Width (yards)");
        printf("Affected Area (sq miles)");
        printf("Below the part table, it will print the total area affected");
}

int Open_File (FILE *infile_tornado)
{
    infile_tornado = fopen("tornado.txt", "r");
    if (infile_tornado == NULL)
    {
        printf("Error opening file");
        return 404;
    }
    else
    {
        printf("File opened successfully");
        return 0;
    }
}

int Get_Data (FILE *infile_tornado, int *fujita_scale, float *path_length_miles, int *path_width_yards)
{
    int data_fetched;
    data_fetched = fscanf(infile_tornado, "%d %f %d", &fujita_scale, &path_length_miles, &path_width_yards);
    return data_fetched;
}


void Calc_Area (float path_length_miles, int path_width_yards, float &affected_area, float &running_total)
{
    *affected_area = path_length_miles * path_width_yards / 1760;
    *running_total = *running_total + *affected_area;
}

int Open_OutFile (FILE *outfile_report)
{
    outfile_report = fopen("report.txt", "w");
    if (outfile_report == NULL)
    {
        printf("Error opening file");
        return 404;
    }
    else
    {
        printf("File opened successfully");
        return 0;
    }
}

int Print_Line (FILE *outfile_report, int fujita_scale, float path_length_miles, int path_width_yards, float affected_area, float running_total)
{
    fprintf(outfile_report, "%d %f %d %f %f", fujita_scale, path_length_miles, path_width_yards, affected_area, running_total);
}

void Print_Report ()
{
    int data_fetched;
    while (data_fetched == 1)
    {
        data_fetched = Get_Data (infile_tornado, &fujita_scale, &path_length_miles, &path_width_yards);
        Calc_Area (path_length_miles, path_width_yards, &affected_area, &running_total);
        Print_Line (outfile_report, fujita_scale, path_length_miles, path_width_yards, affected_area, running_total);
        printf("Line printed");
    }
    fprintf(outfile_report, "Total Area Affected: %f", running_total);
    printf("Report printed");
}

void End_Program ()
{
    fclose(infile_tornado);
    fclose(outfile_report);
    printf("Program ended");
}
