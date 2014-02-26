#include <iostream>
#include "pointerlist.h"
#include "arraylist.h"
using namespace std;

void listTest(List *l)
{
    for (int i = 0; i < 10; i++)
    {
        l->add(i);
    }

    l->print();

    l->remove(9);
    l->print();

    l->remove(0);
    l->print();

    l->remove(2);
    l->print();

    l->remove(3);
    l->print();

    cout << "l->exists(42): " << l->exists(42) << std::endl;
    cout << "l->exists(4): " << l->exists(4) << std::endl;

    std::cout << "Test finished.\n\n";
}

int main()
{
    std::cout << "PointerList test:" << std::endl;

    List *ptrList = new PointerList;
    listTest(ptrList);
    delete ptrList;

    std::cout << "ArrayList test():" << std::endl;

    List *arrList = new ArrayList;
    listTest(arrList);
    delete arrList;

    return 0;
}

