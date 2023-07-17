/*
Program and Question by John Akujobi
Created on the 9th of Decemeber 2022
Part 0 and Part 1 completed on the 12th of December 2022


A text file “Brookings Rainfall 2020-2022.txt” contains the average precipitation per month for each month of the past 4 years.

The first column is for the months of 2022, 2nd column for that of 2021, 3rd for 2020.

- For example
    - Jan22    Jan21   Jan20
    - Feb22   Feb21   Feb20
    - Mar22   Mar21   Mar20
    - Apr22   Apr21   Apr20
    
- Contents of Brookings Rainfall 2020-2022.txt
    
    0.88 0.66 0.43
    
    0.30 0.54 0.49
    
    0.31 2.62 0.59
    
    1.73 1.84 0.77
    
    5.10 1.61 2.98
    
    2.30 0.72 3.11
    
    4.36 2.52 4.01
    
    3.40 1.43 1.73
    
    0.83 3.29 1.65
    
    1.05 4.33 0.93
    
    2.17 0.44 1.51
    
    0.41 1.20 0.26
    
    This data was fetched from the historic data from weatherwx.com. [Brookings SD Climate Averages, Monthly Weather Conditions (weatherwx.com)](https://www.weatherwx.com/climate-averages/sd/brookings.html)
    
    This is all except for Dec 22, in which the value of 0.41 was used to ensure complete data
    
- Part 0
    - Open the file and read
    - Create 3 arrays containing the values of each year
        - E.g `Y2022[ ]` can contain the values for the year 2022
    - Print the contents to the screen
- Part1
    - Calculate the mean for each month for the 3 years
        - E.g Mean of Jan = (Jan22 + Jan21 + Jan20) / 3.0
    - Calculate the total rainfall for each year
    - Find the month with the highest rainfall for each year and the amount of rainfall
    - Find the month with the least rainfall for each year and the amount of rainfall
    - Print to a report file “Precipitation analytics.txt” and to the terminal
        - In a table, print
            - Headers: “Month    2022    2021    2020   Mean”
            - Monthly average precipitation
            - Mean for each month for the past 3 years
            - Total rainfall for each year
        - Below the table, print
            - The month with the highest rainfall for each year and the amount of rainfall
            - The month with the least rainfall for each year and the amount of rainfall
            
- Part 2
    - Bubble Sort the numbers for the years and print using the example below
        - Sorted 2022 = {num1, num2, num3….}
        - Sorted 2021 = {num1, num2, num3….}
        - Sorted 2020 = {num1, num2, num3….}
    - Find the median numbers in the years using the example below
        - Median number for 2022 is ###
        - Median number for 2022 is ###
        - Median number for 2022 is ###
        
- Part 3
    - Ask the user for 12 numbers between 5 and 10 and store them in an array (e.g UserN [12])
        - Make sure that the numbers are
    - Create an array Y22UserN which is the multiple of UserN[12] and the integer version of Y2022[ ]
        - This means each value in Y2022[ ] will multiply with its corresponding value in UserN[12]
        - E.g Y22UserN[ 1 ] = Y2022[ 1 ] * UserN[ 1 ]
    - Sort the array Y22UserN and find its mode
    - Print to the terminal, the values of
        - UserN[ ]
        - Y2022[ ]
        - Y22UserN[ ]
    - Print the mode of Y22UserN[ ]
    - Print the histogram of the valuesin Y22UserN[ ]
*/


#include <stdio.h>

//#define SIZE 12	//For the number of months in a year

//This function simply prints a single array
void printArray (float arr[], int SIZE);	//Function Prototype
void printArray (float arr[], int SIZE)
{
    //int SIZES = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < SIZE; i++ )
	{
		printf("%1.2f\n", arr[i]);
	}

	printf("\n");	//Adds an empty line

	return;
}
//printArray (arr[], SIZE)


//This function gets data from the file
void getdata (float Y22[], float Y21[], float Y20[], int SIZE);
void getdata (float Y22[], float Y21[], float Y20[], int SIZE)
{
    int dataread, gotdata; 

	FILE *inFile = fopen("Brookings_Rainfall_2020_2022.txt", "r");

	/* for (i = 0, dataread == 3, i++)
	{
		dataread = fscanf (inFile, "%f %f %f", Y22[i], Y21[i], Y20[i],);

		if (dataread == 3)
		{
			return 3;
		}
		else if (dataread == EOF)
		{
			printf()
			return 0;
		}
		else if (dataread == 3)
		{
			return 1;
		}
	}*/

	int i = 0;
	do {
		dataread = fscanf (inFile, "%f %f %f", &Y22[i], &Y21[i], &Y20[i]);
		i++;
	} while (dataread == 3);


	if (dataread == 3)
	{
		printf("\nData was all fetched\n");
	}
	else if (dataread == EOF)
	{
		printf("\nLast Line reached\n");
	}
	else
	{
		printf("\nThere was an error\n");
	}

    fclose(inFile);

	return;
}
//getdata (Y22[], Y21[], Y20[], SIZE);


