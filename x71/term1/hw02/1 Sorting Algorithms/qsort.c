/*
Eugene Auduchinok (c) 2013

QuickSort
*/

#include "qsort.h"
#include "util.h"

void qsortRecursive(int *a, int n, int low, int high)
{
	int l = low;
	int r = high;

	int m = a[l + (r - l) / 2];

	while (l <= r)
	{
		while (a[l] < m)
		{
			l++;
		}

		while (a[r] > m)
		{
			r--;
		}

		if (l <= r)
		{
			swap(&a[l], &a[r]);
			l++;
			r--;
		}
	}

	if (r > low)
	{
		qsortRecursive(a, n, low, r);
	}

	if (l < high)
	{
		qsortRecursive(a, n, l, high);
	}
}

void qSort(int *a, int n)
{
    qsortRecursive(a, n, 0, n - 1);
}