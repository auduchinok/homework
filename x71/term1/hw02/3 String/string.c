/*
Eugene Auduchinok (c) 2013

Homework 1.02.03
String
*/

#include "string.h"

int myStrlen(char *s)
{
	int i = 0;
	int count = 0;

	for (i = 0; s[i] != 0; i++)
	{
		count++;
	}

	return count;
}

void myStrcpy(char *dst, char *src)
{
	int i = 0;

	for (i = 0; src[i] != 0; i++)
	{
		dst[i] = src[i];
	}
}

void myStrcat(char *dst, char *src)
{
	int i = 0;
	int begPtr = myStrlen(dst);

	for (i = 0; src[i] != 0; i++)
	{
		dst[begPtr + i] = src[i];
	}

}

int myStrcmp(char* s1, char* s2)
{
	int i = 0;

	for (i = 0; s1[i] != 0 && s2[i] != 0; i++)
	{
		if (s1[i] != s2[i])
		{
			break;
		}
	}

	if (s1[i] == s2[i])
	{
		return 0;
	}

	return (s1[i] > s2[i]) ? 1 : -1;
}