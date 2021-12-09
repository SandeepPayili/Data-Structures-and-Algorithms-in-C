#include<stdio.h>
#include<stdlib.h>
void quick_sort(int *a,int start,int end)
{
	if(start >= end)
	{
		return;
	}
	int pivot = a[start];
	int i=start;
	int j= end;
	while(i<j)
	{
		while(a[i] <= pivot && i<end)
		{
			i++;
		}
		while(a[j] > pivot && j > start)
		{
			j--;
		}
		if(i < j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int temp = a[start];
	a[start] = a[j];
	a[j] = temp;
	quick_sort(a,start,j-1);
	quick_sort(a,j+1,end);
}
int main()
{
	int n;
	printf("\nEnter number of  elements : ");
	scanf(" %d",&n);
	int a[n];
	printf("\nENter elements : ");
	for(int i=0;i<n;i++)
	{
		scanf(" %d",&a[i]);
	}
	quick_sort(a,0,n-1);
	printf("\nAfter Quick Sort  :  ");
	for(int i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
	return 0;
}