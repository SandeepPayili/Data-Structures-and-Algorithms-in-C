/*

ID : B171452
Description :  Graph Traversals Breadth First Search 
Code by Sandeep Payili on 27/01/2021

*/
#include<stdio.h>
#include<stdlib.h>	
#include<stdbool.h>
bool isEmpty(int *queue,int *front,int *rear)
{
	if(*front == *rear)
	{
		return true;
	}
	return false;
}
void Enqueue(int *queue,int data,int *front,int *rear)
{	
	(*rear)++;
	queue[*rear] = data;
}
int Dequeue(int *queue,int *front,int *rear)
{
	(*front)++;
	return queue[*front];
}
/* to ease debug
void print_queue(int *queue,int *front,int *rear)
{
	printf("\nQueue : ");
	for(int i=(*front)+1;i<= *rear;i++)
	{
		printf(" %d ", queue[i]);
	}
	printf("\n");
}
void print_visit_array(int visit[],int nodes)
{
	printf("\nVisit Array : ");
	for(int i=0;i<nodes;i++)
	{
		printf(" %d ", visit[i]);
	}
	printf("\n");
}
*/
void bfs(int **graph,int nodes)
{
	int *queue;
	queue = (int *)malloc(nodes * sizeof(int));
	int *front = (int *)malloc(sizeof(int));
	int *rear = (int *)malloc(sizeof(int));
	*front = -1;
	*rear = -1;
	int visit[nodes];
	for(int i=0;i<nodes;i++)
	{
		visit[i] = 0;
	}
	Enqueue(queue,0,front,rear);
	visit[0] = 1;
	int k;
	while(!isEmpty(queue,front,rear))
	{
		// print_queue(queue,front,rear);
		// print_visit_array(visit,nodes);
		k = Dequeue(queue,front,rear);
		printf(" %d ",k);
		for(int j=0;j<nodes;j++)
		{
			if(graph[k][j] == 1 && visit[j] == 0)
			{
				Enqueue(queue,j,front,rear);
				visit[j] = 1;
			}
			/*
			 else
			 {
			 	printf("\nnot : %d\n", j);
			 }
			 */
		}
	}
}
int main()
{	
	printf("\n\n\t\t\tGraph Traversal Breadth First Search\n\n");
	int op;
	int nodes;
	printf("\nEnter No. of Nodes(vertices) : ");
	scanf(" %d",&nodes);
	if(nodes <=  0)
	{
		printf("\nPlease enter Valid Nodes \n");
		return 0;
	}
	int **graph;
	graph = (int **)malloc(nodes * sizeof(int *));
	for(int i=0;i<nodes;i++)
	{
		graph[i] = (int *)malloc(nodes*sizeof(int));
	}
	printf("\nEnter Graph Data in Matrix Form : \n");
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			scanf(" %d",&graph[i][j]);
		}
	}
	printf("\nOne Possible Breadth First Search of Given Graph is : ");
	bfs(graph,nodes);
	printf("\n");
	return 0;
}

/*
			Graph Traversal Breadth First Search


Enter No. of Nodes(vertices) : 10

Enter Graph Data in Matrix Form : 
0 2 0 0 0 0 0 1 0 0
1 0 1 0 0 1 1 0 0 0 
0 1 0 1 1 0 0 0 0 0 
0 0 1 0 0 0 0 0 0 0
0 0 1 0 0 1 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 1 0 0 0 0 0 1 1 1
1 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0 0

One Possible Breadth First Search of Given Graph is :  0  7  6  1  8  9  2  5  3  4 
*/