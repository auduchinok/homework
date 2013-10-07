/*
Eugene Auduchinok (c) 2013

Homework 1.03.02
Helix
*/

#include <iostream>
using namespace std;

void printHelix(int **a, const int size)
{
	int i = size / 2;
	int j = size / 2;

	cout << a[i][j] << " ";
	j++;

	int count = 1;
	
	for (int level = 3; count < size * size; level += 2)
	{
		for (int k = 0; k < level - 2; k++)
		{
			cout << a[i][j] << " ";
			count++;
			i--;
		}

		for (int k = 0; k < level - 1; k++)
		{
			cout << a[i][j] << " ";
			count++;
			j--;
		}

		for (int k = 0; k < level - 1; k++)
		{
			cout << a[i][j] << " ";
			count++;
			i++;
		}

		for (int k = 0; k < level; k++)
		{
			cout << a[i][j] << " ";
			count++;
			j++;
		}
	}

	cout << endl;
}

int main()
{
	int n = 0;

	cout << "n: ";
	cin >> n;

	int *data = new int[n * n];
	int **array = new int *[n];

	for (int i = 0; i < n; i++)
	{
		array[i] = &data[n * i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = i * n + j + 1;
		}
	}

	printHelix(array, n);

	delete[] array;
	delete[] data;
}