//This function calculates the sum of numbers in an array 
float calcSumArr (float arr[], int SIZE);
float calcSumArr (float arr[], int SIZE)
{
    //Initialize the local sum variable
    float sum = 0.0;

    for (int i = 0; i<SIZE ; i++)
    {
        sum = sum + arr[i];
    }

    return sum;
}
//calcSumArr (arr[], SIZE);


//This function calculates the sum of numbers in an array 
void calcMeanMonthly (float arr1[], float arr2[], float arr3[], float MonthlyMean[], int SIZE);
void calcMeanMonthly (float arr1[], float arr2[], float arr3[], float MonthlyMean[], int SIZE)
{
    for (int i = 0; i<SIZE ; i++)
    {
        MonthlyMean[i] = (arr1[i] + arr2[i] + arr3[i])/3.0;
    }

    return;
}
//calcMeanMonthly (arr1[], arr2[], arr3[], MonthlyMean[], SIZE)


//It prints the month according to the integer input which represents a position in the array
void printmonth (int month);
void printmonth (int month)
{
    switch (month)
    {
        case 0:
            printf("JAN");
            break;
        case 1:
            printf("FEB");
            break;
        case 2:
            printf("MAR");
            break;
        case 3:
            printf("APR");
            break;
        case 4:
            printf("MAY");
            break;
        case 5:
            printf("JUN");
            break;
        case 6:
            printf("JUL");
            break;
        case 7:
            printf("AUG");
            break;
        case 8:
            printf("SEP");
            break;
        case 9:
            printf("OCT");
            break;
        case 10:
            printf("NOV");
            break;
        case 11:
            printf("DEC");
            break;
    }

    return;
}


//This finds the largest number
int highest(float arr[], int SIZE);
int highest(float arr[], int SIZE)
{
    int LPos=0; //Position of the largest value, equal to the i at that time
    for (int i = 0; i<SIZE; i++)
    {
        if (arr[i]>arr[LPos])
        {
            LPos = i;
        }
    }

    return LPos;
}


//This finds the smallest number
int smallest(float arr[], int SIZE);
int smallest(float arr[], int SIZE)
{
    int SPos=0; //Position of the largest value, equal to the i at that time
    for (int i = 0; i<SIZE; i++)
    {
        if (arr[i]<arr[SPos])
        {
            SPos = i;
        }
    }

    return SPos;
}


//Sorts the array
void sortArray(float arr[], int SIZE);
void sortArray(float arr[], int SIZE)
{
    //! Sheesh, i need to learn this one
}


//Prints the result to the terminal
void printresultsT (float arr1[], float arr2[], float arr3[], float MonthlyMean[], int SIZE);
void printresultsT (float arr1[], float arr2[], float arr3[], float MonthlyMean[], int SIZE)
{
    //Print the header
    printf("\nMON\tY22\tY21\tY20\tMean");

    //Print the Months, and values
    for (int i = 0; i<SIZE ; i++)
    {
        printf("\n");
        printmonth(i);
        printf( "\t%1.2f\t%1.2f\t%1.2f\t%1.2f", arr1[i], arr2[i], arr3[i], MonthlyMean[i]);
    }

    float sum1 = (calcSumArr (arr1, SIZE));
    float sum2 = (calcSumArr (arr2, SIZE));
    float sum3 = (calcSumArr (arr3, SIZE));
    float Msum = (calcSumArr (MonthlyMean, SIZE));

    //Prints a line showing the sum per year
    printf("\n\nTotal\t%1.2f\t%1.2f\t%1.2f\t%1.2f", sum1, sum2, sum3, Msum);

    //Prints a line showing the Average per year
    printf("\nAverage\t%1.2f\t%1.2f\t%1.2f\t%1.2f", sum1/SIZE, sum2/SIZE, sum3/SIZE, Msum/SIZE);

    //__________________________Part 2

    int LPos; //Declaring the variable LPos
    
    LPos = highest (arr1, SIZE);
    printf("\n\nLargest in 2022 is %1.2f in the month of ", arr1[LPos]);
    printmonth(LPos);

    LPos = highest (arr2, SIZE);
    printf("\nLargest in 2021 is %1.2f in the month of ", arr2[LPos]);
    printmonth(LPos);

    LPos = highest (arr3, SIZE);
    printf("\nLargest in 2022 is %1.2f in the month of ", arr3[LPos]);
    printmonth(LPos);

    printf("\n");


    int SPos; //Declaring the variable SPos
    
    SPos = smallest (arr1, SIZE);
    printf("\n\nLeast in 2022 is %1.2f in the month of ", arr1[SPos]);
    printmonth(SPos);

    SPos = smallest (arr2, SIZE);
    printf("\nLeast in 2021 is %1.2f in the month of ", arr2[SPos]);
    printmonth(SPos);

    SPos = smallest (arr3, SIZE);
    printf("\nLeast in 2022 is %1.2f in the month of ", arr3[SPos]);
    printmonth(SPos);

    printf("\n");


    return;
}
//printresultsT (arr1[], arr2[], arr3[], MonthlyMean[], SIZE)


