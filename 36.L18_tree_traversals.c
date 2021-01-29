/*

ID : B171452
Description :  Tree Traversals
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

bool isempty(struct ListNode * head)
{
	if(head == NULL){
		return true;
	}
	return false;
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

void insert_in_binary_search_tree(struct BinaryTreeNode **root,int ele)
{
	struct BinaryTreeNode *newNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
	newNode->left = NULL;
	newNode->data = ele;
	newNode->right = NULL;
	if(*root == NULL)
	{
		*root = newNode;
		return;
	}
	struct BinaryTreeNode *temp = *root;
	while(1)
	{
		if( ele < temp->data )
		{
			if(temp->left != NULL)
			{
				temp = temp->left;
			}
			else
			{
				temp->left = newNode;
				break;
			}
		}
		else // equal case will also comes here
		{
			if(temp->right != NULL)
			{
				temp = temp->right;
			}
			else
			{
				temp->right = newNode;
				break;
			}
		}
	}
}

int search_element_in_binary_search_tree(struct BinaryTreeNode *root,int ele)
{
	if(root == NULL)
	{
		return 0;
	}
	struct BinaryTreeNode *temp = root;
	while(temp != NULL)
	{
		if(temp->data == ele)
		{
				return 1;
		}
		else if(ele < temp->data)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;	
		}
	}
	return 0;
}


// least element in right sub tree (if right sub tree is not there highest in left sub tree)
void  delete_node_by_given_element_in_binary_search_tree(struct BinaryTreeNode **root,int ele)
{
	if(*root == NULL)
	{
		printf("\n\nCurrent Binary Search Tree has no root to delete any node .. \n\n");
		return;
	}
	if((*root)->left == NULL && (*root)->right == NULL)
	{	
		if((*root)->data == ele)
		{
				*root = NULL;
		}
		else
		{
			printf("\n\nGiven element not found to delete ... \n\n");
		}
		return;
	}

	if( (*root)->data == ele && (*root)->right != NULL)
	{
					struct BinaryTreeNode *temp = (*root)->right;
					if(temp->left == NULL)
					{
						(*root)->data = temp->data;
						(*root)->right = temp->right;
					}
					else
					{
						struct BinaryTreeNode *parent = temp;
						while(temp->left != NULL)
						{
							parent = temp;
							temp = temp->left;
						}
						(*root)->data = temp->data;
						parent->left = temp->right;
					}	
					return;
	}

	if( (*root)->data == ele && (*root)->right == NULL) // if  (*root)->left == NULL also satisfies it will go to first if condition.
	{
					struct BinaryTreeNode *temp = (*root)->left;
					if(temp->right == NULL)
					{
						(*root)->data = temp->data;
						(*root)->left = temp->left;
					}
					else
					{
						struct BinaryTreeNode *parent;
						while(temp->right != NULL)
						{
							parent = temp;
							temp = temp->right;
						}
						(*root)->data = temp->data;
						parent->right = temp->left;
					}	
					return;
	}

	struct BinaryTreeNode *parent = *root;	
	struct BinaryTreeNode *current = *root;
	while(1)
	{
		if(current == NULL)
		{
			printf("\n\nGiven element not found to delete ... \n\n");
			break;
		}
		if( ele == current->data)
		{
				// if it is leaf node (zero sub nodes)
				if(current->left == NULL && current->right == NULL){
								if(parent->left == current)
								{
									parent->left = NULL;
								}
								if(parent->right == current)
								{
									parent->right = NULL;
								}
				}
				// if  desired node has only one node and that to left side
				else if(current->left != NULL && current->right == NULL)
				{
								if(parent->left == current)
								{
									parent->left = current->left;
								}
								if(parent->right == current)
								{
									parent->right = current->left;
								}
				}
				// if  desired node has only one node and that to right side
				else if(current->left == NULL && current->right != NULL)
				{
								if(parent->left == current)
								{
									parent->left = current->right;
								}
								if(parent->right == current)
								{
									parent->right = current->right;
								}
				}
				else // both left and right nodes are present
				{
					struct BinaryTreeNode *temp = current->right;
					parent = current; //  need to update since it is one step behind for (temp->left == NULL)
					if(temp->left == NULL)
					{
						current->data = temp->data;
						parent->right = temp->right;	
					}
					else
					{
						while(temp->left != NULL)
						{
							parent = temp;
							temp = temp->left;
						}
						current->data = temp->data;
						parent->left = temp->right;
					}	
				}
				break;
		}
		else if(ele < current->data)
		{
			parent = current;
			current = current->left;
		}
		else
		{
			parent = current;
			current = current->right;	
		}
	}
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
int main()
{

	printf("\n\t\t\t\t Tree Traversals (in Binary Search Tree) \n");
	int op;
	int ele;

	struct BinaryTreeNode *root = NULL ;

	int nodes;
	int flag;

	do
	{
			printf("\n1.Insert new Node  							2.Delete node by element  \n");
			printf("3.Print Tree in Pre Order    	4.Print Tree in IN Order    		5.Print Tree in Post Order \n");
			printf("6.Print Tree in Level Order     7.Print Tree (2D) (look at -90 deg)     8.To Exit\n");
			printf("\nEnter your option : ");
			scanf(" %d",&op);
			switch(op)
			{
				case 1 : 
						printf("\nEnter data to insert in new node : ");
						scanf(" %d",&ele);
						insert_in_binary_search_tree(&root,ele);
						break;
				case 2 :
						printf("\nEnter element you want to delete : ");
						scanf(" %d",&ele);
						delete_node_by_given_element_in_binary_search_tree(&root,ele);
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
						print_binary_tree(root);
						break;
				case 7 :
						printf("\n\n");
						print_binary_tree2D(root,0);
						printf("\n\n");
						break;
				case 8 :
				 		break;
				default :
						printf("\n  Invalid Input \n");
			}	
	}while(op!=8);
	return 0;
}