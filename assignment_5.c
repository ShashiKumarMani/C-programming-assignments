/*
Consider int val=0xCAFE; Write expressions using bitwise operators that do the following:
1. test if at least three of last four bits (LSB) are on
2. reverse the byte order (i.e., produce val=0xFECA)
3. rotate four bits (i.e., produce val=0xECAF)
*/

#include<stdio.h>

int main()
{
    int n,i,m;
    int a[32];
    printf("Enter the value without '0x': ");
    scanf("%x",&n);
    printf("Size of array %d\n",sizeof(a)/sizeof(int));
    m=n;
    for(i=31;i>=0;i--)
    {
        a[i]=n%2;
        n=n/2;
    }

    printf("The binary form of the value is : ");
    for(i=0;i<32;i++)
    {
        printf("%d ",a[i]);
    }
    int remainder,reversedNumber;
    while(m != 0)
    {
        remainder = m%10;
        reversedNumber = reversedNumber*10 + remainder;
        m /= 10;
    }
    for(i=31;i>=0;i--)
    {
        a[i]=reversedNumber%2;
        reversedNumber=reversedNumber/2;
    }
    printf("Binary of reversed number : ");
    for(i=0;i<32;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("%d\n",reversedNumber);

    printf("\n");
    return 0;
}
