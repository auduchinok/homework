/*
Eugene Auduchinok (c) 2013
ASMololo interpret
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hash.h"

Hash_Table *create_table()
{
	int i = 0;
	int size = DEFAULT_TABLE_SIZE;
	Hash_Table *result = (Hash_Table *) malloc(sizeof(Hash_Table));

	result->table = (Label *) malloc(sizeof(Label) * size);
	
	for (i = 0; i < size; i++)
	{
		result->table[i].name = NULL;
	}

	result->size = size;
	result->elements = 0;

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

void delete_table(Hash_Table *t)
{
	int i = 0;
	int t_size = t->size;
	Label *table = t->table;

	for (i = 0; i < t_size; i++)
	{
		if (table[i].name != NULL)
		{
			free(table[i].name);
		}	
	}

	free(t->table);
}

void enlarge_table(Hash_Table *t)
{
	int i = 0;
	int new_size = find_greater_prime(t->size);

	Label *old_table = t->table;
	int old_size = t->size;

	t->table = (Label *) malloc(sizeof(Label) * new_size);

	for (i = 0; i < new_size; i++)
	{
		t->table[i].name = NULL;
	}

	t->size = new_size;
	t->elements = 0;

	for (i = 0; i < old_size; i++)
	{
		if (old_table[i].name != NULL)
		{
			hash_add(t, old_table[i]);
		}
	}

	free(old_table);
}

int hashf(char *value, int size)
{
	int i = 0;
	int result = 0;
	int str_length = strlen(value);

	const int BASE = 107;
	int base_pow = 1;
	for (i = 0; i < str_length; i++)
	{
		base_pow = (base_pow * BASE) % size;
		result = (result + value[i] * base_pow) % size;
	}

	return result;
}

int find_place(Hash_Table *t, char *name)
{
	int size = t->size;
	Label *table = t->table;

	int key = hashf(name, size); 

	if (table[key].name != NULL && strcmp(table[key].name, name))
	{
		int step = hashf(name, size - 1) + 1;
		int probe = (key + step) % size;

		while (table[probe].name != NULL)
		{
			if (!strcmp(table[probe].name, name))
			{
				break;
			}

			probe = (probe + step) % size;
		}

		key = probe;
	}

	return key;
}

void hash_add(Hash_Table *t, Label to_add)
{
	int size = t->size;
	Label *table = t->table;

	int key = find_place(t, to_add.name);

	if (table[key].name == NULL)
	{
		table[key] = to_add;
	}
	else
	{
		free(to_add.name);
	}
	
	if (t->elements >= 0.8 * size)
	{
		enlarge_table(t);
	}
}

int get_instr_num(Hash_Table *t, char *name)
{
	int key = find_place(t, name);

	if (t->table[key].name == NULL)
	{
		return -1;
	}

	return t->table[key].instr_num;
}