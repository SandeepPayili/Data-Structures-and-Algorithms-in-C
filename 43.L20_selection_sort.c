/*

ID : B171452
Description :  Selection  Sort
Code by Sandeep Payili on 27/01/2021

*/
#include<stdio.h>
#include<stdlib.h>	
// int a[] same as int  *a

void selection_sort(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		int min = a[i];
		int loc=i;
		for(int j=i;j<n;j++)
		{
			if(a[j] < min)
			{
				min = a[j];
				loc = j;
			}
		}
		int temp = a[i];
		a[i] = a[loc];
		a[loc] = temp;
	}
}

int main()
{
	printf("\n\n\t\tSelection  Sort\n\n");
	int n;
	printf("\nEnter Number of Elements you want to search : ");
	scanf(" %d",&n);
	int a[n];
	printf("\nEnter Elements: ");
	for(int i=0;i<n;i++)
	{
 			scanf(" %d",&a[i]);
	}

	selection_sort(a,n);

	printf("\nAfter Selection  Sort : ");
	for(int i=0;i<n;i++)
	{
 			printf(" %d",a[i]);
	}
	printf("\n\n");
	return 0;
}
