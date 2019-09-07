#include<stdio.h>
#include<string.h>

int min_swaps(char *arr)
{
	int i,pos[100],len,j=0,sum=0,temp,p=0,count=0;
	len=strlen(arr);

	for(i=0;i<len;i++)
	{
		if(arr[i]=='[')
		{
			pos[j]=i;
			j++;
		}
	}

	for(i=0;i<len;i++)
	{
		if(arr[i]=='[')
		{
			count++;
			p++;
		}
		else
		{
			count--;
		}

		if(count<0)
		{
			sum++;
			temp=arr[i];
			arr[i]=arr[pos[p]];
			arr[pos[p]]=temp;
			count=1;
		}
	}
	return sum;
}
int main()
{
	char arr[100];
	printf("Enter the string : ");
	scanf("%s",arr);

	printf("%s\n",arr);
	printf("MIN SWAPS : %d\n",min_swaps(arr));

}
