/*

ID : B171452  
 Code By Sandeep Payili on 11/01/2021

*/

#include<stdio.h>


int Enqueue(int *queue , int *front,int *rear,int *size)
{

			if(*rear  == *size - 1 )
			{
				printf("\nQueue is Full \n");
			}else{
					(*rear)++;
					int ele;
					printf("\nEnter element to Enqueue : ");
					scanf(" %d",&ele);
					queue[*rear] = ele;
			}
		return 0;
}

int Dequeue(int *queue , int *front,int *rear)
{

					if( *front == *rear)
					{
						printf("\nQueue is Empty \n");
					}
					else
					{
						(*front)++;
						printf("\n %d is Dequeued !\n",queue[*front]);
					}
	return 0;
}

int main(){

	
	int size = 10;

	int queue[size];

	int rear = -1,front = -1;

	int operation;

	do{
		printf("\n\n1.Enqueue    2.Dequeue     3.Show Queue    4.Exit \n");

		printf("\nEnter operation : ");
		scanf(" %d",&operation);

		switch(operation){
			case 1 : 
					Enqueue(queue,&front,&rear,&size);
					break;
			case 2 :
					Dequeue(queue,&front,&rear);
					break;
			case 3 :

					printf("\n 			Current Queue					\n ");
					for(int i=front+1;i<=rear;i++)
					{
						printf("  %d    ",queue[i]);
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