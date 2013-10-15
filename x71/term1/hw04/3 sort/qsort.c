/*
Eugene Auduchinok (c) 2013

Homework 1.04.03
Sort
*/

#include <ctype.h>
#include "qsort.h"
#include "sort.h"

int strcmpModes(char* s1, char* s2, Mode mode)
{
	int i = 0;
	int j = 0;

	if (mode == IGNOREBLANKS || mode == IGNOREBOTH)
	{
		while (isblank(s1[i]))
		{
			i++;
		}

		while(isblank(s2[j]))
		{
			j++;
		}
	}

	if (mode == IGNORECASE || mode == IGNOREBOTH)
	{
		while (s1[i] != 0 && s2[j] != 0)
		{
			if (tolower(s1[i]) != tolower(s2[j]))
			{
				break;
			}

			i++;
			j++;
		}

		if (tolower(s1[i]) == tolower(s2[j]))
		{
			return 0;
		}

		return (tolower(s1[i]) > tolower(s2[j])) ? 1 : -1;
	}
	else
	{
		while (s1[i] != 0 && s2[j] != 0)
		{
			if (s1[i] != s2[j])
			{
				break;
			}

			i++;
			j++;
		}

		if (s1[i] == s2[j])
		{
			return 0;
		}

		return (s1[i] > s2[j]) ? 1 : -1;
	}
}

void qsortRecursive(char **a, int n, int low, int high, Mode mode)
{
	int l = low;
	int r = high;

	char *m = a[l + (r - l) / 2];

	while (l <= r)
	{
		while (strcmpModes(a[l], m, mode) < 0)
		{
			l++;
		}

		while (strcmpModes(a[r], m, mode) > 0)
		{
			r--;
		}

		if (l <= r)
		{
			char *tmp = a[l];
			a[l] = a[r];
			a[r] = tmp;
			
			l++;
			r--;
		}
	}

	if (r > low)
	{
		qsortRecursive(a, n, low, r, mode);
	}

	if (l < high)
	{
		qsortRecursive(a, n, l, high, mode);
	}
}

void qSort(SortedArray *a, Mode mode)
{
    qsortRecursive(a->data, a->lines, 0, a->lines - 1, mode);
}
