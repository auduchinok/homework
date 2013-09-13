/*
Eugene Auduchinok (c) 2013

Homework 1.01.03
Move array
*/

#include <iostream>
using namespace std;

void mirrorArray(int *a, int l, int r)
{
	for (int i = 0; i < (r - l) / 2; i++)
	{
		int tmp = a[l + i];
		a[l + i] = a[r - i];
		a[r - i] = tmp;
	}
		
}

void printArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << endl;
}

int main()
{
	int n = 0;
	int m = 0;

	cout << "m: ";
	cin >> m;
	
	cout << "n: ";
	cin >> n;

	int *a = new int [n + m];
	for (int i = 0; i < n + m; i++)
		a[i] = i + 1;

	printArray(a, n + m);

	mirrorArray(a, 0, m - 1);
	mirrorArray(a, m, n - 1);
	mirrorArray(a, 0, m + n - 1);

	printArray(a, m + n);

	delete[] a;
}