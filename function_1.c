/*
    getNum(): get number from user
    binaryToDecimal(): core function to convert binary to decimal
    powerTwo(): calculates power's of two
    firstDigit(): getting first digit from the binary number
    validateBinary(): chacking if whether the number is correct or not

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int powerTwo(int i)
{
	int sum=1;
	while(i>0)
	{
		sum*=2;
		i--;
	}
	return sum;

}
char *getNum(char *p)
{
    p = (char *)malloc(33*sizeof(char));
    printf("Enter a binary value : ");
    scanf("%s",p);
    return p;
}
int binaryToDecimal(char *p,int **q)
{
	int n=strlen(p),i,j,sum=0;
	*q=(int *)malloc(sizeof(int)*n);
	printf("A\n");
	for(i=n-1,j=0;i>=0;i--,j++)
	{
		printf("%d\n",j);
		*q[j]=(p[i]-48);
		printf("C\n");
		sum+=powerTwo(i)*(p[i]-48);
	}
	printf("B\n");
	return sum;
}
/*validation from GeeksForGeeks*/
int validateBinary(int *p,int sum,int n)
{
	int *r,i=0;
	r=(int *)malloc(sizeof(n));
	while(sum>0)
	{
		r[i]=sum%2;
		sum=sum/2;
		i++;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",r[i]);
	}

}
int main()
{
    char *p;
    int sum,*q=NULL,n;
    p=getNum(p);
    n=strlen(p);
    printf("The number is %s\n",p);
    printf("The len is %d\n",n);
    
    sum=binaryToDecimal(p,&q);
    free(p);
    printf("%d \n",sum);
    validateBinary(q,sum,n);
    return 0;

}
