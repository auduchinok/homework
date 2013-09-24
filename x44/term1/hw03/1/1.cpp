/*
Eugene Auduchinok (c) 2013

Homework 1.03.01
Semi-equal strings
*/

#include <iostream>
#include <cstring>
#include "qsort.h"
using namespace std;

bool areSemiEqual(char *s1, char *s2)
{
	if (strlen(s1) != strlen(s2))
	{
		return false;
	}

	qsort(s1, strlen(s1));
	qsort(s2, strlen(s2));

	return !strcmp(s1, s2);
}

int main()
{
	cout << "Semi-equal strings" << endl;

	char s1[100] = {0};
	char s2[100] = {0};

	cout << "s1: ";
	cin.getline(s1, 100);

	cout << "s2: ";
	cin.getline(s2, 100);

	if (areSemiEqual(s1, s2))
	{
		cout << "It is possible." << endl;
	}
	else
	{
		cout << "It is not possible." << endl;
	}
}