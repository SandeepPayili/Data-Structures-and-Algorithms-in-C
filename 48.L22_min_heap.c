/*

ID : B171452
Description :  Min Heap  (Insertion and Deletion)
Code by Sandeep Payili on 29/01/2021

*/
#include<stdio.h>
#include<stdlib.h>
int * heapify_percolate_up_non_recursive(int *a,int i)
{
	int parent_node;
	while(i>0) // 0 index has no parent node
	{
		parent_node = (i - 1)/2;  // to get parent node by formula
		if( a[i] < a[parent_node] )
		{
			int temp = a[i];
			a[i] = a[parent_node];
			a[parent_node] = temp;
		}
		i = parent_node;
	}
	return a;
}
int * heapify_percolate_up_recursive(int *a,int i)
{
	int parent_node;
	if(i>0) // 0 index has no parent node
	{
		parent_node = (i - 1)/2;  // to get parent node by formula
		if( a[i] < a[parent_node] )
		{
			int temp = a[i];
			a[i] = a[parent_node];
			a[parent_node] = temp;
		}
		a = heapify_percolate_up_recursive(a,parent_node);
	}
	return a;
}
int * insert(int *a,int n,int ele)
{
	if(a == NULL)
	{
		a = (int *)malloc(sizeof(int));
		*a = ele;
		return a;
	}
	a = (int *)realloc(a,(n+1) * sizeof(int));
	a[n] = ele; // n+1 size array has n index

	// a = heapify_percolate_up_recursive(a,n);
	a = heapify_percolate_up_non_recursive(a,n);
	return 	a;
}
void print_heap(int *a,int n)
{
	printf("\nCurrent Min Heap : ");
	for(int i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
	printf("\n\n");
}
int * heapify_percolate_down_recursive(int *a,int start_index,int end_index)
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
		a = heapify_percolate_down_recursive(a,min_index,end_index);
	}
	return a;
}

int * heapify_percolate_down_non_recursive(int *a,int start_index,int end_index)
{
	int min_index = -1;
	do
	{
			int left_child_index = (2*start_index) + 1;
			int right_child_index = (2*start_index) + 2;
			min_index = -1;
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
			}	
			start_index = min_index;
	}while(min_index != -1);
	return a;
}

int * delete(int *a,int n)
{
	if( n<=0 )
	{
		return NULL;
	}
	int start_index = 0;
	int end_index = n-1;
	// if(start_index == end_index)// only one element
	// {
	// return a;
	// }
	a[start_index] = a[end_index];
	// a = heapify_percolate_down_recursive(a,start_index,end_index);
	a = heapify_percolate_down_non_recursive(a,start_index,end_index);
	return a;
}
int main()
{
	printf("\n\n\t\t\tMin Heap  Implementation ( Insertion and Deletion )\n\n");
	int n = 0; // number of elements
	int *a;
	a = NULL;
	int op;
	int ele;
	do{
		printf("1.Insert Element 	    	 2.Delete Element \n");
		printf("3.Display all elements     	 4.Quit\n");
		printf("\nEnter your Choice : ");
		scanf(" %d",&op);
		switch(op)
		{
			case 1 :
					printf("\nEnter element to be inserted : ");
					scanf(" %d",&ele);
					a = insert(a,n,ele);
					n = n+1;
					break;
			case 2 :
					a = delete(a,n);
					if( a != NULL)
					{
						n = n - 1;
					}
					break;
			case 3 :
					print_heap(a,n);
					break;
			case 4 :
					break;
			default :
					printf("\nInvalid Input\n\n");
		}
	}while(op!=4);
	return 0;
}