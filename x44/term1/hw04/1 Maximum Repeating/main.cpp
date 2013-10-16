/*
Eugene Auduchinok (c) 2013

Homework 1.04.01
Maximum Repeating
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "heapsort.h"
using namespace std;

void findMaxRepeating(int *a, int n)
{
	heapsort(a, n);

	int i = 0;

	while (i < n - 1 && a[i] != a[i + 1])
	{
		i++;
	}

	if (i < n - 1)
	{
		cout << a[i] << endl;
	}
	else
	{
		cout << "No such element." << endl;
	}
}

int main()
{
	srand(time(NULL));

	int n = 0;
	cout << "n: ";
	cin >> n;

	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}

	findMaxRepeating(a, n);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	delete[] a;
}