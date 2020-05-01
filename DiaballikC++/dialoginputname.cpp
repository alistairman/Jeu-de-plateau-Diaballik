#include "dialoginputname.h"
#include "ui_dialoginputname.h"
#include <stdio.h>

DialogInputName::DialogInputName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInputName)
{
    ui->setupUi(this);
}

DialogInputName::~DialogInputName()
{
    delete ui;
}

void DialogInputName::on_buttonBox_accepted()
{

}
