#pragma once
#include "sort.h"

class QuickSort : public Sort
{
public:
    void sort(int *a, int n);
private:
    void qsort(int *a, int low, int high);
};
