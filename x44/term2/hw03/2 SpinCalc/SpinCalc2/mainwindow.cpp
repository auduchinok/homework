#include <qstring.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calcIt()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(calcIt()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(calcIt()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calcIt()
{
    int value1 = ui->spinBox->value();
    int value2 = ui->spinBox_2->value();
    Operation op = static_cast<Operation> (ui->comboBox->currentIndex());

    try
    {
        double result = calc.calc(op, value1, value2);
        ui->lineEdit->setText(QString::number(result));
    }
    catch (DivideByZeroException)
    {
        ui->lineEdit->setText("Division by zero");
    }
}
