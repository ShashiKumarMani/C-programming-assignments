#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p;
    p = (int *)malloc(sizeof(int)*10);
    for(int i=0;i<5;i++)
    {
        p[i]=i;
    }
    for(int i=0;i<5;i++)
    {
        printf("%d ",p[i]);
    }
    printf("%d ",p[100]);
    return 0;

}
