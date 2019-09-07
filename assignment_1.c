/*
    Program to find nth term and sum upto nth term in a arithmetic series
*/
#include<stdio.h>
int main()
{
    int a,d,n,sum=0,temp,i;
    char choice;

    do{
    printf("Enter first term a and common difference: ");
    scanf("%d %d",&a,&d);

    printf("Enter the value of n : ");
    scanf("%d",&n);

    printf("The nth term is : %d\n",a+(n-1)*d);

    temp=a;
    for(i=0;i<n;i++)
    {
        sum+=a+i*d;
    }
    printf("The sum upto the nth term is %d\n",sum);

    printf("Continue?: [y|n] : ");
    scanf(" %c",&choice);
    }while(choice=='y');
    return 0;
}
