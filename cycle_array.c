/*
	Program to rotate elements of the array by k times
*/

#include<stdio.h>
int main()
{
	int arr[100],k,i,n,j,temp;
	
	printf("Enter the number of elements of array : ");
	scanf("%d",&n);
	printf("Enter the elements of array : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("The elements are : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("Enter the value of k:");
	scanf("%d",&k);

	for(i=0;i<k;i++)
		for(j=1;j<n;j++)
		{
		printf("\n%d ",arr[j]);
		temp=arr[j];
		arr[j]=arr[0];
		arr[0]=temp;
		//printf("%d\n",temp);
		}
	printf("\nThe elements after rotation are : ");
	for(j=0;j<n;j++)
	{
		printf("%d ",arr[j]);
	}
	return 0;
}
