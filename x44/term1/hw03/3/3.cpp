/*
Eugene Auduchinok (c) 2013

Homework 1.03.03
Permutation
*/

#include <iostream>
#include <ctime>
#include "qsort.h"
using namespace std;

int numLength(long long int num)
{
	int count = 0;

	while (num > 0)
	{
		num /= 10;
		count++;
	}

	return count;
}

char *createArray(long long int n)
{
	int nLength = numLength(n);
	
	char *digits = new char [nLength + 1];
	digits[nLength] = 0;

	for (int i = 0; i < nLength; i++)
	{
		digits[i] = '0' + (n % 10);
		n /= 10;
	}

	return digits;
}

void moveNull(char *digits)
{
	int ptr = 0;

	while (digits[ptr] == '0')
	{
		ptr++;
	}

	swap(digits[0], digits[ptr]);
}

int main()
{
	cout << "Permutation" << endl;

	long long int n = 0;
	cout << "n: ";
	cin >> n;

	char *digits = createArray(n);

	qsort(digits, numLength(n));

	if (digits[0] == '0')
	{
		moveNull(digits);
	}

	cout << digits << endl;
}