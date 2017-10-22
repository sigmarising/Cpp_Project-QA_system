#include "item_focus.h"
#include "ui_item_focus.h"

item_focus::item_focus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::item_focus)
{
    ui->setupUi(this);
}

item_focus::~item_focus()
{
    delete ui;
}

void item_focus::SetThisItem(const string &UserID){
    User U(UserID);

    ui->label_itemf_UserName->setText(Convert<string>::Convert_STRtoQSTR(U.getm_Name()));
    ui->label_itemf_Num->setText(Convert<string>::Convert_STRtoQSTR(Convert<long>::Convert_TYPEtoSTR(U.getmNum_QA())));
}
