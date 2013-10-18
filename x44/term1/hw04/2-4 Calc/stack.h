/*
Eugene Auduchinok (c) 2013

Homework 1.04.02
Reverse Polish Notation
*/

#pragma once

struct StackElement
{
	double value;
	StackElement *next;
};

struct Stack
{
	StackElement *top;
};

Stack *createStack();
void push(Stack *stack, double value);
void pop(Stack *stack);
double top(Stack *stack);
bool isEmpty(Stack *stack);
void deleteStack(Stack *stack);