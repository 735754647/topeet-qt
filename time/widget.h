#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QTimer timer;
    QTime  time;

private slots:
    void on_starBt_clicked();

    void timeout_slot();

    void on_closBt_clicked();

    void on_resetBt_clicked();

    void on_bitBt_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
