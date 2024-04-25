#include "login.h"
#include "ui_login.h"
#include "QMessageBox"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->pass_wordlineEdit->setEchoMode(QLineEdit::Password);
        connect(ui->login_2,&QPushButton::clicked,[&](){
            if(ui->user_lineEdit->text()=="xz"&&ui->pass_wordlineEdit->text()=="123456"){
                this->hide();
                w.show();
            }else{
                QMessageBox::warning(this,"登录错误","账号或密码错误");
            }
        });
}

login::~login()
{
    delete ui;
}
