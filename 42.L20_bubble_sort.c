/*

ID : B171452
Description :  Bubble  Sort
Code by Sandeep Payili on 27/01/2021

*/
#include<stdio.h>
#include<stdlib.h>
// int a[] same as int  *a
// brute force
void bubble_sort2(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j] > a[j+1])
			{
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
}
// optimized
void bubble_sort(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-(i+1);j++)
		{
			if(a[j] > a[j+1])
			{
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
	printf("\n\n\t\tBubble  Sort\n\n");
	int n;
	printf("\nEnter Number of Elements you want to search : ");
	scanf(" %d",&n);
	int a[n];
	printf("\nEnter Elements: ");
	for(int i=0;i<n;i++)
	{
 			scanf(" %d",&a[i]);
	}

	bubble_sort(a,n);

	printf("\nAfter Bubble  Sort : ");
	for(int i=0;i<n;i++)
	{
 			printf(" %d",a[i]);
	}
	printf("\n\n");
	return 0;
}
