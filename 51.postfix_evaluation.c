/*
 
ID : B171452
Description :  Post fix Evaluatioon
Code by Sandeep Payili on 19/09/2021

*/

#include<stdio.h>
#include<stdlib.h>
struct stack{
	char *stack_array;
	int top;
};
void push(struct stack *s,char ele,int ascii_digit)
{
	if (ascii_digit == 1)
	{
		s->top++;
		s->stack_array[s->top] = (ele-48); // char_diit - 48 = numeric_digit
	}
	else{
		s->top++;
		s->stack_array[s->top] = ele;
	}
}
int pop(struct stack *s)
{
	return s->stack_array[s->top--];
}
int eval(int operand1,int operand2,char operator)
{
	switch(operator)
	{
		case '+' :
					return operand2 + operand1;
		case '-' :
					return operand2 - operand1;
		case  '*' :
					return operand2 * operand1;
		case '/'  :
					return operand2 / operand1 ; //
		case '^' :
					return operand2 ^ operand1;
 	}
}
int main()
{
	int size=100;
	// printf("\nEnter Maximum size of Post fix Expression : ");
	//scanf(" %d",&size);
	char *expression;
	expression = (char *)malloc(sizeof(char)*size);
	printf("\nEnter Post Fix Expression  :   ");
	scanf(" %[^\n]s",expression);


	struct stack *s;
	s = (struct stack *)malloc(sizeof(struct stack));
	s->stack_array = (char  *)malloc(sizeof(char)*size);
	s->top = -1;

	char *e= expression;
	char symbol = *e;
	int ascii_digit = 1;
	while(symbol != '\0')
	{
		if (symbol== '+' || symbol == '-' || symbol == '/' || symbol == '*' || symbol == '^')
		{
			ascii_digit = 0;
			int operand1 = pop(s);
			int operand2 = pop(s);
			int result = eval(operand1,operand2,symbol);
			push(s,result,ascii_digit);
		}
		else{
			ascii_digit = 1;
			push(s,symbol,ascii_digit);
		}
		e++;
		symbol = *e;
	}
	printf("\nAfter  Evaluation final value is : %d\n",s->stack_array[s->top]);
	return 0;
}

/*

Enter Post Fix Expression  :   53^79*+2-1+

After  Evaluation final value is : 68


Enter Post Fix Expression  :   79*42-2/+

After  Evaluation final value is : 64


*/