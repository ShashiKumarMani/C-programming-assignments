/*
	Program to find pairs of elements in an array whose sum equals to a given value.

*/
#include<stdio.h>

int main()
{
	int sum,i,j,n,arr[100],flag=0;
	printf("Enter the sum value :");
	scanf("%d",&sum);
	printf("Enter the number of elements of the array : ");
	scanf("%d",&n);
	printf("Enter the elements of array : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("The elements of the array is : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	for(i=0;i<n;i++)
	{
	    if(sum - arr[i] > 0)
	    {    
		 for(j=0;j<n;j++)
		 {   
	             if((sum - arr[i] - arr[j])==0)
		     {   
			printf("\nElements at %d and %d equals sum\n",i,j);
			flag=1;
			break;
		     }
		 }
	    }
	    if(flag==1)
	    {
		break;
	    }
	}
	if(flag==0)
	{
		printf("None of the pairs of the elements equals to sum\n");
	}
	return 0;
}
