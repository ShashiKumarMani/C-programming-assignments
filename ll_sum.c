/*
 Given two numbers represented by two lists, write a function that returns the sum list. The sum list is the list representation of the addition of two input numbers.
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
int print_sum(struct node *head1,struct node *head2)
{
	int i=1,a,b,sum=0;
	while(head1 || head2)
	{
		if(head1!=NULL)
		{
			a = head1->data;
			head1=head1->link;
		}
		else
		{
			a=0;
		}
		if(head2!=NULL)
		{
			b = head2->data;
			head2=head2->link;
		}
		else
		{
			b=0;
		}
		sum+=(a + b)*i;
		i*=10;
	}
	return sum;

}
int main()
{
        struct node *head1=NULL,*head2=NULL;
        int T,N,M,i,j,k;

        scanf("%d %d",&N,&M);

        for(j=0;j<N;j++)
        {
		scanf("%d",&k);
            	head1=new_node(head1,k);
        }
        for(j=0;j<M;j++)
        {
                scanf("%d",&k);
                head2=new_node(head2,k);
        }

        printf("%d\n",print_sum(head1,head2));
        return 0;
}
