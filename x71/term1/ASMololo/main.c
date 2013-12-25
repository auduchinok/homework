/*
Eugene Auduchinok (c) 2013
ASMololo interpret
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "interpret.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("asmo: no file is specified.\n");
		printf("usage: asmo file_name\n");
		return 1;
	}

	Instruction *program = parse(argv[1]);
	if (program == NULL)
	{
		return 2;
	}

	char *program_name = strtok(argv[1], ".");

	int result = run(program);
	printf("asmo: %s exited with %d code.\n", program_name, result);

	return 0;
}