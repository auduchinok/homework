#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

static char *line = NULL;
static int line_length = 0;
static int cur = 0;
char *cur_lexem = NULL;

void set_line(char *new_line)
{
	line = new_line;
	line_length = strlen(line);
}

Token_Type get_type(char *lexem)
{

	char type = lexem[0];

	switch (type)
	{
		case '+':
		{
			return TT_ADD;
		}
		case '-':
		{
			return TT_SUB;
		}
		case '*':
		{
			return TT_MUL;
		}
		case '/':
		{
			return TT_DIV;
		}
		case '(':
		{
			return TT_BR_OPEN;
		}
		case ')':
		{
			return TT_BR_CLOSE;
		}
		default:
		{
			if (isdigit(type))
			{
				return TT_NUM;
			}
			else
			{
				return TT_ERR;
			}
		}
	}
}

Token get_token()
{
	Token result;
	result.value = 0;

	result.type = next_token_type();

	if (result.type == TT_NUM)
	{
		result.value = atoi(cur_lexem);

		while (isdigit(line[cur]))
		{
			cur++;
		}
	}
	else
	{
		cur++;
	}
	
	return result;
}

Token_Type next_token_type()
{

	Token_Type result;

	while (isblank(line[cur]))
	{
		cur++;
	}

	if (cur >= line_length)
	{
		result = TT_EOF;
		return result;
	}

	cur_lexem = &line[cur];

	result = get_type(cur_lexem);

	return result;
}