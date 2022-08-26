#include "daily.h"
#include "ui_daily.h"

daily::daily(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::daily)
{
    ui->setupUi(this);
    int max,id;
    max=4;
    id=1;
    for(int i=1;i<=max;i++){
        ui->comboBox->addItem(sq->getName(id));
        ui->comboBox_2->addItem(sq->getName(id));
        ui->comboBox_3->addItem(sq->getName(id));
        id++;
    }
}

daily::~daily()
{
    delete ui;
}
