/*
Eugene Auduchinok (c) 2013

Homework 1.05.1
Stack Calc
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack.h"

int is_operation(char *s)
{
	char ch = s[0];
	return (strlen(s) == 1 && (ch == '+' || ch == '-' || ch == '*' || ch == '/'));
}

int is_num(char *s)
{
	/*
	Разнообразия ради можно добавить сюда хороший разбор double,
	если будет больше времени в конце семестра.
	Возможно, займусь этим после разбора регулярок.
	*/

	int i = 0;
	int has_point = 0;
	int str_len = strlen(s);

	for (i = 0; i < str_len; i++)
	{
		if (!isdigit(s[i]))
		{
			if ((s[i] == '.' || s[i] == ',') && !has_point)
			{
				continue;
			}

			return 0;
		}
	}

	return 1;
}

int main()
{
	printf("Stack calc\n");

	printf("Type\n");
	printf(" - a num: put the num to the stack\n");
	printf(" - an operation out of +,-,*,/ to apply\n");
	printf(" - \"dup\" to dublicate the top value of the stack\n");
	printf(" - \"pop\" to print the top value (don't forget to dublicate first!)\n");
	printf(" - \"exit\" to exit\n");

	Stack *stack = create_stack();
	char command[10] = {0};
	int error = 0;

	while (strcmp(command, "exit"))
	{
		printf(": ");
		scanf("%s", (char *) &command);

		if (is_num(command))
		{
			char *end_of_num = NULL;
			push(stack, strtod(command, &end_of_num));
		}
		else if (is_operation(command))
		{
			double op_a = pop(stack, &error);
			double op_b = pop(stack, &error);

			if (error)
			{
				break;
			}

			char operation = command[0];

			switch (operation)
			{
				case '+':
				{
					push(stack, op_b + op_a);
					break;
				}
				case '-':
				{
					push(stack, op_b - op_a);
					break;
				}
				case '*':
				{
					push(stack, op_b * op_a);
					break;
				}
				case '/':
				{
					push(stack, op_b / op_a);
					break;
				}

			}
		}
		else if (!strcmp(command, "dup"))
		{
			dup(stack);
		}
		else if (!strcmp(command, "pop"))
		{
			double top = pop(stack, &error);

			if (error)
			{
				break;
			}

			printf("top: %f\n", top);
		}
	}

	delete_stack(stack);
}
