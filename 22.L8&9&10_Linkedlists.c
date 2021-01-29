/*

ID : B171452 
Code by Sandeep Payili on 15/01/2021
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

void InsertInLinkedListAtEnd(struct ListNode **head,int data)
{
	struct ListNode *currentNode;
	currentNode = *head;
	if(currentNode == NULL)
	{
		struct ListNode *newNode;
		newNode =  (struct ListNode *)malloc(sizeof(struct ListNode));
		newNode->data = data;
		newNode->next = *head;
		*head = newNode;
	}else{
		while(currentNode->next !=NULL)
		{
			currentNode = currentNode->next;
		}	
		struct ListNode *newNode;
		newNode =  (struct ListNode *)malloc(sizeof(struct ListNode));
		newNode->data = data;
		newNode->next = NULL;
		currentNode->next = newNode;
	}
}

void InsertInLinkedList(struct ListNode **head,int data,int position){
	if(position == 1)
	{
		struct ListNode *newNode;
		newNode =  (struct ListNode *)malloc(sizeof(struct ListNode));
		newNode->data = data;
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		struct ListNode *currentNode;
		currentNode = *head;
		int k=1;
		while(currentNode!=NULL && k < position -1 )
		{
			currentNode = currentNode->next;
			k++;
		}
		if(currentNode == NULL)
		{
			printf("\n\nGiven Position is Invalid...\n\n");
		}else{

			struct ListNode *newNode;
			newNode =  (struct ListNode *)malloc(sizeof(struct ListNode));
			newNode->data = data;
			newNode->next = currentNode->next;
			currentNode->next = newNode;
		}
	}

}

void deletefirstnode(struct ListNode **head){
	if( *head == NULL)
	{
		printf("\nLinked List is Empty!! \n");
		return;
	}
		struct ListNode *temp = (*head)->next;
		*head = (*head)->next;
		temp = NULL;
		return;
}

void deletelastnode(struct ListNode **head){
	if( *head == NULL)
	{
		printf("\nLinked List is Empty!! \n");
		return;
	}
	struct ListNode *currentNode = *head;
	if(currentNode->next == NULL){
		*head = NULL;
		return;
	}
	while(currentNode->next->next != NULL){
		currentNode  = currentNode->next;
	}
	currentNode->next = NULL;
}

void  showmylinkedlist(struct ListNode *head)
{
	struct ListNode *currentNode;
	currentNode = head;

	printf("\n Current Linked List  >>> \n\n");

	while(currentNode!=NULL)
	{
		printf(" %d ",currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
}

int searchelement(struct ListNode *head,int key){

	struct ListNode *currentNode;
	currentNode = head;
	int f=0;
	while(currentNode!=NULL)
	{
		if(currentNode->data == key){
			f = 1;
			break;
		}
		currentNode = currentNode->next;
	}
	if(f==1){
		return 1;
	}else{
		return 0;
	}
}

void DeleteNodeFromLinkedListByPosition(struct ListNode **head,int position)
{
	struct ListNode *currentNode = *head;
	if(currentNode == NULL){
		printf("\n Linked List is Empty\n");
		return;
	}
	if(position == 1){
		*head = currentNode->next; // *head = *head->next;
		currentNode->next = NULL;
	}else{
		int k = 1;
		while(currentNode!=NULL && k < position -1){
			currentNode = currentNode->next;
			k++;
		}
		if(currentNode == NULL){
			printf("\nGiven Position is Invalid ........... \n");
		}else{
			struct ListNode *temp = currentNode->next->next;
			currentNode->next = temp;
			temp =  NULL;
		}
	}
}
/* version 1 
void DeleteNodeFromLinkedListByKey(struct ListNode **head,int key){
		struct ListNode *currentNode = *head;
		struct ListNode *previousPointer = *head;
	if( *head == NULL){
		printf("\n Linked List is Empty\n");
		return;
	}	
	if((*head)->data == key){
		struct ListNode *temp = (*head)->next;
		*head = (*head)->next;
		temp = NULL;
		return;
	}else{
		currentNode = currentNode->next;
	}
	while(currentNode->data!=key && currentNode->next != NULL){
		currentNode = currentNode->next ;
	}
	if(currentNode->next == NULL && currentNode->data != key){
		printf("\nGiven Key Not there\n");
		return;
	}else{
			while(previousPointer->next != currentNode){
				previousPointer = previousPointer->next;
			}
			previousPointer->next = currentNode->next;
			currentNode->next = NULL;		
	}

}
*/
void DeleteNodeFromLinkedListByKey(struct ListNode **head,int key){
		struct ListNode *currentNode = *head;
		struct ListNode *previousPointer = *head;
		if(currentNode == NULL)
		{	
			printf("\nLinked List is Empty\n");
			return;
		}
		if((*head)->data == key){
			struct ListNode *temp = (*head)->next;
			*head = (*head)->next;
			temp = NULL;
			return;
		}
		while(currentNode!=NULL)
		{
			if(currentNode->data == key){
				break;
			}
			currentNode = currentNode->next;
		}
		if(currentNode == NULL)
		{	
			printf("\nkey not found to delete \n");
			return;
		}
		while(previousPointer->next != currentNode)
		{
			previousPointer = previousPointer->next;
		}
		previousPointer->next = currentNode->next;
		currentNode->next = NULL;
}
int CurrentLength(struct ListNode *head){
	struct ListNode *currentNode;
	currentNode = head;
	int count = 0;
	while(currentNode != NULL)
	{
		currentNode = currentNode->next;
		count++;
	}
	return count;
}
void removebeforenode(struct ListNode **head,int key){
		struct ListNode *currentNode = *head;
		struct ListNode *previousPointer =*head;
		if(currentNode == NULL)
		{	
			printf("\nLinked List is Empty\n");
			return;
		}
		if(currentNode->data == key || currentNode->next == NULL){
			printf("\nIt's Previous Node not Available to Delete ! \n");
			return;
		}
		while(currentNode->next->data != key && currentNode->next->next != NULL){
			currentNode = currentNode->next;
		}
		if(currentNode->next->next == NULL && currentNode->next->data != key){
			printf("\nGiven Key is Not found to delete it's before Node \n");
			return;
		}
		
		if(*head == currentNode){
				*head = previousPointer->next; // here *head and previousPointer are same
				previousPointer->next = NULL;
				return;
		}
				while(previousPointer->next != currentNode){
					previousPointer = previousPointer->next;
				}
				previousPointer->next = currentNode->next;
				currentNode->next = NULL;
}

