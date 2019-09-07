/*
	Program to print start node of a loop in a linked list
	
	Constraints:
	1 <= size of the liked list <= 10^5	

*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

struct node{
	int data;
	struct node *link;
};

struct node *add_node(struct node *head,int val)
{
	
	struct node *new=NULL,*temp=NULL;
        new = (struct node*)malloc(sizeof(struct node));
        new->data=val;
        new->link=NULL;

	if(head==NULL)
	{
		head=new;
		return head;
	}
	else
	{
		temp=head;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=new;
		return head;
	}
}
void print_nodes(struct node *head)
{
	printf("print nodes\n");
	struct node *temp=head;
	if(head==NULL)
	{
		printf("EMPTY\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
	}
}
struct node *add_cycle(struct node *head)
{
	struct node *temp=NULL,*prev=NULL,*s1=NULL;
	temp=s1=head;
	int last;
	if(head==NULL)
	{
		return NULL;
	}
	else
	{
		while(temp->link!=NULL)
		{
			prev=temp;
			temp=temp->link;
		}
		last=temp->data;
		
	}
	while(s1->link!=NULL)
	{
		if(s1->data == last)
		{
			prev->link=s1;
			break;
		}
		s1=s1->link;
	}
	return head;
}
int detect_cycle(struct node *head)
{
	struct node *s1=NULL,*s2=NULL;
	s1=s2=head;

	if(head==NULL)
	{
		return -1;
	}
	while(s2&& s2->link)
	{
		s1=s1->link;
		s2=s2->link->link;
		if(s1==s2)
		{
			break;
		}
	}
	if(s1 != s2)
	{
		return -1;
	}
	s1 = head;
	while(s1 != s2)
	{
		s1=s1->link;
		s2=s2->link;
	}
	if(s1 != NULL)
	{
		return s1->data;
	}
	else
	{
		return -1;
	}
}

int main()
{
	struct node *root=NULL;
	int *arr=(int *)malloc(sizeof(int)*MAX),i=0;
	char temp;

	root=NULL;
	for(i=0;i<MAX;i++)
	{
		scanf("%d%c",&arr[i],&temp);
		root=add_node(root,arr[i]);
		if(temp == '\n')
		{
			break;
		}
	}
	//add link from last node
	root=add_cycle(root);
	
	printf("%d\n",detect_cycle(root));
	return 0;
}
