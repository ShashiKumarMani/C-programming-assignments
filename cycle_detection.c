/*
	Program to detect cycle in a linked list
	
	Constraints:
	1 <= size of linked list <= 10^5
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

struct node{
	int data;
	struct node *link;
};

struct node *add_node(struct node *root,int val)
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
	printf("print nodes\n");
	struct node *temp=root;
	if(root==NULL)
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
struct node *add_cycle(struct node *root)
{
	struct node *temp=NULL,*prev=NULL,*s1=NULL;
	temp=s1=root;
	int last;
	if(root==NULL)
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
	return root;
}
int detect_cycle(struct node *root)
{
	struct node *s1=NULL,*s2=NULL;
	s1=s2=root;

	if(root==NULL)
	{
		return -1;
	}
	while(s2!=NULL && s2->link!=NULL)
	{
		s1=s1->link;
		s2=s2->link->link;
		if(s1==s2)
		{
			return 1;
		}
	}
	return 0;
}	
int main()
{
	struct node *root=NULL;
	int *arr=(int *)malloc(sizeof(int)*MAX),i=0;
	char temp;
	printf("Enter the elements : ");
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

        if(detect_cycle(root)==-1)
        {
                printf("EMPTY\n");
        }
        else if(detect_cycle(root)==1)
        {
                printf("YES\n");
        }
        else
        {
                printf("NO\n");
        }

	return 0;


}
