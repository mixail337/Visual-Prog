#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QStringListModel>
#include "add.h"
#include "search.h"
#include "favorite.h"
#include "daily.h"
#include "sql.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
private slots:
    void on_pushButton_clicked();
    //void recieveData(QString str);
    //void RefreshTable();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_6_clicked();

private:
    QSqlTableModel *model;
    QSqlTableModel *model1;
    QString filename;
    QImage image();
    QStringListModel *lmodel;
    sql *sq;
    QStringList list;
    Ui::MainWindow *ui;
    QSqlQuery * query;
    search *search_func;
    favorite *favorite_func;
    daily *daily_func;
    add *add_func;
    int row;
    int id;
    int id1;
};
#endif // MAINWINDOW_H
