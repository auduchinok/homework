#include <iostream>
#include <cstring>
#include "arraylist.h"

const int ArrayList::defaultSize = 8;

ArrayList::ArrayList() : size(defaultSize), head(-1), free(0)
{
    values = new int[size];
    memset(values, 0, sizeof(int) * size);

    refs = new int[size];

    for (int i = 0; i < size - 1; i++)
    {
        refs[i] = i + 1;
    }

    refs[size - 1] = -1;
}

ArrayList::~ArrayList()
{
    delete[] values;
    delete[] refs;
}

void ArrayList::enlarge()
{
    int *newValues = new int[size * 2];
    int *newRefs = new int[size * 2];

    memcpy(newValues, values, sizeof(int) * size);
    memcpy(newRefs, refs, sizeof(int) * size);

    delete[] values;
    delete[] refs;

    values = newValues;
    refs = newRefs;


    for (int i = size; i < size * 2; i++)
    {
        values[i] = 0;
        refs[i] = i + 1;
    }

    refs[size * 2 - 1] = -1;

    free = size;

    size *= 2;
}


void ArrayList::add(int value)
{
    if (free == -1)
    {
        enlarge();
    }

    int toAdd = free;
    values[toAdd] = value;

    free = refs[free];

    refs[toAdd] = head;
    head = toAdd;
}

void ArrayList::remove(int value)
{
    int prev = -1;
    int tmp = head;

    while (tmp != -1)
    {
        if (values[tmp] == value)
        {
            if (tmp == head)
            {
                head = refs[tmp];
            }
            else
            {
                refs[prev] = refs[tmp];
            }

            refs[tmp] = free;
            free = tmp;

            return;
        }

        prev = tmp;
        tmp = refs[tmp];
    }
}

bool ArrayList::exists(int value)
{
    int tmp = head;

    while (tmp != -1)
    {
        if (values[tmp] == value)
        {
            return true;
        }

        tmp = refs[tmp];
    }

    return false;
}

void ArrayList::print()
{
    int tmp = head;

    while (tmp != -1)
    {
        std::cout << values[tmp] << " ";

        tmp = refs[tmp];
    }

    std::cout << std::endl;
}
