#pragma once
#include <QMainWindow>
#include "calc.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void calcIt();

private:
    Ui::MainWindow *ui;
    Calc calc;
};
