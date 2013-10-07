#include <cstring>
#include "isCorrectText.h"
#include "stack.h"
using namespace stack;

bool isBracket(const char ch)
{
	return (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}');
}

bool isCorrect(char *buffer)
{
	int stringLength = strlen(buffer);
	Stack *brStack = createStack(); // BracketsStack
	bool result = false;

	for (int i = 0; i < stringLength; i++)
	{
		char ch = buffer[i];

		if (!isBracket(ch))
		{
			continue;
		}

		if (ch == '(' || ch == '[' || ch == '{')
		{
			push(brStack, ch);
		}
		else
		{
			if (isEmpty(brStack))
			{
				deleteStack(brStack);
				return false;
			}

			if ((ch == ')' && top(brStack) == '(') || (ch == ']' && top(brStack) == '[') || (ch == '}' && top(brStack) == '{'))
			{
				pop(brStack);
			}
			else
			{
				deleteStack(brStack);
				return false;
			}
		}
	}

	result = isEmpty(brStack);

	deleteStack(brStack);
	return result;
}