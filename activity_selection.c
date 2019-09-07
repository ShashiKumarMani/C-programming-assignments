#include<stdio.h>
int main()
{
	int start[100],finish[100],n,i;
	printf("Enter the number of jobs : ");
	scanf("%d",&n);
	
	printf("Enter starts :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&start[i]);
	}
	printf("Enter finish : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&finish[i]);
	}

	printf("%d",0);
	int j=0;

	for(i=1;i<n;i++)
	{
		if(start[i]>finish[j])
		{
			printf("%d ",i);
			j=i; // store previous selected jobs' finish time
		}
	}
	return 0;
}

