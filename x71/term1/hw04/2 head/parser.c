/*
Eugene Auduchinok (c) 2013

Homework 1.04.02
Head
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "parser.h"

enum Mode
{	
	none,
	lines,
	bytes
};

void readLines(FILE *in, int count)
{
	int linesCount = 0;

	while (linesCount < count)
	{
		char c = fgetc(in);

		if (c == EOF)
		{
			printf("\n");
			break;
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
		char c = fgetc(in);

		if (c == EOF)
		{
			printf("\n");
			break;
		}

		fputc(c, stdout);
	}
}

void readFiles(int argc, char **argv, int curArg, enum Mode mode, int count)
{
	int i = 0;
	int filesToRead = argc - curArg;

	printf("files: %d\n", filesToRead);

	if (filesToRead == 0)
	{
		if (mode == lines)
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
			continue;
		}

		if (filesToRead > 1)
		{
			printf("==> %s <==\n", filename);
		}

		if (mode == lines)
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
	enum Mode mode = none;
	int curArg = 1;
	int count = 10;
	int haveReadFile = 0;

	while (curArg < argc)
	{
		char *arg = argv[curArg];

		if (arg[0] != '-')
		{
			if (mode == none)
			{
				mode = lines;
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
			
			if (mode == bytes)
			{
				printf("head: can't combine line and byte counts\n");
				return;
			}

			mode = lines;
			curArg++;
		}
		else
		{
			if ((arg[1] == 'n') || (arg[1] == 'c'))
			{
				if ((arg[1] == 'n' && mode == bytes) || (arg[1] == 'c' && mode == lines))
				{
					printf("head: can't combine line and byte counts\n");
					return;
				}

				mode = (arg[1] == 'n') ? lines : bytes;
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
		if (mode == none)
		{
			mode = lines;
		}

		readFiles(argc, argv, curArg, mode, count);
	}
}