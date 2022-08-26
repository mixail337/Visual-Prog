#include "mainwindow.h"
#include "ui_mainwindow.h"
/*void MainWindow::recieveData(QString str){
    QStringList lst = str.split("*");
    /*QString("INSERT INTO Recipes (id,Name,Ingt,Rec,Pic,Fav,Cat) VALUES ('%0','%1'.'%2');")
            .arg(lst.at(0)).arg(lst.at(1)).arg(lst.at(2));
    //db.inserIntoTable(lst.at(0),lst.at(1),lst.at(2),lst.at(3));
}*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    sq = new sql();
    sq->connect();
    ui->setupUi(this);
    model = new QSqlTableModel(this,sq->db);
    model1= new QSqlTableModel(this,sq->db);
    model1->setTable("Favorite1");
    model ->setTable("Recipe");
    model->select();
    ui->tableView->setModel(model);
    model1->select();
    ui->tableView_2->setModel(model1);
    /*lmodel = new QStringListModel(this);
    lmodel->setStringList(list);
    ui->listView->setModel(lmodel);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->edit(sq->getName());*/
    add_func = new add();
    connect(ui->pushButton,SIGNAL(clicked()),add_func,SLOT(show()));
    search_func = new search();
    connect(ui->pushButton_4,SIGNAL(clicked()),search_func,SLOT(show()));
    favorite_func = new favorite();
    connect(ui->pushButton_3,SIGNAL(clicked()),favorite_func,SLOT(show()));
    daily_func = new daily();
    connect(ui->pushButton_9,SIGNAL(clicked()),daily_func,SLOT(show()));
    //connect(add_func, SIGNAL(sendData(QString)),this, SLOT(recieveData(QString)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_pushButton_8_clicked()
{
    model->select();
    ui->tableView->setModel(model);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    id1 = index.row()+1;
}
void MainWindow::on_pushButton_7_clicked()
{
    //id=0;
    sq->deleteRow(id);
    qDebug() << id;
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    id=0;
    id = index.row()+1;
    qDebug()<<id;
    ui->textBrowser->setPlainText(sq->getIngr(id));
    ui->textBrowser_2->setPlainText(sq->getSpos(id));
    ui->label_2->setText(sq->getName(id));
    filename = sq->getImage(id);
    QImage image(filename);
    ui->label->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::on_pushButton_6_clicked()
{
    sq->insertToFav(ui->label_2->text());
}

