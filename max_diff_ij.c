#include<stdio.h>
int max(int m,int n)
{
	return m>n?m:n;
}
int main()
{
	int i,j,n=-999,m,arr[100];

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("The elements are : ");
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{

			if(i!=j && arr[i]>arr[j])
			{
				m=max(m,j-i);			
			}
		}
	}	
	printf("MAX diff : %d\n",m);
	return 0;


}
