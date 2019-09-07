/*
	Write a program to delete N Nodes in the linked list after skipping M Nodes in the linked list.
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX_NUM 100000

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
        printf("\n");
        struct node *temp=head;

        if(temp==NULL)
        {
                return;
        }
        while(temp!=NULL)
        {
                printf("%d ",temp->data);
                temp=temp->link;
        }
}
struct node *delete_nodes(struct node *head,int N,int M)
{
	int i,j;
	struct node *temp=head,*prev=NULL;
	for(i=-1;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if(temp->link!=NULL)
			{
				prev=temp;
				temp=temp->link;
			}
			else
			{
				return head;
			}
		}
		prev->link=temp->link;
		temp=temp->link;
		prev = prev->link;
	}
	return head;
}
int main()
{
        struct node *head=NULL;
        int T,N,M,n,i,j,*val=NULL;

        scanf("%d",&T);
        struct node *cases[T];
        for(i=0;i<T;i++)
        {
                scanf("%d",&n);
                scanf("%d %d",&N,&M);
                val = (int *)malloc(sizeof(int)*n);
		for(j=0;j<n;j++)
                {
                        scanf("%d",&val[j]);
                }
		head = quick_list(head,val,n);
		head=delete_nodes(head,N,M);
		cases[i]=head;
		head=NULL;
        }
	for(i=0;i<T;i++)
	{
		print_nodes(cases[i]);
		free(cases[i]);
	}
        return 0;
}

