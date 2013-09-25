/*
Eugene Auduchinok (c) 2013

Homework 1.02.06
Polynomial
*/

#include <iostream>
#include <cmath>
using namespace std;

int numLength(long long int num)
{
	num = abs(num);

	int count = 0;

	while (num > 0)
	{
		num /= 10;
		count++;
	}

	return count;
}

void printUpperLine(int *a, const int n)
{
	// First digit sign
	if (a[0] < 0)
	{
		cout << " ";
	}

	if (abs(a[0]) != 1)
	{
		for (int i = 0; i < numLength(a[0]); i++)
		{
			cout << " ";
		}
	}

	cout << " " << n - 1;

	for (int i = 1; i < n - 2; i++)
	{	
		//sign & x
		cout << "  ";

		//coeff
		if (abs(a[i]) != 1)
		{
			int coeffLength = numLength(a[i]);

			for (int j = 0; j < coeffLength; j++)
			{
				cout << " ";
			}
		}

		//pow
		cout << n - i - 1;
	}

	cout << endl;
}

void printLowerLine(int *a, const int n)
{
	if (n == 1)
	{
		cout << a[0] << endl;
		return;
	}

	// First
	if (abs(a[0]) != 1)
	{
		cout << a[0];
	}

	cout << "x";

	// Pow
	if (n > 2)
	{
		cout << " ";
	}

	// Following digits
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] == 0)
		{
			continue;
		}

		// Sign
		if (a[i] > 0)
		{
			cout << "+";
		}
		else
		{
			cout << "-";
		}

		// Coeff
		if (abs(a[i]) != 1)
		{
			cout << abs(a[i]);
		}

		cout << "x";

		// Pow
		if (n - i > 2)
		{
			cout << " ";
		}
	}

	// Last digit
	if (a[n - 1] > 0)
	{
		cout << "+";
	}

	cout << a[n - 1] << endl;
}

void printPolynomial(int *a, const int n)
{
	if (n > 2)
	{
		printUpperLine(a, n);
	}

	printLowerLine(a, n);
}

int main()
{
	cout << "Polynomial" << endl;

	int n = 0;
	cout << "Quantity of coefficients: ";
	cin >> n;

	//int coefficient[] = {1, -2, -1, 1};

	int *coefficient = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> coefficient[i];
	}

	printPolynomial(coefficient, n);

	delete[] coefficient;
}