/*
	Program to merge k sorted linked list
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T,n,m,i,j,k,*num=NULL;

	scanf("%d",&T);

	int *arr[T];
	for(i=0;i<T;i++)
	{
		scanf("%d",&n);

		num = (int *)malloc(sizeof(int)*n);

		for(j=0;j<n;j++)
		{
			scanf("%d",&m);
			num[i]=m;
			arr[i] = (int *)malloc(sizeof(int)*m);
			for(k=0;k<m;k++)
			{
				scanf("%d",&arr[i][k]);
			}
		}
        	for(j=0;j<n;j++)
        	{
        	        m = num[j];
        	        for(k=0;k<m;k++)
        	        {
        	                printf("%d ",arr[j][k]);
        	        }
        	}
	}
}
