// C program to implement Simpson 1/3 and Simpson 3/8 with switch case 
/*
x     a=0,b=6 , n =6;

f(x)=1/(1+x^2) simpson 1/3 ans= 1.366173
simpson 3/8 ans= 1.357081
*/
// C program to implement Simpson 1/3 and Simpson 3/8 with switch case 
#include <stdio.h>
float f(float x)
{
    return 1 / (1 + x * x);
}
void Simpson_1by3(float Y[], float h, int n)
{
    float sum1 = 0, sum2 = 0;

    for (int i = 1; i <= n - 1; i = i + 2)
    {
        sum1 += Y[i];
    }
    for (int i = 2; i <= n - 2; i = i + 2)
    {
        sum2 += Y[i];
    }
    float sum = (Y[0] + Y[n] + (4 * sum1) + (2 * sum2));
    float ans = (sum * h) / 3;
    printf("\nValue of The integral  By Simpson 1/3= %f\n", ans);
}
void Simpson_3by8(float Y[], float h, int n)
{
    float sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (i % 3 == 0)
            sum1 += Y[i];
        else
            sum2 += Y[i];
    }
    float sum = (Y[0] + Y[n] + (3 * sum2) + (2 * sum1));
    float ans = ((3 * h) / 8) * sum;
    printf("\nValue of The integral By Simpson 3/8= %f\n", ans);
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
    int ch;

    printf("Enter 1 for Simpson 1/3 and 2 for Simpson 3/8 : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        Simpson_1by3(Y, h, n);
        break;
    case 2:
        Simpson_3by8(Y, h, n);
        break;
    default:
        printf("Enter valid number ");
        break;
    }
    return 0;
}