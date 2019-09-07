/*
        Program to find if the linked list is palindrome or not
        Palindrome linked list

	Constraints:
	1 <= T <= 100
	1 < N < 10^5
	1 < M < 10^5	
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CASES 1000
#define STRING 100000

struct node{
        char data;
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
        printf("PRINT\n");
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
int find_node(int d,struct node *head1,struct node *head2)
{
	struct node *temp1=head1,*temp2=head2;
	int i=0;
	for(i=0;i<d;i++)
	{
		temp1 = temp1->link;
	}
	while(temp1 && temp2)
	{
		if(temp1 == temp2)
		{
			return temp1->data;
		}
	}
}
int find_intersection(struct node *head1,struct node *head2)
{
	int i=0,j=0,d;
	struct node *temp1=head1,*temp2=head2;

	while(temp1 != NULL)
	{
		i++;
		temp1 = temp1->link;
	}
	while(temp2 != NULL)
	{
		j++;
		temp2 = temp2->link;
	}
	if(i > j)
	{
		d = i - j;
		d = find_node(d,head1,head2);
	}
	else
	{
		d = j - i;
		d = find_node(d,head2,head1);
	}
	return d;
}
int main()
{
	struct node *head1=NULL,*head2=NULL;
        int i,j,T,n,m,*arr1=NULL,*arr2=NULL;

        scanf("%d",&T);

        int *cases = (int *)malloc(sizeof(int)*T);

        for(i=0;i<T;i++)
        {
                scanf("%d %d",&n,&m);
		arr1 = (int *)malloc(sizeof(int)*n);
		arr2 = (int *)malloc(sizeof(int)*m);

		for(j=0;j<n;j++)
		{
			scanf("%d",&arr1[j]);
		}
		for(j=0;j<m;j++)
		{
			scanf("%d",&arr2[j]);
		}
                
		head1 = quick_list(head1,arr1,n);
		head2 = quick_list(head2,arr2,m);
		
		//print_nodes(head1);
		print_nodes(head2);

                cases[i]=find_intersection(head1,head2);
                free(arr1);
		free(arr2);
		free(head1);
		free(head2);
        }
        for(i=0;i<T;i++)
        {
                printf("%d\n",cases[i]);
        }
        free(cases);
        return 0;
}

