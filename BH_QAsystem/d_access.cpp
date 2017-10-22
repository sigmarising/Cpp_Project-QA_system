#include "d_access.h"
#include "ui_d_access.h"
#include "BackEnd/header/func.h"
#include "BackEnd/header/kernal.h"

d_access::d_access(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::d_access)
{
    ui->setupUi(this);

    // begin - hide titlebar, mouse drag anywhere
    this->setWindowFlags(Qt::FramelessWindowHint);
    // end - hide titlebar, mouse drag anywhere

    // hide the label
    ui->label_access_info->hide();

    // focus
    ui->pushButton_access_confirm->setFocus();
    ui->pushButton_access_confirm->setDefault(true);
}

d_access::~d_access()
{
    delete ui;
}

// begin - hide titlebar, mouse drag anywhere
void d_access::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void d_access::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void d_access::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

// end - hide titlebar, mouse drag anywhere

void d_access::on_pushButton_access_return_clicked()
{
    // return to uiset - login
    uiset_prev = uiset;
    uiset = 1;

    close();
}

void d_access::on_pushButton_access_confirm_clicked()
{
    // aceess the user

    // get the strings
    string U_Name = Convert<QString>::Convert_QSTRtoSTR(ui->lineEdit_access_Name->text());
    string U_Key1 = Convert<QString>::Convert_QSTRtoSTR(ui->lineEdit_access_Key1->text());
    string U_Key2 = Convert<QString>::Convert_QSTRtoSTR(ui->lineEdit_access_Key2->text());
    // we ban the null user name
    if (U_Name == ""){
        // label
        ui->label_access_info->setText(QString::fromLocal8Bit("用户名不可以为空！"));
        ui->label_access_info->setStyleSheet(QString("color: red"));
        ui->label_access_info->show();

        // line edit
        ui->lineEdit_access_Name->clear();
        ui->lineEdit_access_Key1->clear();
        ui->lineEdit_access_Key2->clear();
        ui->lineEdit_access_Name->setFocus();

        // must return
        return;
    }


    // we ban the null key
    if(U_Key1 == ""){
        // label
        ui->label_access_info->setText(QString::fromLocal8Bit("密码不可以为空！"));
        ui->label_access_info->setStyleSheet(QString("color: red"));
        ui->label_access_info->show();

        // line edit
        ui->lineEdit_access_Key1->clear();
        ui->lineEdit_access_Key2->clear();
        ui->lineEdit_access_Name->setFocus();

        // must return
        return;
    }


    if ("" == User::find_ID_from_Name(U_Name)){  // Name avaliable
        if(U_Key1 == U_Key2){ // key ok
            // create the user
            User(U_Name, U_Key1);

            // label
            ui->label_access_info->setText(QString::fromLocal8Bit("创建用户成功！"));
            ui->label_access_info->setStyleSheet(QString("color: green"));
            ui->label_access_info->show();

            // line edit
            ui->lineEdit_access_Name->clear();
            ui->lineEdit_access_Key1->clear();
            ui->lineEdit_access_Key2->clear();
            ui->lineEdit_access_Name->setFocus();
        }
        else{ // key wrong
            // label
            ui->label_access_info->setText(QString::fromLocal8Bit("密码输入不一致！"));
            ui->label_access_info->setStyleSheet(QString("color: red"));
            ui->label_access_info->show();

            // line edit
            ui->lineEdit_access_Key1->clear();
            ui->lineEdit_access_Key2->clear();
            ui->lineEdit_access_Key1->setFocus();
        }
    }
    else{ // name duplicate
        // label
        ui->label_access_info->setText(QString::fromLocal8Bit("此用户名已被使用！"));
        ui->label_access_info->setStyleSheet(QString("color: red"));
        ui->label_access_info->show();

        // line edit
        ui->lineEdit_access_Name->clear();
        ui->lineEdit_access_Key1->clear();
        ui->lineEdit_access_Key2->clear();
        ui->lineEdit_access_Name->setFocus();
    }
}
