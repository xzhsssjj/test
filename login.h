#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "widget.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private:
    Ui::login *ui;
    Widget w;
};

#endif // LOGIN_H
