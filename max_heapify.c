#include<stdio.h>
#include<stdlib.h>
int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
void heapify(int *arr,int i,int n)
{
    int l,r,temp,largest;
    l=left(i);
    r=right(i);

    if(l>n || r>n)
    {
        return;
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
    int k=n/2,i;
    printf("%d\n",k);

    for(i=k;i>0;i--)
    {
        heapify(arr,i,n);
    }
}
int main()
{
    int *arr,i,n;
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
    max_heapify(arr,n);
    printf("The elements of the array after max-heapify are : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;

}
