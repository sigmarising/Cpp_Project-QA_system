#include "d_focus.h"
#include "ui_d_focus.h"
#include "item_focus.h"

#define ITEMF_WIDTH 369
#define ITEMF_HIGHT 92

d_focus::d_focus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::d_focus),
    UserNow(User::g_UserNow)
{
    ui->setupUi(this);

    // begin - hide titlebar, mouse drag anywhere
    this->setWindowFlags(Qt::FramelessWindowHint);
    // end - hide titlebar, mouse drag anywhere

    // begin - init list
    ui->listWidget_focus_list->clear();
    UserNow.load_f();
    for(int i = 0;i<UserNow.m_focuslist.size(); i++){
        //init list item
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_focus_list);
        item->setSizeHint(QSize(ITEMF_WIDTH,ITEMF_HIGHT));
        //widget
        item_focus *sublink = new item_focus;
        sublink->SetThisItem(UserNow.m_focuslist[i]);
        //link
        ui->listWidget_focus_list->setItemWidget(item, sublink);
        ui->listWidget_focus_list->addItem(item);
    }
    // end - init list
}

d_focus::~d_focus()
{
    delete ui;
}

// begin - hide titlebar, mouse drag anywhere
void d_focus::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void d_focus::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void d_focus::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

// end - hide titlebar, mouse drag anywhere

void d_focus::on_pushButton_focus_return_clicked()
{
    uiset_prev=uiset;
    uiset = 8;

    close();
}

void d_focus::on_pushButton__focus_Prev_clicked()
{
    // begin - init list
    ui->listWidget_focus_list->clear();
    UserNow.load_f(false);
    for(int i = 0;i<UserNow.m_focuslist.size(); i++){
        //init list item
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_focus_list);
        item->setSizeHint(QSize(ITEMF_WIDTH,ITEMF_HIGHT));
        //widget
        item_focus *sublink = new item_focus;
        sublink->SetThisItem(UserNow.m_focuslist[i]);
        //link
        ui->listWidget_focus_list->setItemWidget(item, sublink);
        ui->listWidget_focus_list->addItem(item);
    }
    // end - init list
}

void d_focus::on_pushButton_focus_Next_clicked()
{
    // begin - init list
    ui->listWidget_focus_list->clear();
    UserNow.load_f(true);
    for(int i = 0;i<UserNow.m_focuslist.size(); i++){
        //init list item
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_focus_list);
        item->setSizeHint(QSize(ITEMF_WIDTH,ITEMF_HIGHT));
        //widget
        item_focus *sublink = new item_focus;
        sublink->SetThisItem(UserNow.m_focuslist[i]);
        //link
        ui->listWidget_focus_list->setItemWidget(item, sublink);
        ui->listWidget_focus_list->addItem(item);
    }
    // end - init list
}

void d_focus::on_listWidget_focus_list_itemDoubleClicked(QListWidgetItem *item)
{
    Q_UNUSED(item);

    User::g_UserLook = UserNow.m_focuslist[ui->listWidget_focus_list->currentRow()];
    User::tNum_QA =1;

    uiset_prev=uiset;
    uiset = 11;

    close();
}
