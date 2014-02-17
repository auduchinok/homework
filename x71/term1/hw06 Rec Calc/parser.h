#ifndef _PARSER_H_
#define _PARSER_H_

#include "lexer.h"

typedef enum Error_Type
{
	ET_NONE,
	ET_WRONG_TOKEN_TYPE,
	ET_DIVIDE_BY_NULL,
	ET_EOF
} Error;

typedef struct Node_Result
{
	Error error;
	double value;
} Result;

Result calc(char *line);

#endif