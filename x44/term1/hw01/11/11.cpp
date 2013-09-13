/*
Eugene Auduchinok (c) 2013

Homework 1.01.11
QuickSort
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "qsort.h"
using namespace std;

void printArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
    
	cout << endl;
}

int main()
{
    srand(time(NULL));
    
    cout << "Array size: ";
    int n = 0;
    cin >> n;
    
    int *a = new int[n];
    
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;        // Да прибудет с нами магическая 
                                    // константа для теста!
	printArray(a, n);
    
	qsort(a, n);
    
	printArray(a, n);
    
    delete[] a;
}