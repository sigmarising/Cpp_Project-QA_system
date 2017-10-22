#include "item_question.h"
#include "ui_item_question.h"
#include "BackEnd/header/kernal.h"

item_Question::item_Question(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::item_Question)
{
    ui->setupUi(this);
}

item_Question::~item_Question()
{
    delete ui;
}

void item_Question::setThisItem(const string &QID)
{
    Question Q(QID);
    ui->label_itemq_AnsNum->setText( Convert<string>::Convert_STRtoQSTR(Convert<long>::Convert_TYPEtoSTR(Q.get_mNumtoAns()) ) );
    ui->label_itemq_time->setText(Convert<string>::Convert_STRtoQSTR( Q.get_mTime() ) );
    User U(Q.get_mUserID());
    ui->label_itemq_user->setText( Convert<string>::Convert_STRtoQSTR( U.getm_Name()) );

    ui->label_itemq_title->setText( Convert<string>::Convert_STRtoQSTR( Q.get_mTitle() ) );
    ui->textBrowser_itemq_text->setPlainText( Convert<string>::Convert_STRtoQSTR( Q.get_mText() ) );
}
