/*
    Program to convert binary to decimal
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char *getnum()
{
    int arr[32];
    printf("Enter the number : ");

}
int powerTwo(int val)
{
    int i=1;
    while(val!=0)
    {
        i*=2;
        val--;
    }
    return i;
}
int bintodecimal(char *arr)
{
    int i=0,j=0,sum=0;
    while(arr[i]!=0)
    {
        i++;
    }
    while(i>=0)
    {
        sum+=(arr[i]-48)*powerTwo(j);
        j++;
        i--;
    }
    return sum;
}

int main()
{
    char *arr;
    int i,val;
    arr = getnum();
    val=bintodecimal(arr);
    printf("%d\n",val);
    return 0;
}
