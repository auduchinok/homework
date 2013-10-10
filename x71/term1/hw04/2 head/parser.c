/*
Eugene Auduchinok (c) 2013

Homework 1.04.02
Head
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

enum Mode
{	
	NONE,
	LINES,
	BYTES
};

typedef enum Mode Mode;

void readLines(FILE *in, int count)
{
	int linesCount = 0;

	while (linesCount < count)
	{
		int c = fgetc(in);
		
		if (feof(in))
		{
			return;
		}

		if (c == '\n')
		{
			linesCount++;
		}

		fputc(c, stdout);
	}
}

void readBytes(FILE *in, int count)
{
	int i = 0;

	for (i = 0; i < count; i++)
	{
		if (feof(in))
		{
			return;
		}

		int c = fgetc(in);

		fputc(c, stdout);
	}
}

// mode: LINES/BYTES, count: number to read
void readFiles(int argc, char **argv, int curArg, Mode mode, int count)
{
	int i = 0;
	int filesToRead = argc - curArg;

	if (filesToRead == 0)
	{
		if (mode == LINES)
		{
			readLines(stdin, count);
		}
		else
		{
			readBytes(stdin, count);
		}

		return;
	}

	for (i = 0; i < filesToRead; i++)
	{
		char *filename = argv[curArg];

		FILE *in = fopen(filename, "r");
		if (in == NULL)
		{
			printf("head: %s: No such file or directory\n", filename);
			curArg++;
			continue;
		}

		if (filesToRead > 1)
		{
			printf("==> %s <==\n", filename);
		}

		if (mode == LINES)
		{
			readLines(in, count);
		}
		else
		{
			readBytes(in, count);
		}

		fclose(in);
		curArg++;
	}
}

void parseNum(char *num, int *count)
{
	int i = 0;

	for (i = 0; num[i] != 0; i++)
	{
		if (!isdigit(num[i]))
		{
			printf("head: illegal line count -- %s\n", num);
			count = 0;
			return;
		}
	}

	*count = atoi(num);
}

void parseArguments(int argc, char **argv)
{
	Mode mode = NONE;
	int curArg = 1;
	int count = 10;
	int haveReadFile = 0;

	while (curArg < argc)
	{
		char *arg = argv[curArg];

		if (arg[0] != '-')
		{
			if (mode == NONE)
			{
				mode = LINES;
			}

			readFiles(argc, argv, curArg, mode, count);
			return;
		}

		if (isdigit(arg[1]))
		{
			parseNum(&arg[1], &count);
			if (count == 0)
			{
				return;
			}
			
			if (mode == BYTES)
			{
				printf("head: can't combine line and byte counts\n");
				return;
			}

			mode = LINES;
			curArg++;
		}
		else
		{
			if (!strcmp(&arg[1], "n") || !strcmp(&arg[1], "c"))
			{
				if ((arg[1] == 'n' && mode == BYTES) || (arg[1] == 'c' && mode == LINES))
				{
					printf("head: can't combine line and byte counts\n");
					return;
				}

				mode = (arg[1] == 'n') ? LINES : BYTES;
				curArg++;

				arg = argv[curArg];

				if (argc == curArg)
				{
					printf("head: option requires an argument -- %c\n", argv[curArg - 1][1]);
					printf("usage: head [-n lines | -c bytes] [file ...]\n");
					return;
				}

				parseNum(arg, &count);
				curArg++;
				if (count == 0)
				{
					return;
				}
			}
			else
			{
				printf("head: illegal option -- %s\n", arg);
				printf("usage: head [-n lines | -c bytes] [file ...]\n");
				return;
			}
		}
	}

	if (!haveReadFile)
	{	
		if (mode == NONE)
		{
			mode = LINES;
		}

		readFiles(argc, argv, curArg, mode, count);
	}
}