/*
Eugene Auduchinok (c) 2013

Homework 1.03.06
Insertion Sort With List
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "list.h"
using namespace std;
using namespace list;

void sort(int *a, int n)
{
	List *sorted = createList();

	for (int i = 0; i < n; i++)
	{
		add(sorted, a[i]);
	}

	sortArray(sorted, a, n);

	deleteList(sorted);
}

int main()
{
	cout << "Insertion Sort" << endl;

	srand(time(NULL));

	int n = 0;
	cout << "n: ";
	cin >> n;

	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}

	sort(a, n);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	delete[] a;
}