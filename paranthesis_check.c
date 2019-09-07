/*
    Program to check if paranthesis is balanced or not
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int match(char a,char b)
{
    if(a-b == -1 || a-b == -2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int paranthesis_check(char *arr)
{
    char temp;
    int i;
    for(i=0;i<strlen(arr);i++)
    {
        if(arr[i]=='{' || arr[i]=='[' || arr[i]=='(')
            push(arr[i]);
        else if(arr[i]=='}' || arr[i]==']' || arr[i]==')')
        {
            if(top==-1)
            {
                //printf("Right paranthesis more than left paranthesis\n");
                return 0;
            }
            temp = pop();
            if(!match(temp,arr[i]))
            {
                return 0;
            }
        }
        if(top==-1)
        {
            return 1;
        }
    }
}
int main()
{
    int n,i,j,k,*cases=NULL;
    printf("Enter the number of test cases [LIMIT-100]: ");
    scanf("%d",&n);
    if(n>100)
    {
        printf("Test cases:Enter a value less than 100\n");
        return 0;
    }
    char *arr[n];
    for(i=0;i<n;i++)
    {
        arr[i]=(char *)malloc(sizeof(char)*105);
        printf("Sequence %d [LIMIT-100]- ",i+1);
        scanf("%s",arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(paranthesis_check(arr[i]))
        {
            printf("Sequence-%d -Not balanced\n",i+1);
        }
        else
        {
            printf("Sequence-%d -Balanced\n",i+1);
        }
    }
    return 0;
}
