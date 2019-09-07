/*
    Assignment 1: find the kth node in a linked list
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *quick_list(struct node *head,int val);
void print_nodes(struct node *head);
void split_list(struct node *head,struct node *a,struct node *b);
int main()
{
  struct node *p=NULL;
  struct node *a=NULL,*b=NULL;
  int n,i,val;

  printf("Enter the number of elements of the linked list : ");
  scanf("%d",&n);
  printf("Enter the elements of the linked list \n");
  for(i=0;i<n;i++)
  {
    printf("Element-%d : ",i);
    scanf("%d",&val);
    p=quick_list(p,val);
    printf("\n");
  }
  printf("The linked list is ");
  print_nodes(p);
  a=b=p;

  split_list(p,a,b);

  print_nodes(a);
  print_nodes(b);

  return 0;


}
struct node *quick_list(struct node *head,int val)
{
    struct node *temp,*p;
    p=head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->link = NULL;
    if(p)
    {
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;

    }
    else
    {
        head=temp;
    }
    return head;

}
void print_nodes(struct node *head)
{
    struct node *p;
    p=head;

    if(p==NULL)
    {
        printf("List empty\n");

    }
    else
    {
        while(p!= NULL)
        {
            printf("%d ",p->data);
            p=p->link;
        }
    }
}
void split_list(struct node *head,struct node *a,struct node *b)
{
    printf("ENTER\n");
    struct node *c=NULL,*d=NULL;
    printf("a--%d\n",a->data);
    printf("b--%d\n",b->data);
    b=b->link;
    printf("b--%d\n",b->data);

    printf("YO");
    c=a;
    d=b;
    while(c->link!=NULL || d->link!=NULL)
    {
        c->link=d->link;
        c=c->link;
        d->link=c->link;
        d=d->link;

    }
    c->link=NULL;
    d->link=NULL;
}
