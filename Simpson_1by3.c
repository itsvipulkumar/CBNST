#include <stdio.h>
float f(float x)
{
    return 1 / (1 + x * x);
}
int main()
{
    int i, j, k, n;
    float a, b, sum1, sum2;
    printf("Enter the no of intervals : ");
    scanf("%d", &n);
    float X[n + 1], Y[n + 1];

    printf("Enter the value of a and b : ");
    scanf("%f%f", &a, &b);
    float h = (b - a) / (float)n;
    for (int i = 0; i <= n; i++)
    {
        X[i] = a + i * h;
    }
    for (int i = 0; i <= n; i++)
    {
        Y[i] = f(X[i]);
    }

    // apply formula

    for (int i = 1; i <= n - 1; i = i + 2)
    { 
        sum1 += Y[i];
    }
    for (int i = 2; i <= n - 2; i = i + 2)
    {
        sum2 += Y[i];
    }
    printf("\n X \n");
    for (int i = 0; i <=n; i++)
        printf("%f ", X[i]);
    printf("\n Y \n");
    for (int i = 0; i <=n; i++)
        printf("%f ", Y[i]);
    float sum = (Y[0] + Y[n] + (4 * sum1) + (2 * sum2));
     float ans=(sum*h)/3;
   printf("\nValue of The integral  = %f",ans); 
    return 0;
}