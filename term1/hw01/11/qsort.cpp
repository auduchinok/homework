#include "qsort.h"
#include <istream>

void qsortRecursive(int*& a, int& n, int low, int high)
{
    if (n < 2)
		return;
    
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
            std::swap(a[l], a[r]);
            l++;
            r--;
		}
	}
    
	if (r - low > 1)
        qsortRecursive(a, n, low, r);
    
    if (high - l > 1)
        qsortRecursive(a, n, l, high);
}

void qsort(int *a, int& n)
{
    qsortRecursive(a, n, 0, n - 1);
}