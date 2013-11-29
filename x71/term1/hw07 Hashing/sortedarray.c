/*
Eugene Auduchinok (c) 2013

Hashing
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedarray.h"

void swap_int(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void swap_ptr(char **a, char **b)
{
	char *c = *a;
	*a = *b;
	*b = c;
}

void qsortRecursive(int *count, char **words, int low, int high)
{
	int l = low;
	int r = high;

	int m = count[l + (r - l) / 2];

	while (l <= r)
	{
		while (count[l] > m)
		{
			l++;
		}

		while (count[r] < m)
		{
			r--;
		}

		if (l <= r)
		{
			swap_int(&count[l], &count[r]);
			swap_ptr(&words[l], &words[r]);

			l++;
			r--;
		}
	}

	if (r > low)
	{
		qsortRecursive(count, words, low, r);
	}

	if (l < high)
	{
		qsortRecursive(count, words, l, high);
	}
}

void sort_array(SortedArray *a)
{
	qsortRecursive(a->count, a->words, 0, a->size - 1);
}

SortedArray *create_from_table(HashTable *t)
{
	SortedArray *result = (SortedArray *) malloc(sizeof(SortedArray));

	int size = t->size;

	result->size = size;
	result->words_total = t->elements;
	result->words = (char **) malloc(sizeof(char *) * size);
	result->count = (int *) malloc(sizeof(int) * size);

	memset(result->words, 0, sizeof(char *) * size);
	memcpy(result->count, t->count, sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		if (t->count[i])
		{
			result->words[i] = (char *) malloc(sizeof(char) * MAX_WORD_LENGTH);
			strcpy(result->words[i], t->table[i]);	
		}
	}
	sort_array(result);

	return result;
}

void print_top(SortedArray *a, int top)
{
	printf("Table size: %d\n", a->size);
	printf("Different words: %d\n\n", a->words_total);

	int limit = (top == 0 || top > a->size) ? a->size : top;

	if (top != 0)
	{
		printf("TOP-%d\n", limit);
	}
	else
	{
		printf("All words:\n");
	}

	for (int i = 0; i < limit; i++)
	{
		if (a->count[i] == 0)
		{
			return;
		}

		printf("%d: (%d) ", i + 1, a->count[i]);
		if (a->count[i])
		{
			printf("%s", a->words[i]);
		}

		printf("\n");
	}
}

void delete_array(SortedArray *a)
{
	int i = 0;

	for (i = 0; i < a->size; i++)
	{
		free(a->words[i]);
	}

	free(a->words);
	free(a->count);
}
