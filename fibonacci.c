#include<stdio.h>
int main()
{
    int a=0,b=1,c,i,n;

    printf("Enter the upper limit : ");
    scanf("%d",&n);
    printf("%d %d ",a,b);

    for(i=0;a+b<=n;i++)
    {
        c = a+b;
        printf("%d ",c);
        a=b,b=c;


    }
    return 0;
}
