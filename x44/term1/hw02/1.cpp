/*
Eugene Auduchinok (c) 2013

Homework 1.02.01
Fibonacci nums
*/

#include <iostream>
using namespace std;

int fibRecurrent(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1 || n == 2)
	{
		return 1;
	}

	return fibRecurrent(n - 1) + fibRecurrent(n - 2);
}

int fibIterative(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}

	int prevPrev = 0;
	int prev = 1;
	int cur = 1;

	for (int i = 2; i <= n; i++)
	{
		cur = prev + prevPrev;
		prevPrev = prev;
		prev = cur;
	}

	return cur;
}

int main()
{
	cout << "Fibonacci nums." << endl;

	int n = 0; 
	cout << "n: ";
	cin >> n;

	cout << "fibRecurrent(" << n << ") = " << fibRecurrent(n) << endl;
	cout << "fibIterative(" << n << ") = " << fibIterative(n) << endl;
}