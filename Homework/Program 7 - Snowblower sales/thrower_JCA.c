/*
Snowblower Sales
A gaming store records the sales of snowblower (snowthrowers) during the colder months (October – March). 
The number of throwers sold is stored in a file named throwers.txt which contains 6 integer values, one per line. 
The first number is for October, the second for November, third for December, fourth for January, fifth for February, and sixth for March.

Write a program to calculate the total number of systems sold during the year,
the average number sold per month,
the month with the most sales,
the month with the least sales,
and the median number of sales.

Your program should have separate functions to:  
•	Read the data
•	Find the number of the month with the most systems sold
•	Find the number of the month with the least systems sold
•	Find the total and average (mean)
•	Sort the data
•	Find the median
•	Print the month name, given the month number (October = 1 …. March = 6).
•	Display the highest month name, lowest month name, total, average, sorted data, and median
    create a frequency array,
    use it to find the mode
    print a histogram of the data for the season.     

Created by John Akujobi
On the 4th of November, 2022
*/

/*
BUGS:

BUG#1: //! The program is running into a segmentation fault when it is trying to read the data from the file.
    The compiler is not giving any errors, and not executing the program at all.
    Tested on CodeBlocks, Visual Studio Code, Programiz, but they gave no errors.
    However, on the online Programiz compiler, it gave an error "Segmentation Fault"
    I search for meaning of this error and read that the program is trying to access an invalid memory location.

*/

//Preprocessor directives
#include <stdio.h>
#include <stdlib.h>

//Function prototypes

//This function reads the data from the file and stores it in the array
void Read_Data(int arr[], int n);

//Finds the month with the most sales
int Find_Most(int arr[]);

//Finds the month with the least sales
int Find_Least(int arr[]);

//Finds the total and average
void Calc_Total_Average(int arr[], int *total, double *average);

//Sorts the array
void Sort(int arr[], int n);

//Finds the median
double Find_Median(int arr[], int n);

//Prints the month name
void Print_Month_Name(int month);

//Displays the results
void Display(int arr[], int most, int least, int total, double average, double median, int mode);

//Builds the frequency array
void Frequency_Array(int arr[], int n, int freq_arr[], int range);

//Prints the histogram
void printHistogram(int freq_arr[], int range);

//Finding the mode
int Find_Mode(int freq_arr[], int range);


int main()
{
    //! Test #
    printf("Test#1\n");

    //Declaring the array
    int arr[6];

    //Declaring the variables
    int most, least, total, mode;
    double average, median;

    //Declaring the frequency array variables
    int freq_arr[6];
    int range = 6;

    //Declaring the constant
    const int n = 6;

    //Calling the functions
    //! Test #
    printf("Test#2\n");

    //Reading the data from the file and storing it in the array using the function Read_Data
    Read_Data(arr, n);

    //! Test #
    printf("Test#3\n");

    //Finding the month with the most sales using the function Find_Most
    most = Find_Most(arr);

    //! Test #
    printf("Test#4\n");

    //Finding the month with the least sales using the function Find_Least
    least = Find_Least(arr);

    //! Test #
    printf("Test#5\n");
    
    //Calculating the total and average using the function Calc_Total_Average
    Calc_Total_Average(arr, &total, &average);

    //! Test #
    printf("Test#6\n");
    
    //Sorting the array using the function Sort
    Sort(arr, n);

    //! Test #
    printf("Test#7\n");
    
    //Finding the median using the function Find_Median
    median = Find_Median(arr, n);

    //! Test #
    printf("Test#9\n");
    
    //Displaying the results using the function Display
    Display(arr, most, least, total, average, median, mode);

    //! Test #
    printf("Test#10\n");

    //Building the frequency array using the function Frequency_Array
    Frequency_Array(arr, n, freq_arr, range);

    //! Test #
    printf("Test#11\n");

    //Printing the histogram using the function printHistogram
    printHistogram(freq_arr, range);

    //! Test #
    printf("Test#12\n");
    
    return 0;
}

