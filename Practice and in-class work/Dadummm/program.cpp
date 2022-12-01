#include <iostream>

using namespace std;

void fun (float num1, float num2, float *res1, float *res2);

int main()
{
    float x = 4.5;
    float y = 1.3;
    float r1, r2;

    fun(x, y, &r1, &r2);

    printf("r1 = %.1f", r1);
    printf("r2 = %.1f", r2);
    return 0;
}

void fun (float num1, float num2, float *res1, float *res2)
{
    *res1 = num1 + num2;
    *res2 = num1 - num2;
}
