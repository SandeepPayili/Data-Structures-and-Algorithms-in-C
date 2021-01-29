/*

ID : B171452  
 Code By Sandeep Payili on 6/01/2021

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	int stack_array[20];
	int top;
	int size;

};

struct stack  push(struct stack s){
			if(s.top == s.size-1)
			{
			 	printf("\nStack is Full\n");
			 }
			 		else
			 		{
			 			s.top++;
			 			int ele;
			 			printf("\nEnter Element to Push : ");
			 			scanf(" %d",&ele);
			 			s.stack_array[s.top] = ele;

			 		}

	return s;
}

struct stack pop(struct stack s){

	if(s.top == -1)
					{
						printf("\nStack is Empty \n");
					}
					else
					{
						printf("\n%d is popped!\n",s.stack_array[s.top]);
						s.top--;
					}


	return s;
}


int main(){

	int op;

	struct stack s;
	s.top = -1;
	printf("\nEnter size of the Stack (<=20) :");
	scanf(" %d",&s.size);

	do
		{

		printf("\n\n 1. Push 2.Pop   3.Show stack  4.Exit\n\n");

		printf("\nEnter Your operation: ");
		scanf(" %d",&op);
		switch(op){
			case 1:
					s = push(s);
			 		break;
			case 2:
					s = pop(s);
					break;
			case 3:

					printf("\n\n                    Current Stack                                \n\n");
					for (int i = 0; i <= s.top; ++i)
					{
						printf("%d  ",s.stack_array[i]);
					}
					break;
			case 4:
					break; // since not to show invalid option i.e., default case
			default:
			       printf("\nInvalid Option \n");
		}
	}while(op!=4);

	return 0;
}