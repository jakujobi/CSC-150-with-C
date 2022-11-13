/*
FIle input and output Example

CSC 150 Fall 2022 
*/

#include <stdio.h>

int main ()
{
    FILE *inFile;   //input file stream
    FILE *outFile;  //output file stream

    int num, sum =0, count = 0;
    float average;

    inFile = fopen ("numbers.txt", "r");

    if (!inFile)
    {
        printf ("OOPs! Something went wrong. Cannot open file.\n");
        exit (100);
    }


    while (fscanf ( inFile, " %d", &num ) != EOF)
    {
        count ++;
        printf ("%d\n", count);
        printf ("num: %d\n", num);
        sum += num;
        printf ("sum: %d\n\n", sum);
    }

    average = sum / count;
    printf ("The average is %lf\n", average);

    outFile = fopen ("output.txt", "w");
    if (!outFile)
    {
        printf ("OOPs! Something went wrong. Cannot open file.\n");
        exit (102);
    }


    sum = 0, count = 0, num = 0;

        while (fscanf ( inFile, " %d", &num ) != EOF)
    {
        count ++;
        fprintf (outFile, "%d\n", count);
        fprintf (outFile, "num: %d\n", num);
        sum += num;
        fprintf (outFile, "sum: %d\n\n", sum);

        average = sum / count;

    }

    fprintf (outFile, "The average is %lf\n", average);

    fclose (inFile);
    fclose (outFile);

    printf ("Done!\n");

    return 0;
}