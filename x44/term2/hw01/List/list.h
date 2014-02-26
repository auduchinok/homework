#pragma once
#include <iostream>

class List
{
public:
    virtual ~List()
    {
    }

    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual bool exists(int value) = 0;
    virtual void print() = 0;
};
