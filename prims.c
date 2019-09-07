#include<stdio.h>
int extract_min(int *key,int *min)
{
	int m=999,i;
	for(i=0;i<n;i++)
	{
		if(key[i]<min && min[0]!=1)
		{
			min=i;
		}

	}
	return i;
}
void prims(int arr[5][5],int n)
{
	int pred[n],key[n],min[n],i,m;
	//initialise nodes
	for(i=0;i<n;i++)
	{
		key[i]=999;
		pred[i]=NULL;
	}
	key[0]=0;

	for(i=0;i<n-1;i++)
	{
		m=extract_min(key,min);
	}

	for(i=0;i<n;i++)
	{
		if(arr[m][i] && arr[m][i] < key[i])
		{
			pred[i]=m;
			key[i]=arr[m][i];
		}
	}

}
int main()
{
	int i,j,n;
	printf("Enter the number of nodes in the matrix : ");
	scanf("%d",&n);
	int arr[n][n];

	printf("Enter the adjacent matrix : ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",arr[i][j]);
		}
	}
	prims(arr[n][n],n);
	return 0;
}
