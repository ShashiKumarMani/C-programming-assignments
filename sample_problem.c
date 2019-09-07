#include<stdio.h>
int exp(int ,int );
int main()
{
    int X=2,Y=3;
    int c;
    c = exp(X,Y);
    printf("-------%d\n",c);
    return 0;
}
int exp(int X,int Y)
{
    int res=1,a=x,b=Y;
    while(b!=0)
    {
        a=a*a;
        b/=2;
    }
    else
    {
        res=res*a;
        b=b-1;
    }
    return res;
}
