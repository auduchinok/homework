#pragma once
#include "sort.h"

class BogoSort : public Sort
{
public:
    void sort(int *a, int n);
private:
    bool isSorted(int *a, int n);
};
