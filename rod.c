/*
	Program to solve rod cutting problem using DP
*/
#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int rod_cutting(int *price,int n)
{
	int val[n+1],max_value=0,j,i;

	val[0]=0;
	max_value=-999;

	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			max_value = max(max_value,price[j]+val[i-j-1]);	
		}	
		val[i]=max_value;
		printf("i:%d-->%d\n",i,max_value);
	}
	return val[n];
}
int main()
{
	int n;
	printf("Enter the length : ");
	scanf("%d",&n);

	int val[n];
	
	printf("Enter the values of each length : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}

	printf("The max value is %d\n",rod_cutting(val,n));

}
