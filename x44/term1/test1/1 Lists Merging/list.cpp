#include <iostream>
#include "list.h"
using namespace list;

list::List *list::createList()
{
	List *result = new List;
	result->first = nullptr;

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

	if (isEmpty(list) || value > list->first->value)
	{
		toAdd->next = list->first;
		list->first = toAdd;

		return;
	}

	ListElement *tmp = list->first;

	while (tmp->next != nullptr && tmp->next->value > value)
	{
		tmp = tmp->next;
	}

	toAdd->next = tmp->next;
	tmp->next = toAdd;
}

void list::printList(List *list)
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