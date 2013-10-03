/*
Eugene Auduchinok (c) 2013

Homework 1.03.02
Float
*/

#include <stdio.h>
#include <stdlib.h>

int numLength(int num)
{
	int count = 0;

	if (num == 0)
	{
		return 1;
	}

	if (num < 0)
	{
		count++;
	}

	num = abs(num);

	while (num > 0)
	{
		num /= 10;
		count++;
	}

	return count;
}

void printSign(int *numPointer)
{
	if ((*numPointer >> 31) & 1)
	{
		printf("-");
	}
}

int printExponent(int *numPointer)
{
	int i = 0;
	int numInt = 0;

	for (i = 30; i > 22; i--)
	{
		numInt <<= 1;

		if ((*numPointer >> i) & 1)
		{
			numInt++;
		}
	}

	if ((*numPointer >> 31) & 1)
	{
		printf(" ");
	}

	printf(" %d\n", numInt - 127);

	return numLength(numInt - 127);
}

int hasSignificand(int *numPointer)
{
	int i = 0;

	for (i = 22; i > 0; i--)
	{
		if ((*numPointer >> i) & 1)
		{
			return 1;
		}
	}

	return 0;
}

void printSignificand(int *numPointer)
{
	int i = 0;
	int j = 0;
	int nullCounter = 0;

	printf(" * 1.");

	for (i = 22; i > 0; i--)
	{
		if ((*numPointer >> i) & 1)
		{
			for (j = 0; j < nullCounter; j++)
			{
				printf("0");
			}

			printf("1");

			nullCounter = 0;
		}
		else
		{
			nullCounter++;
		}
	}
}

void printTwo(int indentation)
{
	int i = 0;
	
	printf("2");

	for (i = 0; i < indentation; i++)
	{
		printf(" ");
	}
}

int printException(int *numPointer)
{
	int i = 0;

	int current = (*numPointer >> 30) & 1;

	for (i = 29; i > 22; i--)
	{
		if (((*numPointer >> i) & 1) != current)
		{
			return 0;
		}
	}

	if (current == 0)
	{
		printf("null\n");

		return 1;
	}
	else
	{
		for (i = 22; i > 0; i--)
		{
			if ((*numPointer >> i) & 1)
			{
				printf("nan\n");

				return 1;
			}
		}

		if ((*numPointer >> 31) & 1)
		{
			printf("-inf\n");
		}
		else
		{
			printf("inf\n");
		}

		return 1;
	}
}

int main()
{
	float num = 0;

	printf("Float\n");

	printf("num: ");
	scanf("%f", &num);

	int *numPointer = (int *) &num;
	int indentation = 0;

	if (printException(numPointer))
	{
		return 0;
	}

	indentation = printExponent(numPointer);
	printSign(numPointer);
	printTwo(indentation);
	if (hasSignificand(numPointer))
	{
		printSignificand(numPointer);
	}

	printf("\n");
}