#include<limits.h>
#include<stdio.h>
//tail recursion!!!
int bin_search(int arr[], int low, int high, int diff) 
{ 
    // There must be two elements to find the missing 
    if (high <= low) 
        return INT_MAX; 
  
    // Find index of middle element 
    int mid = low + (high - low)/2; 
  
    // The element just after the middle element is missing. 
    // The arr[mid+1] must exist, because we return when 
    // (low == high) and take floor of (high-low)/2 
    if (arr[mid+1] - arr[mid] != diff) 
        return (arr[mid] + diff); 
  
    // The element just before mid is missing 
    if (mid > 0 && arr[mid] - arr[mid-1] != diff) 
        return (arr[mid-1] + diff); 
  
    // If the elements till mid follow AP, then recur 
    // for right half 
    if (arr[mid] == arr[0] + mid*diff) 
        return bin_search(arr, mid+1, high, diff); 
  
    // Else recur for left half 
  
    return bin_search(arr, low, mid-1, diff); 
} 
int find_missing(int *arr,int n)
{
	int diff,i;
	//assume only one element is missing,then
	diff = (arr[n-1]-arr[0])/n;

	printf("%d\n",bin_search(arr,0,n,diff));
}
int main()
{
	int arr[100],n,i;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	find_missing(arr,n);
	return 0;
}
