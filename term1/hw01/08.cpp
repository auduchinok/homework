#include <iostream>
using namespace std;

long long int factorialIterative(int n)
{
	long long int answer = 1;

	for (int i = 2; i <= n; i++)
		answer *= i;

	return answer;
}

long long int factorialRecurrent(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * factorialRecurrent(n - 1);
}

void test1()
{
	cout << "Test 1: ";

	if (factorialRecurrent(5) == 120)
		cout << "OK." << endl;
	else
		cout << "Wrong." << endl;
}

void test2()
{
	cout << "Test 2: ";

	if (factorialIterative(5) == 120)
		cout << "OK." << endl;
	else
		cout << "Wrong." << endl;
}

void runTests()
{
	test1();
	test2();
}

int main()
{
	cout << "Homework 1.01.08" << endl;
	cout << "Factorials" << endl;

	runTests();

	int n = 0;

	cout << "n: ";
	cin >> n;

	cout << "Recurrent: " << factorialRecurrent(n) << endl;
	cout << "Iterative: " << factorialIterative(n) << endl;
}