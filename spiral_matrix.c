#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m,n,i,j;
	printf("Enter the dimensions of the matrix : ");
	scanf("%d %d",&m,&n);
	int *arr[m];

	for(i=0;i<m;i++)
	{
		arr[i] = (int *)malloc(sizeof(int)*n);		
	}
	printf("Enter the elements of the array : ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("The elements of the matrix are \n");
	for(i=0;i<m;i++)
	{
                for(j=0;j<n;j++)
                {
                        printf("%d ",arr[i][j]);
                }
		printf("\n");
        }
	char c;
	printf("SPIRAL FORM\n");
	printf("CONTINUE ? : ");
	scanf("%c",&c);
	if(c == 'n')
		return 0;
	for(i=0;i<m;i++)
	{
		if(i%2 ==0)
		{
			for(j=0;i<n;j++)
			{
				printf("%d ",arr[i][j]);
			}
		}
		else
		{
			for(j=n-1;j>=0;j--)
			{
				printf("%d ",arr[i][j]);
			}
		}
		printf("\n");
	}
	return 0;


}
