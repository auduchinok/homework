/* Eugene Auduchinok, 2014
 * hw144-2.2.3 Matrix Sorter */

#pragma once

template <typename T>
class MatrixSorter
{
public:
    MatrixSorter() : a(nullptr) {}

    void sort(T **matrix, int length, int height)
    {
        a = matrix;
        matrixHeight = height;

        qsort(0, length - 1);

        a = nullptr;
        matrixHeight= 0;
    }

private:
    T **a;  // matrix array
    int matrixHeight;

    void qsort(int low, int high)
    {
        int l = low;
        int r = high;

        T m = a[0][l + (r - l) / 2];

        while (l <= r)
        {
            while (a[0][l] < m)
            {
                l++;
            }

            while (a[0][r] > m)
            {
                r--;
            }

            if (l <= r)
            {
                swapColumns(l, r);

                l++;
                r--;
            }
        }

        if (r > low)
        {
            qsort(low, r);
        }

        if (l < high)
        {
            qsort(l, high);
        }

    }

    void swapColumns(int columnA, int columnB)
    {
        for (int i = 0; i < matrixHeight; i++)
        {
            T tmp = a[i][columnA];
            a[i][columnA] = a[i][columnB];
            a[i][columnB] = tmp;
        }
    }
};
