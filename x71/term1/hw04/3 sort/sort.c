/*
Eugene Auduchinok (c) 2013

Homework 1.04.03
Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "qsort.h"

char *readLine(FILE *in)
{
	int size = 8;
	int length = 0;

	char *result = (char *) malloc(sizeof(char) * size);

	int c = 0;

	while (c != '\n')
	{
		c = getc(in);
		
		if (c == -1)
		{
			c = '\n';
		}
		
		result[length] = c;
		length++;

		if (length == size)
		{
			size *= 2;
			result = realloc(result, sizeof(char) * size);
		}
	}

	result[length] = 0;

	return result;
}

void readFile(SortedArray *result, FILE *in)
{
	int lines = result->lines;
	int linesAllocated = result->linesAllocated;

	while (!feof(in))
	{
		result->data[lines] = readLine(in);
		lines++;

		if (lines == linesAllocated)
		{
			linesAllocated *= 2;
			result->data = realloc(result->data, sizeof(char *) * linesAllocated);
		}
	}

	result->lines = lines;
	result->linesAllocated = linesAllocated;
}

// Modes: ignoreBlanks/ignoreCase
SortedArray createSortedArray(char **argv, int filesToRead, int firstFileNum, Mode mode)
{
	int i = 0;
	SortedArray result;

	result.linesAllocated = 8;
	result.data = (char **) malloc(sizeof(char *) * result.linesAllocated);
	result.lines = 0;

	if (filesToRead == 0)
	{
		readFile(&result, stdin);
	}
	else
	{	
		for (i = firstFileNum; i < filesToRead + firstFileNum; i++)
		{
			FILE *in = fopen(argv[i], "r");
			if (in == NULL)
			{
				printf("sort: open failed: %s: No such file or directory\n", argv[i]);
				continue;
			}

			readFile(&result, in);
		}
	}

	qSort(&result, mode);

	return result;
}

void printArray(SortedArray a)
{
	int i = 0;

	for (i = 0; i < a.lines; i++)
	{
		printf("%s", a.data[i]);
	}
}

void deleteArray(SortedArray array)
{
	int i = 0; 

	for (i = 0; i < array.lines; i++)
	{
		free(array.data[i]);
	}
}