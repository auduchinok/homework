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
		while (l < r && !isalpha(str[l]) && !isdigit(str[l]))
		{
			l++;
		}

		while (l < r && !isalpha(str[r]) && !isdigit(str[r]) && r >= 0)
		{
			r--;
		}

		if (l >= r)
			return 1;

		if (tolower(str[l]) != tolower(str[r]))
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
	char str[100] = {0};
	
	fgets(str, 100, stdin);

	if (isPalindrome(str))
	{
		printf("String is palindrome.\n");
	}
	else
	{
		printf("String is not palindrome.\n");
	}
}