/*
Eugene Auduchinok (c) 2013

Homework 1.01.10
Palindrome
*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
	char str[100] = {0};

	cout << "string: ";
	cin.getline(str, 100);

	int left = 0;
	int right = strlen(str) - 1;

	while (left < right)
	{
		if (str[left] != str[right])
		{
			cout << "No." << endl;
			return 0;
		}

		left++;
		right--;

		while (isspace(str[left]))
			left++;

		while (isspace(str[right]))
			right--;
	}

	cout << "Yes." << endl;
}