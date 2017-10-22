#include "d_login.h"
#include "ui_d_login.h"
#include "BackEnd/header/kernal.h"
#include "BackEnd/header/func.h"

d_login::d_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::d_login)
{
    ui->setupUi(this);

    // begin - hide titlebar, mouse drag anywhere
    this->setWindowFlags(Qt::FramelessWindowHint);
    // end - hide titlebar, mouse drag anywhere

    // hide the label
    ui->label_login_info->hide();

    // set button focus
    //ui->pushButton_login_login->setFocus();
    ui->pushButton_login_login->setDefault(true);
}

d_login::~d_login()
{
    delete ui;
}


// begin - hide titlebar, mouse drag anywhere
void d_login::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void d_login::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void d_login::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

// end - hide titlebar, mouse drag anywhere


void d_login::on_pushButton_login_quit_clicked()
{
    // exit
    SysRun = false;

    close();
}

void d_login::on_pushButton_login_access_clicked()
{
    // goto ui - access
    uiset_prev = uiset;
    uiset = 2;

    close();
}

void d_login::on_pushButton_login_login_clicked()
{
    // login
    string U_Name = Convert<QString>::Convert_QSTRtoSTR(ui->lineEdit_login_Name->text());
    string U_Key = Convert<QString>::Convert_QSTRtoSTR(ui->lineEdit_login_Key->text());
    string U_ID = User::find_ID_from_Name(U_Name);

    if ("" != U_ID){  // u_name ok
        User U(U_ID);
        if (U.check_key(U_Key)) { // key ok
            // goto uiset - operate
            uiset_prev = uiset;
            uiset = 3;

            User::g_UserNow = U_ID; // the U_ID
            QuesList::tNum = 1; // 初始化操作

            close();
        }
        else{ // key wrong
            ui->label_login_info->setText( QString::fromLocal8Bit("密码错误！") );
            ui->label_login_info->setStyleSheet(QString("color: red"));
            ui->label_login_info->show();

            // line edit reset
            ui->lineEdit_login_Key->clear();
            ui->lineEdit_login_Key->setFocus();
        }
    }
    else{ // doesn't have this u_name
        ui->label_login_info->setText( QString::fromLocal8Bit("用户名错误！") );
        ui->label_login_info->setStyleSheet(QString("color: red"));
        ui->label_login_info->show();

        // line edit reset
        ui->lineEdit_login_Name->clear();
        ui->lineEdit_login_Key->clear();
        ui->lineEdit_login_Name->setFocus();
    }
}
