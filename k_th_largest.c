#include<stdio.h>
#include<stdlib.h>

int arr[100],n;

int left(int i)
{
	return i*2+1;
}
int right(int i)
{
	return i*2+2;
}

void heapify(int k)
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
		heapify(largest);
	}

}
void max_heapify()
{
	for(int i=(n/2)-1;i>=0;i--)
	{
		heapify(i);
	}
}
int delete_max(int k)
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
int main()
{
    int i;
    printf("enter n: ");
    scanf("%d",&n);
    
    printf("Enter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The elements of the array are : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    max_heapify(n);
    printf("The elements of the array after max-heapify are : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("Enter the kth value : ");
    int k;
    scanf("%d",&k);

    if(k>=n)
    {
	    printf("Enter k value less or equal to n\n");
   		return 0;
    }

    k = delete_max(k);
    printf("MAX is %d\n",k);

    return 0;

}
