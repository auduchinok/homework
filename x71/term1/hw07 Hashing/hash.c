/*
Eugene Auduchinok (c) 2013

Hashing
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hash.h"

HashTable *create_table(int size)
{
	int i = 0;
	HashTable *result = (HashTable *) malloc(sizeof(HashTable));

	result->table = (char **) malloc(sizeof(char *) * size);
	result->count = (int *) malloc(sizeof(int) * size);
	
	for (i = 0; i < size; i++)
	{
		result->table[i] = NULL;
		result->count[i] = 0;
	}

	result->size = size;
	result->elements = 0;
	result->collisions = 0;
	result->words_total = 0;
	result->find_attempts = 0;

	return result;
}

int is_prime(int n)
{
	int i = 0;
	int sqrtN = sqrt(n);

	for (i = 2; i <= sqrtN; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

int find_greater_prime(int n)
{
	int result = n * 2 + 1;

	while (!is_prime(result))
	{
		result += 2;
	}

	return result;
}

void enlarge_table(HashTable *t)
{
	int i = 0;
	int new_size = find_greater_prime(t->size);

	char **old_table = t->table;
	int *old_count = t->count;
	int old_size = t->size;

	t->table = (char **) malloc(sizeof(char *) * new_size);
	t->count = (int *) malloc(sizeof(int) * new_size);

	for (i = 0; i < new_size; i++)
	{
		t->table[i] = NULL;
		t->count[i] = 0;
	}

	t->size = new_size;
	t->elements = 0;

	for (i = 0; i < old_size; i++)
	{
		if (old_table[i])
		{
			add(t, old_table[i], old_count[i]);
		}
	}

	free(old_table);
	free(old_count);
}

int hashf(char *value, int size)
{
	int result = 0;
	int str_length = strlen(value);

	const int BASE = 107;
	int base_pow = 1;
	for (int i = 0; i < str_length; i++)
	{
		base_pow = (base_pow * BASE) % size;
		result = (result + value[i] * base_pow) % size;
	}

	return result;
}

void add(HashTable *t, char *value, int repeats)
{
	int size = t->size;
	char **table = t->table;

	int key = hashf(value, size); 

	if (table[key] != NULL && strcmp(table[key], value))
	{
		int step = hashf(value, size - 1) + 1;
		int probe = (key + step) % size;
		t->find_attempts++;

		while (table[probe] != NULL)
		{
			if (!strcmp(table[probe], value))
			{
				break;
			}

			probe = (probe + step) % size;
			t->find_attempts++;
		}

		key = probe;

		t->collisions++;
	}

	if (table[key] == NULL)
	{
		table[key] = value;
		t->elements++;
	}
	else
	{
		free(value);
	}
	
	t->count[key] += repeats;
	t->words_total += repeats;

	if (t->elements >= 0.8 * size)
	{
		enlarge_table(t);
	}
}

void add_once(HashTable *t, char *value)
{
	// Add with no repeating.
	add(t, value, 1);
}

void delete_table(HashTable *t)
{
	for (int i = 0; i < t->size; i++)
	{
		free(t->table[i]);
	}

	free(t->table);
	free(t->count);
}

void print(HashTable *t)
{
	printf("size: %d\n", t->size);
	printf("elements: %d\n", t->elements);
	printf("collisions: %d\n", t->collisions);

	for (int i = 0; i < t->size; i++)
	{
		printf("%d: (%d)", i, t->count[i]);
		if (t->count[i])
		{
			printf("%s", t->table[i]);
		}

		printf("\n");
	}
}
