/*
    Program to find largest of three numbers using ternary operators
*/
#include<stdio.h>
int main()
{
    int a,b,c;
    char choice;
    do{
    printf("Enter three integers with spaces and press Enter: ");
    scanf("%d %d %d",&a,&b,&c);
    c = (a>b)?(a>c? a: c):(b>c?b:c);
    printf("The largest integer is %d\n",c);
    printf("Continue? [y|n] : ");
    scanf(" %c",&choice);
    }while(choice=='y');

    return 0;
}
