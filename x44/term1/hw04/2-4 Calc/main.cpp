/*
Eugene Auduchinok (c) 2013

Homework 1.04.02
Calc
*/

#include <iostream>
#include "calc.h"
using namespace std;

int main()
{
	cout << "Calc" << endl;

	char *s = new char[100];
	cout << "expr: ";
	cin.getline(s, 100);

	cout << calc(s) << endl;
	delete[] s;
}