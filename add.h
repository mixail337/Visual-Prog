#ifndef ADD_H
#define ADD_H
#include "sql.h"
#include <QWidget>
#include <QFileDialog>

namespace Ui {
class add;
}

class add : public QWidget
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

private:
    Ui::add *ui;
    sql *sq;
signals:
    void sendData(QString str);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
};

#endif // ADD_H
