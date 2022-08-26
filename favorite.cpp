#include "favorite.h"
#include "ui_favorite.h"

favorite::favorite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::favorite)
{
    ui->setupUi(this);
    Model = new QStringListModel(this);
    Model->setStringList(List);
    ui->listView->setModel(Model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

favorite::~favorite()
{

    delete ui;
}

void favorite::on_pushButton_5_clicked()
{
    int id=1;
    List.clear();
    //int max = sq->getIdMax();
    int max=4;
    for(int i=1;i<=max;i++){
        int row = Model->rowCount();
        Model->insertRows(row, id);
        List.append(sq->getNamefromFav(id));
        Model->setStringList(List);
        ui->listView->setModel(Model);
        id++;
        if(id>max) id=1;
        qDebug()<<id;
    }
    //id =1;
}


void favorite::on_listView_clicked(const QModelIndex &index)
{
     id1 = index.row()+1;
}




void favorite::on_pushButton_2_clicked()
{
    sq->deleteRowFromFav(id1);
    Model->removeRows(ui->listView->currentIndex().row(),1);
    qDebug() << id1;
}

