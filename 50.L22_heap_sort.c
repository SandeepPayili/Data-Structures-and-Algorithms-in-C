/*

ID : B171452
Description :  Heap Sort
Code by Sandeep Payili on 29/01/2021

*/
#include<stdio.h>
#include<stdlib.h>

void max_heapify(int *a,int start_index,int end_index)
{
	int left_child_index = (2*start_index) + 1;
	int right_child_index = (2*start_index) + 2;
	int max_index = -1;
	if(right_child_index <= end_index)
	{
		if( a[left_child_index]  > a[right_child_index])
		{
			max_index = left_child_index;
		}
		else
		{
			max_index = right_child_index;
		}
	}
	else if(left_child_index <= end_index)
	{
		max_index = left_child_index;
	}
	if( max_index != -1 && a[max_index] > a[start_index])
	{
		int temp = a[start_index];
		a[start_index] = a[max_index];
		a[max_index] = temp;
		max_heapify(a,max_index,end_index);
	}
}


void max_heap_sort(int *a,int n)
{
	// building heap
	for(int i = (n-1)/2 ; i>=0 ; i--)
	{
		max_heapify(a,i,n-1);
	}
	// deleting one by ond to get sorted
	for(int i = n-1 ; i > 0 ;i--)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		max_heapify(a,0,i-1);
	}
}

void min_heapify(int *a,int start_index,int end_index)
{
	int left_child_index = (2*start_index) + 1;
	int right_child_index = (2*start_index) + 2;
	int min_index = -1;
	if(right_child_index <= end_index)
	{
		if( a[left_child_index]  < a[right_child_index])
		{
			min_index = left_child_index;
		}
		else
		{
			min_index = right_child_index;
		}
	}
	else if(left_child_index <= end_index)
	{
		min_index = left_child_index;
	}
	if( min_index != -1 && a[min_index] < a[start_index])
	{
		int temp = a[start_index];
		a[start_index] = a[min_index];
		a[min_index] = temp;
		min_heapify(a,min_index,end_index);
	}
}

void min_heap_sort(int *a,int n)
{
	// building heap
	for(int i = (n-1)/2 ; i>=0 ; i--)
	{
		min_heapify(a,i,n-1);
	}
	// deleting one by ond to get sorted
	for(int i = n-1 ; i > 0 ;i--)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		min_heapify(a,0,i-1);
	}
}

int main()
{
	printf("\n\n\t\tHeap Sort  \n\n");
	int n;
	printf("Enter number of elements : ");
	scanf(" %d",&n);
	int a[n];
	printf("\nEnter elements : ");
	for(int i=0;i<n;i++)
	{
		scanf(" %d",&a[i]);
	}

	max_heap_sort(a,n);

	printf("\nAfter Heap Sort (Ascending order) : ");
	for(int i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
	printf("\n\n");

	min_heap_sort(a,n);

	printf("\nAfter Heap Sort (Descending order) : ");
	for(int i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
	printf("\n\n");

	return 0;
}

/*
		Heap Sort  

Enter number of elements : 10

Enter elements : 4 8 9 1 0 6 2 7 3 5

After Heap Sort (Ascending order) :  0  1  2  3  4  5  6  7  8  9 


After Heap Sort (Descending order) :  9  8  7  6  5  4  3  2  1  0 

*/