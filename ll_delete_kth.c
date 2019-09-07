/*
    Assignment 1: delete the kth node from a linked list
    Constraints:
    1. 1 <= N <= 10^6
    2. 1 <= K <= N
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *quick_list(struct node *head,int *val,int n)
{
    int i=0;
    struct node *temp,*p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val[0];
    temp->link = NULL;
    head=temp;
    p=temp;

    for(i=1;i<n;i++)
    {
	    temp = (struct node *)malloc(sizeof(struct node));
	    temp->data = val[i];
	    temp->link=NULL;
	    p->link=temp;
	    p=temp;
    }
    return head;
}

void print_nodes(struct node *head)
{
    struct node *p;
    p=head;

    while(p!= NULL)
    {
            printf("%d ",p->data);
            p=p->link;
    }
}

void delete_k(struct node *head,int k)
{
    struct node *p,*q,*r;
    int count=0;
    p=q=r=head;

    while(count<k)
    {
        q=q->link;
        if(q==NULL)
        {
            printf("ERROR\n");
            return;
        }
        count++;
    }
    while(q!=NULL)
    {
        q=q->link;
        r=p;
        p=p->link;
    }
    r->link=p->link;
    free(p);

    return;
}

int main()
{
  struct node *p=NULL;
  int n,i,val,k,*arr=NULL;

  scanf("%d %d",&n,&k);
  arr = (int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }

  p=quick_list(p,arr,n);
  delete_k(p,k);
  print_nodes(p);
  return 0;
}


