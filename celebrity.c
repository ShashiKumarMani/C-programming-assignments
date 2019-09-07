/*
    Program to find the celebrity in a given adjacent matrix
*/
#include<stdio.h>
#include<stdlib.h>
int is_celebrity(int **arr,int n)
{
    int i,j,celeb=0;

    for(i=0;i<n;i++)
    {
        if(arr[celeb][i]==1)
        {
            celeb=i;//potential celebrity
        }
    }
    for(i=0;i<n;i++)
    {
        //if celeb knows any other person OR is not know by the rest
        if(i!=celeb &&(arr[celeb][i]==1|| arr[i][celeb]!=1))
        {
            return -1;
        }
    }
    return celeb;
}
int main()
{
    int n,i,j,k;
    printf("Enter the number of test cases [LIMIT-50] : ");
    scanf("%d",&n);
    int *cases = (int *)malloc(sizeof(int)*n); //store results

    for(i=0;i<n;i++)
    {
        int l;
        printf("Enter the number of people in test case %d [LIMIT-100]: ",i);
        scanf("%d",&l);
        int *arr[l];
        for(j=0;j<l;j++)
        {
            arr[j]=(int *)malloc(sizeof(int)*l);
        }

        for(int j=0;j<l;j++)
        {
            for(int k=0;k<l;k++)
            {
                scanf("%d",&arr[j][k]);
            }
        }
        cases[i]=is_celebrity(arr,l);
        //free memory
        for(j=0;j<l;j++)
        {
            free(arr[j]);
        }
    }
    //print results
    for(i=0;i<n;i++)
    {
        printf("%d\n",cases[i]);
    }
    free(cases);
    return 0;
}
