/*

ID : B171452  
 Code By Sandeep Payili on 11/01/2021

*/

#include<stdio.h>
#include<stdlib.h>


struct queue{
	int size;
	int * queue_array;
	int rear;
	int front;
};

int main()
{
	struct queue *q;

	q = (struct queue *)malloc(sizeof(struct queue));

	q->front = -1;
	q->rear = -1;

	printf("\nEnter size of the Queue : ");
	scanf(" %d",&q->size);

	q->queue_array = (int *)malloc(q->size * sizeof(int));


	int operation;

	do{
		printf("\n\n1.Enqueue    2.Dequeue     3.Show Queue    4.Exit \n");

		printf("\nEnter operation : ");
		scanf(" %d",&operation);

		switch(operation){
			case 1 : 

					if(q->rear  ==  q->size - 1)
					{
						printf("\nQueue is Full \n");
					}
					else
					{
						q->rear++;
						int ele;
						printf("\nEnter element to Enqueue : ");
						scanf(" %d",&ele);
						q->queue_array[q->rear] = ele; 
					}
					break;
			case 2 :
					if(q->front == q->rear )
					{
						printf("\nQueue is Empty \n");
					}
					else
					{
						q->front++;
						printf("\n %d is Dequeued !\n",q->queue_array[q->front]);
					}
					break;
			case 3 :

					printf("\n 			Current Queue					\n ");
					for(int i=q->front + 1 ; i <= q->rear ; i++)
					{
						printf("  %d    ",q->queue_array[i]);
					}
					break;
			case 4 :
					break;
			default:
			       printf("\nInvalid Option \n");
		}
	}while(operation != 4);
	return 0;
}
