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
    printf("\n");
}
struct node *merge_list(struct node *head1,struct node *head2)
{
    struct node *merge,*temp;
    if(head1==NULL)
    {
        return head2
    }
    if(head2==NULL)
    {
        return head1
    }
    if(head1->data <= head2->data)
    {
        merge=head1;
        temp=head1;
        head1=head1->link;
    }
    else
    {
        merge=head2;
        temp=head2;
        head2=head2->link;
    }
    while(head1 && head2)
    {
        if(head1<=head2)
        {
            temp=head1;
            head1=head1->link;
            head2=temp->link;
        }
        else
        {
            temp=head2;
            head2=head2->link;
            head1=temp->link;
        }
    }

}
int main()
{
  struct node *head1=NULL,*head2=NULL;
  int n1,n2,i,val;

  printf("Enter the number of elements of the linked list 1: ");
  scanf("%d",&n1);
  printf("Enter the elements of the linked list \n");
  for(i=0;i<n1;i++)
  {
    printf("Element-%d : ",i);
    scanf("%d",&val);
    head1=quick_list(head1,val);
    printf("\n");
  }
  printf("Enter the number of elements of the linked list 1: ");
  scanf("%d",&n2);
  printf("Enter the elements of the linked list \n");
  for(i=0;i<n2;i++)
  {
    printf("Element-%d : ",i);
    scanf("%d",&val);
    head2=quick_list(head2,val);
    printf("\n");
  }
  printf("The linked list are :\n");
  print_nodes(head1);
  print_nodes(head2);
  return 0;
}
