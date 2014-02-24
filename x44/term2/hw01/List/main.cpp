#include <iostream>
#include "pointerlist.h"

using namespace std;

int main()
{
    List *list = new PointerList;

    list->add(5);
    list->add(10);

    list->print();

    delete list;

    return 0;
}

