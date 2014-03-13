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
    int val1 = ui->spinBox->value();
    int val2 = ui->spinBox_2->value();
    int op = ui->comboBox->currentIndex();

    int result = 0;

    switch (op)
    {
        case 0:
        {
            result = val1 + val2;

            break;
        }
        case 1:
        {
            result = val1 - val2;

            break;
        }
        case 2:
        {
            result = val1 * val2;

            break;
        }
        case 3:
        {
            if (val2 == 0)
            {
                ui->lineEdit->setText("");
                return;
            }

            result = val1 / val2;
        }
    }

    ui->lineEdit->setText(QString::number(result));

}
