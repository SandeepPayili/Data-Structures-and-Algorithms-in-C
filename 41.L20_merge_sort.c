/*

ID : B171452
Description :  Merge Sort
Code by Sandeep Payili on 27/01/2021

*/
#include<stdio.h>
#include<stdlib.h>
// int a[] same as int  *a
void merge(int a[],int start,int mid,int end)
{
	int temp_n = end-start+1;
	int b[temp_n];
	int k= 0;
	int i = start;
	int j = mid+1;
	while( i <= mid && j <= end)
	{
		if(a[i] < a[j])
		{
			b[k] = a[i];
			i++;
			k++;
		}
		else
		{
			b[k] = a[j];
			j++;
			k++;
		}
	}
	while(i <= mid)
	{
		b[k] = a[i];
		i++;
		k++;
	}
	while(j <= end)
	{
		b[k] = a[j];
		j++;
		k++;
	}
	for(i = 0 ; i < temp_n ; i++)
	{
		a[start] = b[i];
		start++;
	}
}

void merge_sort(int a[],int start,int end)
{
	if(start < end)
	{
		int mid;
		mid = (start+end)/2;
		merge_sort(a,start,mid);
		merge_sort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}

int main()
{
	printf("\n\n\t\tMerge Sort\n\n");
	int n;
	printf("\nEnter Number of Elements you want to search : ");
	scanf(" %d",&n);
	int a[n];
	printf("\nEnter Elements: ");
	for(int i=0;i<n;i++)
	{
 			scanf(" %d",&a[i]);
	}

	merge_sort(a,0,n-1);

	printf("\nAfter Meger Sort : ");
	for(int i=0;i<n;i++)
	{
 			printf(" %d",a[i]);
	}
	printf("\n\n");
	return 0;
}