//This function reads the data from the file and stores it in the array
void Read_Data( int arr[], int n)
{
    FILE *in_thrower_file;

    if (!(in_thrower_file = fopen ("throwers.txt", "r")))
    {
    printf("throwers.txt could not be opened\n");
    return;
    }

    else
    {
        printf("throwers.txt was opened\n");
        for(int i=0; i < n; i++)
        {
            fscanf(in_thrower_file, "%d", &arr[i]);
        }

        fclose(in_thrower_file);
        return;
    }
}



//This function finds the month with the most sales
int Find_Most(int arr[])
{
    //Declaring the variables
    int most = 0;

    //Finding the month with the most sales
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] > arr[most])
        {
            most = i;
        }
    }

    return most;
}

//This function finds the month with the least sales
int Find_Least(int arr[])
{
    //Declaring the variables
    int least = 0;

    //Finding the month with the least sales
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] < arr[least])
        {
            least = i;
        }
    }

    return least;
}

//This function finds the total and average
void Calc_Total_Average(int arr[], int *total, double *average)
{
    //Declaring the variables
    int sum = 0;

    //Finding the total
    for (int i = 0; i < 6; i++)
    {
        sum += arr[i];
    }

    //Storing the total in the pointer
    *total = sum;

    //Finding the average
    *average = (double)sum / 6;
}

//This function sorts the data
void Sort(int arr[], int n)
{
    //Declaring the variables
    int i, j, min, temp;

    //This loop sorts the array in ascending order
    //using the selection sort algorithm
    //Source: https://www.geeksforgeeks.org/selection-sort/
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}



//This function finds the median
double Find_Median(int arr[], int n)
{
    //Declaring the variables
    double median;

     //Finding the median
    if (arr[2] == arr[3])
    {
        median = (double)(arr[2] + arr[3]) / 2.0;
    }
    else
    {
        median = arr[3];
    }

    //median= (arr[n/2] +arr[(n+1)/2])* 0.5;

    return median;
}

//This function prints the month name to the terminal, given the month number
void Print_Month_Name(int month)
{
    //Declaring the array
    //char *months[6] = {"October", "November", "December", "January", "February", "March"};
    //Location of BUG
    //!ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings] gcc

    //Printing the month name
    switch (month)
    {
        case 0:
            printf("October");
            break;
        case 1:
            printf("November");
            break;
        case 2:
            printf("December");
            break;
        case 3:
            printf("January");
            break;
        case 4:
            printf("February");
            break;
        case 5:
            printf("March");
            break;
    } 

    //Printing the month name
    //printf("%s", months[month]); //Not needed
}

//This function displays the highest month name, lowest month name, total, average, sorted data, and median
void Display(int arr[], int most, int least, int total, double average, double median, int mode)
{
    //Printing the highest month name
    printf("The month with the most sales is ");
    Print_Month_Name(most);
    printf(".\n");
    
    //Printing the lowest month name
    printf("The month with the least sales is ");
    Print_Month_Name(least);
    printf(".\n");

    //Printing the total
    printf("The total number of snowblowers sold is %d.\n", total);

    //Printing the average
    printf("The average number of snowblowers sold is %.2f.\n", average);

    //Printing the sorted data
    printf("The sorted data is: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf(".\n");

    //Printing the median
    printf("The median is %.2f.\n", median);

    //Printing the mode
    printf("The mode is %d.\n", mode);

    return;
}


//Builds the frequency array
void Frequency_Array(int arr[], int n, int freq_arr[], int range)
{
    //Declaring local variable f
    int f;

    //Zero out freq ary
    for(f = 0; f < n; f++);
    {
        freq_arr[f] = 0;
    }

    //Source: Today's class 12/6/2022
    for(int i=0; i < n; i++)
    {
        freq_arr[arr[i] ]++;
    }

    return;
}

//Prints the histogram
void printHistogram(int freq_arr[], int range)
{
    for(int f=0; f < range; f++)
    {
        printf("%2d: %2d ", f, freq_arr[f]);

        for(int i=0; i < freq_arr[f]; i++)
        {
            printf(" *");
        }
        printf("\n");
    }
    printf("\n\n");
}


//Finding the mode
int Find_Mode(int freq_arr[], int range)
{
    //Declaring the variables
    int mode = 0;

    //Finding the mode
    for (int i = 0; i < range; i++)
    {
        if (freq_arr[i] > freq_arr[mode])
        {
            mode = i;
        }
    }

    return mode;
}