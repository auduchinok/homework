/*
Eugene Auduchinok (c) 2013

Homework 1.01.01
QuickPowerFunction
*/

#include <stdio.h>

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

double quickPow(int a, int n)
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
	printf("QuickPowerFunction\n");

	int a = 0;
	int n = 0;

	printf("a: ");
	scanf("%d", &a);

	printf("n: ");
	scanf("%d", &n);

	printf("a ^ n =  %f\n", quickPow(a, n));
}