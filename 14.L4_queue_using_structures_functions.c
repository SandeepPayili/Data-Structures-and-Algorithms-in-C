/*

ID : B171452  
 Code By Sandeep Payili on 11/01/2021

*/

#include<stdio.h>

struct queue{

	int size;

	int queue_array[20];

	int rear,front;

};


struct queue Enqueue(struct queue q)
{

				if(q.rear  == q.size - 1 ){
						printf("\nQueue is Full \n");
					}else{
						q.rear++;
						int ele;
						printf("\nEnter element to Enqueue : ");
						scanf(" %d",&ele);
						q.queue_array[q.rear] = ele;
					}

	return q;

}

struct queue Dequeue(struct queue q){
					if( q.front == q.rear)
					{
						printf("\nQueue is Empty \n");
					}
					else
					{
						q.front++;
						printf("\n %d is Dequeued !\n",q.queue_array[q.front]);
					}
		return q;
}

int main(){

	struct queue q;

	q.rear = -1;
	q.front = -1;

	printf("\nEnter size of the Queue (<=20) :");
	scanf(" %d",&q.size);

	int operation;

	do{
		printf("\n\n1.Enqueue    2.Dequeue     3.Show Queue    4.Exit \n");

		printf("\nEnter operation : ");
		scanf(" %d",&operation);

		switch(operation){
			case 1 : 
					q = Enqueue(q);		
					break;
			case 2 :
					q = Dequeue(q);			
					break;
			case 3 :

					printf("\n 			Current Queue					\n ");
					for(int i=q.front+1;i<=q.rear;i++)
					{
						printf("  %d    ",q.queue_array[i]);
					}
					break;
			case 4 :
					break;
			default : 
				printf("\n Invalid Option   \n");
		}
	}while(operation!=4);
	return 0;
}