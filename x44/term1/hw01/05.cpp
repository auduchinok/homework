/*
Eugene Auduchinok (c) 2013

Homework 1.01.05
Brackets balance
*/

#include <iostream>
#include <cstring>
using namespace std;

bool checkBalance(char* str)
{
	int balance = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (balance < 0)
		{
			return false;
		}

		if (str[i] == '(')
			balance++;
		else if (str[i] == ')')
			balance--;
	}

	return (balance == 0);
}

void test1()
{
	cout << "Test 1: ";

	char str[] = {"(1)(2(3))"};

	if (checkBalance(str))
		cout << "OK." << endl;
	else
		cout << "Wrong." << endl;
}

bool test2()
{
	cout << "Test 2: ";

	char str[] = {"(1)(2(3))("};

	if (!checkBalance(str))
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
	runTests(); 

	char str[100] = {0};

	cout << "string: ";
	cin.getline(str, 100);

	if (checkBalance(str))
		cout << "OK." << endl;
	else
		cout << "Wrong." << endl;
}