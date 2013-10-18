/*
Eugene Auduchinok (c) 2013

Homework 1.04.02
Reverse Polish Notation
*/

#include <utility>
#include "stack.h"

Stack *createStack()
{
	Stack *result = new Stack;
	result->top = nullptr;

	return result;
}

void push(Stack *stack, double value)
{
	StackElement *toAdd = new StackElement;
	toAdd->value = value;
	toAdd->next = stack->top;

	stack->top = toAdd;
}

bool isEmpty(Stack *stack)
{
	return	stack->top == nullptr;
}

void pop(Stack *stack)
{
	if (isEmpty(stack))
	{
		return;
	}

	StackElement *toDelete = stack->top;

	stack->top = toDelete->next;
	delete toDelete; 
}

double top(Stack *stack)
{
	return stack->top->value;
}

void deleteStack(Stack *stack)
{
	while (!isEmpty(stack))
	{
		pop(stack);
	}

	delete stack;
}