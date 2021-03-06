/*

ID : B171452
Description :  Tree Traversals and Constructing tree from given pre order and in order
Code by Sandeep Payili on 25/01/2021

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SPACE  5

struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};
void print_binary_tree2D(struct BinaryTreeNode *root,int space)
{
	if(root == NULL)
	{
		// printf("\n Binary Tree has no root  \n");		 as it is recursive call this will print more then one time 
		return;
	}
	space  = space + SPACE;
	print_binary_tree2D(root->right,space);
	for (int i=SPACE ; i< space;i++)
	{
		printf(" ");
	}
	printf(" %d ", root->data);
	printf("\n");
	print_binary_tree2D(root->left,space);

}
void print_tree_in_pre_order(struct BinaryTreeNode *root)
{
	if(root!=NULL)
	{
		printf(" %d ", root->data);
		print_tree_in_pre_order(root->left);
		print_tree_in_pre_order(root->right);
	}
}
void print_tree_in_in_order(struct BinaryTreeNode *root)
{
	if(root!=NULL)
	{
		print_tree_in_in_order(root->left);
		printf(" %d ", root->data);
		print_tree_in_in_order(root->right);
	}
}
void print_tree_in_post_order(struct BinaryTreeNode *root)
{
	if(root!=NULL)
	{
		print_tree_in_post_order(root->left);
		print_tree_in_post_order(root->right);
		printf(" %d ", root->data);
	}
}	

struct BinaryTreeNode * construct_tree_from_pre_in_order(int in_order[],int start,int end,int pre_order[],int *pre_order_index)
{
		if(start > end) // 0 > -1
		{
			return NULL;
		}
		struct BinaryTreeNode * node =  (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
		node->data = pre_order[(*pre_order_index)++];
		int i=0;
		for(i=start;i<end;i++)
		{
			if(in_order[i] == node->data )
			{
				break;
			}
		}
		// for post order first we call left first
		node->left = construct_tree_from_pre_in_order(in_order,start,i-1,pre_order,pre_order_index);
		node->right = construct_tree_from_pre_in_order(in_order,i+1,end,pre_order,pre_order_index);
		return node;
}

int main()
{

	printf("\n\t\t\t\t Construct Tree from Given IN order and Pre Order  \n");
	int op;
	struct BinaryTreeNode *root = NULL ;
	int n;
	printf("\n\nEnter no of nodes : ");
	scanf(" %d",&n);
	int in_order[n];
	int pre_order[n];
	printf("\nEnter Pre Order Traversal : ");
	for(int i=0;i<n;i++)
	{
		scanf(" %d",&pre_order[i]);
	}
	printf("\nEnter IN Order Traversal : ");
	for(int i=0;i<n;i++)
	{
		scanf(" %d",&in_order[i]);
	}
	int copy_start_index = 0;
	int  *pre_order_index = &copy_start_index ;
	int start = 0;
	int end = n-1;
	root = construct_tree_from_pre_in_order(in_order,start,end,pre_order,pre_order_index);
	printf("\n\nTree Constructed Successfully!! \n\n");
	do
	{
			printf("\n1.Re - enter Pre Order   data							2.Re - Enter IN Order  data\n");
			printf("3.Print Tree in Pre Order        	4.Print Tree in IN Order    		5.Print Tree in Post Order \n");
			printf("6.Print Tree (2D) (look at -90 deg)     7.To Exit\n");
			printf("\nEnter your option : ");
			scanf(" %d",&op);
			switch(op)
			{
				case 1 : 
						printf("\nEnter Pre Order Traversal : ");
						for(int i=0;i<n;i++)
						{
							scanf(" %d",&pre_order[i]);
						}
						*pre_order_index = 0 ;
						start = 0;
						end = n-1;
						root = construct_tree_from_pre_in_order(in_order,start,end,pre_order,pre_order_index);
						printf("\n\nTree Constructed Successfully!! with new data \n\n");					
						break;
				case 2 :
						printf("\nEnter IN Order Traversal : ");
						for(int i=0;i<n;i++)
						{
							scanf(" %d",&in_order[i]);
						}
						*pre_order_index = 0 ;
						start = 0;
						end = n-1;
						root = construct_tree_from_pre_in_order(in_order,start,end,pre_order,pre_order_index);
						printf("\n\nTree Constructed Successfully!! with new data \n\n");					
						break;
				case 3 :
						print_tree_in_pre_order(root);
						break;
				case 4 :
						print_tree_in_in_order(root);
						break;
				case 5 :
						print_tree_in_post_order(root);
						break;
				case 6 :
						printf("\n\n");
						print_binary_tree2D(root,0);
						printf("\n\n");
						break;
				case 7 :
				 		break;
				default :
						printf("\n  Invalid Input \n");
			}	
	}while(op!=7);
	return 0;
}