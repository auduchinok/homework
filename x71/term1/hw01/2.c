/*
Eugene Auduchinok (c) 2013

Homework 1.01.02
Palindrome
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str)
{
	int l = 0;
	int r = strlen(str) - 1;

	while (l < r)
	{
		while (!isalpha(str[l]) && !isdigit(str[l]))
		{
			l++;
		}

		while (!isalpha(str[r]) && !isdigit(str[r]))
		{
			r--;
		}

		if (l >= r)
			return 1;

		if (str[l] != str[r])
		{
			return 0;
		}

		l++;
		r--;
	}

	return 1;
}

int main()
{
	char str[100];
	int i;
	char nextChar;

	for (i = 0; nextChar != '\n'; i++)
	{
		nextChar = getchar();
		str[i] = nextChar;
	}

	// Is it possible to read a line using scanf() function?

	if (isPalindrome(str))
	{
		printf("Yes.\n");
	}
	else
	{
		printf("No.\n");
	}
}