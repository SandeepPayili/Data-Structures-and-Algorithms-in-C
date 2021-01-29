/*

ID : B171452
Description :  Queue Using Double Linked List  (Enqueue at Tail Dequeue at Head)
Code by Sandeep Payili on 19/01/2021

*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	struct ListNode *prev;
	int data;
	struct ListNode *next;
};

struct ListNode * Enqueue(struct ListNode *head,int ele)
{
	struct ListNode *newNode;
	newNode =  (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->data = ele;
	if(head == NULL)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		head = newNode;
		return head;
	}
	struct ListNode *temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	newNode->next = NULL;
	newNode->prev = temp;
	temp->next = newNode;
	return head;
}
void Dequeue(struct ListNode **head)
{
	if(*head == NULL)
	{
		printf("\nQueue is Empty !.. Unable to Dequeue .. \n\n");
		return;
	}
	if((*head)->next == NULL )
	{
		*head = NULL;
		return;
	}
	(*head) = (*head)->next;
	(*head)->prev = NULL;
}
int peek(struct ListNode *head){
	if(head == NULL){
		return 0;		
	}
	struct ListNode *temp = head;
	return temp->data;
}

void show_current_queue(struct ListNode *head){
	if(head == NULL)
	{
		printf("\n Current Queue is Empty !... \n");
		return ;
	}
	printf("\nCurrent Queue is : \n");
	struct ListNode *temp = head;
	while(temp != NULL)
	{
		printf(" %d ",temp->data);		
		temp = temp->next;
	}
	printf("\n\n");
}

int main()
{
	printf("\nQueue Implementation Using Double Linked List (Enqueue at Tail & Dequeue at Head ) \n\n");
	struct ListNode *head = NULL;
	int op;
	int ele;
	do
	{
		printf("\n1.Enqueue 		2.Dequeue   	3.Peek  	4.Show Current Queue  	5.To Exit\n");
		printf("\nEnter your option : ");
		scanf(" %d",&op);
		switch(op){
			case 1 :
					printf("\nEnter Element You Want to Enqueue : ");
					scanf(" %d",&ele);
					head = Enqueue(head,ele);
					break;
			case 2 :
					Dequeue(&head);
					break;
			case 3 :
					ele = peek(head);
					if(ele == 0)
					{
						printf("\nCurrent Queue is Empty !.\n");
					}
					else
					{
						printf("\nTop Element of Current Queue is  :  %d \n",ele);
					}
					break;
			case 4 :
					show_current_queue(head);
					break;
			case 5 :
					break;
			default:
					printf("\nInvalid Input\n");
		}
	}while(op!=5);

	return 0;
}