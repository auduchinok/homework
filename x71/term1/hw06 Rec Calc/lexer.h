#ifndef _LEXER_H_
#define _LEXER_H_

typedef enum Token_Type
{
	TT_NUM,
	TT_BR_OPEN,
	TT_BR_CLOSE,
	TT_ADD,
	TT_SUB,
	TT_MUL,
	TT_DIV,
	TT_EOF,
	TT_ERR
} Token_Type;

typedef struct Token
{
	Token_Type type;
	int value;
} Token;

void set_line(char *line);
Token get_token();
Token_Type next_token_type();

#endif