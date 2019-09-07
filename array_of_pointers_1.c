#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size;
    printf("Enter the value : ");
    scanf("%d",&size);
    int *ptr[size];

    ptr[0]=(int *)malloc(sizeof(int)*12);

    for(int i=0;i<12;i++)
    {
        scanf("%d",&ptr[0][i]);
    }
}
