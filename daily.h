#ifndef DAILY_H
#define DAILY_H

#include <QWidget>
#include <sql.h>
namespace Ui {
class daily;
}

class daily : public QWidget
{
    Q_OBJECT

public:
    explicit daily(QWidget *parent = nullptr);
    ~daily();

private:
    sql *sq;
    Ui::daily *ui;
};

#endif // DAILY_H
