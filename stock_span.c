/*
    Program to find Stock Span
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int top=-1;
int stack[MAX];

int isempty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull()
{
    if(top==MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int push(int val)
{
    if(!isfull())
    {
        top++;
        stack[top]=val;

    }
    else
    {
        printf("PUSH:STACK FULL\n");
    }
}
int pop()
{
    int val;
    if(!isempty())
    {
        val = stack[top];
        top--;
        return val;
    }
    else{
        printf("POP:STACK EMPTY\n");
    }

}
void print_span(int *arr,int n)
{
    int i,element;
    push(0);
    printf("%d ",1);

    for(i=1;i<n;i++)
    {
        while(!isempty() && arr[stack[top]]<= arr[i])
        {
            element = pop();
        }
        isempty()?printf("%d ",i+1):printf("%d ",i - stack[top]);
        push(i);
    }
}
int main()
{
    int n,i,j,k,*cases=NULL;
    printf("Enter the number of test cases [LIMIT-100]: ");
    scanf("%d",&n);
    if(n>100)
    {
        printf("Test cases:Enter a value less than 1000\n");
        return 0;
    }
    int *arr[n];
    cases = (int *)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        printf("Enter number of elements of array %d: ",i+1);
        scanf("%d",&k);
        if(k>100)
        {
            printf("Array values:Enter a value less than 100\n");
            return 0;
        }
        cases[i]=k;

        arr[i]=(int *)malloc(sizeof(int)*k);
        printf("Enter elements of array with spaces %d : ",i+1);
        for(j=0;j<k;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        print_span(arr[i],cases[i]);
    }
    return 0;
}
