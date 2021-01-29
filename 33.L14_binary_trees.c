/*

ID : B171452
Description :  Introduction to Binary trees and inserting new node in binary tree(using Queue) and printing Binary tree in 1D and 2D.
Code by Sandeep Payili on 19/01/2021

*/

#include<stdio.h>
#include<stdlib.h>
#define SPACE  5
struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};

struct ListNode{
	struct BinaryTreeNode *data;
	struct ListNode *next;
};

struct ListNode * Enqueue(struct ListNode **head,struct BinaryTreeNode * ele)
{
	struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->data = ele;
	newNode->next = *head;
	*head = newNode;
	return *head;
}

 struct BinaryTreeNode * Dequeue(struct ListNode **head)
{
	if(*head == NULL)
	{
		return  NULL;
	}
	struct ListNode *temp = *head;
	if(temp->next == NULL)
	{
		struct BinaryTreeNode *to_return = temp->data;
		*head = NULL;
		return to_return;
	}
	struct ListNode *previousNode = *head;
	while(temp->next != NULL)
	{
		previousNode = temp;
		temp = temp->next;
	}
	struct BinaryTreeNode *to_return = temp->data;
	previousNode->next = temp->next;
	return to_return;
}

void insert(struct BinaryTreeNode **root,int ele)
{
		if(*root  == NULL)
		{
			struct BinaryTreeNode *newNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
			newNode->left = NULL;
			newNode->data = ele;
			newNode->right = NULL;
			*root = newNode;
		}
		else
		{
			struct  ListNode *head = NULL;
			head = Enqueue(&head,*root);

			struct BinaryTreeNode *temp;
			while(1)
			{
				temp = Dequeue(&head);
				if(temp->left != NULL)
				{
					head = Enqueue(&head,temp->left);
				}
				else
				{
					break;
				}
				if(temp->right != NULL)
				{
					head = Enqueue(&head,temp->right);	
				}
				else
				{
					break;
				}
			}

			struct BinaryTreeNode *newNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
			newNode->left = NULL;
			newNode->data = ele;
			newNode->right = NULL;
			if(temp->left == NULL)
			{
				temp->left = newNode;
			}
			else
			{
				temp->right = newNode;
			}
		}
}

void print_binary_tree(struct BinaryTreeNode *root)
{
	if(root == NULL)
	{
			printf("\n Binary Tree has no root  \n");		
			return;
	}
	struct ListNode *head = NULL;
	head = Enqueue(&head,root);

	struct BinaryTreeNode *temp;
	printf("\n\n");
	while(1)
	{
		temp = Dequeue(&head);
		if(temp == NULL) // CHECKING QUEUE IS EMPTY OR NOT
		{
			break;
		}
		printf(" %d ",temp->data);
		if(temp->left != NULL)
		{
			head = Enqueue(&head,temp->left);
		}
		if(temp->right != NULL)
		{
			head = Enqueue(&head,temp->right);
		}
	}
	printf("\n\n");
}

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

int main()
{

	printf("\n\t\t Binary Tree  Implementation\n");
	int op;
	int ele;

	struct BinaryTreeNode *root = NULL ;

	do
	{
			printf("\n1.Insert new Node (level order)  2.Print Current Binary Tree (1D)   3.Print Current Binary Tree(2D) (look at -90 deg)    4.To Exit\n");
			printf("\nEnter your option : ");
			scanf(" %d",&op);

			switch(op)
			{
				case 1 : 
						printf("\nEnter data to insert in new node : ");
						scanf(" %d",&ele);
						insert(&root,ele);
						break;
				case 2 :
						print_binary_tree(root);
						break;
				case 3 :
						printf("\n\n");
						print_binary_tree2D(root,0);
						printf("\n\n");
						break;
				case 4 :
				 		break;
				default :
						printf("\n  Invalid Input \n");
			}	
	}while(op!=4);
	return 0;
}