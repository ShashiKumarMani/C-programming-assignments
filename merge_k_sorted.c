#include<stdio.h>
#include<stdlib.h>

int left(int i)
{
        return i*2+1;
}
int right(int i)
{
        return i*2+2;
}

void heapify(int *arr,int k,int n)
{
        int largest,i,temp,l,r;
        l=left(k);
        r=right(k);
        largest=k;

        if(l<n && arr[l] > arr[k])
        {
                largest=l;
        }
        if(r<n && arr[r] > arr[largest])
        {
                largest=r;
        }
        if(largest != k)
        {
                temp=arr[k];
                arr[k]=arr[largest];
                arr[largest]=temp;
                heapify(arr,largest,n);
        }
}
void max_heapify(int *arr,int n)
{
        for(int i=(n/2)-1;i>=0;i--)
        {
                heapify(arr,i,n);
        }
}
int delete_max(int *arr,int k,int n)
{
        int temp;
        for(int i=1;i<k;i++)
        {
                temp = arr[0];
                arr[0]=arr[n-1];
                n--;
        }
        return temp;
}
void merge_k(int *arr,int n,int *final,int *num)
{
	int a,b,c;
	for(int i=0;i<n;i++)
	{
		a = delete_max(arr[i]);
		b = delete_max(arr[i]);
		c = delete_max(arr
	}

}
int main()
{
	int *num=NULL,n,i;
	printf("Enter the number of arrays : " );
	scanf("%d",&n);
	num = (int *)malloc(sizeof(int)*n);
	int *arrays[n],*final=NULL,sum=0;
	for(i=0;i<n;i++)
	{
		printf("Enter the number of elements in the array-%d : ",i+1);
		scanf("%d",&num[i]);
		arrays[i] = (int *)malloc(sizeof(int) * num[i]);
		sum+=num[i];
	}
	
	final = (int *)malloc(sizeof(int)*sum);

	for(i=0;i<n;i++)
	{
		printf("Enter elements of array %d : ",i+1);
		for(int j=0;j<num[i];j++)
		{
			scanf("%d",&arrays[i][j]);
		}
		printf("\n");
		
	}
	for(i=0;i<n;i++)
	{
		max_heapify(arrays[i],num[i]);
	}
        for(i=0;i<n;i++)
        {
                printf("Elements : ");
                for(int j=0;j<num[i];j++)
                {
                        printf("%d",arrays[i][j]);
                }
		printf("\n");
        }

	merge_k(arrays,n,final,num);

	return 0;

}
