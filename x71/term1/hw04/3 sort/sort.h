/*
Eugene Auduchinok (c) 2013

Homework 1.04.03
Sort
*/

#ifndef sort_h
#define sort_h

enum Mode
{
	NONE,
	IGNOREBLANKS,
	IGNORECASE,
	IGNOREBOTH,
	ERROR
};
typedef enum Mode Mode;

struct SortedArray
{
	int linesAllocated;
	char **data;
	int lines;
};
typedef struct SortedArray SortedArray;

SortedArray createSortedArray(char **argv, int filesToRead, int firstFileNum, Mode mode);
void printArray(SortedArray a);
void deleteArray(SortedArray array);

#endif