/*
	Alternative split of a linked list
	
	Constraints:
	1. 1 <= T <= 100
	2. 1 <= N <= 10^5
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
struct node *divide(struct node *head1)
{
	struct node *temp1=head1,*temp2=NULL,*head2=NULL;
	if(temp1->link == NULL)
	{
		return NULL;
	}
	else
	{
		head2=(temp1)->link;
	}
	temp2=head2;
	while(temp2 || temp1)
	{
		temp1->link=temp2->link;
		temp1=temp1->link;
		if(temp1 == NULL || temp1->link == NULL)
		{
			temp2->link=NULL;
			break;
		}
		temp2->link=temp1->link;
		temp2=temp2->link;
	}
	return head2;
}
int main()
{
	struct node *head1=NULL,*head2=NULL;
	int N,n,i,j,*val=NULL;

	scanf("%d",&N);
	struct node *cases[N*2];

	for(i=0;i<N;i++)
	{
		scanf("%d",&n);
		val = (int *)malloc(sizeof(int)*n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&val[j]);
		}
		head1 = quick_list(head1,val,n);

		printf("LIST CREATED\n");
		
		head2 = divide(head1);
		//print_nodes(head1);
		//print_nodes(head2);
		cases[i*2]=head1;
		cases[i*2+1]=head2;
		head1=NULL;
		head2=NULL;
	}
	for(i=0;i<N*2;i++)
	{
		print_nodes(cases[i]);
	}
	return 0;
}
