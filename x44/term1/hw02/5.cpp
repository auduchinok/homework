/*
Eugene Auduchinok (c) 2013

Homework 1.02.05
Heapsort
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
}

void createTree(int *a, int j)
{
	while (j > 0)
	{
		if (j % 2 == 0)
		{
			if (a[j] > a[j / 2])
			{
				swap(a[j], a[j / 2]);
				j /= 2;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (a[j] > a[(j - 1) / 2])
			{
				swap(a[j], a[(j - 1) / 2]);
				j = (j - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
}
void heapsort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		createTree(a, i);
	}

	for (int i = 0; i < n - 1; i++)
	{
		swap(a[0], a[n - 1 - i]);

		for (int j = 1; j < n - 1 - i; j++)
		{
			createTree(a, j);
		}
	}
}

int main()
{
	cout << "Heapsort" << endl;

	srand(time(NULL));

	int n = 0;
	cout << "n: ";
	cin >> n;

	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}

	printArray(a, n);

	heapsort(a, n);

	printArray(a, n);

	delete[] a;
}