#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <sql.h>
#include <QStringListModel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
namespace Ui {
class search;
}

class search : public QWidget
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    ~search();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QStringListModel *Model;
    QStringList List;
    sql *sq;
    Ui::search *ui;
};

#endif // SEARCH_H
