/*
Eugene Auduchinok (c) 2013

Homework 1.01.09
Power function
*/

#include <iostream>
#include <cmath>
using namespace std;

double pow(int a, int n)
{
	if (a == 0)
	{
		return 0;
	}

	double answer = 1;

	if (n == 0)
		return answer;

	for (int i = 0; i < abs(n); i++)
	{
		if (n > 0)
			answer *= a;
		else
			answer /= a;
	}

	return answer;
}

int main()
{
	double a = 0;

	cout << "a: ";
	cin >> a;

	int n = 0;

	cout << "n: ";
	cin >> n;

	if (a == 0 && n < 0)
	{
		cout << "Exception: division by 0" << endl;	
		return 1;
	}

	cout << pow(a, n) << endl;
}