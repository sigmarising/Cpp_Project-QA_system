#include <string>
#include "d_write.h"
#include "ui_d_write.h"
#include "BackEnd/header/kernal.h"
#include "BackEnd/header/func.h"
#include "BackEnd/header/define.h"
using namespace std;

d_write::d_write(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::d_write)
{
    ui->setupUi(this);

    // begin - hide titlebar, mouse drag anywhere, glass shadow border
    this->setWindowFlags(Qt::FramelessWindowHint);
    // end - hide titlebar, mouse drag anywhere, glass shadow border


    Question Q(Question::g_QuesNow);
    // title
    ui->label_info->hide();
    ui->label_write_Qtitle->setText( Convert<string>::Convert_STRtoQSTR(Q.get_mTitle()) );
    ui->textBrowser_write_Qtext->setPlainText(Convert<string>::Convert_STRtoQSTR(Q.get_mText()) );
}

d_write::~d_write()
{
    delete ui;
}

// begin - hide titlebar, mouse drag anywhere
void d_write::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void d_write::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void d_write::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}
// end - hide titlebar, mouse drag anywhere

void d_write::on_pushButton_write_return_clicked()
{
    uiset_prev=uiset;
    uiset = 4;

    close();
}

void d_write::on_pushButton_write_ok_clicked()
{
    string text = Convert<QString>::Convert_QSTRtoSTR((ui->textEdit_write_Atext->toPlainText()));
    // 回答不可以为空
    if(""==text){
        ui->label_info->setText(QString::fromLocal8Bit("回答内容不可以为空！"));
        ui->label_info->setStyleSheet(QString("color: red"));
        ui->label_info->show();

        return;
    }

    Question(Question::g_QuesNow).add_answer(User::g_UserNow,text);

    uiset_prev = uiset;
    uiset = 4;

    close();
}
