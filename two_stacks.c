/*
    Functions to implement two stack in a single array
*/
#define MAX 100
int stack[MAX];
int top1=-1;
int top2=MAX;

void push1(int val)
{
    if(top1<top2-1)
    {
        stack[++top1]=val;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}
int pop1()
{
    if(top1>=0)
    {
        return stack[top--];
    }
    else
    {
        printf("Stack Underflow\n");
    }
}
void push2()
{
    if(top1<top2-1)
    {
        return stack[--top2];
    }
    else
    {
        printf("Stack Overflow\n");
    }
}
void pop2()
{
    if(top<MAX)
    {
        return stack[top2++];
    }
    else
    {
        printf("Stack Underflow\n");
    }
}
