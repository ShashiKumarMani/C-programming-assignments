#include<stdio.h>
#include<stdlib.h>

int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
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
    int k=n/2-1,i;
    for(i=k;i>=0;i--)
    {
        heapify(arr,i,n);
    }
}
void print_heap(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int sort(int *arr,int n,int k)
{
    int temp;
    for(int i=0;i<k;i++)
    {
        temp=arr[0];
        arr[0]=arr[n-1];
        arr[n-1]=temp;
        --n;
        printf("N-%d\n",n);
        max_heapify(arr,n);
        print_heap(arr,n);
    }
    return arr[0];
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
    print_heap(arr,n);
    max_heapify(arr,n);
    printf("\nThe elements of the array are : ");
    print_heap(arr,n);

    printf("\nEnter the k value : ");
    scanf("%d",&k);
    sort(arr,n,k);

    printf("\nThe %d largest element of the array is %d : ",k,sort(arr,n,k));

    return 0;

}
