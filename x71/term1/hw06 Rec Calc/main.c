// Implement double in "lexer.c"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"

void print_result(char *expression, Result result)
{
	printf("calc: ");

	if (result.error == ET_NONE)
	{
		printf("%s = %f\n", expression, result.value);
	}
	else
	{
		printf("error: ");

		switch (result.error)
		{
			case ET_WRONG_TOKEN_TYPE:
			{
				// not handled yet
				break;
			}
			case ET_DIVIDE_BY_NULL:
			{
				printf("division by null.\n");
				break;
			}
			default:
			{
				printf("unexpected end of file\n");
			}
		}
	}
}

int main(int argc, char *argv[])
{
	char *expression = NULL;

	if (argc > 1)
	{
		FILE *in = fopen(argv[1], "r");

		if (in == NULL)
		{
			printf("calc: %s: No such file or directory\n", argv[1]);
			return 1;
		}

		fseek(in, 0, SEEK_END);
		int file_length = ftell(in);
		rewind(in);

		expression = (char *) malloc(sizeof(char) * file_length);
		fread(expression, sizeof(char), file_length, in);
		
		fclose(in);
	}
	else
	{
		const int MAX_LENGTH = 1024;
		expression = (char *) malloc(sizeof(char) * MAX_LENGTH);
			
		printf("Expression: \n");
		fgets(expression, MAX_LENGTH, stdin);
	}

	Result result = calc(expression);

	print_result(expression, result);	

	free(expression);
	return 0;
}