#include <stdio.h>
#include <stdbool.h>


int linearsearch(int *array, int size, int value)
{
    int location = -1;

    //Check if the value is in the array
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            location = i;
        }
    }

    return location;
}


void bubbleSort(int *array, int size)
{
    int temp;
    bool swapped ;
    //Loop to make 1 pass
    //start i at the beginning,

    do
    {
        swapped = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }


        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i+1];
                array[i+1] = array[i];
                array[i] = temp;
            }
        }

    } while (swapped == true);
    

}