#include "item_answer.h"
#include "ui_item_answer.h"

item_answer::item_answer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::item_answer)
{
    ui->setupUi(this);
}

item_answer::~item_answer()
{
    delete ui;
}

void item_answer::SetThisItem(const string &AnsID){
    Answer A(AnsID);
    User U(A.get_mUserID());

    ui->label_itemans_ansUser->setText( Convert<string>::Convert_STRtoQSTR(U.getm_Name()) );
    ui->label_itemans_date->setText( Convert<string>::Convert_STRtoQSTR(A.get_mTime()) );
    ui->label_itemans_praisNum ->setText( Convert<string>::Convert_STRtoQSTR( Convert<long>::Convert_TYPEtoSTR(A.get_mpraiseNum()) ) );

    ui->textBrowser_itemans_text->setPlainText( Convert<string>::Convert_STRtoQSTR(A.get_mText()) );
}
