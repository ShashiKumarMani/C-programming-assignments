/*
    Assignment 1: insert the kth node in a linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *quick_list(struct node *head,int val);
void print_nodes(struct node *head);
void insert_k(struct node *,int,int);

int main()
{
  struct node *p=NULL;
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

  int k,k_data;
  printf("Enter the value of k : ");
  scanf("%d",&k);
  printf("Enter the data : ");
  scanf("%d",&k_data);

  insert_k(p,k,k_data);
  printf("The linked list after the deletion\n");

  print_nodes(p);
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

void insert_k(struct node *head,int k,int k_data)
{
    struct node *p,*q,*r,*s;
    int count=0;
    p=q=r=head;

    s=(struct node *)malloc(sizeof(struct node));
    s->data=k_data;
    s->link=NULL;

    while(count<k)
    {
        q=q->link;
        if(q==NULL)
        {
            printf("The list length is smaller than the value k\n");
            return;
        }
        count++;
    }

    while(q!=NULL)
    {
        q=q->link;
        p=p->link;

    }
    r=p->link;

    s->link=r;
    p->link=s;

    return;
}
