#include "d_focusfull.h"
#include "ui_d_focusfull.h"
#include "item_last.h"

#define ITEML_WIDTH 450
#define ITEML_HEIGHT 160

d_focusFull::d_focusFull(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::d_focusFull),
    UserLook(User::g_UserLook)
{
    ui->setupUi(this);

    // begin - hide titlebar, mouse drag anywhere, glass shadow border
    this->setWindowFlags(Qt::FramelessWindowHint);
    // end - hide titlebar, mouse drag anywhere, glass shadow border

    ui->label_focusfull_Username->setText(Convert<string>::Convert_STRtoQSTR(UserLook.getm_Name()));


    if(User(User::g_UserNow).check_focus(User::g_UserLook)){//已关注
        ui->pushButton_focusfull_focus->setStyleSheet("border-image: url(:/icons/resource/Focus_Yes.png);");
    }
    else{//未关注
        User(User::g_UserNow).add_focus(User::g_UserLook);
        ui->pushButton_focusfull_focus->setStyleSheet("border-image: url(:/icons/resource/Focus_No.png);");
    }

    // begin - init list
    ui->listWidget_focusfull_list->clear();
    UserLook.load_qa();
    for(int i = 0; i<UserLook.m_qalist.size();i++){
        //init item
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_focusfull_list);
        item->setSizeHint(QSize(ITEML_WIDTH,ITEML_HEIGHT));
        //widget
        item_last *sublink = new item_last;
        sublink->SetThisitem(UserLook.m_qalist[i]);
        //link
        ui->listWidget_focusfull_list->setItemWidget(item, sublink);
        ui->listWidget_focusfull_list->addItem(item);
    }
    // end - init list
}

d_focusFull::~d_focusFull()
{
    delete ui;
}

// begin - hide titlebar, mouse drag anywhere
void d_focusFull::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void d_focusFull::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void d_focusFull::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

// end - hide titlebar, mouse drag anywhere

void d_focusFull::on_pushButton_focusfull_return_clicked()
{
    uiset_prev=uiset;
    uiset = 10;

    close();
}

void d_focusFull::on_pushButton_focusfull_Prev_clicked()
{
    // begin - init list
    ui->listWidget_focusfull_list->clear();
    UserLook.load_qa(false);
    for(int i = 0; i<UserLook.m_qalist.size();i++){
        //init item
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_focusfull_list);
        item->setSizeHint(QSize(ITEML_WIDTH,ITEML_HEIGHT));
        //widget
        item_last *sublink = new item_last;
        sublink->SetThisitem(UserLook.m_qalist[i]);
        //link
        ui->listWidget_focusfull_list->setItemWidget(item, sublink);
        ui->listWidget_focusfull_list->addItem(item);
    }
    // end - init list
}

void d_focusFull::on_pushButton_focusfull_Next_clicked()
{
    // begin - init list
    ui->listWidget_focusfull_list->clear();
    UserLook.load_qa(true);
    for(int i = 0; i<UserLook.m_qalist.size();i++){
        //init item
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_focusfull_list);
        item->setSizeHint(QSize(ITEML_WIDTH,ITEML_HEIGHT));
        //widget
        item_last *sublink = new item_last;
        sublink->SetThisitem(UserLook.m_qalist[i]);
        //link
        ui->listWidget_focusfull_list->setItemWidget(item, sublink);
        ui->listWidget_focusfull_list->addItem(item);
    }
    // end - init list
}

void d_focusFull::on_pushButton_focusfull_focus_clicked()
{
    if(User(User::g_UserNow).check_focus(User::g_UserLook)){//已关注
        User(User::g_UserNow).remove_focus(User::g_UserLook);
        if(!(User::g_UserLook == User::g_UserNow))
            ui->pushButton_focusfull_focus->setStyleSheet("border-image: url(:/icons/resource/Focus_No.png);");
    }
    else{//未关注
        User(User::g_UserNow).add_focus(User::g_UserLook);
        ui->pushButton_focusfull_focus->setStyleSheet("border-image: url(:/icons/resource/Focus_Yes.png);");
    }
}
