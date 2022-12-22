#include <stdio.h>
int main()
{
    int n;
    printf("Enter no of ovservation : ");
    scanf("%d", &n);
    float X[n], Y[n];
    float a[n][n];
    printf("Enter the value of X : ");
    for (int i = 0; i < n; i++)
        scanf("%f", &X[i]);
    printf("Enter the value of Y : ");
    for (int i = 0; i < n; i++)
        scanf("%f", &Y[i]);

    // finding the value of summ x,summy, summxy, summx*x;
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 = sum1 + X[i];          // summ x;
        sum2 = sum2 + Y[i];          // summ y
        sum3 = sum3 + (X[i] * X[i]); // summ x*x
        sum4 = sum4 + (X[i] * Y[i]); // summ x*y
    }

    // fit the value at right postion to apply gause elimination;
    a[0][0] = n;
    a[0][1] = sum1;
    a[0][2] = sum2;
    a[1][0] = sum1;
    a[1][1] = sum3;
    a[1][2] = sum4;

    printf("\n Formed Matrix \n ");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    // convert to UTM

    float ratio;
    float x, y;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j > i)
            {
                ratio = a[j][i] / a[i][i];
                for (int k = 0; k < 3; k++)
                {
                    a[j][k] = a[j][k] - (ratio * a[i][k]);
                }
            }
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
    // find values of a and b
    int m = 2;
    float value[2] = {0};

    float sum = 0;
    value[m - 1] = a[m - 1][m] / a[m - 1][m - 1];
    for (int i = 0; i < 2; i++)
    {
        sum = 0;
        for (int j = 0; j < 2; j++)
        {
            if (i != j)
            {
                sum = sum + a[i][j] * value[j];
            }
        }
        value[i] = (a[i][m] - sum) / a[i][i];
    }
    printf("\n Values are  : \n");

    x = value[0];
    y = value[1];

    printf("Value of a : %.2f and b : %.2f \n", x, y);
    printf("Formed curve line : y=a+bx =>> y=%.2f+%.2fx\n", x, y);
}