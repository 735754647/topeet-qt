#include "widget.h"
#include "ui_widget.h"

#include <QDesktopWidget>
#include <QStyle>
#include <QRect>

static int i;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));

    time.setHMS(0,0,0,0);
    ui->showTime->setText("00:00:00:000");
    QDesktopWidget *deskTopWidget = QApplication::desktop();
    QRect deskRect = deskTopWidget->availableGeometry();

    int appH = deskRect.height();
    int appW = deskRect.width();
    this->setFixedSize(appW, appH);
    setGeometry(0, 0, appW, appH);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::timeout_slot()
{
    //qDebug("HAHAH");

    time = time.addMSecs(40);

    ui->showTime->setText(time.toString("hh:mm:ss.zzz"));

}
void Widget::on_starBt_clicked()
{
    timer.start(30);
}

void Widget::on_closBt_clicked()
{
    timer.stop();

}

void Widget::on_resetBt_clicked()
{
    timer.stop();
    time.setHMS(0,0,0,0);
    ui->showTime->setText("00:00:00:000");

    ui->bitTime->clear();
    i=0;
}

void Widget::on_bitBt_clicked()
{
    QString temp;

    i=i+1;

    temp.sprintf("%d:",i);

    ui->bitTime->append(temp);

    ui->bitTime->append(time.toString("hh:mm:ss.zzz"));
}















