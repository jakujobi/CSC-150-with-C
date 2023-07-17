/* Caleb McGregor
   11-11-2022
   CSC 150 Tu Th 9:30
   Program 6 Pointers
*/

// In this program it demonstrates pointers, loops, and utilizing files
// to create a report about tornadoes.

#include <stdio.h>

// function prototypes
void printWelcome ();                                                          // gives opening to program
int getFile (FILE* inTornado, int* ratingEF, float* pathLength, int* pathWidth);// accesses the file tornado.txt
void calcPath (float pathLength, int pathWidth,int affectArea, int* runTotal);   // takes length and width multiplies and adds to running total
int printFile (FILE* outReport,int ratingEF,
                float pathLength, int pathWidth, int affectArea, int runTotal);  // takes what is calculated from calcPath and prints outfile report.txt
void printBye ();                                                              // gives closing of program

int main ()
{
// local declaration
    FILE* inTornado; //infile
	FILE* outReport; //outfile

	int ratingEF;    // EF rating
	float pathLength;  // Length of Tornado path (miles)
	int pathWidth;   // Width of Tornado path  (yards)
	int affectArea;  // Total affected area of Tornado (square miles)
	int runTotal;    // Running total (square miles)


// Welcome to program
    printWelcome ();

// Retrieve file
    if (!(inTornado = fopen ("tornado.txt", "r"))) // opening infile
    {
    printf("\aError opening tornado file\n");
    return 100;
    }

    else
    {
    printf("Input file opened successfully\n");
    }

    if (!(outReport = fopen ("report.txt", "w"))) // opening outfile
    {
        printf("\aError opening report file\n");
    return 102;
    }
    else
    {
        printf("Output file created/opened successfully\n");
    }

// Calculates total affected area and prints into outfile
    while (getFile (inTornado, &ratingEF, &pathLength, &pathWidth))
	   {
	    calcPath (pathLength, pathWidth, affectArea, &runTotal);
	    printFile (outReport, ratingEF, pathLength, pathWidth, affectArea, runTotal);
	   }

    fclose (inTornado);
	fclose (outReport);

// End the program
    printBye ();

    return;
}


void printWelcome ()
{
    printf("________________________________________________________\n");
    printf("|Every year, tornadoes run rampant through states like |\n");
    printf("|Oklahoma causing miles of damage. This program shows  |\n");
    printf("|the affected area via the people who chase them...    |\n");
    printf("| These are their stories...                           |\n");
    printf("|            CSI: Tornado Analyst Unit                 |\n\n");

    return;
}


int getFile (FILE* inTornado, int* ratingEF, float* pathLength, int* pathWidth)
{
//	Local Declarations
	int ioResult;

//	Statements
	ioResult = fscanf(inTornado, "%d %f %d", ratingEF,
	                  pathLength, pathWidth);
//    printf ("\nEF Rating: %d, Path Length: %f, Path Width: %d\n", *ratingEF, *pathLength, *pathWidth);
	
    if (ioResult == EOF)
	    return 0;
	else if (ioResult != 3)
	   {
	    printf("\aError reading data\n");
	    return 0;
	   }
	else
	   return;

}


void calcPath (float pathLength, int pathWidth, int affectArea, int* runTotal)
{
//	Local Declarations

    affectArea = pathLength * pathwidth / 1760; //the 1760 is to convert yards to miles

    runTotal = affectArea + runTotal;
    printf("pathwidthMiles: %f,    Affected Area: %d, Running Total: %d\n", pathwidthMiles, affectArea, runTotal);

    return;
}


int printFile (FILE* outReport,int ratingEF,
        float pathLength, int pathWidth, int affectArea, int runTotal)
{
//	Statements
	fprintf(outReport, " %d %lf %d %d %d\n",ratingEF, pathLength, pathWidth, affectArea, runTotal);
	return 1;
}


void printBye ()
{
    printf("| This concludes the program, the results from program |\n");
    printf("| can be accessed in file called report.txt, please    |\n");
    printf("| continue with caution! Program not responsible for   |\n");
    printf("| any incursions by tornado! Thank you and good bye :) |\n");
    printf("|______________________________________________________|\n");

    return;
}
