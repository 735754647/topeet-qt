#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QString>
#include <QHostAddress>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


    QUdpSocket *udpSocket;

private slots:
    void on_openBt_clicked();

    void readyRead_slot();

    void on_sendBt_clicked();

    void on_closBt_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
