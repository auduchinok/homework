#pragma once

namespace list
{
	struct ListElement
	{
		int value;
		ListElement *next;
	};

	struct List
	{
		ListElement *first;
	};

	List *createList();
	void deleteList(List *list);
	void add(List *list, int value);
	void sortArray(List *list, int *a, int n);
};