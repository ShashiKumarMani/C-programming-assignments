/*
        Program to find if the linked list is palindrome or not using recursion.
        
        Constraints:
        1. 1<= T <= 100
        2. 1 <= N <= 10^5
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
//Function to check for palindrome using recursion
int is_palindrome(struct node **head1,struct node *head2)
{
	int flag,flag2;

	if(head2 == NULL)
	{
		return 1;
	}
	flag = is_palindrome(head1,head2->link);
	if(!flag)
	{
		return 0;
	}
	flag2 = ((*head1)->data == head2->data)?1:0;

	(*head1) = (*head1)->link;

	return flag2;
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

                cases[i]=is_palindrome(&head,head);

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
}

