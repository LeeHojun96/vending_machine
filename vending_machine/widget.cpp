#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{

    money += coin;
    ui->lcdNumber->display(money);

    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 100);
}

void Widget::returnCoin(int *coin500, int *coin100, int *coin50, int *coin10)
{
    *coin500 = money/500;
    money = money%500;
    *coin100 = money/100;
    money = money%100;
    *coin50 = money/50;
    money = money%50;
    *coin10 = money/10;
    money = money%10;
}



void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbReturn_clicked()
{
    int coin500 = 0;
    int coin100 = 0;
    int coin50 = 0;
    int coin10 = 0;
    char message[200] = {0};


    // print changes as mgBox
    returnCoin(&coin500,&coin100,&coin50,&coin10);
    std::sprintf(message, "500:%d, 100:%d, 50:%d, 10:%d", coin500, coin100, coin50, coin10);

    QMessageBox::about(this,"Return Coin", message);
    changeMoney(-money);
}

