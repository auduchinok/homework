/*
Eugene Auduchinok (c) 2013

Hashing
*/

#ifndef sortedarray_h
#define sortedarray_h

#include "hash.h"

static const int MAX_WORD_LENGTH = 64;

typedef struct SortedArray
{
	char **words;
	int *count;
	int size;
	int words_total;
} SortedArray;

SortedArray *create_from_table(HashTable *t);
void delete_array(SortedArray *a);
void print_top(SortedArray *a, int top);

#endif
