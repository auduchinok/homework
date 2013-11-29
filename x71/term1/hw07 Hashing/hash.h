/*
Eugene Auduchinok (c) 2013

Hashing
*/

#ifndef hash_h
#define hash_h

struct HashTable
{
	char **table;
	int size;
	int elements;
	int words_total;
	int *count;
	int collisions;
	int find_attempts;
};
typedef struct HashTable HashTable;

HashTable *create_table(int size);
void delete_table(HashTable *t);
void add(HashTable *t, char *value, int repeats);
void add_once(HashTable *t, char *value);
void print(HashTable *t);
int find_greater_prime(int n);

#endif
