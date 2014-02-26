#include <iostream>
#include "pointerlist.h"

PointerList::PointerList() : head(nullptr)
{
}

PointerList::~PointerList()
{
    ListElement *tmp = head;

    while (tmp != nullptr)
    {
        ListElement *toDel = tmp;

        tmp = tmp->next;

        delete toDel;
    }
}

bool PointerList::isEmpty()
{
    return head == nullptr;
}

void PointerList::add(int value)
{
    ListElement *toAdd = new ListElement;
    toAdd->value = value;

    toAdd->next = head;
    toAdd->prev = nullptr;

    if (!isEmpty())
    {
        head->prev = toAdd;
    }

    head = toAdd;
}

void PointerList::remove(int value)
{
    ListElement *tmp = head;

    while (tmp != nullptr)
    {
        if (tmp->value == value)
        {
            if (tmp == head)
            {
                head = tmp->next;
            }
            else
            {
                tmp->prev->next = tmp->next;
            }

            if (tmp->next != nullptr)
            {
                tmp->next->prev = tmp->prev;
            }

            delete tmp;
        }

        tmp = tmp->next;
    }
}

bool PointerList::exists(int value)
{
    ListElement *tmp = head;

    while (tmp != nullptr)
    {
        if (tmp->value == value)
        {
            return true;
        }

        tmp = tmp->next;
    }

    return false;
}

void PointerList::print()
{
    ListElement *tmp = head;

    while (tmp != nullptr)
    {
        std::cout << tmp->value << " ";

        tmp = tmp->next;
    }

    std::cout << std::endl;
}
