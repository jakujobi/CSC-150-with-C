// Supriya Paudel
// CSC 150
// Program 7
// program to calculate the total number of systems sold during the year,
// the average number sold per month,
//the month with the most sales,
//the month with the least sales,
// and the median number of sales of the snowblowers

#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#define SIZE 6

// read no more than max item values  from data.txt

//returns number of items stored into ary
 int readFile (int ary[], int max_items);

// print with a separate function
void printData (int ary[], int num_items);

// find and return the location of the largest value in ary

// find the total and average of an array, send back in pointer params
void calcAryTotAvg (int ary[], int num_items, float *total, float * avg);
// print the calculate results
void printResults( float total, float average, int large_sol , int small_sol, double median, int mode);

int findlargeSold(int ary[], int num_items);

int findsmallSold(int ary[], int num_items);

// sorting
void bubbleSort (int ary[], int num_items);
float getMedian(int ary[], int num_items);
int getMode(int ary[],int num_items);
void Print_Month_Name(int month);

int main()
{

// define an array to hold the integer

    int data[SIZE] = {0};
    float total, average;
    int large_sol ;
    int small_sol;
    int num_items;
    double median;
    int mode;
    int month;


    // read the data.txt from store into data
    num_items =readFile(data, SIZE);
    printData(data, num_items);

    // calculate the total and average of the numbers in data
    //  store results back into our total and average variables
    calcAryTotAvg(data, num_items, &total, &average);

    //find the locations of the largest & smallest values
    large_sol = findlargeSold (data, num_items);
    small_sol = findsmallSold(data, num_items);

    //sort the data
    bubbleSort(data, num_items);

    median = getMedian(data, num_items);
    mode =  getMode( data, num_items);
    //print the array
    // pass an array with just the name because
    // arrays pass as pointers and the array name
    // is a pointer that contians the array's
    // starting address in memory
    printData(data, SIZE);

    //print the results of calculations
    printResults (total, average , large_sol, small_sol, median, mode);
    return 0;
}

void Print_Month_Name(int month)
{

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

   return;

}

// read data from a file into a partially array
 // count the iteams as I read them
 // return the number of items to main
 // ary is the array being read into
 // max_items is the max number of items to read
 // reads form data.txt
 int readFile (int ary[], int max_items)
 {
    // open the file
     FILE * inFile;
     int num_items;
     inFile = fopen("throwers.txt", "r");

        // check for error opening file
     if (!inFile)
     {
         printf("Error opening throwers.txt file!\n");
         exit(102);
     }
     // read the data into ary, counting the items read
      num_items = 0;
     while ( (num_items < max_items) &&
            (fscanf(inFile, "%d", &ary[num_items]) !=EOF ) )
     {
         num_items++;
     }

     return num_items;
 }


// reading the data from tornado.txt

//int readFile()

// function to print an array
// ary is the array being printed
// num_item is the number of items to print

// print the array
void printData (int ary[], int num_items)
{
    int i;
        for ( i=0; i < num_items; i++)
    {
    printf("%5d", ary[i]);
    }
    printf("\n");
    return;
}

//finds the month with the least sales
int findsmallSold(int ary[], int num_items)

{
    int small_sol = 0;  // assume 0th item is largest to start
    int i;

    // start at 1 to check remaining items
    for (i=1; i< num_items; i++)
    {
        if(ary[i] < ary[small_sol])
            small_sol= i;
    }
    return small_sol;
}


// find and return the location of the largest calue in ary
// ary is the array to search
// num_items is the number of items ti search
// return;
int findlargeSold(int ary[], int num_items)

{
    int large_sol = 0;  // assume 0th item is largest to start
    int i;

    // start at 1 to check remaining items
    for (i=1; i< num_items; i++)
    {
        if(ary[i] > ary[large_sol])
            large_sol= i;
    }
    return large_sol;
}


// find the total and average of an array, send back in pointer params
// ary is the array being processed
// num_items is the number of items to process
// total is used to send back the total of the values process
// sta
void calcAryTotAvg (int ary[], int num_items, float *total, float * avg)
{
    int i;
    // find the total
    *total= 0;
    for(i=0; i< num_items; i++)
    {
        *total = *total + ary[i];
    }

    // find the average
    *avg= *total / num_items;

    return;
}

// sort the array using bubble sort
void bubbleSort (int ary[], int num_items)
{
    int temp;
    int i;
    bool swap;

    do
    {
        swap = false;
        // 1 pass in my sorting algorithm
        for (i=0; i < num_items-1; i++)
        {
            if (ary [i] > ary [i+1])
            {
            // swap them
            temp = ary[i];
            ary[i] = ary [i+1];
            ary[i+1] = temp;
            swap = true;
            }
        }
    }while (swap == true);
    return;
}


// get the formla for the median
float getMedian(int ary[], int num_items)
{
    double  median;


    if (num_items % 2 == 0)
    {
        median = (ary[(num_items) / 2] + ary[num_items / 2-1]) / 2.0;
    }
    else
    {
        median= ary[num_items / 2];
    }


    return median;
}

//This function is used to find the mode of the array
int getMode(int ary[],int num_items)
{
    //source: https://www.tutorialspoint.com/learn_c_by_examples/mode_program_in_c.htm
   int highValue = 0, highCount = 0, i, j;

   for (i = 0; i < num_items; ++i) {
      int count = 0;

      for (j = 0; j < num_items; ++j) {
         if (ary[j] == ary[i])
         ++count;
      }

      if (count > highCount) {
         highCount = count;
         highValue = ary[i];
      }
   }

   return highValue;
}


// print the calculated results
void printResults( float total, float average, int large_sol, int small_sol, double median, int mode)
{
    printf("\n");
    printf("The total number of items sold are %.2f\n", total);
    printf("The avg number of items sold per month %4.2f\n", average);

    printf(" The  month with largest amount of sales is ", large_sol);
    Print_Month_Name(large_sol);
    printf(".\n");

    printf("The month with the least  sales is  ");
    Print_Month_Name(small_sol);
    printf(".\n");


    printf("Median of the given array: %.2lf\n", median);
    printf("Mode of the given array : %.2d\n", mode);

    return;
}
