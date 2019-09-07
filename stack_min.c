/*
    Program to get minimum element of stack in O(1) time and O(1) space
*/
#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
int min=-1;

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
    if(isempty())
    {
        top++;
        stack[top]=(val);
        min=val;
    }
    else if(!isfull())
    {
        top++;
        if(val < min)
        {
            stack[top]=(2*val - min);
            min=val;

        }
        else
        {
            stack[top]=(val);
        }
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
        if((val = stack[top])>min)
        {
            top--;
            return val;
        }
        else
        {
            min = 2*min - stack[top];
            top--;
        }
    }
    else{
        printf("POP:STACK EMPTY\n");
    }
}
void print_stack()
{
    if(isempty())
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
int getmin()
{
    if(!isempty())
    {
        printf("The minimum element is %d\n",min);
    }
    else
    {
        printf("STACK EMPTY\n");
    }
}
int main()
{
    while(1)
    {
        int data,option;
        printf("Enter option\n1. Push\n2. Pop\n3. Print stack\n4. Print minimum element\n5. QUIT\n-->");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                    printf("Enter value : ");
                    scanf("%d",&data);
                    push(data);
                break;
            case 2:
                    data = pop();
                break;
            case 3:
                    printf("Stack : ");
                    print_stack();
                break;
            case 4:
                    getmin();
                break;
            case 5:
                    return(0);
                break;
            default:
                    printf("ENTER VALID OPTION\n");
        }
    }
    return 0;
}
