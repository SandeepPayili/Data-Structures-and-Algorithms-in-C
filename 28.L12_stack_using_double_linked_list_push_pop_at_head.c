/*

ID : B171452
Description : Stack Using  Double Linked List 
Code by Sandeep Payili on 19/01/2021

*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	struct ListNode *prev;
	int data;
	struct ListNode *next;
};
struct ListNode * push(struct ListNode *head,int ele)
{
	struct ListNode *newNode;
	newNode =  (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->data = ele;
	newNode->prev = NULL;
	if(head == NULL)
	{
		newNode->next = NULL;
		head = newNode;
		return head;
	}
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	return head;
}

void pop(struct ListNode **head)
{
	if(*head == NULL)
	{
		printf("\nStack is Empty !.. Unable to Pop .. \n\n");
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

void show_current_stack(struct ListNode *head)
{
	printf("\n");
	if(head ==NULL)
	{
		printf("\nStack is Empty !.\n");	
		return;
	}
	struct ListNode *temp = head;
	printf("Current Stack is (right to left) :  \n");
	while(temp != NULL)
	{
		printf(" %d ",temp->data);
		temp = temp->next;
	}
	printf("\n\n");
}
int peek(struct ListNode *head)
{
	if(head == NULL)
	{
		return 0;
	}

	return head->data;
}

int main()
{
	printf("\n\nStack Implementation Using Double Linked List(Pushing and Popping at head)\n\n");
	struct ListNode *head = NULL;
	int op;
	int ele;
	do
	{
		printf("\n1.Push 		2.Pop   	3.Peek  	4.Show Current Stack  	5.To Exit\n");
		printf("\nEnter your option : ");
		scanf(" %d",&op);
		switch(op){
			case 1 :
					printf("\nEnter Element You Want to Push : ");
					scanf(" %d",&ele);
					head = push(head,ele);
					break;
			case 2 :
					pop(&head);
					break;
			case 3 :
					ele = peek(head);
					if(ele == 0)
					{
						printf("\nCurrent Stack is Empty !.\n");
					}
					else
					{
						printf("\nTop Element of Current Stack is  :  %d \n",ele);
					}
					break;
			case 4 :
					show_current_stack(head);
					break;
			case 5 :
					break;
			default:
					printf("\nInvalid Input\n");
		}
	}while(op!=5);

	return 0;
}
