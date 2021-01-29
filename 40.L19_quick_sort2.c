/*

ID : B171452
Description :  Quick SOrt
Code by Sandeep Payili on 25/01/2021

*/
//QUick Sort taking pivot at end and traversing whole array
#include<stdio.h>
#include<stdlib.h>
int partition(int *a,int start,int end)
{	
		int pivot = a[end];
		int pivot_index = start;
		for (int i = start; i < end; ++i)
		{
			if(a[i]<=pivot)
			{
				int temp = a[i];
				a[i] = a[pivot_index];
				a[pivot_index] = temp;

				pivot_index++;
			}
		}
		int temp = a[pivot_index];
		a[pivot_index] =  a[end];
		a[end] = temp;
		return pivot_index;
}
void quick_sort(int *a,int start,int end)
{
	if(start >= end)
	{
		return;
	}
	int pivot_index = partition(a,start,end);
	quick_sort(a,start,pivot_index-1);
	quick_sort(a,pivot_index+1,end);
}	

int main()
{
	printf("\n\n\t\t\t\tQuick Sort Implementation \n\n");
	int n;
	printf("\nEnter Number of elements you want to sort : ");
	scanf(" %d",&n);
	int a[n];
	printf("\nEnter elements : ");
	for(int i=0;i<n;i++)
	{
		scanf(" %d",&a[i]);
	}

	quick_sort(a,0,n-1);

	printf("\n\nAfter Quick Sort \n\n");
	printf("Array is : ");
	for(int i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
	printf("\n");
	return 0;
}