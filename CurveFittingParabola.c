#include <stdio.h>
int main()
{
    int n;
    printf("Enter no of ovservatio : ");
    scanf("%d", &n);
    float a[n][n], X[n], Y[n];

    printf("Enter the value of X : ");
    for (int i = 0; i < n; i++)
        scanf("%f", &X[i]);
    printf("Enter the value of Y : ");
    for (int i = 0; i < n; i++)
        scanf("%f", &Y[i]);


     float sx=0,sx2=0,sx3=0,sx4=0,sxy=0,sx2y=0,sy=0;
    for (int i = 0; i < n; i++)
    {
         sx+=X[i];
         sy+=Y[i];
         sx2=sx2+(X[i]*X[i]);
         sx3=sx3+(X[i]*X[i]*X[i]);
         sx4=sx4+(X[i]*X[i]*X[i]*X[i]);
         sxy+=(X[i]*Y[i]);
         sx2y=sx2y+(X[i]*X[i]*Y[i]);
         
    }
      a[0][0]=sx2;
      a[0][1]=sx;
      a[0][2]=n;
      a[0][3]=sy;
      a[1][0]=sx3;
      a[1][1]=sx2;
      a[1][2]=sx;
      a[1][3]=sxy;
      a[2][0]=sx4;
      a[2][1]=sx3;
      a[2][2]=sx2;
      a[2][3]=sx2y;




     // convert to UTM

    float ratio;
    float x, y,z;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j > i)
            {
                ratio = a[j][i] / a[i][i];
                for (int k = 0; k < 4; k++)
                {
                    a[j][k] = a[j][k] - (ratio * a[i][k]);
                }
            }
        }
    }
    printf("\nUTM Matrix : \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }

   
    // find values of a b and c by applyBackSubsitution
    int m = 3;
    float value[3] = {0};

    float sum = 0;
    value[m - 1] = a[m - 1][m] / a[m - 1][m - 1];
    for (int i = m-2; i>=0; i--)
    {
        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            if (i != j)
            {
                sum = sum + a[i][j] * value[j];
            }
        }
        value[i] = (a[i][m] - sum) / a[i][i];
    }

    x = value[0];
    y = value[1];
    z = value[2];

    printf("\nValue of a : %.2f , \nValue of b : %.2f \nValue of c : %.2f\n", x, y,z);
    printf("Equation of parabola : y=ax^2+bx+c =>> y=%.2fx^2 + %.2fx + %.2f\n", x, y,z);

    return 0;
}