void removeafternode(struct ListNode **head,int key){
		struct ListNode *currentNode = *head;
		if(currentNode == NULL)
		{	
			printf("\nLinked List is Empty\n");
			return;
		}
		while(currentNode->data != key && currentNode->next!= NULL)
		{
			currentNode = currentNode->next;
		}		
		if(currentNode->next == NULL && currentNode->data != key)
		{
			printf("\nGiven Key is Not found to delete it's after  Node \n");
			return;	
		}
		if(currentNode->next == NULL && currentNode->data == key)
		{
			printf("\nIt's After  Node not Available to Delete ! \n");
			return;	
		}
		currentNode->next = currentNode->next->next;
}

int main(){

	struct ListNode *head = NULL;

	int data,position=1;
	int op;

	int current_length , middle;
	do
	{
		printf("\n1.Insert at Beginning			2.Insert at End				3.Insert at Given Position");
		printf("\n4.Delete 1st Node			5.Delete Last Node			6.Delete Node by Position");
		printf("\n7.Search Key 				8.Delete Node by Given Key  		9.Show Current Linked List");
		printf("\n10.Get Count 				11.Insert Node  At Middle 		12.Delete Node at Middle");
		printf("\n13.Remove Before Node of Given key	14.Remove after Node of Given key       15.To EXit\n");

		printf("\n\nEnter Your Option :  ");
		scanf(" %d",&op);
		switch(op){
			case 1: 
					printf("\nEnter Data to be Inserted At Beginning : ");
					scanf(" %d",&data);
					InsertInLinkedListAtBegin(&head,data);
					break;
			case 2 :
					printf("\nEnter Data to be Inserted at End : ");
					scanf(" %d",&data);
					InsertInLinkedListAtEnd(&head,data);
					break;
			case 3 :
					printf("\nEnter Data to be Inserted : ");
					scanf(" %d",&data);
					printf("\nEnter Position to be Inserted : ");
					scanf(" %d",&position);
					InsertInLinkedList(&head,data,position);
					break;
			case 4 :
					deletefirstnode(&head);
					break;
			case 5 :
					deletelastnode(&head);
					break;
			case 6:
					printf("\nEnter Position to be Delete : ");
					scanf(" %d",&position);			
					DeleteNodeFromLinkedListByPosition(&head,position);
					break;
			case 7 :
					printf("\nEnter Data to Search Key : ");
					scanf(" %d",&data);
					int temp;
					temp = searchelement(head,data);
					if(temp == 1){
						printf("\nKey found..\n");
					}else{
						printf("\nKey not found..\n");
					}
					break;
			case 8:
					printf("\nEnter Key  to be Delete : ");
					scanf(" %d",&data);			
					DeleteNodeFromLinkedListByKey(&head,data);
					break;
			case 9 :
					showmylinkedlist(head);
					break;
			case 10 :
					printf("\nCurrent Linked List Length  is : %d\n",CurrentLength(head));
					break;
			case 11:
					current_length = CurrentLength(head);
					printf("\nEnter Data to be Inserted At Middle : ");
					scanf(" %d",&data);
					if(current_length %2 == 0){
						middle = (current_length / 2) + 1;
					}else{
						middle = (current_length + 1 ) / 2;
					}
					InsertInLinkedList(&head,data,middle);
					break;
			case 12:
					current_length = CurrentLength(head);
					if(current_length %2 == 0){
						middle = (current_length / 2);
					}else{
						middle = (current_length + 1 ) / 2;
					}
					DeleteNodeFromLinkedListByPosition(&head,middle);					
					break;
			case 13 :
					printf("\nEnter key that's before node you want to delete  : ");
					scanf(" %d",&data);
					removebeforenode(&head,data);
					break;
			case 14:
					printf("\nEnter key that's after node you want to delete  : ");
					scanf(" %d",&data);
					removeafternode(&head,data);
					break;
			case 15:
					break;
			default:
					printf("\nInvalid Input\n");		
		}	
		
	}while(op!=15);
	return 0;
}