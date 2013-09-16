/*
Eugene Auduchinok (c) 2013

Homework 1.02.03
Partitions
*/

#include <iostream>
using namespace std;

void cleanNextNums(int *a, const int n, const int beg)
{
	for (int i = beg; i < n; i++)
	{
		if (a[i] == 0)
			return;

		a[i] = 0;
	}
}

void printPartitions(int *a, const int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			cout << endl;
			return;
		}

		cout << a[i] << " ";
	}

	cout << endl;
}

void createPartitions(int *a, const int n, const int left, const int place)
{
	if (place == 0)
	{
		a[place] = n;
	}
	else
	{
		a[place] = min(a[place - 1], left);
	}

	while (a[place] > 0)
	{
		if (left - a[place] == 0)
		{
			printPartitions(a, n);
		}
		else
		{
			createPartitions(a, n, left - a[place], place + 1);
		}

		a[place]--;
	}
}

int main()
{
	cout << "Partitions." << endl;

	int n = 0;

	while (n < 1)
	{
		cout << "n: ";
		cin >> n;
	} 

	int *partitions = new int[n];
	for (int i = 0; i < n; i++)
	{
		partitions[i] = 0;
	}

	createPartitions(partitions, n, n, 0);

	delete[] partitions;
}