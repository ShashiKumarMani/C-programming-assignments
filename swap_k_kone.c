/*
    Assignment 3: swap the kth and k-1 node from the end of a linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *quick_list(struct node *head,int val);
void print_nodes(struct node *head);
struct node *swap_k(struct node *,int);

int main()
{
  struct node *p=NULL;
  int n,i,val,k,k_data;

  scanf("%d %d",&n,&k);
  if(n<=0 || n>=100)
  {
    printf("ERROR\n");
    return 0;
  }
  if(k<1 || k>=n)
  {
    printf("The value of k must be between 1 and n=%d",n);
    return 0;
  }

  for(i=0;i<n;i++)
  {
    scanf("%d",&val);
    p=quick_list(p,val);
  }
  p=swap_k(p,k);
  printf("\n");
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
    printf("\n");
}

struct node *swap_k(struct node *head,int k)
{
    struct node *p,*q,*r,*s;
    int count=0;
    p=q=s=head;

    while(count<k-1)
    {
        q=q->link;
        count++;
    }

    while(q->link!=NULL)
    {
        q=q->link;
        r=p;
        p=p->link;

    }
    //k -1 first node
    if(r==head)
    {
        r->link=p->link;
        p->link=r;
        return p;
    }
    //swap k and k-1 nodes
    while(s->link!=r)
    {
        s=s->link;
    }
    r->link=p->link;
    p->link=r;
    s->link=p;
    return head;
}
