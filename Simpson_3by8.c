// simpson 3.8 rule
//
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

    for (int i = 1; i <= n - 1; i++)
    {
        if (i % 3 == 0)
            sum1 += Y[i];
        else
            sum2 += Y[i];
    }

    printf("\n sum 1 : %f\n", sum1);
    printf("\n sum 2  : %f\n", sum2);
    float sum = (Y[0] + Y[n] + (3 * sum2) + (2 * sum1));
    float ans = ((3 * h) / 8) * sum;
    printf("\nValue of The integral  = %f", ans);
    return 0;
}