/*

ID : B171452 
Code By Sandeep Payili on 13/1/20201

*/

/*

Without Brackets

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{

	char *stack_array;
	int size;
	int top;

};

void push(struct stack *s,char ele)
{
	s->top++;
	s->stack_array[s->top] = ele;
}

void pop(struct stack *s)
{
	printf("%c",s->stack_array[s->top]);
	s->top--;
}

int precedence(char symbol)
{	
	if(symbol == '^')
	{
		return 3;
	}
	else if(symbol == '/' || symbol == '*' )
	{	
		return 2;
	}
	else if(symbol == '+' || symbol == '-')
	{
		return 1;
	}
	return -1;
}


int main()
{
	char *infix_expression;
	int expression_max_size = 100;

	infix_expression = (char *)malloc(expression_max_size * sizeof(char));

	printf("\nEnter Your infix expression   : ");
	scanf(" %[^\n]s",infix_expression);

	int infix_expression_size;
	infix_expression_size = strlen(infix_expression);

	struct stack *s;
	s = (struct stack *)malloc(sizeof(struct stack));
	s->size = infix_expression_size;
	s->stack_array = (char *)malloc(s->size * sizeof(char));
	s->top = -1;

	for (int i = 0; infix_expression[i] != '\0'; ++i)
	{
		
		if (infix_expression[i] == '+'  || infix_expression[i] == '-'  || infix_expression[i] == '/' || infix_expression[i] == '*' || infix_expression[i] == '^'  )
		{
				char symbol = infix_expression[i];
				
				if( ( s->top == -1 ) || (  precedence(symbol) > precedence(s->stack_array[s->top])  ) ) 
				{
					push(s,symbol);	
				}
				else
				{
					while(( s->top != -1 ) && (  precedence(symbol) <= precedence(s->stack_array[s->top])  ))
					{
						pop(s);
					}
					push(s,symbol);
				}
		}
		else
		{
			printf("%c", infix_expression[i] );
		}

	}

	while(s->top != -1)
	{
		pop(s);
	}
	printf("\n");
	return 0;
}
