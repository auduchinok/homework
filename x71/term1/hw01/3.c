/*
Eugene Auduchinok (c) 2013

Homework 1.01.03
isPrime?
*/

#include <stdio.h>
#include <math.h>

int isPrime(const int n)
{
	int sqrtN = sqrt(n);
	int i = 0;

	if (n < 2)
		return 0;

	for (i = 2; i <= sqrtN; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	int n = 0;

	scanf("%d", &n);

	if (isPrime(n))
	{
		printf("%d is prime.\n", n);
	}
	else
	{
		printf("%d is not prime.\n", n);
	}
}