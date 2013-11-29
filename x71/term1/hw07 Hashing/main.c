/*
Eugene Auduchinok (c) 2013

Hashing
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "hash.h"
#include "sortedarray.h"

static const int DEFAULT_TOP = 100;

int is_suitable(char ch)
{
	if (isalpha(ch) || isdigit(ch))
	{
		return 1;
	}

	return (ch == '\'' || ch == '-');
}

char *clean_word(char *word)
{
	int i = 0;
	char *result = (char *) malloc(sizeof(char) * MAX_WORD_LENGTH);
	int res_len = 0;

	for (i = 0; word[i] != '\0'; i++)
	{
		if (is_suitable(word[i]))
		{
			result[res_len] = tolower(word[i]);
			res_len++;
		}

		result[res_len] = '\0';
	}

	free(word);

	return result;
}

int main(int argc, char **argv)
{
	printf("Words chart (hashing task)\n");

	FILE *in = fopen(argv[1], "r");

	if (!in)
	{
		printf("Can't open the file. Exiting.\n");
		return 1;
	}
	
	fseek(in, 0, SEEK_END);
	int fileLength = ftell(in);
	fseek(in, 0, SEEK_SET);

	int tableSize = find_greater_prime(fileLength / 100);
	HashTable *table = create_table(tableSize);

	while (!feof(in))
	{
		char *word = (char *) malloc(sizeof(char) * MAX_WORD_LENGTH);
		fscanf(in, "%s", word);

		word = clean_word(word);
		add_once(table, word);
	}

	fclose(in);

	SortedArray *sorted = create_from_table(table);

	printf("\nFile Length: %d\n", fileLength);
	printf("Words total: %d\n", table->words_total);
	printf("Collisions: %d\n", table->collisions);
	printf("Find attempts: %d\n", table->find_attempts);

	int top = (argc > 2) ? atoi(argv[2]) : DEFAULT_TOP;
	print_top(sorted, top);

	delete_table(table);
	delete_array(sorted);
}
