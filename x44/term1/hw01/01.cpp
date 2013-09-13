/*
Eugene Auduchinok (c) 2013

Homework 1.01.01
x^4 + x^3 + x^2 + x
*/

#include <iostream>
using namespace std;

int main()
{
	int x = 0;

	cout << "x: ";
	cin >> x;

	int x2 = x * x;

	cout << (x2 + 1) * (x2 + x) << endl;
}