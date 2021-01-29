/*

ID : B171452
Description :  Insertion  Sort
Code by Sandeep Payili on 27/01/2021

*/
#include<stdio.h>
#include<stdlib.h>	
// int a[] same as int  *a

void insertion_sort(int *a,int n)
{
	for(int i=1;i<n;i++)
	{
		int key = a[i];
		int j = i - 1;
		while(j>=0 && a[j] > key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}	
}

int main()
{
	printf("\n\n\t\tInsertion  Sort\n\n");
	int n;
	printf("\nEnter Number of Elements you want to search : ");
	scanf(" %d",&n);
	int a[n];
	printf("\nEnter Elements: ");
	for(int i=0;i<n;i++)
	{
 			scanf(" %d",&a[i]);
	}

	insertion_sort(a,n);

	printf("\nAfter Insertion  Sort : ");
	for(int i=0;i<n;i++)
	{
 			printf(" %d",a[i]);
	}
	printf("\n\n");
	return 0;
}
