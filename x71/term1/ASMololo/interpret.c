/*
Eugene Auduchinok (c) 2013
ASMololo interpret
*/

#include <stdio.h>
#include <stdlib.h>
#include "interpret.h"

static int r[4] = {0};
static int memory[DEFAULT_MEM_SIZE];

int get_value(Operand op)
{
	switch (op.type)
	{
		case OT_CONST:
		{
			return op.value;
		}

		case OT_REG:	
		{
			return r[op.value];
		}

		case OT_MEM:
		{
			return memory[op.value];
		}

		case OT_PTR:
		{
			return memory[r[op.value]];
		}

		default:
		{
			return 0;
		}
	}
}

void mov(Operand dest, Operand src)
{
	int value = get_value(src);

	if (dest.type == OT_REG)
	{
		r[dest.value] = value;
	}

	else if (dest.type == OT_MEM)
	{
		memory[dest.value] = value;
	}

	else if (dest.type == OT_PTR)
	{
		memory[r[dest.value]] = value;
	}
}

void math(Instr_Type i_type, Operand reg, Operand op)
{
	int dest = reg.value;
	int value1 = get_value(reg);
	int value2 = get_value(op);

	switch (i_type)
	{
		case IT_ADD:
		{
			r[dest] = value1 + value2;
			break;
		}
		case IT_SUB:
		{
			r[dest] = value1 - value2;
			break;
		}
		case IT_MUL:
		{
			r[dest] = value1 * value2;
			break;
		}
		case IT_DIV:
		{
			r[dest] = value1 / value2;
			break;
		}
		case IT_MOD:
		{
			r[dest] = value1 % value2;
			break;
		}
		default:
		{
			/* do nothing */
		}
	}
}

void cond_jmp(int *ip, Instr_Type i_type, Operand reg, Operand to)
{
	int value = get_value(reg);

	if ((i_type == IT_JE && value == 0) ||
		(i_type == IT_JG && value > 0) ||
		(i_type == IT_JL && value < 0) ||
		(i_type == IT_JNE && value != 0) ||
		(i_type == IT_JNG && value <= 0) ||
		(i_type == IT_JNL && value >= 0))
	{
		*ip = to.value;
	}
	else
	{
		(*ip)++;
	}
}

int run(Instruction *program)
{

	int ip = 0; // instruction pointer

	while (program[ip].type != IT_HLT)
	{
		Instruction instr = program[ip];
		Instr_Type i_type = instr.type;

		if (i_type == IT_MOV)
		{
			mov(instr.op[0], instr.op[1]);
		}

		else if (is_math_instr_type(i_type))
		{
			math(i_type, instr.op[0], instr.op[1]);
		}

		else if (i_type == IT_JMP)
		{
			ip = instr.op[0].value;
			continue;
		}

		else if (is_cond_jmp_instr_type(i_type))
		{
			cond_jmp(&ip, i_type, instr.op[0], instr.op[1]);
			continue;
		}

		ip++;
	}

	int exit_code = get_value(program[ip].op[0]);

	return exit_code;
}
