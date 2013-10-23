/*
Eugene Auduchinok (c) 2013

Homework 1.05.05
English Numerals
*/

#include <iostream>
#include "nums.h"
using namespace std;

void printDigit(int n)
{
	const char *digits[] = {
		"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};
	const int offset = 1;

	cout << digits[n - offset];
}

void printTens(int n)
{
	const char *tens[] = {
		"twenty","thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
	};
	const int offset = 2;

	cout << tens[n - offset];
}

void print10To19(int n)
{
	const char *tenToNineteen[] = {
		"eleven", "twelve", "thirteen", "fourteen", "fifteen",
		"sixteen", "seventee", "eighteen", "nineteen"
	};
	const int offset = 11;

	cout << tenToNineteen[n - offset];
}

void printThousand(int n, bool lastPart)
{
	int hundreds = n / 100;
	int tens = (n % 100) / 10;
	int ones = n % 10;

	if (hundreds)
	{
		printDigit(hundreds);
		cout << " hundred";
	}

	if (hundreds && tens)
	{
		cout << " ";

		if (lastPart)
		{
			cout << "and ";
		}
	}

	if (tens == 1)
	{
		print10To19(n % 100);
		return;
	}

	if (tens > 1)
	{
		printTens(tens);
	}

	if (tens && ones)
	{
		cout << "-";
	}
	else if (ones)
	{
		cout << " ";
	}

	if (ones)
	{
		printDigit(ones);
	}
	
}

void printNum(int n)
{
	if (n == 0)
	{
		cout << "zero" << endl;
		return;
	}

	int thousands = n / 1000;

	if (thousands > 0)
	{
		printThousand(thousands, false);
		cout << " thousand ";
	}

	printThousand(n % 1000, true);
	cout << endl;
}