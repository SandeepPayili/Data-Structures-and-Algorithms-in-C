/*

ID : B171452  
 Code By Sandeep Payili on 6/01/2021

*/

/*

 Main Points to Remember ::

 	in stacs we can oly remove and add at particular side only...

 	Global Variables are not secure

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	/* static

	int stack[30];
	int size = 30, top = -1,op= 0;

	*/
	int stack[30];
	int size = 30, top = -1,op= 0;
	

		do
		{
		printf("\n\n 1. Push 2.Pop   3.Show stack  4.Exit\n\n");

		printf("\nEnter Your operation: ");
		scanf(" %d",&op);
		switch(op){
			case 1:
			 		if(top == size-1)
			 		{
			 			printf("\nStack is Full\n");
			 		}
			 		else
			 		{
			 			top++;
			 			int ele;
			 			printf("\nEnter Element to Push : ");
			 			scanf(" %d",&ele);
			 			stack[top] = ele;

			 		}

			 		// stack[++top] = ele;  assigning will get problem but not with returning
			 		break;
			case 2:
					if(top == -1)
					{
						printf("\nStack is Empty \n");
					}
					else
					{
						printf("\n%d is popped!\n",stack[top]);
						top--;
					}

					// stack[top--]; assigning will get problem but not with returning
					break;
			case 3:

					printf("\n\n                    Current Stack                                \n\n");
					for (int i = 0; i <= top; ++i)
					{
						printf("%d  ",stack[i]);
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