/*
    Program to print a staircase
*/

#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter the value of N [0<N<100]: ");
    scanf("%d",&n);

    if(n<=0 || n>100)
    {
        printf("Enter value within the limit\n");
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("# ");
        }
        printf("\n");
    }

}
