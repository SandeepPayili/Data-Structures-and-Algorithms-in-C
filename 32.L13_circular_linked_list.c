/*

ID : B171452
Description :  Circular Linked List 
Code by Sandeep Payili on 19/01/2021

*/

#include<stdio.h>
#include<stdlib.h>
struct CLLNode {
	int data;
	struct CLLNode *next;
};

void insertatfirst(struct CLLNode **head,int ele)
{
	struct CLLNode *newNode = (struct CLLNode * )malloc(sizeof(struct CLLNode));
	newNode->data = ele;
	if(*head == NULL)
	{
		*head = newNode;
		newNode->next = *head;
		return ;
	}
	struct CLLNode *temp = *head;
	while(temp->next != *head)
	{
		temp = temp->next;
	}
	newNode->next = *head;
	*head = newNode;
	temp->next = *head;  // temp->next = newNode;
}
void insertatlast(struct CLLNode **head,int ele)
{
	struct CLLNode *newNode = (struct CLLNode * )malloc(sizeof(struct CLLNode));
	newNode->data = ele;
	if(*head == NULL)
	{
		*head = newNode;
		newNode->next = *head;
		return ;
	}
	struct CLLNode *temp = *head;
	while(temp->next != *head)
	{
		temp = temp->next;
	}
	newNode->next = *head;
	temp->next = newNode;
}
void removefirstnode(struct CLLNode **head)
{
	if(*head == NULL)
	{
		printf("\nCurrent Circular Linked List is Empty !... Unable to Remove first Node ....  \n");
		return ;
	}	
	if( (*head)->next  ==  *head){
		(*head)->next = NULL;
		*head = NULL;
		return ;
	}
	struct CLLNode *temp = *head;
	while(temp->next != *head)
	{
		temp = temp->next;
	}

	struct CLLNode *to_delete = (*head)->next;
	*head = (*head)->next;
	temp->next = *head;
	to_delete = NULL;
}
void removelastnode(struct CLLNode **head)
{	
	if(*head == NULL)
	{
		printf("\nCurrent Circular Linked List is Empty !... Unable to Remove Last  Node ....  \n");
		return ;
	}	
	if( (*head)->next  ==  *head){
		(*head)->next = NULL;
		*head = NULL;
		return ;
	}
	struct CLLNode *temp = *head;
	while( temp->next->next != *head )
	{
			temp = temp->next;
	}
	temp->next->next = NULL;
	temp->next = *head;
}
void show_current_circular_linked_list(struct CLLNode *head)
{
	if(head == NULL)
	{
		printf("\nCurrent Circular Linked List is Empty !...\n");
			return ;
	}
	struct CLLNode *temp = head;
	printf("\n\n\t\tCurrent Circular Linked List is : \n");
	do
	{
		printf(" %d ",temp->data);
		temp = temp->next;
	}
	while(temp != head);
	printf("\n\n");
}
int main()
{
	printf("\n\n\t\t\t\tCircular Linked Lists\n\n");
	struct CLLNode *head = NULL;

	int op;
	int ele;
	do
	{
		printf("\n1.Insert new node at Head   		2.Insert new node at end  				3.Remove First Node");
		printf("\n4.Remove last Node  			5.Show current Circular Linked List 		        6.To exit \n");
		printf("\nEnter your Option : ");
		scanf(" %d",&op);
		switch(op)
		{
			case 1 :
					printf("\nEnter the element you want to insert at First Node : ");
					scanf(" %d",&ele);
					insertatfirst(&head,ele);
					break;
			case 2 :
					printf("\nEnter the element you want to insert at Last Node  : ");
					scanf(" %d",&ele);
					insertatlast(&head,ele);
					break;
			case 3 :
					removefirstnode(&head);
					break;
			case 4 :
					removelastnode(&head);
					break;
			case 5 :
					show_current_circular_linked_list(head);
					break;
			case 6 :
					break;
			default :
			    	printf("\nInvalid Input\n");
		}
	}while(op!=6);

	return 0;
}