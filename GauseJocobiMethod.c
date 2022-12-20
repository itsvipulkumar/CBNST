#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define EP 0.0001
int n;
int flag;
float findSum(int i, float a[][n + 1])
{
    float sum=0;
    for (int k = 0; k < n; k++)
    {
        if (i != k)
        {
            sum += a[i][k];
        }
    }
    return sum;
}
bool isMethodApplicable(float a[][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fabs(a[i][i]) > findSum(i, a))
                continue;
            else
                return false;
        }
    }
    return true;
}

void printFun(int itr, float values[n])
{
    printf("Iteration : %d ", itr);
    for (int i = 0; i < n; i++)
    {
        printf("Value[%d] : %f ", i + 1, values[i]);
    }
    printf("\n");
}
void findValues(float a[][n + 1],  int maxItr, float value_old[])
{
    float value_new[n], sum = 0;
    int i,j,k,itr;
    for ( itr = 1; itr <= maxItr; itr++)
    {
        for ( i = 0; i < n; i++)
        {
            sum=0;
            for ( j = 0; j < n; j++)
            {
                if (i!=j)
                {
                    sum += a[i][j] * value_old[j];
                }
            }
            value_new[i] = (a[i][n] - sum) / a[i][i];
        }

        // check creteria satisfied or not
        //int flag = 0;
        for ( k = 0; k < n; k++)
        {
            if (fabs(value_old[k] - value_new[k]) < EP)
                continue;
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printFun(itr, value_new);
            return ;
        }
        flag = 0;

        printFun(itr, value_new);
        for ( k = 0; k < n; k++)
            value_old[k] = value_new[k];
    }
    printFun(itr, value_new);
}
int main()
{
    int i, j, k, x, y;
    float ratio;
    int maxItr;
    printf("Enter max no of iteration : \n");
    scanf("%d", &maxItr);
    printf("Enter no of Unknowns\n");
    scanf("%d", &n);
    float a[n][n + 1];
    float value_old[n];
    printf("Enter the Augmented Matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
            scanf("%f", &a[i][j]);
    }

    if (!isMethodApplicable(a))
    {
        printf("Method is not applicable \n");
        return 0;
    }
    for (int i = 0; i < n; i++)
        value_old[i] = 0;
    findValues(a,maxItr, value_old);

    return 0;
}