//Prints the result to the terminal
void printresultsFile (float arr1[], float arr2[], float arr3[], float MonthlyMean[], int SIZE);
void printresultsFile(float arr1[], float arr2[], float arr3[], float MonthlyMean[], int SIZE)
{
    FILE *outFile;
    outFile = fopen("Precipitation_output_John Akujobi.txt", "w");

    //Checks if it opened the output file
    if (!(outFile))
    {
        printf("\nError opening Report.txt file.\nPlease check if the file exists.\n");
        //return 404;
    }
    //Else it prints an error message to the terminal
    else
    {
        printf("\nReport.txt File opened successfully.\n");
        //return 0;
    }

    //Print the header
    fprintf(outFile,"MON\tY22\tY21\tY20\tMean");

    //Print the Months, and values
    for (int i = 0; i<SIZE ; i++)
    {
        fprintf(outFile,("\n"));
        
        //Prints the month to file using a switch case
        switch (i)
        {
            case 0:
                fprintf(outFile,"JAN");
                break;
            case 1:
                fprintf(outFile,"FEB");
                break;
            case 2:
                fprintf(outFile,"MAR");
                break;
            case 3:
                fprintf(outFile,"APR");
                break;
            case 4:
                fprintf(outFile,"MAY");
                break;
            case 5:
                fprintf(outFile,"JUN");
                break;
            case 6:
                fprintf(outFile,"JUL");
                break;
            case 7:
                fprintf(outFile,"AUG");
                break;
            case 8:
                fprintf(outFile,"SEP");
                break;
            case 9:
                fprintf(outFile,"OCT");
                break;
            case 10:
                fprintf(outFile,"NOV");
                break;
            case 11:
                fprintf(outFile,"DEC");
                break;
        }

        //Prints the data to the file
        fprintf(outFile,"\t%1.2f\t%1.2f\t%1.2f\t%1.2f", arr1[i], arr2[i], arr3[i], MonthlyMean[i]);
    }


    float sum1 = (calcSumArr (arr1, SIZE));
    float sum2 = (calcSumArr (arr2, SIZE));
    float sum3 = (calcSumArr (arr3, SIZE));
    float Msum = (calcSumArr (MonthlyMean, SIZE));

    //Prints a line showing the sum per year
    fprintf(outFile,"\n\nTotal\t%1.2f\t%1.2f\t%1.2f\t%1.2f", sum1, sum2, sum3, Msum);

    //Prints a line showing the Average per year
    fprintf(outFile,"\nAverage\t%1.2f\t%1.2f\t%1.2f\t%1.2f", sum1/SIZE, sum2/SIZE, sum3/SIZE, Msum/SIZE);


    fprintf(outFile,"\n");  //Print an empty line under in the file

    fclose(outFile); //Close the file

    printf("\nResults have been posted to the output file \"Precipitation output - John Akujobi.txt\"\n\n");

    return;
}
//printresultsFile (arr1[], arr2[], arr3[], MonthlyMean[], SIZE)




//___________________________________________________________________________________________________________________________________________
int main ()
{
    //FILE *inFile;
    
    int SIZE = 12;  //For the number of months in a year

	float Y22[12]; 	//stores numbers for 2022
	float Y21[12];	//stores numbers for 2021
	float Y20[12];	//stores numbers for 2020
    float MonthlyMean[12];

    //Calls getdata to fetch data from the file
    //Assign it into the arrays fro the years
	getdata (Y22, Y21, Y20, SIZE);

    //Prints the years' arrays to the terminal
    printf("\nYear 2022\n");
	printArray(Y22, SIZE);  //Prints the numbers for 2022
    printf("\nYear 2021\n");
	printArray(Y21, SIZE);  //Prints the numbers for 2021
    printf("\nYear 2020\n");
	printArray(Y20, SIZE);  //Prints the numbers for 2020

    //Calculates the monthly mean and inserts them into the array MonthlyMean
    calcMeanMonthly(Y22, Y21, Y20, MonthlyMean, SIZE);

    //Prints the Monthly mean to the terminal
    printf("\nMonthly Mean\n");
    printArray(MonthlyMean, SIZE);

    //Prints the months, data and monthly mean in a table to the terminal
    printresultsT (Y22, Y21, Y20, MonthlyMean, SIZE);

    //Prints the results to the file
    printresultsFile (Y22, Y21, Y20, MonthlyMean, SIZE);


	return 0;
}