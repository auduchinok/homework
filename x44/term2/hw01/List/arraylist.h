#pragma once
#include "list.h"

class ArrayList : public List
{
public:
    ArrayList();
    ~ArrayList();
    void add(int value);
    void remove(int value);
    bool exists(int value);
    void print();

private:
    static const int defaultSize;
    int size;
    int head;
    int free;

    int *values;
    int *refs;

    void enlarge();
};
