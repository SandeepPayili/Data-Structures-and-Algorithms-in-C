/*

ID : B171452
Description : printing Binary trees and counting nodes and searching particular element and deleting particular node (in two ways).
Code by Sandeep Payili on 22/01/2021

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
int number_of_nodes(struct BinaryTreeNode *root)
{
	int count = 0;
	if(root == NULL)
	{
			return count;
	}
	struct ListNode *head = NULL;
	head = Enqueue(&head,root);

	struct BinaryTreeNode *temp;
	while(1)
	{
		temp = Dequeue(&head);
		if(temp == NULL) // CHECKING QUEUE IS EMPTY OR NOT
		{
			break;
		}
		if(temp->left != NULL)
		{
			head = Enqueue(&head,temp->left);
		}
		if(temp->right != NULL)
		{
			head = Enqueue(&head,temp->right);
		}
		count++;
	}
	return count;
}

int search_element(struct BinaryTreeNode *root,int ele)
{
	if(root == NULL)
	{
			return 0;
	}
	struct ListNode *head = NULL;
	head = Enqueue(&head,root);

	struct BinaryTreeNode *temp;
	while(1)
	{
		temp = Dequeue(&head);
		if(temp == NULL) // CHECKING QUEUE IS EMPTY OR NOT
		{
			break;
		}
		if(temp->left != NULL)
		{
			head = Enqueue(&head,temp->left);
		}
		if(temp->right != NULL)
		{
			head = Enqueue(&head,temp->right);
		}
		if(temp->data == ele)
		{
			return 1;
		}
	}
	return 0;
}

struct BinaryTreeNode * find_element_node(struct BinaryTreeNode *root,int ele)
{
	struct ListNode *head = NULL;
	head = Enqueue(&head,root);
	struct BinaryTreeNode *temp;
	while( !isempty(head))
	{
		temp = Dequeue(&head);
		if(temp->data == ele)
		{
			return temp;
		}
		if(temp->left != NULL)
		{
			Enqueue(&head,temp->left);
		}
		if(temp->right != NULL)
		{
			Enqueue(&head,temp->right);
		}
	}
	return NULL;
}

struct BinaryTreeNode * find_leaf_node(struct BinaryTreeNode *root)
{
	struct ListNode *head = NULL;
	head = Enqueue(&head,root);
	struct BinaryTreeNode *temp;
	while(! isempty(head) )
	{
		temp = Dequeue(&head);
		if(temp->left != NULL)
		{
			Enqueue(&head,temp->left);
		}
		if(temp->right != NULL)
		{
			Enqueue(&head,temp->right);
		}
	}
	return temp;
}
struct BinaryTreeNode * find_leaf_parent_node(struct BinaryTreeNode *root,struct BinaryTreeNode *leaf_node)
{
	struct ListNode *head = NULL;
	head = Enqueue(&head,root);
	struct BinaryTreeNode *temp;
	while(! isempty(head) )
	{
		temp = Dequeue(&head);
		if(temp->left == leaf_node)
		{
			return temp;
			
		}
		else
		{
			if(temp->left != NULL)
			{

				Enqueue(&head,temp->left);
			}
		}
		if(temp->right == leaf_node)
		{
			return temp;
			
		}
		else
		{
			if(temp->right != NULL)
			{
				
				Enqueue(&head,temp->right);
			}
		}
	}
	return NULL;
}
void delete_node_by_given_element(struct BinaryTreeNode **root, int ele)
{
	// happens in three steps (nodes)
	// replaces level order last right node data in removing node 


	if(*root == NULL) // empty tree
	{
		printf("\n\n Current Binary tree has no root ... Unable to  delete any node !... \n");
		return ;
	}
	if( (*root)->left == NULL && (*root)->right == NULL ) // only root tree
	{
		if((*root)->data == ele)
		{
			*root = NULL;				
			return ;
		}
		printf("\nGiven element is not found to delete !..\n\n");
		return;	
	} 

	struct BinaryTreeNode * element_node;
	 struct BinaryTreeNode * leaf_node;
	 struct BinaryTreeNode * leaf_parent_node;
	element_node = find_element_node(*root,ele);
	if(element_node == NULL)
	{
		printf("\nGiven element is not found to delete !..\n\n");
		return;
	}
	leaf_node = find_leaf_node(*root);
	if(leaf_node == NULL)
	{
		printf("\nUnable to Find leaf node \n\n");
		return;
	}
	leaf_parent_node = find_leaf_parent_node(*root,leaf_node);
	if(leaf_parent_node  == NULL)
	{
		printf("\nUnable to Find leaf Parent node \n\n");
		return;
	}
	element_node->data = leaf_node->data;
	if(leaf_parent_node->left == leaf_node)
	{	
		leaf_parent_node->left = NULL;
	}	
	else
	{
		leaf_parent_node->right = NULL;
	}
}

struct BinaryTreeNode *  delete_node_by_given_element_in_single_traversal(struct BinaryTreeNode *root,int ele)
{
	if(root == NULL) // empty tree
	{
		printf("\n\n Current Binary tree has no root ... Unable to  delete any node !... \n");
		return root;
	}
	if( root->left == NULL && root->right == NULL ) // only root tree
	{
		if(root->data == ele)
		{
			root = NULL;				
			return root;
		}
		printf("\nGiven element is not found to delete !..\n\n");
		return root;	
	} 
	struct ListNode *head = NULL;
	head = Enqueue(&head,root);
	struct BinaryTreeNode *temp = NULL;
	struct BinaryTreeNode *key_node = NULL;

	//struct BinaryTreeNode *leaf_parent_node = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode)); 
	// above will not work as it will create new memory in heap and it's left and right values will be changes in itself but not efftect in root(tree)
	struct BinaryTreeNode *parent_left_node = NULL; // as it is pointer variable it will not reflect in main function we are returning *root.
	struct BinaryTreeNode *parent_right_node = NULL;
	while(!isempty(head))
	{
		temp = Dequeue(&head);
		if(temp->data == ele)
		{
			key_node = temp;
		}
		if(temp->left != NULL)
		{
			head = Enqueue(&head,temp->left);
			// leaf_parent_node->left = temp;
			// leaf_parent_node->right = NULL;
			parent_left_node = temp;
			parent_right_node = NULL;
		}
		if(temp->right != NULL)
		{
			head = Enqueue(&head,temp->right);
			// leaf_parent_node->left = NULL;
			// leaf_parent_node->right = temp;
			parent_left_node = NULL;
			parent_right_node = temp;
		}
	}
	if(key_node != NULL)
	{
			key_node->data = temp->data;

			if( parent_right_node != NULL)
			{
				parent_right_node->right = NULL;
			}	
			if( parent_left_node != NULL)
			{
				parent_left_node->left  = NULL;
			}
			return root;
	}
	else
	{
		printf("\nGiven element is not found to delete !..\n\n");
		return root;	
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

	printf("\n\t\t\t\t Binary Tree  Implementation\n");
	int op;
	int ele;

	struct BinaryTreeNode *root = NULL ;

	int nodes;
	int flag;

	do
	{
			printf("\n1.Insert new Node (level order)    2.number of nodes    				 3.Search for element  \n");
			printf("4.Delete node by element   	   5.Delete Node by Given Element(single traversal)	 6.Print Current Binary Tree (1D)\n");	
			printf("7.Print Current Binary Tree(2D) (look at -90 deg)  					 8.To Exit\n");
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
						nodes = number_of_nodes(root);
						printf("\n\nThere are %d nodes in Current Binary Tree\n\n",nodes);
						break;
				case 3 :
						printf("\nEnter element you want to search : ");
						scanf(" %d",&ele);
						flag = search_element(root,ele);
						if(flag == 1 )
						{
							printf("\nGiven element is Found !! \n");
						}
						else
						{
							printf("\nGiven element is Not Found !! \n");	
						}
						break;
				case 4 :
						printf("\nEnter element you want to delete : ");
						scanf(" %d",&ele);
						delete_node_by_given_element(&root,ele);
						break;
				case  5 :
						printf("\nEnter element you want to delete : ");
						scanf(" %d",&ele);
						root = delete_node_by_given_element_in_single_traversal(root,ele);
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