#include "d_me.h"
#include "ui_d_me.h"
#include "BackEnd/header/kernal.h"

d_me::d_me(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::d_me)
{
    ui->setupUi(this);

    // begin - hide titlebar, mouse drag anywhere
    this->setWindowFlags(Qt::FramelessWindowHint);
    // end - hide titlebar, mouse drag anywhere
}

d_me::~d_me()
{
    delete ui;
}

// begin - hide titlebar, mouse drag anywhere
void d_me::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void d_me::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void d_me::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

// end - hide titlebar, mouse drag anywhere

void d_me::on_pushButton__write_logout_clicked()
{
    uiset_prev = uiset;
    uiset = 1;

    close();
}

void d_me::on_pushButton_me_return_clicked()
{
    uiset_prev = uiset;
    uiset = 3;

    close();
}

void d_me::on_pushButton_write_changeKey_clicked()
{
    uiset_prev = uiset;
    uiset = 9;

    close();
}

void d_me::on_pushButton_write_focus_clicked()
{
    uiset_prev = uiset;
    uiset = 10;

    User::tNum_F =1;

    close();
}
