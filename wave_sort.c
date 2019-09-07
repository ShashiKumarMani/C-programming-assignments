#include<stdio.h>
void insertion_sort(int *arr,int n)
{
	int j,key,i;

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
}
int main()
{
	int arr[100],n,i,temp;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	insertion_sort(arr,n);

	for(i=0;i<n;i+=2)
	{
		temp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=temp;
	}
	printf("\nWave sorted array : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

