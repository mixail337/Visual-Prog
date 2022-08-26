#include "add.h"
#include "ui_add.h"
add::add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}


void add::on_pushButton_clicked()
{
    sq->insert(ui->lineEdit_2->text(),ui->textEdit_3->toPlainText(),ui->lineEdit->text(),ui->textEdit->toPlainText(),ui->comboBox->currentText(),ui->lineEdit_3->text().toInt());
    connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(close()));

}


void add::on_pushButton_3_clicked()
{
    QString filename = QFileDialog::getOpenFileName(0,"C/Users/podmi/Desktop/VP/kurs/recimages",QDir::currentPath(),"*.png *jpeg *jpg *gif");
         ui->lineEdit->setText(filename);
         QImage image1(filename);
         ui->label->setPixmap(QPixmap::fromImage(image1));
}


void add::on_pushButton_2_clicked()
{
    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(close()));
    ui->lineEdit_2->setText("");
    ui->textEdit_3->setPlainText("");
    ui->lineEdit->setText("");
    ui->textEdit->setPlainText("");
    ui->label->setText("");
}

