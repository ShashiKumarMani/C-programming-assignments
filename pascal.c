/*
    Assignment 15: Program to print pascal's triangle
*/

#include<stdio.h>
int main()
{
    int n;
    char option;
    do{
    printf("Enter the number of rows : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i-j == 0)||(j==0))
            {
                printf("%d  ",1);
            }
            else if(i-j >0 )
            {
                printf("%d  ",i);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("Continue? [y|n] : ");
    scanf(" %c",&option);
    }while(option=='y');
    return 0;
}
