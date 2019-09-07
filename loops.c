#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    float d;

    printf("Enter a number : ");
    scanf("%d",&a);
    printf("YOU HAVE ENTERED : %d\n",a);
    printf("PROCESSING.........\n");
    d = sqrt(a);
    printf("Square root : %f\n",d);

    for(int i=2;i<=d;i++)
    {
        if(a%i==0)
        {
            printf("NUMBER NOT PRIME\n");
            return 0;
        }
    }
    printf("PRIME!!!!\n");

    return 0;




}
