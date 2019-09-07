/*
    Proram to solve petrol filling problem
*/
#include<stdio.h>
#include<stdlib.h>

int petrol_filling(int *arr,int n)
{
    int sum=0,diff=0,start=0,i,j;
    for(i=0;i<n;i++)
    {
        sum=sum+arr[i]-arr[n+i];
        if(sum<0)
        {
            start=i+1;
            diff=diff+sum;
            sum=0;
        }
    }
    return (sum+diff>=0)? start:-1;
}
int main()
{
    int n,i,val,N,j;
    printf("Enter the number of test cases : ");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        printf("Enter the number of petrol pumps : ");
        scanf("%d",&n);
        int *arr = (int *)malloc(sizeof(int)*n*2);
        printf("Enter the values and distances : ");
        for(j=0;j<n*2;j++)
        {
            scanf("%d",&arr[j]);
        }
        val=petrol_filling(arr,n);
        printf("NO : %d\n",val);
    }
    return 0;
}
