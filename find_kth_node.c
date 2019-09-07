/*
    Find the kth node from the end of a linked list
    Constraints:
    1. 1 <= T <= 200
    2. 1 <= L <= 10^3
    3. 1 <= N <= 10^3
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *link_add(struct node *head,int val)
{
    struct node *temp,*i,*j;
    i=head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->link=NULL;
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    while(i->link!=NULL)
    {
        i=i->link;
    }
    i->link=temp;
    return head;
}
int find_k(struct node *head,int k)
{
    struct node *p,*q,*r,*s;
    int count=0;
    p=q=r=head;

    while(count<k-1)
    {
        q=q->link;
        if(q==NULL)
        {
            printf("The list length is smaller than the value k\n");
            return -1;
        }
        count++;
    }
    while(q->link!=NULL)
    {
        q=q->link;
        p=p->link;
    }
    return p->data;
}
int main()
{
   
    int i,j,k,num,val,n,*cases=NULL;
    scanf("%d",&n);
    if(n<0 || n>100)
    {
	    printf("ERROR: 1<=n<=100\n");
	    return 0;
    }
    cases = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        struct node *arr=NULL;
        scanf("%d %d",&num,&k);
	if(num<1 || num>100)
        {
            printf("ERROR\n");
            i--;
            continue;
        }
        if(k<1 || k>num)
        {
            printf("ERROR\n");
            i--;
            continue;
        }
        for(j=0;j<num;j++)
        {
            scanf("%d",&val);
            arr=link_add(arr,val);
        }
        k=find_k(arr,k);
        cases[i]=k;
        free(arr);
    }
    for(i=0;i<n;i++)
    {
        if(cases[i]==-1)
        {
            printf("ERROR\n");
            break;
        }
        printf("%d\n",i+1,cases[i]);
    }
    free(cases);
}
