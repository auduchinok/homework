/* 
Eugene Auduchinok (c) 2013

Homework 1.02.02
QuickPowerFunction
*/

#include <iostream>
using namespace std;

double powRec(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}

	double binPow = powRec(a, n / 2) * powRec(a, n / 2);

	if (n % 2 == 0)
	{
		return binPow;
	}
	else
	{
		return binPow * a;
	}
}

double pow(int a, int n)
{
	if (a == 0)
	{
		return 0;		
	}

	if (n == 0)
	{
		return 1;
	}

	if (n > 0)
	{
		return powRec(a, n);
	}
	else
	{
		return 1 / powRec(a, n);
	}
}

int main()
{
	cout << "QuickPowerFunction" << endl;

	int a = 0;
	cout << "a: ";
	cin >> a;

	int n = 0;
	cout << "n: ";
	cin >> n;

	cout << "a ^ n = " <<  pow(a, n) << endl;
}