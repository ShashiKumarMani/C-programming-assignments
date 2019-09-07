/*
	Program to perform Depth first search on a undirected graph
	AND detect cycles of len 3 

*/
#include<stdio.h>
#define MAX 50
int arr[MAX][MAX],n=0,prev=0;

void dfs(int v,int *visited)
{	
	visited[v]=1;
	for(int i=0;i<n;i++)
	{
		if(arr[v][i])
		{
		       	if(visited[i]!=1)
			{
				visited[i]=1;
				prev = v;
				dfs(i,visited);

			}
			else if(visited[i]==1 && i!=prev)
			{

				printf("CYCLE EXISTS vertices - %d-%d-%d\n",v,i,prev);
			}
		}
	}
}
int main()
{
	int v=0,i,j;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);

	int visited[n],distance[n];
	
	printf("Enter the graph in matrix form :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Enter the starting vertex [0-n]: ");
	scanf("%d",&v);
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	dfs(v,visited);
	printf("The visited vertices are : ");
	for(i=0;i<n;i++)
	{
		if(visited[i] && i!=v)
		{
			printf("%d ",i);
		}
	}
}
