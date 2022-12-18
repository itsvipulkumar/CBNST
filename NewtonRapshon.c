#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define EP 0.0001
float f(float x)
{
    return x * x * x - 3 * x - 5;
}
float fDiff(float x)
{
    return 3 * x * x - 3;
}

int main()
{
    int maxItr, i = 1;
    float x1, x2;
    float x0;
    float x;
    printf("No of iteration : ");
    scanf("%d", &maxItr);
    printf("Enter intial value : ");
    scanf("%f%f", &x1, &x2);
    // if(f(x1)<f(x2))
    // x0=x1;
    // else
    // x0=x2;
    if (fabs(f(x1))<fabs(f(x2)))
        x0 = x1;
    else
        x0 = x2;
    while (i <= maxItr)
    {

        x = x0 - f(x0) / fDiff(x0);
        if(fabs(x-x0)<EP){
            printf(" MAX Iteration : %d Final Root : %f\n", i, x);
            break;
        }
        printf("Iteration : %d Root : %f\n", i, x);
        x0 = x;
        i++;
    }

    return 0;
}