#include<stdio.h>
void quick(int *arr,int n)
{
	int pivot = arr[0],i=0,temp,j;
	for(j=1;j<n;j++)
	{
		if(arr[i] > arr[j])
		{
			printf("%d\n",arr[j]);
			i++;
			temp = arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}	
		//temp=arr[i];
		//arr[i]=arr[0];
		//arr[0]=temp;
	}

}
int main()
{
	int arr[100],n,i,j;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("The elements are : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}

	quick(arr,n);
	printf("SORTED : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
