/*
Eugene Auduchinok (c) 2013

Homework 1.01.06
Substrings
*/

#include <iostream>
#include <cstring>
using namespace std;

int countSubstrings(char *s, char *s1)
{
	int sLength = strlen(s);
	int s1Length = strlen(s1);

	int count = 0;
	int i = 0;

	while (i < sLength - s1Length)
	{
		int j = 0;

		while (j < s1Length && s[i + j] == s1[j])
		{
			j++;
		}

		if (j == s1Length)
		{
			count++;
			i++;

			continue;
		}

		else if (j > 0)
		{
			i += j;
		}

		else
		{
			i++;
		}
	}

	return count;
}

void test()
{	
	cout << "Test 1: ";

	char s[] = {"abbabcacbbabbda"};
	char s1[] = {"bba"};

	if (countSubstrings(s, s1) == 2)
		cout << "OK!" << endl;
	else
		cout << "Wrong." << endl;
}

int main()
{
	test();

	char s[100] = {0};
	cout << "s: ";
	cin.getline(s, 100);

	char s1[50] = {0};
	cout << "s1: ";
	cin.getline(s1, 50);

	cout << countSubstrings(s, s1) << " substring(s)" << endl;
}