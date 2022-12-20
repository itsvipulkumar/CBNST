#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j;
    float x;
    printf("How many value you want to enter : ");
    scanf("%d", &n);

    float X[n], Y[n], sum = 0, term;
    printf("\nEnter value  of  X: \n");
    for (i = 0; i < n; i++)
        scanf("%f", &X[i]);
    printf("\nEnter value  of  Y: \n");
    for (i = 0; i < n; i++)
        scanf("%f", &Y[i]);

    printf("Enter value of x for which you want to find the value of Y : ");
    scanf("%f", &x);

    for (i = 0; i < n; i++)
    {
        printf("X : %f  , Y : %f \n", X[i], Y[i]);
    }
    for (int i = 0; i < n; i++)
    {
        term = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                term = term * ((x - X[j]) / (X[i] - X[j]));
        }

        sum = sum + term * Y[i];
        printf("sum : %f \n", sum);
        printf("term : %f \n", term);
    }
    printf("\nValue at X=%g is = %f", x, sum);

    return 0;
}