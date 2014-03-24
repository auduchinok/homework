#pragma once
#include <QObject>

// It didn't like a 'div' name, so I had to rename them all this way. :)
enum Operation {addition, substraction, multiplication, division};

class Calc : public QObject
{
    Q_OBJECT
public slots:
    double calc(Operation op, int a, int b);
};
