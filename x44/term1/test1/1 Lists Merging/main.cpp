#include <iostream>
#include "list.h"
using namespace std;
using namespace list;

void readList(List *list, int length)
{
	for (int i = 0; i < length; i++)
	{
		int toAdd = 0;

		cout << "next: ";
		cin >> toAdd;

		add(list, toAdd);
	}
}

int main()
{
	cout << "Lists Merging" << endl;

	List *commonList = createList();

	int list1Length = 0;
	int list2Length = 0;

	cout << "List 1 Length: ";
	cin >> list1Length;

	cout << "List 2 Length: ";
	cin >> list2Length;

	cout << "List 1: " << endl;
	readList(commonList, list1Length);

	cout << "List 2: " << endl;
	readList(commonList, list2Length);

	cout << "Common List: " << endl;
	printList(commonList);

	deleteList(commonList);
}