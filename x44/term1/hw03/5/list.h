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
	void remove(List *list, int value);
	void removeInTurns(List *list, int index);
	void printList(List *list);
	int get(List *list, int index);
};