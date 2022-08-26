#include "search.h"
#include "ui_search.h"

search::search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    Model = new QStringListModel(this);
    Model->setStringList(List);
    ui->listView->setModel(Model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

search::~search()
{
    delete ui;
}

void search::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()==true) {
        List.clear();int row = Model->rowCount();
        Model->insertRows(row, 1);
        List.append(sq->searchName(ui->textEdit->toPlainText()));
        Model->setStringList(List);
        ui->listView->setModel(Model);

    }
    if(ui->radioButton_2->isChecked()==true){
        List.clear();int row = Model->rowCount();
        Model->insertRows(row, 1);
        List.append(sq->searchIngr(ui->textEdit->toPlainText()));
        Model->setStringList(List);
        ui->listView->setModel(Model);
    }
    if(ui->radioButton_4->isChecked()==true) {
        List.clear();int row = Model->rowCount();
        Model->insertRows(row, 1);
        List.append(sq->searchCookName(ui->textEdit_2->toPlainText(),ui->textEdit->toPlainText()));
        Model->setStringList(List);
        ui->listView->setModel(Model);
    }
    if(ui->radioButton_5->isChecked()==true) {
        List.clear();int row = Model->rowCount();
        Model->insertRows(row, 1);
        List.append(sq->searchTime(ui->textEdit->toPlainText().toInt()));
        Model->setStringList(List);
        ui->listView->setModel(Model);
    }
}


void search::on_pushButton_2_clicked()
{
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    List.clear();
    Model->setStringList(List);
    ui->listView->setModel(Model);
}

