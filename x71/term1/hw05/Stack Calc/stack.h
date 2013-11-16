/*
Eugene Auduchinok (c) 2013

Homework 1.05.1
Stack Calc
*/

#ifndef STACK_H
#define STACK_H

struct StackElement
{
	double value;
	struct StackElement *next;
};
typedef struct StackElement StackElement;

struct Stack
{
	StackElement *top;
};
typedef struct Stack Stack;

Stack *create_stack();
void delete_stack(Stack *stack);
void push(Stack *stack, double value);
double pop(Stack *stack, int *error);
void dup(Stack *stack);
int is_empty(Stack *stack);

#endif
