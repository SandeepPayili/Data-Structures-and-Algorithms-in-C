// cycle start node in linked list
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
int find_cycle_start_node(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            slow = head;// mathematical proof
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow->data;
        }
    }
    return -1;
}
int main()
{
    struct ListNode *head=NULL;
    InsertInLinkedListAtBegin(&head,9);
    struct ListNode *to_create_cycle = head;
    InsertInLinkedListAtBegin(&head,7);
    InsertInLinkedListAtBegin(&head,6);
    InsertInLinkedListAtBegin(&head,4);
    struct ListNode *to_create_cycle2 = head;
    InsertInLinkedListAtBegin(&head,3);
    InsertInLinkedListAtBegin(&head,2);
    to_create_cycle->next = to_create_cycle2;

    //showmylinkedlist(head);
  
    int cycle_start_node = find_cycle_start_node(head);
    if (cycle_start_node != -1)
    {
        printf("\n Yes! there is cycle and it is starting at node   %d \n\n",cycle_start_node);
    }else{
        printf("\n No! there no cycle\n");
    }
    return 0;
}
/*

Linked List  >>> 
2  3  4  6  7  9  4  6  7  9  4  6  7  9  4  6  ..............

OUTPUT:

 Yes! there is cycle and it is starting at node   4

*/