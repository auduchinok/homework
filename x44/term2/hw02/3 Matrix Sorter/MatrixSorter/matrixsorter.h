/* Eugene Auduchinok, 2014
 * hw144-2.2.3 Matrix Sorter */

#pragma once

template <typename T>
class MatrixSorter
{
public:
    MatrixSorter() {}

    void sort(T **matrix, int length, int height)
    {
        qsort(matrix, 0, length - 1, height);
    }

private:
    void qsort(T **a, int low, int high, int height)
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
                swapColumns(a, l, r, height);

                l++;
                r--;
            }
        }

        if (r > low)
        {
            qsort(a, low, r, height);
        }

        if (l < high)
        {
            qsort(a, l, high, height);
        }

    }

    void swapColumns(int **a, int columnA, int columnB, int height)
    {
        for (int i = 0; i < height; i++)
        {
            T tmp = a[i][columnA];
            a[i][columnA] = a[i][columnB];
            a[i][columnB] = tmp;
        }
    }
};
