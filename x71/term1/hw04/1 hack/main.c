/*
Eugene Auduchinok (c) 2013

Homework 1.04.01
Hack
*/

#include <stdio.h>

void hack()
{
	printf("HACKED\n");
}

void read_line()
{
	int i = 0;
	char array[4] = {0};
	
	gets(array);

	if (i == 'h')
	{
		*(((int *) &array) + 4) = (int) &hack;
	}
}

int main()
{
	printf("Hack gets()\n");

	read_line();
}
