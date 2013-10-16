/*
Eugene Auduchinok (c) 2013

Homework 1.04.01
Maximum Repeating
*/

#include <utility>
#include "heapsort.h"

void createTree(int *a, int j)
{
	while (j > 0)
	{
		if (j % 2 == 0)
		{
			if (a[j] < a[j / 2])
			{
				std::swap(a[j], a[j / 2]);
				j /= 2;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (a[j] < a[(j - 1) / 2])
			{
				std::swap(a[j], a[(j - 1) / 2]);
				j = (j - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
}
void heapsort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		createTree(a, i);
	}

	for (int i = 0; i < n - 1; i++)
	{
		std::swap(a[0], a[n - 1 - i]);

		for (int j = 1; j < n - 1 - i; j++)
		{
			createTree(a, j);
		}
	}
}