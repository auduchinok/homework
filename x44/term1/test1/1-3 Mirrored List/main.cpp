/*
Eugene Auduchinok (c) 2013

Mirrored List
*/

#include <iostream>
#include <sstream>
#include "list.h"
using namespace std;

list::List *readList()
{
	list::List *result = list::create();

	cout << "Type a string containing the list:" << endl;

	char string[256] = {0};
	cin.getline(string, 256);

	stringstream ss;
	ss << string;

	int num = 0;
	while (ss >> num)
	{
		list::add(result, num);
	}

	return result;
}

bool isMirrored(list::List *list)
{
	int size = list->size;

	for (int i = 0; i < size / 2; i++)
	{
		if (list::get(list, i) != list::get(list, size - 1 - i))
		{
			return false;
		}
	}

	return true;
}

int main()
{
	cout << "Mirrored List" << endl;

	list::List *list = readList();

	if (isMirrored(list))
	{
		cout << "List is mirrored." << endl;
	}
	else
	{
		cout << "List is not mirrored." << endl;
	}

	list::deleteList(list);
}