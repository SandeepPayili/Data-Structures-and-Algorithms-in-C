/*

ID : B171452
Description :  Graph Traversals Depth First Search 
Code by Sandeep Payili on 28/01/2021

*/
#include<stdio.h>
#include<stdlib.h>	
void dfs(int k,int **graph,int *visit,int nodes)
{
		 	if(visit[k] == 0) // skips checking below for loop while back tracking
		 	{
		 		visit[k] = 1;
		 		printf(" %d ",k);
		 		for(int j=0;j<nodes;j++)
		 		{
		 			if(graph[k][j] == 1 && visit[j] == 0)
		 			{
		 				dfs(j,graph,visit,nodes);
		 			}
		 		}
		 	}
}

int main()
{	
	printf("\n\n\t\t\tGraph Traversal Depth First Search\n\n");
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
	int *visit;
	visit = (int *)malloc(nodes*sizeof(int));
	for (int i = 0; i < nodes; ++i)
	{
		visit[i] = 0;
	}
	printf("\nOne Possible Depth First Search of Given Graph is : ");
	dfs(0,graph,visit,nodes);
	// for non linked nodes
	for(int i=0;i<nodes;i++)
	{
		if(visit[i] == 0)
		{
			dfs(i,graph,visit,nodes);
		}
	}
	printf("\n");
	return 0;
}
/*

			Graph Traversal Depth First Search


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

One Possible Depth First Search of Given Graph is :  0  7  6  1  2  3  4  5  8  9 
*/

/*
	0          3
   /  \       / \
  1    2     4   5 
  
			Graph Traversal Depth First Search


Enter No. of Nodes(vertices) : 6

Enter Graph Data in Matrix Form : 
0 1 1 0 0 0 
1 0 0 0 0 0
1 0 0 0 0 0
0 0 0 0 1 1
0 0 0 1 0 0
0 0 0 1 0 0

One Possible Depth First Search of Given Graph is :  0  1  2  3  4  5 
*/