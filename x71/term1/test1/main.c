#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int *readPolynomial(int *polySize)
{
	printf("Read:\n");

	int i = 0;
	int memSize = 8;
	
	int *result = (int *) malloc(sizeof(int) * memSize);
	for (i = 0; i < memSize; i++)
	{
		result[i] = 0;
	}

	int ch = 0;

	while (ch != '\n')
	{
		int numLen = 0;
		char num[10];
		for (i = 0; i < 10; i++)
		{
			num[i] = 0;
		}

		ch = getchar();

		do
		{
			num[numLen] = ch;
			numLen++;

			ch = getchar();

		} while (!isspace(ch));

		result[*polySize] = atoi(num);

		*polySize = *polySize + 1;

		if (*polySize == memSize)
		{
			result = (int *) realloc(result, sizeof(int) * memSize * 2);

			if (result == NULL)
			{
				printf("Can't allocate memory.\n");
				return NULL;
			}

			for (i = *polySize; i < memSize; i++)
			{
				result[i] = 0;
			}
		}
	}

	return result;
}

void printPolynomial(int *a, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

void sum(int *polyA, int polyASize, int *polyB, int polyBSize);
{
	int polyCSize = (polyASize > polyBSize) ? (polyASize + 1) : (polyBSize + 1);
	int *polyC = (int *) malloc(sizeof(int) * polyCSize);
	for (i = 0; i < polyCSize; i++)
	{
		polyC[i] = 0;
	}

	

	free(polyC);
}

int main()
{
	int i = 0;
	int polyASize = 0;
	int *polyA = readPolynomial(&polyASize);

	int polyBSize = 0;
	int *polyB = readPolynomial(&polyBSize);

	int op = getchar();

	if (op == '+')
	{
		sum(polyA, polyASize, polyB, polyBSize);
	}

	free(polyA);
	free(polyB);
}