/*
Eugene Auduchinok (c) 2013

Homework 1.04.03
Sort
*/

#include <stdio.h>
#include <string.h>
#include "sort.h"

Mode parseOptions(int argc, char **argv, int *curArg)
{
	int i = 0;
	int ignoreBlanks = 0;
	int ignoreCase = 0;
	Mode mode = NONE;

	for (i = *curArg; i < argc; i++)
	{
		if (argv[i][0] != '-')
		{
			break;
		}

		if (!strcmp("-b", argv[i]))
		{
			ignoreBlanks = 1;
		}
		else if (!strcmp("-f", argv[i]))
		{
			ignoreCase = 1;
		}
		else if (!strcmp("-bf", argv[i]) || !strcmp("-fb", argv[i]))
		{
			ignoreCase = 1;
			ignoreBlanks = 1;
		}
		else
		{
			printf("sort: invalid option -- %c\n", argv[i][1]);
			mode = ERROR;
			return mode;
		}

		*curArg = *curArg + 1;
	}

	if (ignoreBlanks && ignoreCase)
	{
		return IGNOREBOTH;
	}
	else if (ignoreBlanks)
	{
		return IGNOREBLANKS;
	}
	else if (ignoreCase)
	{
		return IGNORECASE;
	}

	return mode;
}

int main(int argc, char **argv)
{
	int curArg = 1;
	Mode mode = parseOptions(argc, argv, &curArg);

	if (mode == ERROR)
	{
		return -1;
	}

	SortedArray array = createSortedArray(argv, argc - curArg, curArg, mode);
	printArray(array);

	deleteArray(array);
}