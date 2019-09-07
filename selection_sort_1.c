#include<stdio.h>
#define MAX 10
int main()
{
	int a[MAX],i,j,k,n,temp,min;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &a[i]);
	}
    for(j=0;j<n-1;j++)
    {
        min=j;
        for(k=j+1;k<n;k++)
        {
            if(a[min]>a[k])
            {
                min=k;
            }
        }
        if(min!=j)
        {
            temp = a[j];
            a[j]=a[min];
            a[min]=temp;
        }

    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
