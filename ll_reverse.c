/*
  Given N elements to a linked list, your task is to reverse the linked list. We need to reverse the list by changing links between nodes.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_NUM 1000

struct node{
	int data;
	struct node *link;
};

struct node *new_node(struct node *root,int val)
{
	
	struct node *new=NULL,*temp=NULL;
        new = (struct node*)malloc(sizeof(struct node));
        new->data=val;
        new->link=NULL;

	if(root==NULL)
	{
		root=new;
		return root;
	}
	else
	{
		temp=root;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=new;
		return root;
	}
}
void print_nodes(struct node *root)
{
	struct node *temp=root;
	if(root==NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}
struct node *reverse(struct node *head)
{
	struct node *prev=NULL,*curr=head,*next=NULL;
	if(curr->link==NULL)
	{
		return head;
	}
	while(curr!=NULL)
	{
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}
int main()
{
	struct node *head=NULL;
	int T,n,i,j,k;

	scanf("%d",&T);
	if(T<1 || T>100)
	{
		printf("Test cases [1<=T<=100]\n");
		return 0;
	}
	struct node *cases[T];

	for(i=0;i<T;i++)
	{
		scanf("%d",&n);
		if(n<1 || n>MAX_NUM)
		{
			i--;
			continue;
		}
		for(j=0;j<n;j++)
		{
			scanf("%d",&k);
			head=new_node(head,k);
		}
		head=reverse(head);
		cases[i]=head;
		head=NULL;
	}
	printf("\n");
	for(i=0;i<T;i++)
	{
		print_nodes(cases[i]);
		free(cases[i]);
	}
	return 0;
}
