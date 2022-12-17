// Secant Method for finding root of the eqn
#include <stdio.h>
#include <stdlib.h>
#define EP 0.0001
float f(float x){
      return x*x*x-5*x+1;
}
float findX(float x1, float x2)
{
    return (x1 * f(x2) - x2*f(x1)) / (f(x2) - f(x1));
}
int main()
{
    int i = 1, maxItr;
    float x, x1, x2;
    printf("Enter the max no of iteration : ");
    scanf("%d", &maxItr);
    printf("Enter initial values : ");
    scanf("%f%f", &x1, &x2);
    x = findX(x1, x2);
    while (i <= maxItr)
    {
        x1 = x2;
        x2 = x;
        printf("Iteration : %d Root : %f\n", i, x);

        x = findX(x1, x2);
        if (fabs(x - x2) < EP)
        {
            printf("Total Iteration : %d Final Root : %f\n", i, x);
            return 0;
        }
    }

    return 0;
}