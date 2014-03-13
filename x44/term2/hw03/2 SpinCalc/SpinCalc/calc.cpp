#include <QMessageBox>
#include "calc.h"
#include "ui_calc.h"

Calc::Calc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calc)
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calc()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(calc()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(calc()));
}

Calc::~Calc()
{
    delete ui;
}

void Calc::calc()
{
    enum Operation {add, sub, mul, div};

    int val1 = ui->spinBox->value();
    int val2 = ui->spinBox_2->value();
    Operation op = static_cast<Operation> (ui->comboBox->currentIndex());

    double result = 0;

    switch (op)
    {
        case add:
        {
            result = val1 + val2;

            break;
        }
        case sub:
        {
            result = val1 - val2;

            break;
        }
        case mul:
        {
            result = val1 * val2;

            break;
        }
        case div:
        {
            if (val2 == 0)
            {
                ui->lineEdit->setText("");
                return;
            }

            result = val1 / static_cast<double> (val2);
        }
    }

    ui->lineEdit->setText(QString::number(result));

}
