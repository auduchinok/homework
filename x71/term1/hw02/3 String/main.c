/*
Eugene Auduchinok (c) 2013

Homework 1.02.03
String
*/

#include <stdio.h>
#include "string.h"

void tests()
{
	char a[] = {"String."};
	printf("%d\n", myStrlen(a));

	char b[20] = {0};
	myStrcpy(b, a);
	printf("%s\n", b);

	char c[20] = {0};
	myStrcpy(c, a);
	myStrcat(c, b);
	printf("%s\n", c);

	printf("%d\n", myStrcmp(a, b));
	printf("%d\n", myStrcmp(b, c));
}

int main()
{
	tests();
}