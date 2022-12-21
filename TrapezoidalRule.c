#include <stdio.h>
float f(float x)
{
    return x * x * x;
}
int main()
{
    int i, j, n;
    float a, b,h,ans,sum=0;
    printf("Enter no of intervals : ");
    scanf("%d", &n);
    printf("Enter the value of a and b : ");
    scanf("%f%f", &a, &b);
    h = (b-a) /(float) n;
    float X[n + 1], Y[n + 1];

    for (i = 0; i <= n; i++)
    {
        X[i] = a + i * h;
    }
     for (i = 0; i <= n; i++)
    {
        Y[i] = f(X[i]);
    }
    // apply forumula
    // for y1 to yn-1
    for (int i = 1; i <= n - 1; i++)
    {
        sum = sum + Y[i];
    }
    ans = h / 2 * ((Y[0] + Y[n]) + 2 * sum);
    printf("\nAnswers is : %f ", ans);
    return 0;
}