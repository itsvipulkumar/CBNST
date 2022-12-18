#include <stdio.h>

int n;
void convertToUTM(float a[][n + 1], int n)
{

    float ratio;
    int x, y, i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; i < n; j++)
        {
            if (j > i)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < n + 1; k++)
                    a[j][k] = a[j][k] - (ratio * a[i][k]);
                printf("Intermediate forms:\n");
                for (x = 0; x < n; x++)
                {
                    for (y = 0; y < n + 1; y++)
                        printf("%.2f ", a[x][y]);
                    printf("\n");
                }
                printf("\n");
            }
        }
    }
}

void convertToUpperTriangular(float a[][n + 1], int n)
{
    int i, j, x, y, k;
    float ratio;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j > i)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < n + 1; k++)
                    a[j][k] = a[j][k] - (ratio * a[i][k]);

                printf("Intermediate forms:\n");
                for (x = 0; x < n; x++)
                {
                    for (y = 0; y < n + 1; y++)
                        printf("%.2f ", a[x][y]);
                    printf("\n");
                }
                printf("\n");
            }
        }
    }
}
void applyBackSubsitution(float a[][n + 1], float values[], int n)
{

    values[n-1]=a[n-1][n]/a[n-1][n-1];
    float sum=0;
    for(int i=n-2;i>=0;i--)
    {
        sum=0;
        for(int j=i+1;j<n;j++)
        {

             sum=sum+(a[i][j]*values[j]);
        }
        values[i]=(a[i][n]-sum)/a[i][i];
    }
}
void printValue(float values[],int n)
{
    for(int i=0;i<n;i++)
    printf("%.2f\n",values[i]);
}
int main()
{
    int i, j, k;
    printf("Enter the no Unknown variables  : ");
    scanf("%d", &n);
    float a[n][n + 1], values[n];
    printf("Enter Augument matrix : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    convertToUpperTriangular(a, n);
    applyBackSubsitution(a, values, n);
    printValue(values,n);

    return 0;
}