/*

ID : B171452 
Code By Sandeep Payili on 13/01/2021

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	char *stack_array;
	int top;
};
int precedence(char symbol){
	if(symbol == '^')
	{
		return 3;
	}
	else if(symbol == '*' || symbol == '/')
	{
		return 2;
	}
	else if(symbol == '+' || symbol == '-')
	{
		return 1;
	}
	else if (symbol == '(')
	{
		return 0;
	}
	else
		return -1;
}
void push(struct stack *s,int symbol)
{
	s->top++;
	s->stack_array[s->top] = symbol;
}
void pop(struct stack *s)
{
	if(s->stack_array[s->top] == '(')
	{
		s->top--;	
	}else
	{
		printf("%c",s->stack_array[s->top]);
		s->top--;	
	}
}
int main()
{
	char expression[100];
	printf("\nEnter Infix Expression : ");
	scanf(" %[^\n]s",expression);

	char *e = expression;

	struct stack *s;
	s = (struct stack *)malloc(sizeof(struct stack));
	s->top = -1;
	s->stack_array = (char *)malloc( strlen(expression) * sizeof(char));

	char symbol = *e;

	while(symbol != '\0')
	{
		if(symbol == '(')
		{
			 push(s,symbol);
		}
		else if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
		{
			if(( s->top == -1 ) || ( precedence(symbol) > precedence(s->stack_array[s->top]) ) ) // precedence('(') == 0
			{
				push(s,symbol);
			}
			else
			{
				while( (s->stack_array[s->top] != -1 ) && (s->stack_array[s->top] != ')' ) && ( precedence(symbol) <= precedence(s->stack_array[s->top]) ) )
				{
					pop(s);
				}
				push(s,symbol);
			}
		}
		else if(symbol == ')')
		{
			while(s->stack_array[s->top] != '(')
			{
				pop(s);
			}
			pop(s);
		}
		else
		{
			printf("%c",symbol);
		}
		e++;
		symbol = *e;
	}
	while(s->top != -1)
	{
				pop(s);
	}
	printf("\n");
	return 0;
}


/*
 Input 1 : ( (A * B) + (C / D) )
 Output 1: A B * C D / +

 Input 2 :x ^ y / (5 * z) + 10
 Output 2 :x y ^ 5 z * / 10 +

*/