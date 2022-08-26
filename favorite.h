#ifndef FAVORITE_H
#define FAVORITE_H

#include <QWidget>
#include <QStringListModel>
#include <sql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
namespace Ui {
class favorite;
}

class favorite : public QWidget
{
    Q_OBJECT

public:
    explicit favorite(QWidget *parent = nullptr);
    ~favorite();

private slots:
    void on_pushButton_5_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    QStringListModel *Model;
    QStringList List;
    sql *sq;
    Ui::favorite *ui;
    int id1;
};

#endif // FAVORITE_H
