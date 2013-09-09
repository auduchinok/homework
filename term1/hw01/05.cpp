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

	if (balance == 0)
		return true;
	else
		return false;
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

void runTests() // Стоит выносить в отдельную функцию?
{
	test1();
	test2();
}

int main()
{
	cout << "Homework 1.01.05" << endl;
	cout << "Brackets balance" << endl;

	runTests(); 

	char str[100] = {0};

	cout << "string: ";
	cin.getline(str, 100);

	if (checkBalance(str))
		cout << "OK." << endl;
	else
		cout << "Wrong." << endl;
}