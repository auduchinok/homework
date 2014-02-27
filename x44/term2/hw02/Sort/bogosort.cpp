#include <cstdlib>
#include <utility>
#include "bogosort.h"

bool BogoSort::isSorted(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            return false;
        }
    }

    return true;
}

void BogoSort::sort(int *a, int n)
{
    while (!isSorted(a, n))
    {
        for (int i = 0; i < n; i++)
        {
            std::swap(a[i], a[rand() % n]);
        }
    }
}
