/* Not part of the code at all
#include <stdio.h>

void print(FILE *outp, int id, double avg);

int main()
{
        FILE *pOutFile;
        int item;
        double cost = 40.0;

        pOutFile = fopen("output.txt", "w");
        fprintf(pOutFile, "Item\tCost\n");

        for (item = 1; item <= 5; item++)
        {
                fprintf(pOutFile, item, average);
                cost += 20;
        }

        fclose(pOutFile);
        return 0;
}

void print(FILE *outp, int item, double cost)
{
        fprintf(outp, "%5d\t%9.2f\n", item, cost);
}
*/

/* 
    Write a code segment that defines any needed variabled, then calls the following fumction:
    void getDigit (int *value)
    {
        //get the one's digit
        *value = *value % 10;
    }
*/

#include <stdio.h>

void getDigit(int *value);

int main()
{
        int value = 0;

        printf("Enter a number: ");
        scanf("%d", &value);

        getDigit(&value);

        printf("The one's digit is %d", value);

        return 0;
}

void getDigit(int *value)
{
        *value = *value % 10;
}