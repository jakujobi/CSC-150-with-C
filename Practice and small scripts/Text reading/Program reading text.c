/*
    This program reads a text file and does some simple operations on it.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    int count = 0;

    // Open the file
    fp = fopen("Sample.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open file");
        exit(0);
    }

    // Read the file
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
        count++;
    }

    //Close the file
    fclose(fp);
    printf("Close file");
    printf("The number of characters in the file is %d", count);
    return 0;
}