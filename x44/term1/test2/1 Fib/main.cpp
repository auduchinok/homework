#include <iostream>
using namespace std;

int fib(int n)
{
	if (n < 2)
	{
		return 1;
	}

	int num1 = 1;
	int num2 = 1;

	int sum = 2;

	for (int i = 2; i < n; i++)
	{
		num1 = num2;
		num2 = sum;

		sum = num1 + num2;
	}

	return sum;
}

int main()
{
	cout << "Fib" << endl;

	int n = 0;
	cout << "n: ";
	cin >> n;

	cout << fib(i) << endl;
}