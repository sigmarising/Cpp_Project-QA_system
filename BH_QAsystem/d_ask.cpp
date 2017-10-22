#include "d_ask.h"
#include "ui_d_ask.h"
#include "BackEnd/header/func.h"
#include "BackEnd/header/kernal.h"

d_ask::d_ask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::d_ask)
{
    ui->setupUi(this);

    // begin - hide titlebar, mouse drag anywhere
    this->setWindowFlags(Qt::FramelessWindowHint);
    // end - hide titlebar, mouse drag anywhere

    ui->label_Info->hide();
}

d_ask::~d_ask()
{
    delete ui;
}

// begin - hide titlebar, mouse drag anywhere
void d_ask::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void d_ask::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void d_ask::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}
// end - hide titlebar, mouse drag anywhere

void d_ask::on_pushButton_ask_return_clicked()
{
    uiset_prev = uiset;
    uiset = 3;

    close();
}

void d_ask::on_pushButton_ask_ok_clicked()
{
    string title = Convert<QString>::Convert_QSTRtoSTR(ui->lineEdit_ask_title->text());
    string text = Convert<QString>::Convert_QSTRtoSTR(ui->textEdit_ask_text->toPlainText());

    // 标题不可以为空
    if(""==title){
        ui->label_Info->setText(QString::fromLocal8Bit("问题标题不可以为空！"));
        ui->label_Info->setStyleSheet(QString("color: red"));
        ui->label_Info->show();

        return;
    }
    // 内容不可以为空
    if(""==text){
        ui->label_Info->setText(QString::fromLocal8Bit("问题内容不可以为空！"));
        ui->label_Info->setStyleSheet(QString("color: red"));
        ui->label_Info->show();

        return;
    }

    Question Q(title, User::g_UserNow, text);
    User U(User::g_UserNow);
    U.add_qa(Q.get_mID());

    uiset_prev = uiset;
    uiset = 3;

    close();
}
