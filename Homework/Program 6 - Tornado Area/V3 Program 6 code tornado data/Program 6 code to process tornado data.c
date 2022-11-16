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



Functions (for each function, give the function’s prototype and 1 or 2 lines describing how the function works.)
1.	void Welcome ();
        Prints a welcome statements and tells the user the purpose of the program

2.	int Open_File (File *infile_tornado);
        Opens the tornado file and reads from it
        Prints error or success message to the terminal
        Returns 404 if unsuccessful
3.	int Get_Data (File *infile_tornado, int *fujita_scale, float *path_length_miles, int *path_width_yards);
        It reads a line of data from the tornado.txt
        Stores them into the pointers
        Uses a local variable [data_fetched]
4.	void Calc_Area (float *affected_area, float *path_length_miles, int *path_width_yards);
        Calculates the area affected for each tornado and keeps a running total of the areas
        Uses the formula [path_width_miles * path_length_yards /1760]
            Divided by 1760 to convert the yards to miles
5.	int Open_OutFile (File *outfile_report);
        Creates/ Opens the Repot.txt file
        Tells the terminal if file is successfully opened or not
        Returns 404 if unsuccessful

6.	int Print_Line (File *outfile_report, int *fujita_scale, float *path_length_miles, int *path_width_yards, float *affected_area););
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

#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
void Welcome ();
int Open_File (FILE *infile_tornado);
int Get_Data (FILE *infile_tornado, int *fujita_scale, float *path_length_miles, int *path_width_yards);
void Calc_Area (float *affected_area, float *path_length_miles, int *path_width_yards);
int Open_OutFile (FILE *outfile_report);
int Print_Line (FILE *outfile_report, int *fujita_scale, float *path_length_miles, int *path_width_yards, float *affected_area);
//void Print_Report (FILE *outfile_report, float *running_total);
void End_Program (FILE *infile_tornado, FILE *outfile_report);

int main ()
{
    //Declare Variables

    //The files used by the program
    FILE *infile_tornado;   //The Input tornado.txt file
    FILE *outfile_report;   //The Output Report.txt file

    int fujita_scale;    //first data on each line, has to be between 0 - 6

    float path_length_miles;    //Path length of the tornado

    int path_width_yards;   //path_width of the tornado in yards

    float affected_area;    //calculated area affected by each tornado

    float running_total;    //the running total of the affected area

    int data_fetched;   //used to check if data was fetched from the file

    //Function Calls
    Welcome (); //Prints a welcome statement and tells the user the purpose of the program

    Open_File (infile_tornado); //Opens the tornado file and reads from it
    printf("\nCalled Open_File\n"); //testing the open function

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
    printf("\nCalled Open_OutFile\n"); //testing to check if it ran successfully

    outfile_report = fopen("Report.txt", "w");
    printf("outfile report ran\n");

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

    Get_Data (infile_tornado, &fujita_scale, &path_length_miles, &path_width_yards); //Reads a line of data from the tornado.txt
    printf("\nCalled Get_Data\n"); //testing to check if it ran successfully

    while (Get_Data (infile_tornado, &fujita_scale, &path_length_miles, &path_width_yards))
    {
        printf("\nEntered the while loop\n"); //testing to check when the while loop starts

        Calc_Area (&affected_area, &path_length_miles, &path_width_yards);
        //Calculates the area affected for each tornado and keeps a running total of the areas

        printf("\nCalled Calc_Area\n"); //testing to check Calc_Area ran successfully

        Print_Line (outfile_report, &fujita_scale, &path_length_miles, &path_width_yards, &affected_area);

        printf("\nCalled Print_Line\n");

        running_total += affected_area;

    }

    float total_area = running_total;

    fprintf(outfile_report, "Total Area Affected: %f", total_area);
    printf("Report printed successfully.");

    End_Program (infile_tornado, outfile_report);

    return 0;
}


//This function prints a welcome statement and tells the user the purpose of the program
void Welcome ()
{
    printf("\n\nHello World!\nWelcome to the Tornado Report Program\n");
    printf("This program will read the tornado.txt file and create a report [Report.txt] containing the following data, printed in columns:\n");
    printf("EF rating, Path Length (miles), Path Width (yards), Affected Area (sq miles)\n");
    printf("Below this, it will print the total area affected by the tornadoes.\\n");
}

//This function opens the tornado file and reads from it
//It then prints error or success message to the terminal
int Open_File (FILE *infile_tornado)
{
    //
}

int Open_OutFile (FILE *outfile_report)
{
    //
}


int Get_Data (FILE *infile_tornado, int *fujita_scale, float *path_length_miles, int *path_width_yards)
{
    printf("Opened Get_Data\n");
    int data_fetching;

    printf("declared data_fetching\n");

    //BUGGGG - This code is leading to a segmentation fault
    data_fetching = fscanf(infile_tornado, "%d %f %d", fujita_scale, path_length_miles, path_width_yards);

    printf("data_fetching has been done");

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

    printf("Get_Data ran successfully.\n");
}

void Calc_Area (float *affected_area, float *path_length_miles, int *path_width_yards)
{
    float path_width_miles = *path_width_yards / 1760.0;
    float affectedArea = *path_length_miles * path_width_miles;
    *affected_area = affectedArea;
}

int Print_Line (FILE *outfile_report, int *fujita_scale, float *path_length_miles, int *path_width_yards, float *affected_area)
{
    fprintf(outfile_report, "%d %f %d %f", *fujita_scale, *path_length_miles, *path_width_yards, *affected_area);
    return 0;
}



void End_Program (FILE *infile_tornado, FILE *outfile_report)
{
    fclose(infile_tornado);
    fclose(outfile_report);
    printf("Files closed successfully.");
}
