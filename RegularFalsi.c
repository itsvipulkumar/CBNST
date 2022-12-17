// Regular falsi method
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ep 0.0001 //3 decimal places 
float f(float x)
{
    return x * x * x - 2 * x - 5;
}
float biset(float x1, float x2)
{
    return (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
}
int main()
{
    int i = 1, maxItr;
    float x, x1, x2;
    printf("Enter the max no of iteration : ");
    scanf("%d", &maxItr);

    printf("Enter initial values : ");
    scanf("%f%f", &x1, &x2);

    while (i <= maxItr)
    {
        x = biset(x1, x2);
        if (f(x) * f(x1) < 0)
            x2 = x;
        else if (f(x) * f(x2) < 0)
            x1 = x;
        float x3 = biset(x1, x2);
        printf("Iteration : %d Root : %f \n", i, x);
        if (fabs(x3 - x) < ep) // for finding error 3 decimal places 
        {
            printf("Total Iteration : %d Final Root : %f \n", i, x);
            return 0;
        }
        i++;
    }
    return 0;
}