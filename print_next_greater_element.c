/*
    Program to print the next greater element for elements in an array
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

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

void print_next_great(int **arr,int cases[],int n)
{
    int element,next,i,j=0;
    for(i=0;i<n;i++)
    {
        push(arr[i][0]);
        for(j=1;j<cases[i];j++)
        {
            next = arr[i][j];
            if(!isempty())
            {
                element = pop();
                while(element < next)
                {
                    printf("%d ",next);
                    if(isempty())
                        break;
                    element=pop();
                }
                if(element > next)
                {
                    push(element);
                }
            }
            push(next);
        }
        while(!isempty())
        {
            element = pop();
            next=-1;
            printf("%d ",next);
        }
        printf("\n");
    }
}
int main()
{
    int n,i,j,k,*cases=NULL;
    printf("Enter the number of test cases [LIMIT-1000]: ");
    scanf("%d",&n);
    if(n>1000)
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
        if(k>1000)
        {
            printf("Array values:Enter a value less than 1000\n");
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
    print_next_great(arr,cases,n);
    for(i=0;i<n;i++)
    {
        free(arr[i]);
    }

    return 0;
}
