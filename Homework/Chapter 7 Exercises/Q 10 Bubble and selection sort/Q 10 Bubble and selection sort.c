/*
show the following array after each pass using the bubble sort, then show the same array after each pass using the selection sort:

32  12  46  18  56  30 27
*/

#include <stdio.h>

void bubbleSort(int *array, int size);
void selectionSort(int *array, int size);
void printArray(int *array, int size);

int main()
{
        int array[7] = {32, 12, 46, 18, 56, 30, 27};

        printf("Bubble sort:\n");
        bubbleSort(array, 7);
        printArray(array, 7);

        printf("Selection sort:\n");
        selectionSort(array, 7);
        printArray(array, 7);

        return 0;
}

//Bubble sort implementation
void bubbleSort(int *array, int size)
{
        //declaring local variables
        int i, j, temp;

        //looping through the array
        for (i = 0; i < size - 1; i++)
        {
                for (j = 0; j < size - 1; j++)
                {
                        if (array[j] > array[j + 1])
                        {
                                temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                        }
                }
        }
}


void selectionSort(int *array, int size)
{
        int i, j, temp, min;

        for (i = 0; i < size - 1; i++)
        {
                min = i;
                for (j = i + 1; j < size; j++)
                {
                        if (array[j] < array[min])
                        {
                                min = j;
                        }
                }
                temp = array[i];
                array[i] = array[min];
                array[min] = temp;
        }
}


void printArray(int *array, int size)
{
        int i;

        for (i = 0; i < size; i++)
        {
                printf("%d\t", array[i]);
        }
        printf("Thank you for using this program. Goodbye.\n");
}

/*
Bubble sort:
12      18      27      30      32      46      56      Thank you for using this program. Goodbye.

First pass
32, 12, 46, 18, 56, 30, 27
12, 32, 46, 18, 56, 30, 27
12, 32, 18, 46



Selection sort:
12      18      27      30      32      46      56      Thank you for using this program. Goodbye.
*/

