/*
Eugene Auduchinok (c) 2013

Homework 1.04.03
Stack-calc
*/

#include <sstream>
#include <cstdlib>
#include "postfix.h"
#include "stack.h"
using namespace std;

double calc(char *exprStr)
{
	exprStr = createPostfix(exprStr);

	std::stringstream expr(exprStr);
	Stack *s = createStack();
	char lex[20];

	while (!expr.eof())
	{
		expr >> lex;
		
		if (strlen(lex) == 1 && isOperator(lex[0]))
		{
			double op2 = top(s);
			pop(s);
			double op1 = top(s);
			pop(s);

			switch (lex[0])
			{
				case '+':
				{
					push(s, op1 + op2);
					break;
				}
				case '-':
				{
					push(s, op1 - op2);
					break;
				}
				case '*':
				{
					push(s, op1 * op2);
					break;
				}
				case '/':
				{
					push(s, op1 / op2);
					break;
				}
			}

			continue;
		}

		push(s, atoi(lex));
	}

	double result = top(s);
	pop(s);
	delete s;

	return result;
}