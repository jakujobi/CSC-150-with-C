#include <stdio.h>

#define SIZE 10

int main()
{
    int data[SIZE];

    //Get data from the user
    printf("Enter %d integers: ", SIZE);

    /* 
    scanf("%d", &data[0]);
    scanf("%d", &data[1]);
    scanf("%d", &data[2]);
     * &data[0] is the address of the first element in the array
     * &data[1] is the address of the second element in the array
     * &data[2] is the address of the third element in the array
     * ...
     * &data[9] is the address of the tenth element in the array
    */
    
    printf("data: %x\n", data);

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &data[i]);
    }
    
    //Print the data
    printf("\nYou entered: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%4d ", data[i]);
    }

    printf("data: %d %d %d %d %d %d %d %d %d %d", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9]);

    return 0;
}