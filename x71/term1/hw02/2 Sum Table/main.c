/* 
Eugene Auduchinok (c) 2013

Homework 1.02.02
Sum Table
*/

#include <stdio.h>
#include <stdlib.h>

void printTable(int **table, int n)
{
	int i = 0;
	int j = 0;

	FILE *out;
	out = freopen("sum.txt", "w", stdout);

	if (out == NULL)
	{
		return;
	}

	for (j = 0; j < n; j++)
	{
		printf("+-------");
	}

	fputs("+\n", out);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("|%7d", table[i][j]);
		}

		printf("|\n");

		for (j = 0; j < n; j++)
		{
			printf("+-------");
		}

		printf("+\n");
	}

}

int **createTable(int **table, int n)
{
	int i = 0;
	int j = 0;	

	for (i = 0; i < n; i++)
	{
		table[i][0] = 1;
		table[0][i] = 1;
	}

	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			table[i][j] = table[i - 1][j] + table[i][j - 1];
		}
	}

	return table;
}

int main()
{
	printf("Sum table\n");

	int i = 0;
	int n = 0;

	printf("Table size: ");
	scanf("%d", &n);

	int *data = (int *) malloc(sizeof(int) * n * n);
	int **table = (int **) malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		table[i] = &data[i * n];
	}

	createTable(table, n);

	printTable(table, n);

	free(table);
	free(data);
}