#include <iostream>
using namespace std;

int main()
{
	cout << "Homework 1.01.02" << endl;
	cout << "a div b" << endl;

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