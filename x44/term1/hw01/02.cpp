/*
Eugene Auduchinok (c) 2013

Homework 1.01.02
a div b
*/

#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;

	cout << "a: ";
	cin >> a;

	cout << "b: ";
	cin >> b;

	while (a - b > 0)
	{
		a -= b;
		c++;
	}

	cout << c << endl;
}