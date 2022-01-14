// cycle detection in linked list
// floyed_cycle_detection_algorithm
// also known as Tortoise Hare Algorithm
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
void  showmylinkedlist(struct ListNode *head)
{
	struct ListNode *currentNode;
	currentNode = head;

	printf("\n Current Linked List  >>> \n");

	while(currentNode!=NULL)
	{
		printf(" %d ",currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
}
void make_cycle_at_end(struct ListNode **head)
{
    struct ListNode *currentNode;
    currentNode = *head;
    while(currentNode->next!=NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = *head;
}
int detech_cycle(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    struct ListNode *head=NULL;
    InsertInLinkedListAtBegin(&head,9);
    InsertInLinkedListAtBegin(&head,7);
    InsertInLinkedListAtBegin(&head,6);
    InsertInLinkedListAtBegin(&head,4);
    InsertInLinkedListAtBegin(&head,3);
    InsertInLinkedListAtBegin(&head,2);
    // showmylinkedlist(head);

    int cycle = detech_cycle(head);
    if (cycle == 1)
    {
        printf("\n Yes! there is cycle\n");
    }else{
        printf("\n No! there no cycle\n");
    }

    make_cycle_at_end(&head); // making linked list as cyclic linked list
    // showmylinkedlist(head);
    
    cycle = detech_cycle(head);
    if (cycle == 1)
    {
        printf("\n Yes! there is cycle\n");
    }else{
        printf("\n No! there no cycle\n");
    }

    return 0;
}