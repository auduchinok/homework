#include <utility>
#include "quicksort.h"

void QuickSort::sort(int *a, int n)
{
    qsort(a, 0, n - 1);
}

void QuickSort::qsort(int *a, int low, int high)
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
            std::swap(a[l], a[r]);

            l++;
            r--;
        }
    }

    if (r > low)
    {
        qsort(a, low, r);
    }

    if (l < high)
    {
        qsort(a,l, high);
    }

}
