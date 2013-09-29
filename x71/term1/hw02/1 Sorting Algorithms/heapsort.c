/*
Eugene Auduchinok (c) 2013

Heapsort
*/

#include "heapsort.h"
#include "util.h"

void createTree(int *a, int j)
{
	while (j > 0)
	{
		if (j % 2 == 0)
		{
			if (a[j] > a[j / 2])
			{
				swap(&a[j], &a[j / 2]);
				j /= 2;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (a[j] > a[(j - 1) / 2])
			{
				swap(&a[j], &a[(j - 1) / 2]);
				j = (j - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
}

void heapSort(int *a, int n)
{
	int i = 0;
	int j = 0;

	for (i = 1; i < n; i++)
	{
		createTree(a, i);
	}

	for (i = 0; i < n - 1; i++)
	{
		swap(&a[0], &a[n - 1 - i]);

		for (j = 1; j < n - 1 - i; j++)
		{
			createTree(a, j);
		}
	}
}