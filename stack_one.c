/*
    Design a data-structure SpecialStack that supports all the stack operations like
    push(), pop(), isEmpty(), isFull() and an additional operation getMin()
    which should return minimum element from the SpecialStack.
    Perform getMin() operation in 0(1) time complexity and 0(1) space complexity.

*/
#include<stdio.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct stack
{
    struct node *head;
    struct node *middle;
    int count;
};

void push(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev=NULL;
    temp->next=s->head;
    s->count+=1;

    if(s->count == 1)
    {
        s->middle =temp;
    }
    else
    {
        s->head->prev = temp;
        if(s->count & 1)
        {
            s->middle = s->middle->prev;
        }

    }
    s->head = temp;
}

int main()
{
    int N;
    printf("Enter the number of test cases : ");
    scanf("%d",&N);
    int *arr[N];

    for(i=0;i<N;i++)
    {
        printf("Enter the number of elements : ");
        scanf("%d",&n);
        arr[i]=(int *)malloc(sizeof(int)*n);

        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}
