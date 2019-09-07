#include<stdio.h>
#include<stdlib.h>
int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+1+1;
}
void heapify(int *arr,int i,int n)
{
    int l,r,temp,largest;
    l=left(i);
    r=right(i);

    if(l>n || r>n)
    {
        return;s
    }
    if(l<=n && arr[l]>arr[i])
        largest = l;
    else
        largest=i;

    if(r<=n && arr[r]>arr[largest])
        largest = r;

    if(largest != i)
        temp = arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;

        heapify(arr,largest,n);
}
void max_heapify(int *arr,int n)
{
    int i;
    for(i=(n-1)/2;i>0;i--)
        maxheapify(arr,n,i);
}

void heapsort(int *arr,int n)
{
    int temp,i;
    max_heapify(arr,n);

    printf("--> ");
    for(int j=0;j<n;j++)
            printf("%d ",arr[j]);

    for(i=0;i<n;i++)
    {
        temp=arr[0];arr[0]=arr[n-1];arr[n-1]=temp;
        n=n-1;
        max_heapify(arr,n);
        printf("--> ");
        for(int j=0;j<n;j++)
            printf("%d ",arr[j]);
    }
}

int main()
{
    int *arr,i,n,k;
    printf("enter n: ");
    scanf("%d",&n);
    arr = (int *)malloc(sizeof(int)*n);

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
    heapsort(arr,n);

    return 0;

}
