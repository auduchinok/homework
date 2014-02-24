#pragma once
#include "list.h"

class PointerList : public List
{
public:
    PointerList();
    ~PointerList();
    void add(int value);
    void remove(int value);
    bool exists(int value);
    void print();

private:
    struct ListElement
    {
        int value;
        ListElement *next;
        ListElement *prev;
    };

    ListElement *head;

    bool isEmpty();
};
