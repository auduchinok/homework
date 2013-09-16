/*
Eugene Auduchinok (c) 2013

Homework 1.02.04
Stern-Brokot Tree
*/

#include <iostream>
using namespace std;

void sternBrokotTree(int n, int a, int b, int c, int d)
{
	if (b + d > n)
		return;

	sternBrokotTree(n, a, b, a + c, b + d);

	cout << a + c << "/" << b + d << " ";

	sternBrokotTree(n, a + c, b + d, c, d);
}

int main()
{
	cout << "Stern-Brokot Tree" << endl;

	int n = 0;
	cout << "n: ";
	cin >> n;

	sternBrokotTree(n, 0, 1, 1, 1);

	cout << endl;
}