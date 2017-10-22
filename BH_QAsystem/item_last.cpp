#include "item_last.h"
#include "ui_item_last.h"

item_last::item_last(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::item_last)
{
    ui->setupUi(this);
}

item_last::~item_last()
{
    delete ui;
}

void item_last::SetThisitem(const string &QAID){
    if(QAID.length()==10){//问题
        Question Q(QAID);

        ui->label_last_qa->setText( QString::fromLocal8Bit("提问了") );
        ui->label_last_praiseoransnum->setText(QString::fromLocal8Bit("回答数"));
        ui->label_last_num->setText(Convert<string>::Convert_STRtoQSTR(Convert<long>::Convert_TYPEtoSTR(Q.get_mNumtoAns())));
        ui->label_last_data->setText(Convert<string>::Convert_STRtoQSTR(Q.get_mTime()));
        ui->label_last_Qtitle->setText(Convert<string>::Convert_STRtoQSTR(Q.get_mTitle()));

        ui->textBrowser_last_text->setPlainText(Convert<string>::Convert_STRtoQSTR(Q.get_mText()));

    }
    else{//回答
        Answer A(QAID);
        Question Q(QAID.substr(0,10));

        ui->label_last_qa->setText( QString::fromLocal8Bit("回答了") );
        ui->label_last_praiseoransnum->setText(QString::fromLocal8Bit("点赞数"));
        ui->label_last_num->setText(Convert<string>::Convert_STRtoQSTR(Convert<long>::Convert_TYPEtoSTR(A.get_mpraiseNum())));
        ui->label_last_data->setText(Convert<string>::Convert_STRtoQSTR(A.get_mTime()));
        ui->label_last_Qtitle->setText(Convert<string>::Convert_STRtoQSTR(Q.get_mTitle()));

        ui->textBrowser_last_text->setPlainText(Convert<string>::Convert_STRtoQSTR(A.get_mText()));

    }
}
