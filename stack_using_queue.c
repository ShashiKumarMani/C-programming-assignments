#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *queue=NULL,*front=NULL,*rear=NULL;

void push(int x)
{
    if(queue==NULL)
    {
        queue=(struct node *)malloc(sizeof(struct node));
        queue->data=x;
        queue->next=NULL;
        rear=queue;
        front=queue;
    }
    else
    {
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=x;
        rear->next=temp;
        rear=temp;
    }
    struct node *temp=rear;
    while(front!=temp)
    {
        struct node *t=front;
        front=front->next;
        rear->next=t;
        rear=t;
        rear->next=NULL;
    }
}
int pop()
{
    struct node *temp=front;
    int val=front->data;
    front=front->next;
    free(temp);
    return val;
}
void print_queue()
{
    struct node *p;
    p=rear;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    printf("The values are pushed\n");

    print_queue();
    return 0;
}
