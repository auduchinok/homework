#include <iostream>
#include "stack.h"
using namespace stack;

stack::Stack *stack::createStack()
{
	Stack *result = new Stack;
	result->top = nullptr;

	return result;
}

void stack::deleteStack(Stack *stack)
{
	StackElement *tmp = stack->top;

	while (tmp != nullptr)
	{
		StackElement *toDelete = tmp;
		tmp = tmp->next;
		delete toDelete;
	}

	delete stack;
}

bool stack::isEmpty(Stack *stack)
{
	return (stack->top == nullptr);
}

void stack::push(Stack *stack, char value)
{
	StackElement *toAdd = new StackElement;
	
	toAdd->value = value;
	toAdd->next = stack->top;
	stack->top = toAdd;
}

void stack::pop(Stack *stack)
{
	if (isEmpty(stack))
	{
		return;
	}

	StackElement *toDelete = stack->top;
	stack->top = toDelete->next;

	delete toDelete;
}

char stack::top(Stack *stack)
{
	return stack->top->value;
}