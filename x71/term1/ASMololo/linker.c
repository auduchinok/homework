/*
Eugene Auduchinok (c) 2013
ASMololo interpret
*/

#include <stdio.h>
#include <stdlib.h>
#include "linker.h"

Instruction *link(Instruction *program, int size, Hash_Table *labels)
{
	int i = 0;
	int label_op_num = 0;

	for (i = 0; i < size; i++)
	{
		if (program[i].type == IT_JMP)
		{
			label_op_num = 0;
		}
		else if (is_cond_jmp_instr_type(program[i].type))
		{
			label_op_num = 1;
		}
		else
		{
			continue;
		}
		
		Operand *label_op = &program[i].op[label_op_num];

		label_op->type = OT_INSTR_NUM;
		label_op->value = get_instr_num(labels, label_op->label);

		if (label_op->value == -1)
		{
			printf("asmo: at line %d: unknown label: \n", i);
			exit(5);
		}
	}

	return program;
}