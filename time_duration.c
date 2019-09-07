#include<stdio.h>
#define MAX 100
int main()
{
    int arr[MAX],top=0,n,i,d,m;
    printf("Enter the number of works : ");
    scanf("%d",&n);

    printf("Enter the value of starting hour,starting minute,ending hour and ending minute in SH SM EH EM and press enter\n");
    for(i=0;i<n;i++)
    {
        printf("WORK-%d - [SH SM EH EM]: ",i+1);
        scanf("%d %d %d %d",&arr[top],&arr[top+1],&arr[top+2],&arr[top+3]);
        if(arr[top+1]>=60||arr[top+3]>=60||arr[top+1]<0||arr[top+3]<0||arr[top]>=24||arr[top+2]>=24||arr[top]<0||arr[top+2]<0)
        {
            printf("Invalid values..Try again\n");
            i--;
        }
        top+=4;
    }
    top=0;
    for(i=0;i<n;i++)
    {
        d=arr[top+2]-arr[top];
        {
            m = (60-arr[top+3])+ arr[top+1];
        }
        printf("WORK-%d - HOURS-%d MINUTES-%d\n",i+1,d,m);
        top+=4;
    }
    return 0;
}
