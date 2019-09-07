/*
    Assignment 1: delete the kth node from a linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

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
struct node *pairwise_swap(struct node *head)
{
	struct node *p,*q,*r;
	if(head==NULL || head->link==NULL)
	{
		printf("CANNOT PERFORM SWAP\n");
		return head;
	}
	p = head;
	q = head->link;
	r = head->link->link;
	
	p->link=q->link;
	q->link=p;
	head=q;
	
	r=p;
	p=r->link;
	q=p->link;

	while(p!=NULL || q!=NULL)
	{
		p->link=q->link;
		q->link=p;
		r->link=q
	}
	return head;

}
int main()
{
  struct node *p=NULL;
  int n,i,val,k;

  printf("Enter the number of elements of the linked list [LIMIT-1000]: ");
  scanf("%d",&n);
  if(n<1||n>=1000)
  {
    printf("n:Enter a value between 1 and 1000 : ");
    return 0;
  }
  printf("Enter the elements of the linked list \n");
  for(i=0;i<n;i++)
  {
    printf("Element-%d : ",i);
    scanf("%d",&val);
    p=quick_list(p,val);
  }
  printf("The linked list is ");
  print_nodes(p);

  //perform swap
  printf("Nodes after the swap \n");
  p=pairwise_swap(p);
  print_nodes(p);

  return 0;


}
