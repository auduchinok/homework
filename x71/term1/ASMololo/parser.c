/*
Eugene Auduchinok (c) 2013
ASMololo interpret
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "hash.h"
#include "linker.h"

Operand_Type get_math_operand_type(char *op)
{
	switch (op[0])
	{
		case 'r':
		{
			return OT_REG;
			break;
		}
		case '[':
		{
			return (op[1] == 'r') ? OT_PTR : OT_MEM;
			break;
		}
		default:
		{
			return OT_CONST;
		}
	}
}

Operand get_math_operand(char *op)
{
	Operand result;

	result.type = get_math_operand_type(op);

	if (result.type != OT_CONST)
	{
		op = (result.type == OT_PTR) ? &op[2] : &op[1];
	}

	result.value = atoi(op);

	return result;
}

Operand get_label_operand(char *op)
{
	Operand result;

	result.type = OT_LABEL;
	result.label = (char *) malloc(sizeof(char) * LABEL_SIZE);
	strcpy(result.label, op);
	
	return result;
}

void to_lower(char *str)
{
	int i = 0;
	int str_length = strlen(str);

	for (i = 0; i < str_length; i++)
	{
		str[i] = tolower(str[i]);
	}
}

Instruction *parse(char *filename)
{
	const int DEFAULT_SIZE = 8;

	int size = DEFAULT_SIZE;
	Instruction *program = (Instruction *) malloc(sizeof(Instruction) * size);
	int count = 0;

	Hash_Table *labels = create_table();

	FILE *in = fopen(filename, "r");
	if (in == NULL)
	{
		printf("asmo: %s: no such file or folder.\n", filename);
		return NULL;
	}

	while (!feof(in))
	{
		char line[LINE_SIZE] = {'\0'};
		fgets(line, LINE_SIZE, in);

		char *label = strtok(line, " \t\n");
		to_lower(label);

		char *instr = NULL;

		if (label[strlen(label) - 1] == ':')
		{
			label[strlen(label) - 1] = '\0';
			Label to_add;

			to_add.name = (char *) malloc(sizeof(char) * LABEL_SIZE);
			strcpy(to_add.name, label);

			to_add.instr_num = count;

			hash_add(labels, to_add);

			instr = strtok(NULL, " \t\n");
			to_lower(instr);
		}
		else
		{
			instr = label;
		}

		program[count].type = get_instr_type(instr);

		char *op = strtok(NULL, " \t\n");
		
		if (program[count].type == IT_JMP)
		{
			program[count].op[0] = get_label_operand(op);
			program[count].op[1].type = OT_NONE;
		}
		else
		{
			program[count].op[0] = get_math_operand(op);

			if (program[count].type == IT_HLT)
			{
				count++;
				continue;
			}

			op = strtok(NULL, " \t\n");

			if (is_cond_jmp_instr_type(program[count].type))
			{
				program[count].op[1] = get_label_operand(op);
			}
			else
			{
				program[count].op[1] = get_math_operand(op);
			}
		}

		count++;

		if (count == size)
		{
			size *= 2;
			program = (Instruction *) realloc(program, sizeof(Instruction) * size);
		}
	}

	program = link(program, count, labels);

	return program;
}