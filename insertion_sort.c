/*
 * INSERTION SORT
 * */

#include<stdio.h>
int main()
{
	int arr[100],n,i,j,temp,key;
	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("The array is :");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	for(j=1;j<n;j++)
	{
		key=arr[j];

		i=j-1;
		if(arr[i]>key)
		{
			while( i>=0 && arr[i]>key)
			{
				arr[i+1]=arr[i];
				i--;
			}
			arr[i+1]=key;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
