/*

ID : B171452
Description :  Stack Using Linked List (Pushing and Popping at tail)
Code by Sandeep Payili on 18/01/2021

*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode{
	int data;
	struct ListNode *next;
};
struct ListNode *push(struct ListNode *head,int ele){
		struct ListNode *newNode =  (struct ListNode *)malloc(sizeof(struct ListNode));
		newNode->data = ele;

		struct ListNode *currentNode = head;
		if(currentNode == NULL)
		{
			newNode->next = head;
			head = newNode;	
			return head;
		}
		while(currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}

		currentNode->next = newNode;
		newNode->next = NULL;

		return head;
}

struct ListNode *  pop(struct ListNode *head){
	if(head == NULL)
	{
		printf("\nStack is Empty !. Unable to Pop...\n");
		return head;
	}
	struct ListNode *currentNode = head;
	if(currentNode->next == NULL)
	{
			head = NULL;
			return head;
	}
	struct ListNode *previousNode = head;
	while(currentNode->next != NULL)
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	previousNode->next = NULL;
	return head;
}
int peek(struct ListNode *head)
{
	if(head == NULL)
	{
		return 0;
	}
	struct ListNode *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	return temp->data;
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
	printf("Current Stack is (left to right):  \n");
	while(temp != NULL)
	{
		printf(" %d ",temp->data);
		temp = temp->next;
	}
	printf("\n\n");
}
int main()
{
	printf("\n\nStack Implementation Using Linked List(Pushing and Popping at tail)\n\n");
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
					head = pop(head);
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
