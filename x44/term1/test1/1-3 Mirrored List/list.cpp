/*
Eugene Auduchinok (c) 2013

Mirrored List
*/

#include <iostream>
#include "list.h"
using namespace list;

list::List *list::create()
{
	List *result = new List;
	result->first = nullptr;
	result->size = 0;

	return result;
}

void list::deleteList(List *list)
{
	ListElement *tmp = list->first;

	while (tmp != nullptr)
	{
		ListElement *toDelete = tmp;
		tmp = tmp->next;
		delete toDelete;
	}

	delete list;
}

bool isEmpty(List *list)
{
	return (list->first == nullptr);
}

void list::add(List *list, int value)
{
	ListElement *toAdd = new ListElement;
	toAdd->value = value;
	toAdd->next = list->first;
	list->first = toAdd;

	(list->size)++;
}

int list::get(List *list, int index)
{
	ListElement *tmp = list->first;
	for (int i = 0; i < index; i++)
	{
		tmp = tmp->next;
	}

	return tmp->value;
}

void list::print(List *list)
{
	if (isEmpty(list))
	{
		return;
	}

	ListElement *tmp = list->first;

	while (tmp != nullptr)
	{
		std::cout << tmp->value << " ";

		tmp = tmp->next;
	}

	std::cout << std::endl;
}