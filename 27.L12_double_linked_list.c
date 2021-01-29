/*

ID : B171452
Description :  Double Linked List 
Code by Sandeep Payili on 18/01/2021

*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	struct ListNode *prev;
	int data;
	struct ListNode *next;
};

void insertatbegin(struct ListNode **head,int ele)
{
	struct ListNode *newNode;
	newNode =  (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->data = ele;
	newNode->prev = NULL;
	if(*head == NULL)
	{
		newNode->next = NULL;
		*head = newNode;
		return ;
	}
	newNode->next = *head;
	(*head)->prev = newNode;
	*head = newNode;
}
struct ListNode * insertatend(struct ListNode *head,int ele)
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
void insertatgivenposition(struct ListNode **head,int position,int ele)
{
	if(position == 1){
		struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
		newNode->data = ele;
		newNode->prev = NULL;

		if(*head == NULL)
		{
			newNode->next = *head;
			*head = newNode;
		}	
		else
		{
			(*head)->prev = newNode;
			newNode->next = *head;
			*head = newNode;
		}
		return;
	}
	int k = 1;
	struct ListNode *currentNode = *head;
	while( k < position -1 && currentNode!= NULL) // currentNode->next!= NULL will  case error while postion is not 1 in empty list.
	{
		currentNode = currentNode->next;
		k++;
	}
	if(currentNode == NULL) // or k!= position - 1 
	{
		printf("\nGiven Position is Invalid !..\n\n");
		return;
	}
	struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->data = ele;

	if(currentNode->next != NULL)
	{
		newNode->next = currentNode->next;
		newNode->prev = currentNode;
		currentNode->next->prev = newNode;
		currentNode->next = newNode;
	}
	else
	{
		newNode->next = NULL;
		newNode->prev = currentNode;
		currentNode->next = newNode;
	}
}
void removefirstnode(struct ListNode **head)
{
	if(*head == NULL)
	{
		printf("\nLinked List is Empty !.. Unable to Remove First Node .. \n\n");
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
void removelastnode(struct ListNode **head)
{
	if(*head == NULL)
	{
		printf("\nLinked List is Empty !.. Unable to Remove last  Node .. \n\n");
		return;
	}
	if((*head)->next == NULL )
	{
		*head = NULL;
		return;
	}
	struct ListNode *temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	/*struct ListNode *to_delete = temp->prev ;
	temp = temp->prev;
	temp->next = NULL;
	to_delete = NULL;
	*/
	temp->prev->next = NULL;
	temp->prev = NULL;
}

void removenodeatgivenposition(struct ListNode **head,int position)
{
	if(*head == NULL)
	{
		printf("\nLinked List is Empty !.. Unable to Remove Given  Node .. \n\n");
		return;
	}
	if(position == 1 )
	{
		if((*head)->next == NULL)
		{
			(*head) = NULL;
		}
		else
		{
			struct ListNode *to_delete = (*head)->next;
			(*head)->next->prev = NULL;
			(*head) = (*head)->next;
			to_delete = NULL;
		}
		return;
	}
	int k = 1;
	struct ListNode *temp = *head;
	while( k < position - 1 && temp->next != NULL)
	{
		temp = temp->next;
		k++;
	}
	if(k != position - 1 || temp->next == NULL)
	{
		printf("\nGiven Position is Invalid !..\n\n");
		return;
	}

	if(temp->next->next == NULL)
	{
		struct ListNode *to_delete = temp->next->prev; 
		temp->next = temp->next->next;
		to_delete = NULL;
	}
	else
	{
		temp->next = temp->next->next;
		temp->next->prev  = temp;
	}
}
void insertnodenexttogivenkey(struct ListNode **head , int key,int ele)
{
	if(*head == NULL)
	{
		printf("\nDouble Linked List is Empty !..\n\n");
		return;
	}	
	struct ListNode *temp = *head;
	while(temp->data != key  && temp->next != NULL)
	{
		temp = temp->next;
	}
	if(temp->data != key && temp->next == NULL)
	{
		printf("\n Given Key Not Found to insert  next node  !..\n");
		return;
	}
	struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->data = ele;
	if(temp->data == key && temp->next == NULL)
	{
		newNode->next = NULL;
		newNode->prev = temp;
		temp->next = newNode;
	}
	else
	{
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next->prev = newNode;
		temp->next = newNode;
	}
}

