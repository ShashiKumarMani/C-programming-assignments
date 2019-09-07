#include<stdio.h>
void act(int *start,int *finish,int n)
{
	int i=0;
	printf("%d",i);

	for(int j=1;j<n;j++)
	{
		if(start[j]>=finish[i])
		{
			printf("%d\n",j);
			i=j;
		}
	}
}
int main()
{
	int n,start[100],finish[100],i;
	printf("Enter the number of works :");
	scanf("%d",&n);
	printf("\nEnter the start and finish time : ");
	for(i=0;i<n;i++)
	{
		printf("Work-%d - : ",i+1);
		scanf("%d %d",&start[i],&finish[i]);
	}
        for(i=0;i<n;i++)
        {
                printf("%d %d\n",start[i],finish[i]);
        }
	act(start,finish,n);

	return 0;}
