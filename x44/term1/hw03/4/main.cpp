/* 
Eugene Auduchinok (c) 2013

Homework 1.03.04
List Implementation
*/

#include <iostream>
#include "list.h"
using namespace std;

void test1()
{
	List *list = createList();

	add(list, 1);
	add(list, 2);
	add(list, 5);
	add(list, 3);
	add(list, 0);
	add(list, 4);
	add(list, 0);

	remove(list, 3);
	remove(list, 0);
	remove(list, 0);

	printList(list);

	deleteList(list);

	cout << "End of the test." << endl << endl;
}

int main()
{	
	cout << "Sorted list" << endl;

	cout << "Run a test? y/n" << endl;
	char test = 0;
	cin >> test;

	if (test == 'y' || test == 'Y')
	{
		test1();
	}

	List *list = createList();

	int mode = -1;

	while (mode != 0)
	{
		cout << "0 - exit" << endl << 
			"1 - add a value to sorted list" << endl <<
			"2 - remove a value from sorted list" << endl <<
			"3 - print list" << endl;

		cout << "your choice: ";
		cin >> mode;

		switch (mode)
		{
			case 1:
			{
				int toAdd = 0;
				cout << "value: ";
				cin >> toAdd;
				add(list, toAdd);

				break;
			}
			case 2:
			{
				int toRemove = 0;
				cout << "value: ";
				cin >> toRemove;
				remove(list, toRemove);

				break;
			}
			case 3:
			{
				printList(list);
			}
		}
	}

	deleteList(list);
}