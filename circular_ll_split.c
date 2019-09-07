/*
    Assignment 1: insert the kth node in a linked list
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
  return 0;


}
