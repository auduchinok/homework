#ifndef CALC_H
#define CALC_H

#include <QMainWindow>

namespace Ui {
class Calc;
}

class Calc : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calc(QWidget *parent = 0);
    ~Calc();

private slots:
    void calc();

private:
    Ui::Calc *ui;

};

#endif // CALC_H
