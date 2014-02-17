#include "parser.h"
#include "bool.h"

Result expr();
Result term();
Result factor();

bool is_sum_or_sub(Token_Type type)
{
	return type == TT_ADD || type == TT_SUB;
}

bool is_mult_or_div(Token_Type type)
{
	return type == TT_MUL || type == TT_DIV;
}

Result expr()
{
	Result result = term();

	Token_Type next_type = next_token_type();

	while (is_sum_or_sub(next_type))
	{
		Token operator = get_token();
		Result second = term();

		if (second.error != ET_NONE)
		{
			result.error = second.error;
			return result;
		}

		switch (operator.type)
		{
			case TT_ADD:
			{
				result.value += second.value;
				break;
			}
			case TT_SUB:
			{
				result.value -= second.value;
				break;
			}
			default:
			{
				// wrong token type
			}
		}

		next_type = next_token_type();
	}

	return result;
}

Result term()
{
	Result result = factor();
	result.error = ET_NONE;

	Token_Type next_type = next_token_type();

	while (is_mult_or_div(next_type))
	{
		Token operator = get_token();
		Result second = factor();

		switch (operator.type)
		{
			case TT_MUL:
			{
				result.value *= second.value;
				break;
			}
			case TT_DIV:
			{
				if (second.value == 0)
				{
					result.error = ET_DIVIDE_BY_NULL;
					return result;
				}

				result.value /= second.value;
				break;
			}
			default:
			{
				// wrong token type
			}
		}

		next_type = next_token_type();
	}

	return result;
}

Result factor()
{
	Result result;
	result.error = ET_NONE;
	
	Token next = get_token();

	switch (next.type)
	{
		case TT_BR_OPEN:
		{
			result = expr();

			next = get_token();
			if (next.type != TT_BR_CLOSE)
			{
				// wrong token type
			}

			break;
		}
		case TT_NUM:
		{
			result.value = next.value;
			break;
		}
		default:
		{
			// wrong token type
		}
	}

	return result;
}

Result calc(char *line)
{
	set_line(line);

	Result result = expr();

	// Token last = get_token();

	// if (last.type != TT_EOF)
	// {
	// 	result.error = ET_WRONG_TOKEN_TYPE;
	// 	printf("Should be end here.\n");
	// 	printf("%d\n", last.value);
	// 	//  Здесь бы сделать еще вывод неверного токена, все дела. :)
	// }

	return result;
}