/*
This program reads the list of pairs of numbers from the given file "Number_List.txt"
and prints an output file with the sum and averages of the numbers.

Created by John Akujobi
On the 21st of November 2022
*/

/*
Features
1. Read the file
2. Calculate the sum and average
3. Print the output file
*/

//Functions

#include <stdio.h>

int get_number(FILE *num_file, float *num1, float *num2);
        //This function reads a single line from the file
        //and returns the number
        //It also checks for the end of the file and incomplete lines
        //get_number(num_file, &num1, &num2)

int get_number(FILE *num_file, float *num1, float *num2)
{
    float readnumber;

    readnumber = fscanf(num_file, "%f %f", num1, num2);

    if (readnumber != 2)
    {
        printf("Error Reading from File");
        return 1;
    }
    else if (readnumber != EOF)
    {
        printf("End of File Reached");
        return 1;
    }
    else
    {
        printf("File read successfully");
        return 0;
    }
}



void sum_and_average (float *num1, float *num2, float *sum, float *average);
        //This function calculates the sum and average of the numbers
        //passes the output by parameters
        //sum_and_average (&num1, &num2, &sum, &average)

void sum_and_average (float *num1, float *num2, float *sum, float *average)
{
    //calculates the sum
    *sum = (*num1) + (*num2);

    //calculates the average
    *average = (*sum)/2.0;

    return;
}




void print_output (FILE *out_file, float *num1, float *num2, float *sum, float *average);
        //This function prints the output to the screen
        //And it prints a line to the output file
        //print_output (out_file, &num1, &num2, &sum, &average)

void print_output (FILE *out_file, float *num1, float *num2, float *sum, float *average)
{
    fprintf(out_file, "%f \t %f \t %f \t %f", *num1, *num2, *sum, *average);
}



//Main Program
int main ()
{
    FILE *out_file;

    FILE *num_file;

    float num1, num2, sum, average;

    int readnumber;

    //Open the input file
    num_file = fopen ("Number_List.txt", "r");

    //Open or create the output file
    out_file = fopen ("Output file.txt", "w");

    readnumber = get_number(num_file, &num1, &num2);

    fprintf (out_file, "num1\tnum2\tsum\taverage");

    //Create a while loop
    while (readnumber == 0)
    {
        //Reads the numbers from the input file
        readnumber = get_number(num_file, &num1, &num2);

        //Calls the sum_and_average function
        sum_and_average (&num1, &num2, &sum, &average);

        //Call the print_output function
        print_output (out_file, &num1, &num2, &sum, &average);
    }
        
    printf("\nDoneeeeeee\n");

    return (0);
}
    

    