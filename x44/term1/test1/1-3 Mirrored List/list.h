/*
Eugene Auduchinok (c) 2013

Mirrored List
*/

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
		int size;
		ListElement *first;
	};

	List *create();
	void deleteList(List *list);
	void add(List *list, int value);
	void print(List *list);
	int get(List *list, int index);
};