/*

ID : B171452
Description :  Convert Given Array to Max Heap  
Code by Sandeep Payili on 29/01/2021

*/
#include<stdio.h>
#include<stdlib.h>
void heapify(int *a,int start_index,int end_index)
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
		heapify(a,max_index,end_index);
	}
}

int main()
{
	printf("\n\n\t\tConversion of Array to Max Heap  \n\n");
	int n;
	printf("Enter number of elements : ");
	scanf(" %d",&n);
	int a[n];
	printf("\nEnter elements : ");
	for(int i=0;i<n;i++)
	{
		scanf(" %d",&a[i]);
	}
	for(int i=((n-1)/2) ; i>=0 ; i--)
	{
		heapify(a,i,n-1);
	}	
	printf("\n Max Heap : ");
	for(int i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
	printf("\n\n");
	return 0;
}
/*
		Conversion of Array to Max Heap  

Enter number of elements : 7

Enter elements : 10 15 16 24 35 28 18

 Max Heap :  35  24  28  10  15  16  18 

*/
/*

	   	 15
		/   \
   	   14    9
  	  /  \   / \
 	13    3 8   7
	/ \  /
   12  1 0

choosing (n-1)/2 is better than (n-1)/2 -1 

 */
