#include "calc.h"

double Calc::calc(Operation op, int a, int b)
{
    switch (op)
    {
    case addition:
    {
        return a + b;
    }
    case substraction:
    {
        return a - b;
    }
    case multiplication:
    {
        return a * b;
    }
    case division:
    {
        if (b == 0)
        {
            throw DivideByZeroException();
        }

        return a / static_cast<double> (b);
    }
    }
}
