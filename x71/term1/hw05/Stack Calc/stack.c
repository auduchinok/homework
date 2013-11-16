/*
Eugene Auduchinok (c) 2013

Homework 1.05.1
Stack Calc
*/

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack *create_stack()
{
	Stack *result = (Stack *) malloc(sizeof(Stack));
	result->top = NULL;

	return result;
}

void delete_stack(Stack *stack)
{
	StackElement *tmp = stack->top;

	while (tmp != NULL)
	{
		StackElement *to_delete = tmp;
		tmp = tmp->next;
		free(to_delete);
	}

	free(stack);
}

int is_empty(Stack *stack)
{
	return (stack->top == NULL);
}

void push(Stack *stack, double value)
{
	StackElement *to_add = (StackElement *) malloc(sizeof(StackElement));
	
	to_add->value = value;
	to_add->next = stack->top;
	stack->top = to_add;
}

double pop(Stack *stack, int *error)
{
	if (is_empty(stack))
	{
		printf("Not enough operands in the stack.\nExiting..\n");
		*error = 1;
		return 0;
	}

	int top_value = stack->top->value;

	StackElement *to_delete = stack->top;
	stack->top = to_delete->next;
	free(to_delete);

	return top_value;
}

void dup(Stack *stack)
{
	if (is_empty(stack))
	{
		printf("The stack is empty.\n");
		return;
	}

	StackElement *copy = (StackElement *) malloc(sizeof(StackElement));

	copy->value = stack->top->value;
	copy->next = stack->top;
	stack->top = copy;
}
