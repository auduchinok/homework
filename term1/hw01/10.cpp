#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
	cout << "Homework 1.01.10" << endl;
	cout << "Palindrome" << endl;

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