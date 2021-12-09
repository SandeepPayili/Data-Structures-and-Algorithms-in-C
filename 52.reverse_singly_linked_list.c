/*
 
ID : B171452
Description :  Reversing Singly linked list
Code by Sandeep Payili on 19/09/2021

*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode{
	int data;
	struct ListNode *next;
};
void InsertInLinkedListAtBegin(struct ListNode **head,int data)
{
		struct ListNode *newNode;
		newNode =  (struct ListNode *)malloc(sizeof(struct ListNode));
		newNode->data = data;
		newNode->next = *head;
		*head = newNode;	
}
void reversesinglylinkedlist(struct ListNode **head)
{
	if( (*head) == NULL)
	{
		printf("\nSingly Linked List is Empty\n");
		return;
	}
	struct ListNode *prev = NULL;
	struct ListNode *curr = *head;
	struct ListNode *next = NULL;
	//prev and curr to reverse links and next to store next node address.
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}
void showlsinglylinkedlist(struct ListNode *head)
{
	struct ListNode *temp = head;
	if(temp == NULL)
	{
		printf("\nSingly Linked List is Empty\n");
		return;
	}
	while(temp!=NULL)
	{
		printf(" %d ",temp->data);
		temp = temp->next;
	}
}
int main()
{
	struct ListNode *head = NULL;
	int op;
	int ele;
	do
	{
		printf("\n1.Insert at Begin    2.Reverse Singly Linked List  3.Show Linked List 4.Exit\n");
		printf("\nEnter operation : ");
		scanf(" %d",&op);
		switch(op)
		{
			case 1 :
			           printf("\nEnter element to be inserted : ");
			           scanf(" %d",&ele);
			           InsertInLinkedListAtBegin(&head,ele);
			           break;
			case 2 :
			           reversesinglylinkedlist(&head);
			           break;
			case 3 :
						showlsinglylinkedlist(head);
						break;
			case 4 :
						break;
			default :	
						printf("\nInvalid Input\n");
		}
	}while(op!=4);
	return 0;
}