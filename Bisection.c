#include <stdio.h>
// Bisection Method
#include <math.h>
// #define f(x) x *x *x - 2 * x - 5;
float findValueAt(float x)
{
    return 3 * x - cos(x) - 1; // equation
}
float biset(float x1, float x2)
{
    return (x1 + x2) / 2;
}
int main()
{
    int n, i = 1;
    float x1, x2;
    float x;
    printf("No of iteration : ");
    scanf("%d", &n);
    printf("Enter intial value : ");
    scanf("%f%f", &x1, &x2);
    while(i<= n)
    {
         x = biset(x1, x2);
        if (findValueAt(x) * findValueAt(x1) < 0)
        {
            x2 = x;
        }
       else if (findValueAt(x) * findValueAt(x2) < 0)
        {
            x1 = x;
        }

        printf("Iteration : %d  Roots : %f\n",i,x);
        i++;
    }
    printf("Root is : %f Total iteration :%d ",x,--i);
}