#include <iostream>
#include "list.h"

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

bool list::isEmpty(List *list)
{
	return (list->first == nullptr);
}

void list::add(List *list, int value)
{
	ListElement *toAdd = new ListElement;
	toAdd->value = value;

	if (isEmpty(list) || value < list->first->value)
	{
		toAdd->next = list->first;
		list->first = toAdd;

		return;
	}

	ListElement *tmp = list->first;

	while (tmp->next != nullptr && tmp->next->value < value)
	{
		tmp = tmp->next;
	}

	toAdd->next = tmp->next;
	tmp->next = toAdd;
}

void list::remove(List *list, int value)
{
	if (list->first->value > value)
	{
		return;
	}

	if (list->first->value == value)
	{
		ListElement *toDelete = list->first;
		list->first = list->first->next;
		delete toDelete;

		return;
	}

	ListElement *tmp = list->first;

	while (tmp->next != nullptr && tmp->next->value < value)
	{
		tmp = tmp->next;
	}

	if (tmp->next == nullptr || tmp->next->value > value)
	{
		return;
	}

	ListElement *toDelete = tmp->next;
	tmp->next = toDelete->next;
	delete toDelete;
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

int list::get(List *list, int index)
{
	ListElement *tmp = list->first;

	for (int i = 0; i < index - 1; i++)
	{
		tmp = tmp->next;
	}

	return tmp->value;
}