void removenextnodeofgivenkey(struct ListNode **head,int key)
{
	if(*head == NULL)
	{
		printf("\nDouble Linked List is Empty !..\n\n");
		return;
	}
	struct ListNode *temp = *head;
	while(temp->data != key  && temp->next != NULL)
	{
		temp = temp->next;
	}
	if(temp->data == key && temp->next == NULL)
	{
		printf("\nIt's Next Node Not available to delete !..\n\n");
		return;
	}
	if(temp->data != key && temp->next == NULL)
	{
		printf("\n Given Key Not Found to delete it's next node  !..\n");
		return;
	}
	if(temp->next->next == NULL)
	{
		struct ListNode *to_delete = temp->next->prev; 
		temp->next = temp->next->next;
		to_delete = NULL;
	}
	else
	{
		temp->next = temp->next->next;
		temp->next->prev = temp;
	}
}
void showdoublelinkedlist(struct ListNode *head){
	if(head == NULL)
	{
		printf("\nDouble Linked List is Empty !..\n\n");
		return;
	}
	struct ListNode *temp = head;
	printf("\n Current Double Linked List is  :  \n\n");
	while(temp != NULL)
	{
		printf(" %d ",temp->data);
		temp = temp->next;
	}
	printf("\n\n");
}
int main()
{
	printf("\n\t\t\t\tDouble Linked List Implementation\n\n");
	struct ListNode *head = NULL;
	int op;
	int ele;
	int position;
	do{
		printf("1.Insert at Beginning			2.Insert at End  			3.Insert at Given Position \n");
		printf("4.Remove First Node    	 		5.Remove last Node 			6.Remove Node by its Position \n");
		printf("7.Insert Node Next to Given Key 	8.Remove next node of given Key		9.Show Current Double Linked List \n");
		printf("10.To Exit\n");
		printf("\nEnter Your Option : ");
		scanf(" %d",&op);
		switch(op){
			case 1 : 
						printf("\nEnter Element you want to insert at Beginning : ");
						scanf(" %d",&ele);
						insertatbegin(&head,ele); // call by reference
						break;
			case 2 :	
						printf("\nEnter Element you want to insert at End : ");
						scanf(" %d",&ele);
						head = insertatend(head,ele); // call by value
						break;
			case 3 :
						printf("\nEnter position where you want to insert : ");
						scanf(" %d",&position);
						printf("\nEnter Element you want to insert at  %d position :  ",position);
						scanf(" %d",&ele);
						insertatgivenposition(&head,position,ele);
						break;
			case 4 :
						removefirstnode(&head);
						break;
			
			case 5 :
						removelastnode(&head);
						break;
			case 6 :
						printf("\nEnter position where you want to Remove Node : ");
						scanf(" %d",&position);
						removenodeatgivenposition(&head,position);
						break;
			case 7 :
						printf("\nEnter Key to which  next Node should be created : ");
						scanf(" %d",&position);
						printf("\nEnter element you want to insert : ");
						scanf(" %d",&ele);
						insertnodenexttogivenkey(&head,position,ele);
						break;
			case 8 :
						printf("\nEnter Key in which it's Next Node want to Delete : ");
						scanf(" %d",&ele);
						removenextnodeofgivenkey(&head,ele);
						break;
			case 9 :
						showdoublelinkedlist(head);
						break;
			case 10 :
						break;
			default :
					printf("\nInvalid input\n");
		}
	}while(op!=10);
	return 0;
}