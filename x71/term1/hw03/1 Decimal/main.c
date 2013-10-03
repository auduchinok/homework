/*
Eugene Auduchinok (c) 2013

Homework 1.03.01
Decimal
*/

#include <stdio.h>
#include <stdlib.h>

void printNum(int num)
{
	int i;
	int started = 0;

	for (i = 31; i >= 0; i--)
	{
		if ((num >> i) & 1)
		{
			started = 1;

			printf("1");
		}
		else
		{
			if (started)
			{
				printf("0");
			}
		}
	}

	printf("\n");
}

int main()
{
	int num = 0;

	printf("Decimal\n");

	printf("num: ");
	scanf("%d", &num);

	printNum(num);
}