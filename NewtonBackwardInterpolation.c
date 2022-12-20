#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
void createDifferenceTable(float a[][n+1])
{
        for(int j=2;j<n+1;j++)
        {
            for(int i=0;i<n-j+1;i++)
            {
                a[i][j]=a[i+1][j-1]-a[i][j-1];
            }
        }
}
void Difftable(float a[][n+1])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            printf("%f ",a[i][j]);
        }
        printf("\n");
    }
}
void findValues(float a[][n+1], float x,int n)
{
    float u,u1,y;
    u=(x-a[n-1][0])/(a[1][0]-a[0][0]); // initial u ie (a+hu)=f(x);
    u1=u;
    int fact=1;
    y=a[n-1][1];

    for(int i=2;i<=n;i++)
    {
       y=y+(u1*a[n-i][i])/fact;
       fact=fact*i;
       u1=u1*(u+(i-1)); // find u*(u+1)*(u+2) etc term
    }
    printf("\nValue at X:%f is : %f",x,y);
}
int main()
{
    
    int i, j, k;
    float x, y;
    printf("Enter total values : ");
    scanf("%d", &n);
    float a[n][n + 1];
    printf("\n Enter value of X : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &a[i][0]);
    }
    printf("\n Enter value of Y : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &a[i][1]);
    }
    printf("\n Enter value of x : ");
    scanf("%f", &x);

    createDifferenceTable(a);
    Difftable(a);
    printf("\n\n");
    findValues(a, x,n);
}