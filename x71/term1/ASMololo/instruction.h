/*
Eugene Auduchinok (c) 2013
ASMololo interpret
*/

#ifndef _INSTR_H_
#define _INSTR_H_

#include "bool.h"

typedef enum Instr_Type
{	
	// move
	IT_MOV = 0,

	// math
	IT_ADD = 1,
	IT_SUB = 2, // & cmp
	IT_MUL = 3,
	IT_DIV = 4,
	IT_MOD = 5,

	// jump
	IT_JMP = 6,

	// cond jump
	IT_JE = 7,
	IT_JNE = 8,
	IT_JG = 9,
	IT_JNG = 10,
	IT_JL = 11,
	IT_JNL = 12,

	// halt
	IT_HLT = 13
} Instr_Type;

typedef enum Operand_Type
{
	OT_NONE = 0,
	OT_CONST = 1,
	OT_REG = 2,
	OT_MEM = 3,
	OT_PTR = 4,
	OT_LABEL = 5,
	OT_INSTR_NUM = 6
} Operand_Type;

typedef struct Operand
{
	Operand_Type type;
	union
	{
		int value;
		char *label;
	};
} Operand;

typedef struct Instruction
{
	Instr_Type type;
	Operand op[2];
} Instruction;

#define LINE_SIZE 128
#define INSTR_SIZE 5

bool is_cond_jmp_instr_type(Instr_Type i_type);
bool is_math_instr_type(Instr_Type i_type);
Instr_Type get_instr_type(char *instr);

#endif