/*

ID : B171452
Description :  Quick SOrt
Code by Sandeep Payili on 25/01/2021

*/
//QUick Sort taking pivot at first element
#include<stdio.h>
#include<stdlib.h>
int partition(int *a,int start,int end)
{	
			int pivot = a[start];
			int i = start,j= end;
			while(i<j)
			{
				while(a[i] <= pivot && i < end)
				{
					i++;
				}
				while(a[j] > pivot  && j>start)
				{
					j--;
				}	
				if( i < j )
				{
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
			int temp = pivot;
			a[start] = a[j];
			a[j] = temp;	
			return j;
}
int partition2(int *a,int start,int end)
{	
		 if(end - start > 1)
		 {
			int pivot = a[start];
			int i = start+1,j= end;
			while(i<j)
			{
				while(a[i] <= pivot && i < end)
				{
					i++;
				}
				while(a[j] > pivot  && j>start)
				{
					j--;
				}	
				if( i < j )
				{
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
			
			int temp = a[start];
			a[start] = a[j];
			a[j] = temp;
			return j;
		}
		else
		{
			if(a[start] > a[end])
			{
				int temp = a[end];
				a[end] = a[start];
				a[start] = temp;
			}
			return 1; // 0 or 1 because it has only two elements in array
		}
			
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