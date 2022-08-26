#ifndef SQL_H
#define SQL_H

#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QFile>
#include <QSqlError>
#include <QStandardItemModel>
class sql
{
public:
    sql();
    QSqlDatabase db;
    void connect();
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();
    bool createFavTable();
    bool insertToFav(QString name);
    QString Q2I(int val){return QString::fromStdString(std::to_string(val));}
    bool insert(QString name,QString ingr, QString pic,QString spos,QString cook, int time);
    bool remove(const int id);
    QString getName(int id);
    QString getIngr(int id);
    QString getSpos(int id);
    QString getImage(int id);
    QString getNamefromFav(int id);
    QString searchName(QString name);
    QString searchIngr(QString name);
    QString searchCookName(QString cook,QString name);
    QString searchTime(int time);
    int getIdMax();
    QStandardItemModel*transData();
    int getId();
    bool deleteRow(int id);
    bool deleteRowFromFav(int id);
private:
   int count=0;
};

#endif // SQL_H
