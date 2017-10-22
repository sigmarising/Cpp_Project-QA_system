#include "d_question.h"
#include "ui_d_question.h"
#include "item_answer.h"

#define ITEMA_WIDTH 450
#define ITEMA_HEIGH 154

d_question::d_question(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::d_question),
    UserNow(User::g_UserNow),
    QueNow(Question::g_QuesNow)
{
    ui->setupUi(this);

    // begin - hide titlebar, mouse drag anywhere
    this->setWindowFlags(Qt::FramelessWindowHint);
    // end - hide titlebar, mouse drag anywhere

    // focus
    ui->pushButton__question_Next->setFocus();
    ui->pushButton__question_Next->setDefault(true);

    // settext
    ui->label_question_Quser->setText(Convert<string>::Convert_STRtoQSTR(User(QueNow.get_mUserID()).getm_Name()));
    ui->label_question_title->setText(Convert<string>::Convert_STRtoQSTR(QueNow.get_mTitle()));
    ui->textBrowser_question_text->setPlainText(Convert<string>::Convert_STRtoQSTR(QueNow.get_mText()));
    ui->label_question_Time->setText(Convert<string>::Convert_STRtoQSTR(QueNow.get_mTime()));

    // 关注
    if(UserNow.check_focus(QueNow.get_mUserID())){ //已关注
        ui->pushButton_question_focus->setStyleSheet("border-image: url(:/icons/resource/Focus_Yes.png);");
    }
    else{// 未关注
        ui->pushButton_question_focus->setStyleSheet("border-image: url(:/icons/resource/Focus_No.png);");
    }


    // begin - init list
    ui->listWidget_question_ansList->clear();
    QueNow.load_AnsList();
    for(int i = 0; i<QueNow.m_AnsList.size(); i++){
        // init list item
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_question_ansList);
        item->setSizeHint(QSize(ITEMA_WIDTH,ITEMA_HEIGH));
        // widget
        item_answer *sublink = new item_answer;
        sublink->SetThisItem(QueNow.m_AnsList[i]);
        // link
        ui->listWidget_question_ansList->setItemWidget(item, sublink);
        ui->listWidget_question_ansList->addItem(item);
    }
    // end - init list
}

d_question::~d_question()
{
    delete ui;
}

// begin - hide titlebar, mouse drag anywhere
void d_question::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void d_question::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void d_question::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

// end - hide titlebar, mouse drag anywhere

void d_question::on_pushButton_question_return_clicked()
{
    uiset_prev = uiset;
    uiset = 3;

    close();
}

void d_question::on_pushButton_question_focus_clicked()
{
    if(UserNow.check_focus(QueNow.get_mUserID())){ //已关注 进行取消关注
        UserNow.remove_focus(QueNow.get_mUserID());
        if(!(QueNow.get_mUserID() == UserNow.getm_ID()) )//自己不可以取消关注自己
            ui->pushButton_question_focus->setStyleSheet("border-image: url(:/icons/resource/Focus_No.png);");
    }
    else{// 未关注 进行关注
        UserNow.add_focus(QueNow.get_mUserID());
        ui->pushButton_question_focus->setStyleSheet("border-image: url(:/icons/resource/Focus_Yes.png);");
    }
}

void d_question::on_pushButton__question_Write_clicked()
{
    uiset_prev = uiset;
    uiset = 7;

    close();
}

void d_question::on_pushButton_question_Prev_clicked()
{
    // begin - init list
    ui->listWidget_question_ansList->clear();
    QueNow.load_AnsList(false);
    for(int i = 0; i<QueNow.m_AnsList.size(); i++){
        // init list item
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_question_ansList);
        item->setSizeHint(QSize(ITEMA_WIDTH,ITEMA_HEIGH));
        // widget
        item_answer *sublink = new item_answer;
        sublink->SetThisItem(QueNow.m_AnsList[i]);
        // link
        ui->listWidget_question_ansList->setItemWidget(item, sublink);
        ui->listWidget_question_ansList->addItem(item);
    }
    // end - init list
}


void d_question::on_pushButton__question_Next_clicked()
{
    // begin - init list
    ui->listWidget_question_ansList->clear();
    QueNow.load_AnsList(true);
    for(int i = 0; i<QueNow.m_AnsList.size(); i++){
        // init list item
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_question_ansList);
        item->setSizeHint(QSize(ITEMA_WIDTH,ITEMA_HEIGH));
        // widget
        item_answer *sublink = new item_answer;
        sublink->SetThisItem(QueNow.m_AnsList[i]);
        // link
        ui->listWidget_question_ansList->setItemWidget(item, sublink);
        ui->listWidget_question_ansList->addItem(item);
    }
    // end - init list
}

void d_question::on_listWidget_question_ansList_itemDoubleClicked(QListWidgetItem *item){
    Q_UNUSED(item);

    Answer::g_AnswerNow = QueNow.m_AnsList[ui->listWidget_question_ansList->currentRow()];

    uiset_prev=uiset;
    uiset = 6;

    close();
}
