/*
Eugene Auduchinok (c) 2013

Homework 1.04.02
Reverse Polish Notation
*/

#include <cstring>
#include <cctype>
#include "stack.h"
using namespace std;

bool isOperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

int opPriority(char c)
{
	if (c == '*' || c == '/')
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

void putToResult(char *res, int &resLength, char c)
{
	res[resLength] = c;
	resLength++;

	res[resLength] = ' ';
	resLength++;
}

void putNumToResult(char *res, int &resLength, char *num, int &numLength)
{
	num[numLength] = 0;
	res[resLength] = 0;
	strcat(res, num);
	resLength += numLength;

	res[resLength] = ' ';
	resLength++;
}

char *createPostfix(char *src)
{
	int srcLength = strlen(src);
	char *result = new char[srcLength];
	int resultLength = 0;

	bool readingNum = false;
	char *num = new char[10];
	int numLength = 0;

	Stack *s = createStack();

	for (int i = 0; i < srcLength; i++)
	{
		if (isdigit(src[i]))
		{
			if (!readingNum)
			{
				numLength = 0;
				readingNum = true;
			}
			
			num[numLength] = src[i];
			numLength++;
			
			continue;
		}
		else
		{
			if (readingNum)
			{
				putNumToResult(result, resultLength, num, numLength);
				readingNum = false;
			}
		}

		if (isspace(src[i]))
		{
			continue;
		}

		if (isOperator(src[i]))
		{
			while (!isEmpty(s) && isOperator(top(s)) && opPriority(src[i]) <= opPriority(top(s)))
			{
				putToResult(result, resultLength, top(s));
				pop(s);
			}

			push(s, src[i]);
			continue;
		}

		if (src[i] == '(')
		{
			push(s, src[i]);
			continue;
		}

		if (src[i] == ')')
		{
			while (top(s) != '(')
			{
				putToResult(result, resultLength, top(s));
				pop(s);
			}

			pop(s);
		}
	}

	if (readingNum)
	{
		putNumToResult(result, resultLength, num, numLength);
	}

	while (!isEmpty(s))
	{
		putToResult(result, resultLength, top(s));
		pop(s);
	}

	result[resultLength - 1] = 0;
	delete[] src;

	return result;
}