/*P8.12 Program of sorting using radix sort*/
#include<stdio.h>
#include<stdlib.h>

struct  node
{
	int data ;
	struct node *next;
}*start=NULL;

void radix_sort()
{
	int i,k,dig,least_sig,most_sig;
	struct node *p, *rear[10], *front[10];

	least_sig=1;
	most_sig=large_dig(start);

	for(k=least_sig; k<=most_sig; k++) 
	{
		/*Make all the queues empty at the beginning of each pass*/
		for(i=0; i<=9 ; i++)
		{
			rear[i] = NULL;
			front[i] = NULL ;
		}
		
		for( p=start; p!=NULL; p=p->next )
		{
			/*Find kth digit in the number*/
			dig = digit(p->data, k);
		
			/*Add the number to queue of dig*/
			if(front[dig] == NULL)			
				front[dig] = p ;
			else
				rear[dig]->next = p;
			rear[dig] = p;
		}
		
		/*Join all the queues to form the new nexted list*/
		
		i=0;
		while(front[i] == NULL)
			i++;
		start = front[i];	
		while(i<9) 
		{
			if(rear[i+1]!=NULL)
				rear[i]->next=front[i+1];
			else
				rear[i+1]=rear[i];
			i++;
		}
		rear[9]->next=NULL;
	}
}/*End of radix_sort*/

/*This function finds number of digits in the largest element of the list */
int large_dig()
{
	struct node *p=start;
	int large=0,ndig=0;

	/*Find largest element*/
	while(p != NULL)
	{
		if(p ->data > large)
			large = p->data;
		p = p->next ;
	}
	/*Find number of digits in largest element*/
	while(large != 0)
	{
		ndig++;
		large = large/10 ;
	}
	return(ndig);
} /*End of large_dig()*/

/*This function returns kth digit of a number*/
int digit(int number, int k)
{
	int digit, i ;
	for(i=1; i<=k; i++)
	{
		digit = number % 10 ;
		number = number /10 ;
	}
	return(digit);
}/*End of digit()*/



main()
{
	struct node *temp,*q;
	int i,n,item;

	printf("Enter the number of elements in the list : ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&item);

		/*Inserting elements in the nexted list*/
		temp= malloc(sizeof(struct node));
		temp->data=item;
		temp->next=NULL;

		if(start==NULL) /*Inserting first element */
			start=temp;
		else
		{
			for(q=start; q->next; q=q->next);
			q->next=temp;
		}
	}/*End of for*/

	radix_sort();
	printf("Sorted list is :\n");
	
	for(q=start; q; q=q->next)
		printf("%d ", q->data);
	
	printf("\n");

}/*End of main()*/

