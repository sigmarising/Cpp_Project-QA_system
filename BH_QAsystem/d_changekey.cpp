#include <string>
#include "d_changekey.h"
#include "ui_d_changekey.h"
#include "BackEnd/header/kernal.h"
#include "BackEnd/header/func.h"
using namespace std;

d_changeKey::d_changeKey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::d_changeKey)
{
    ui->setupUi(this);

    // begin - hide titlebar, mouse drag anywhere, glass shadow border
    this->setWindowFlags(Qt::FramelessWindowHint);
    // end - hide titlebar, mouse drag anywhere, glass shadow border

    ui->label_changeKey_info->hide();
}

d_changeKey::~d_changeKey()
{
    delete ui;
}

// begin - hide titlebar, mouse drag anywhere
void d_changeKey::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void d_changeKey::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void d_changeKey::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}
// end - hide titlebar, mouse drag anywhere

void d_changeKey::on_pushButton_changeKey_return_clicked()
{
    uiset_prev = uiset;
    uiset = 8;

    close();
}

void d_changeKey::on_pushButton_changeKey_ok_clicked()
{
    string Key_old = Convert<QString>::Convert_QSTRtoSTR(ui->lineEdit_changeKey_oldKey->text());
    string Key_1 = Convert<QString>::Convert_QSTRtoSTR(ui->lineEdit_changeKey_key1->text());
    string Key_2 =Convert<QString>::Convert_QSTRtoSTR(ui->lineEdit_changeKey_key2->text());

    User U(User::g_UserNow);
    if(U.check_key(Key_old)){// key正确
        // 防止空的新密码
        if(Key_1 == ""){
            ui->label_changeKey_info->setText( QString::fromLocal8Bit("新密码不可以为空！") );
            ui->label_changeKey_info->setStyleSheet(QString("color: red"));
            ui->label_changeKey_info->show();

            ui->lineEdit_changeKey_oldKey->clear();
            ui->lineEdit_changeKey_key1->clear();
            ui->lineEdit_changeKey_key2->clear();

            // 必须return
            return;
        }

        if(Key_1 == Key_2){// 可以修改
            U.key_change(Key_1);

            ui->label_changeKey_info->setText( QString::fromLocal8Bit("修改成功！") );
            ui->label_changeKey_info->setStyleSheet(QString("color: green"));
            ui->label_changeKey_info->show();

            ui->lineEdit_changeKey_oldKey->clear();
            ui->lineEdit_changeKey_key1->clear();
            ui->lineEdit_changeKey_key2->clear();
        }
        else{// 不可以修改
            ui->label_changeKey_info->setText( QString::fromLocal8Bit("新密码不一致！") );
            ui->label_changeKey_info->setStyleSheet(QString("color: red"));
            ui->label_changeKey_info->show();

            ui->lineEdit_changeKey_oldKey->clear();
            ui->lineEdit_changeKey_key1->clear();
            ui->lineEdit_changeKey_key2->clear();
            ui->lineEdit_changeKey_oldKey->setFocus();
        }
    }
    else{// key不正确
        ui->label_changeKey_info->setText( QString::fromLocal8Bit("原密码不正确！") );
        ui->label_changeKey_info->setStyleSheet(QString("color: red"));
        ui->label_changeKey_info->show();

        ui->lineEdit_changeKey_oldKey->clear();
        ui->lineEdit_changeKey_key1->clear();
        ui->lineEdit_changeKey_key2->clear();
        ui->lineEdit_changeKey_oldKey->setFocus();
    }
}
