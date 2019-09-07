/*
	Program to find if the linked list is palindrome or not
	Palindrome linked list
	
	Constraints:
	1. 1<= T <= 100
	2. 1 <= N <= 10^5
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

//add node at the end of the list
struct node *new_node(struct node *head,int val)
{
	struct node *s1=head,*temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->link=NULL;

	if(head==NULL)
	{
		head=temp;
		return head;
	}
	while(s1->link!=NULL)
	{
		s1=s1->link;
	}
	s1->link=temp;
	return head;
}
struct node *reverse(struct node *temp)
{
	struct node *prev=NULL,*next=NULL,*curr=temp;
	while(curr!=NULL)
	{
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}
	temp=prev;
	return temp;
}
int list_equal(struct node *head,struct node *temp)
{
	struct node *temp1=head,*temp2=temp;
	while(temp1&&temp2)
	{
		if(temp1->data==temp2->data)
		{
			temp1=temp1->link;
			temp2=temp2->link;
		}
		else
		{
			return 0;
		}
	}

	if(temp1==NULL && temp2==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
int is_palindrome(struct node *head,int n)
{
	struct node *mid=NULL,*sp=NULL,*prev=NULL,*temp=NULL;
	int cases,i=0;
	sp=head;
	
	if(n==1)
	{
		return 1;
	}
	while(i<(n/2))
	{
		prev=sp;
		sp=sp->link;
		i++;	
	}
	//if n is odd
	if(n%2)
	{
		mid=sp;
		sp=sp->link;
	}
	temp=sp;

	//first half
	prev->link=NULL;
	//reverse second half
	temp=reverse(temp);

	cases=list_equal(head,temp);
	
	//create the original list
	temp=reverse(temp);
	
	//if ll is odd 
	if(mid!=NULL)
	{
		prev->link=mid;
		mid->link=temp;
	}
	else
	{
		prev->link=temp;
	}
	return cases;
}
int main()
{
	struct node *head=NULL;
	int i,j,N,n;

	scanf("%d",&N);

	int *cases = (int *)malloc(sizeof(int)*N);
	char *string=NULL;

	for(i=0;i<N;i++)
	{
		scanf("%d",&n);

		string=(char *)malloc(sizeof(char)*(n+1));
		scanf("%s",string);
		
		string[n]='\0';

		for(j=0;j<strlen(string);j++)
		{
			head=new_node(head,string[j]);
		}
	
		cases[i]=is_palindrome(head,strlen(string));
	
		free(string);
		free(head);
		head=NULL;
	}
	for(i=0;i<N;i++)
	{
		(cases[i])?printf("YES\n"):printf("NO\n");
	}
	free(cases);
	return 0;

