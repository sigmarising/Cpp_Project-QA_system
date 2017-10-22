#include "d_answer.h"
#include "ui_d_answer.h"

d_answer::d_answer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::d_answer),
    UserNow(User::g_UserNow),
    QueNow(Question::g_QuesNow),
    AnsNow(Answer::g_AnswerNow)
{
    ui->setupUi(this);

    // begin - hide titlebar, mouse drag anywhere
    this->setWindowFlags(Qt::FramelessWindowHint);
    // end - hide titlebar, mouse drag anywhere

    if(UserNow.check_focus(AnsNow.get_mUserID())){//已关注
        ui->pushButton_ask_focus->setStyleSheet("border-image: url(:/icons/resource/Focus_Yes.png);");
    }
    else{//未关注
        ui->pushButton_ask_focus->setStyleSheet("border-image: url(:/icons/resource/Focus_No.png);");
    }

    if(AnsNow.already_praise(UserNow.getm_ID())){//已赞
        ui->pushButton_ask_praise->setStyleSheet("border-image: url(:/icons/resource/Praise_Yes.png);");
    }
    else{// 未赞
        ui->pushButton_ask_praise->setStyleSheet("border-image: url(:/icons/resource/Praise_No.png);");
    }

    //settext
    ui->label_ask_user->setText(Convert<string>::Convert_STRtoQSTR(User(AnsNow.get_mUserID()).getm_Name()) );
    ui->label_ask_QueTitle->setText(Convert<string>::Convert_STRtoQSTR(QueNow.get_mTitle()));
    ui->textBrowser_ask_Qtext->setPlainText(Convert<string>::Convert_STRtoQSTR(QueNow.get_mText()));
    ui->textBrowser_ask_Atext->setPlainText(Convert<string>::Convert_STRtoQSTR(AnsNow.get_mText()));
    ui->label_ask_praiseNum->setText(Convert<string>::Convert_STRtoQSTR(Convert<long>::Convert_TYPEtoSTR(AnsNow.get_mpraiseNum())));
    ui->label_Qtime->setText(Convert<string>::Convert_STRtoQSTR(AnsNow.get_mTime()));
}

d_answer::~d_answer()
{
    delete ui;
}

// begin - hide titlebar, mouse drag anywhere
void d_answer::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void d_answer::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void d_answer::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}
// end - hide titlebar, mouse drag anywhere

void d_answer::on_pushButton_ask_return_clicked()
{
    uiset_prev = uiset;
    uiset = 4;

    close();
}

void d_answer::on_pushButton_ask_focus_clicked()
{
    if(UserNow.check_focus(AnsNow.get_mUserID())){//已关注 进行取消关注
        UserNow.remove_focus(AnsNow.get_mUserID());
        if(!(AnsNow.get_mUserID() == UserNow.getm_ID()))
            ui->pushButton_ask_focus->setStyleSheet("border-image: url(:/icons/resource/Focus_No.png);");
    }
    else{// 未关注 进行关注
        UserNow.add_focus(AnsNow.get_mUserID());
        ui->pushButton_ask_focus->setStyleSheet("border-image: url(:/icons/resource/Focus_Yes.png);");
    }
}

void d_answer::on_pushButton_ask_praise_clicked()
{
    if(AnsNow.already_praise(UserNow.getm_ID())){//已赞
        AnsNow.sub1_mpraiseNum(UserNow.getm_ID());
        ui->pushButton_ask_praise->setStyleSheet("border-image: url(:/icons/resource/Praise_No.png);");
    }
    else{// 未赞
        AnsNow.add1_mpraiseNum(UserNow.getm_ID());
        ui->pushButton_ask_praise->setStyleSheet("border-image: url(:/icons/resource/Praise_Yes.png);");
    }
    ui->label_ask_praiseNum->setText(Convert<string>::Convert_STRtoQSTR(Convert<long>::Convert_TYPEtoSTR(AnsNow.get_mpraiseNum())));
}
