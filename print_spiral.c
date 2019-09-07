/*
 *	Program to print the matrix in spiral form
 * */
#include<stdio.h>

int main()
{
	int arr[100][100],i,j,m,n;

	printf("Enter the dimensions : ");
	scanf("%d %d",&m,&n);

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
        for(i=0;i<m;i++)
        {
	/*	if(i%2)
		{
                	for(j=n-1;j>=0;j--)
                	{
                        	printf("%d ",arr[i][j]);
                	}
			printf("\n");
		}
	*/
		for(j=0;j<n;j++)
		{

			printf("%d ",arr[i][j]);
		}
		printf("\n");
        }
	
	return 0;

}
