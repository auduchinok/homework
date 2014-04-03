/* Eugene Auduchinok, 2014
 * hw144-2.2.3 Matrix Sorter */

#include <QTextStream>
#include "matrixsorter.h"

void print(int **a, int length, int height)
{
    QTextStream out(stdout);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            out << a[i][j] << " ";
        }

        out << endl;
    }
}

int main()
{
    QTextStream out(stdout);
    out << "hw2.2.3 Matrix Sorter" << endl;

    int **a = new int*[3];
    for (int i = 0; i < 3; i++)
    {
        a[i] = new int[3];
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = i * 3 + j + 1;
        }
    }
    a[0][0] = 2;
    a[0][1] = 1;

    print(a, 3, 3);

    out << endl;

    MatrixSorter<int> sorter;
    sorter.sort(a, 3, 3);

    print(a, 3, 3);
}
