#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(){
    if(money >= 100)
           ui->pbCoffee->setEnabled(true);
    else
           ui->pbCoffee->setEnabled(false);

    if(money >= 150)
           ui->pbTea->setEnabled(true);
    else
           ui->pbTea->setEnabled(false);

     if(money >= 200)
           ui->pbMilk->setEnabled(true);
     else
           ui->pbMilk->setEnabled(false);
   }


int money=0;
void Widget::on_pb10_clicked()
{
    money+=10;
    ui->lcdNumber->display(money);
    changeMoney();
}

void Widget::on_pb50_clicked()
{
    money+=50;
    ui->lcdNumber->display(money);
    changeMoney();
}

void Widget::on_pb100_clicked()
{
    money+=100;
    ui->lcdNumber->display(money);
    changeMoney();
}

void Widget::on_pb500_clicked()
{
    money+=500;
    ui->lcdNumber->display(money);
    changeMoney();
}

void Widget::on_pbCoffee_clicked()
{
    money-=100;
    ui->lcdNumber->display(money);
    changeMoney();
}

void Widget::on_pbTea_clicked()
{
    money-=150;
    ui->lcdNumber->display(money);
    changeMoney();
}

void Widget::on_pbMilk_clicked()
{
    money-=200;
    ui->lcdNumber->display(money);
    changeMoney();
}

void Widget::on_pbReset_clicked()
{
    QMessageBox m;
    QString s = QString::number(money);
    m.information(nullptr, "Changes",s);

}
