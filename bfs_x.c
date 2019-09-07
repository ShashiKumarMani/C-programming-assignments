#include<stdio.h>
#define MAX 50
int arr[MAX][MAX],pi[MAX][MAX],d[MAX],queue[MAX],f=-1,r=-1,n=0;
void enqueue(int data)
{
	if(r==MAX)
	{
		printf("OVERFLOW\n");
	}
	else if(f==-1 && r==-1)
	{
		f=r=0;
		queue[r]=data;
	}
	else
	{
		queue[++r]=data;
	}
}
int dequeue()
{
	int data;
	if(f==-1)
	{
		printf("UNDERFLOW\n");
	}
	else if(f==r)
	{
		data = queue[f];
		f=r=-1;
		return data;
	}
	else
	{
		return queue[f++];
	}
}
int isempty()
{
	if(f==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void bfs(int v,int *visited)
{
	int u;
	
	visited[v]=1;

	if(!isempty())
	{
		printf("QUEUE NOT EMPTY\n");
		return
	}

	enqueue(v);

	while(!isempty())
	{
		u=dequeue();
		printf("dequeued - %d\n",u);
		for(int i=0;i<n;i++)
		{
			if(arr[u][i] && !visited[i])
			{
				pi[u][i]=u;
				enqueue(i);
				visited[i]=1;
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
		for(j=0;j<n;j++)
		{
			pi[i][j]=-1;
		}
		visited[i]=0;
		distance[i]=0;
	}
	bfs(v,visited);
	printf("The visited vertices are : ");
	for(i=0;i<n;i++)
	{
		if(visited[i] && i!=v)
		{
			printf("%d ",i);
		}
	}
	printf("\n The predecessor matrix is\n ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",pi[i][j]);
		}
		printf("\n");
	}
}
