/*
    Program to print a staircase
*/
#include<stdio.h>

int main()
{
    int lines;
    char option;
    do{
    printf("Enter the number of lines : ");
    scanf("%d",&lines);

    if(lines==0)
    {
        printf("Enter a non zero number\n");
        goto jump;
    }
    for(int i=0;i<=lines;i++)
    {
        for(int j=0;j<i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    jump:

    printf("Continue? [y|n] : ");
    scanf(" %c",&option);
    }while(option=='y');

    return 0;
}
