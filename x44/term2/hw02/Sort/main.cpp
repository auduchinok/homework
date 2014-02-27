#include <iostream>
#include <cstdlib>
#include "bogosort.h"
#include "quicksort.h"
using namespace std;

void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}

void testSort(Sort *s, int n)
{
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }

    print(a, n);

    s->sort(a, n);
    print(a, n);
}

int main()
{
    srand(time(NULL));

    std::cout << "QuickSort (22):\n";
    Sort *qSort = new QuickSort;
    testSort(qSort, 22);
    delete qSort;
    std::cout << std::endl;

    std::cout << "BogoSort (11):\n";
    Sort *bgsort = new BogoSort;
    testSort(bgsort, 11);
    delete bgsort;
    std::cout << std::endl;

    return 0;
}

