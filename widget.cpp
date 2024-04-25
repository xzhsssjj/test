#include "widget.h"
#include "ui_widget.h"
#include <qDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->tcp = new QTcpServer(this);
    this->socket_tcp = new QTcpSocket(this);
    qDebug()<<"socket,tcp对象创建成功";
    ui->lineEdit->setText(QString("192.168.7.129"));
    ui->lineEdit_2->setText(QString("8848"));
    connect(socket_tcp,&QTcpSocket::disconnected,this,&Widget::falie_con);
    connect(socket_tcp,&QTcpSocket::connected,this,&Widget::successful_con);
    connect(socket_tcp,&QTcpSocket::readyRead,this,&Widget::get_pic_data);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->textEdit->append(QString("连接主机"));
    this->socket_tcp->abort();
    this->socket_tcp->connectToHost(ui->lineEdit->text(),ui->lineEdit_2->text().toInt());
}

void Widget::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
}

void Widget::successful_con()
{
    ui->textEdit->append(QString("连接成功"));
}

void Widget::falie_con()
{
    ui->textEdit->append(QString("连接失败"));
}

void Widget::get_pic_data()
{
    //qDebug()<<"缓冲区有数据";
    if(flag == false){
        char size_buff[4];
        socket_tcp->read(size_buff,4);
        this->pic_size = *(int*)size_buff;
        //qDebug()<<"pic_size"<<pic_size;
        this->flag = true;
    }

    if(this->flag == true && socket_tcp->bytesAvailable() > pic_size){
        QByteArray data = socket_tcp->read(pic_size);
        QPixmap pic_data;
        pic_data.loadFromData(data);
        ui->label_4->setPixmap(pic_data);
        this->flag = false;
    }
}

void Widget::on_horizontalSlider_valueChanged(int value)
{
    qDebug()<<"发送m0舵机转动的目标角度"<<value;
    unsigned short value_1 = value * 11 + 500;
    unsigned short data = (short) value_1;
    unsigned char cmd[5] = {0xff, 0x02, 0x04};
/*取数据低位*/
    cmd[3] = data & 0xff;
/*取数据高位*/
    cmd[4] = data >> 8;
/*发送数据*/
    this->socket_tcp->write((const char*)cmd, 5);
    qDebug()<<"发送的脉宽"<<value_1;
    qDebug()<<"发送完成";
}

void Widget::on_horizontalSlider_2_valueChanged(int value)
{
    qDebug()<<"发送m1舵机转动的目标角度"<<value;
    unsigned short value_1 = value * 11 + 500;
    unsigned short data = (short) value_1;
    unsigned char cmd[5] = {0xff, 0x02, 0x05};
/*取数据低位*/
    cmd[3] = data & 0xff;
/*取数据高位*/
    cmd[4] = data >> 8;
/*发送数据*/
    this->socket_tcp->write((const char*)cmd, 5);
    qDebug()<<"发送的脉宽"<<value_1;
    qDebug()<<"发送完成";
}

void Widget::on_horizontalSlider_3_valueChanged(int value)
{
    qDebug()<<"发送m2舵机转动的目标角度"<<value;
    unsigned short value_1 = value * 11 + 500;
    unsigned short data = (short) value_1;
    unsigned char cmd[5] = {0xff, 0x02, 0x06};
/*取数据低位*/
    cmd[3] = data & 0xff;
/*取数据高位*/
    cmd[4] = data >> 8;
/*发送数据*/
    this->socket_tcp->write((const char*)cmd, 5);
    qDebug()<<"发送的脉宽"<<value_1;
    qDebug()<<"发送完成";
}

void Widget::on_horizontalSlider_4_valueChanged(int value)
{
    qDebug()<<"发送m3舵机转动的目标角度"<<value;
    unsigned short value_1 = value * 11 + 500;
    unsigned short data = (short) value_1;
    unsigned char cmd[5] = {0xff, 0x02, 0x07};
/*取数据低位*/
    cmd[3] = data & 0xff;
/*取数据高位*/
    cmd[4] = data >> 8;
/*发送数据*/
    this->socket_tcp->write((const char*)cmd, 5);
    qDebug()<<"发送的脉宽"<<value_1;
    qDebug()<<"发送完成";
}

void Widget::on_horizontalSlider_5_valueChanged(int value)
{
    qDebug()<<"发送m4舵机转动的目标角度"<<value;
    unsigned short value_1 = value * 11 + 500;
    unsigned short data = (short) value_1;
    unsigned char cmd[5] = {0xff, 0x02, 0x08};
/*取数据低位*/
    cmd[3] = data & 0xff;
/*取数据高位*/
    cmd[4] = data >> 8;
/*发送数据*/
    this->socket_tcp->write((const char*)cmd, 5);
    qDebug()<<"发送的脉宽"<<value_1;
    qDebug()<<"发送完成";
}

void Widget::on_horizontalSlider_6_valueChanged(int value)
{
    qDebug()<<"发送m5舵机转动的目标角度"<<value;
    unsigned short value_1 = value * 11 + 500;
    unsigned short data = (short) value_1;
    unsigned char cmd[5] = {0xff, 0x02, 0x09};
/*取数据低位*/
    cmd[3] = data & 0xff;
/*取数据高位*/
    cmd[4] = data >> 8;
/*发送数据*/
    this->socket_tcp->write((const char*)cmd, 5);
    qDebug()<<"发送的脉宽"<<value_1;
    qDebug()<<"发送完成";
}
