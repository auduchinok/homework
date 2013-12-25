/*
Eugene Auduchinok (c) 2013
ASMololo interpret
*/

#ifndef _HASH_H_
#define _HASH_H_

#include "label.h"

#define DEFAULT_TABLE_SIZE 7

typedef struct Hash_Table
{
	Label *table;
	int size;
	int elements;
} Hash_Table;

Hash_Table *create_table();
void delete_table(Hash_Table *t);
void hash_add(Hash_Table *t, Label to_add);
int get_instr_num(Hash_Table *t, char *name);

#endif