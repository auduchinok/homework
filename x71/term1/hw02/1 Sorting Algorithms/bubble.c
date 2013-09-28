#include "bubble.h"
#include "util.h"

void bubbleSort(int *a, int n)
{
	int i, j;

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[i] < a[j])
			{
				swap(&a[i], &a[j]);
			}
		}
	}
}