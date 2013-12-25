/*
Eugene Auduchinok (c) 2013
ASMololo interpret
*/

#include <string.h>
#include "instruction.h"

bool is_cond_jmp_instr_type(Instr_Type i_type)
{
	return i_type == IT_JE || i_type == IT_JNE || i_type == IT_JG ||
		i_type == IT_JNG || i_type == IT_JL || i_type == IT_JNL;
}

bool is_math_instr_type(Instr_Type i_type)
{
	return i_type == IT_ADD || i_type == IT_SUB || i_type == IT_MUL ||
		i_type == IT_DIV || i_type == IT_MOD;
}

Instr_Type get_instr_type(char *instr)
{
	// тут сделать бы сравнение после проверки хеша

	if (!strcmp(instr, "add"))
	{
		return IT_ADD;
	}
	if (!strcmp(instr, "sub") || !strcmp(instr, "cmp"))
	{
		return IT_SUB;
	}
	if (!strcmp(instr, "mul"))
	{
		return IT_MUL;
	}
	if (!strcmp(instr, "div"))
	{
		return IT_DIV;
	}
	if (!strcmp(instr, "mod"))
	{
		return IT_MOD;
	}
	if (!strcmp(instr, "hlt"))
	{
		return IT_HLT;
	}
	if (!strcmp(instr, "jmp"))
	{
		return IT_JMP;
	}
	if (!strcmp(instr, "je"))
	{
		return IT_JE;
	}
	if (!strcmp(instr, "jne"))
	{
		return IT_JNE;
	}
	if (!strcmp(instr, "jg"))
	{
		return IT_JG;
	}
	if (!strcmp(instr, "jng"))
	{
		return IT_JNG;
	}
	if (!strcmp(instr, "jl"))
	{
		return IT_JL;
	}
	if (!strcmp(instr, "jnl"))
	{
		return IT_JNL;
	}

	return 0;
}