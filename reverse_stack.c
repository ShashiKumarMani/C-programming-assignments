/*
    Program to reverse a stack using recursion
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;

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
        printf("STACK FULL\n");
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
void print_stack()
{
    if(!isempty)
    {
        printf("PRINT:STACK EMPTY\n");
        return;
    }
    int j=top;
    for(j;j>=0;j--)
    {
        printf("%d ",stack[j]);
    }
    printf("\n");
}
void insert(int x)
{
    if(isempty())
    {
        push(x);
    }
    else
    {
        char c = pop();
        insert(x);
        push(c);
    }
}
void reverse()
{
    if(!isempty())
    {
        char c = pop();
        reverse();
        insert(c);
    }
}
int main()
{
    int data,option,n,i,*cases,k,j,N;
    printf("Enter the number of test cases [LIMIT-100] : ");
    scanf("%d",&N);
    if(N<=0 || N>=100)
    {
        printf("The number of test cases must be greater than 0 and less 100\n");
        return 0;
    }
    for(i=0;i<N;i++)
    {
        printf("Enter the number of elements of stack %d [LIMIT-100]: ",i+1);
        scanf("%d",&n);
        if(n<=0 || n>=100)
        {
            printf("The number of elements must be greater than 0 and less 100\n");
            return 0;
        }
        printf("Enter the values : ");
        for(j=0;j<n;j++)
        {
            scanf("%d",&data);
            push(data);
        }
        printf("Elements of stack : ");
        print_stack();
        reverse();
        printf("Reversed stack: ");
        print_stack();
        top=-1;
    }
    return 0;
}
