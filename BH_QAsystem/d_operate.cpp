#include <QListWidget>
#include <QListWidgetItem>
#include "d_operate.h"
#include "ui_d_operate.h"
#include "BackEnd/header/define.h"
#include "item_question.h"

#define ITEMQ_WIDTH 454
#define ITEMQ_HEIGHT 158

D_operate::D_operate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::D_operate),
    U(User::g_UserNow), // init the user
    FindorNot(false)
{
    ui->setupUi(this);

    // begin - hide titlebar, mouse drag anywhere, glass shadow border
    this->setWindowFlags(Qt::FramelessWindowHint);
    // end - hide titlebar, mouse drag anywhere, glass shadow border

    // focus
    ui->pushButton_operate_Next->setFocus();
    ui->pushButton_operate_Next->setDefault(true);
    ui->radioButton_operate_Title->setChecked(true);

    // label - name
    ui->label_operate_User->setText( Convert<string>::Convert_STRtoQSTR(U.getm_Name()) );


    // begin - init list
    ui->listWidget_operate_List->clear();  // clear list
    QL.load_question(FindorNot);     // default load
    for(int i = 0; i < QL.m_questionList.size(); i++){
        // init list item
        // use pointer to avoid delete
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_operate_List);
        item->setSizeHint(QSize(ITEMQ_WIDTH,ITEMQ_HEIGHT));  // set box
        // create widget
        // use pointer to avoid delete
        item_Question *sublink = new item_Question;
        // setup widget
        sublink->setThisItem(QL.m_questionList[i]);
        // link
        ui->listWidget_operate_List->setItemWidget(item, sublink);
        ui->listWidget_operate_List->addItem(item);
    }
    // end - init list
}

D_operate::~D_operate()
{
    if(FindorNot) // 如果进行了搜索操作 再次返回后需要重置列表
        QuesList::tNum = 1;

    delete ui;
}

// begin - hide titlebar, mouse drag anywhere
void D_operate::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void D_operate::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void D_operate::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}
// end - hide titlebar, mouse drag anywhere

void D_operate::on_pushButton_operate_AboutMe_clicked()
{
    // goto uiset - about me
    uiset_prev = uiset;
    uiset = 8;

    close();
}

void D_operate::on_pushButton_operate_Prev_clicked()
{
    // begin - init list
    ui->listWidget_operate_List->clear();  // clear list
    QL.load_question(false, FindorNot);     // default load
    for(int i = 0; i < QL.m_questionList.size(); i++){
        // init list item
        // use pointer to avoid delete
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_operate_List);
        item->setSizeHint(QSize(ITEMQ_WIDTH,ITEMQ_HEIGHT));  // set box
        // create widget
        // use pointer to avoid delete
        item_Question *sublink = new item_Question;
        // setup widget
        sublink->setThisItem(QL.m_questionList[i]);
        // link
        ui->listWidget_operate_List->setItemWidget(item, sublink);
        ui->listWidget_operate_List->addItem(item);
    }
    // end - init list
}

void D_operate::on_pushButton_operate_Next_clicked()
{
    // begin - init list
    ui->listWidget_operate_List->clear();  // clear list
    QL.load_question(true, FindorNot);     // default load
    for(int i = 0; i < QL.m_questionList.size(); i++){
        // init list item
        // use pointer to avoid delete
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_operate_List);
        item->setSizeHint(QSize(ITEMQ_WIDTH,ITEMQ_HEIGHT));  // set box
        // create widget
        // use pointer to avoid delete
        item_Question *sublink = new item_Question;
        // setup widget
        sublink->setThisItem(QL.m_questionList[i]);
        // link
        ui->listWidget_operate_List->setItemWidget(item, sublink);
        ui->listWidget_operate_List->addItem(item);
    }
    // end - init list
}

void D_operate::on_pushButton_operate_ask_clicked()
{
    uiset_prev = uiset;
    uiset = 5;

    close();
}

void D_operate::on_pushButton_operate_search_clicked()
{
    ui->listWidget_operate_List->clear();  // clear list
    FindorNot = true;
    QuesList::tNum = 1;

    string str = Convert<QString>::Convert_QSTRtoSTR(ui->lineEdit_operate_search_str->text());
    if(""==str){ //排除空串

        return;
    }
    if(ui->radioButton_operate_Title->isChecked()){
        QL.findQuestion(str);
    }
    else{
        DataTime DT;
        DT.set_DataTime(str);
        QL.findQuestion(DT);
    }

    // begin - init list
    ui->listWidget_operate_List->clear();  // clear list
    QL.load_question(FindorNot);     // default load
    for(int i = 0; i < QL.m_questionList.size(); i++){
        // init list item
        // use pointer to avoid delete
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_operate_List);
        item->setSizeHint(QSize(ITEMQ_WIDTH,ITEMQ_HEIGHT));  // set box
        // create widget
        // use pointer to avoid delete
        item_Question *sublink = new item_Question;
        // setup widget
        sublink->setThisItem(QL.m_questionList[i]);
        // link
        ui->listWidget_operate_List->setItemWidget(item, sublink);
        ui->listWidget_operate_List->addItem(item);
    }
    // end - init list
}

void D_operate::on_listWidget_operate_List_itemDoubleClicked(QListWidgetItem *item)
{
    Q_UNUSED(item);
    // get the row num and find the corr string id
    Question::g_QuesNow = QL.m_questionList[ui->listWidget_operate_List->currentRow()];
    Question::tNum = 1; // init

    uiset_prev = uiset;
    uiset = 4;


    close();
}


void D_operate::on_pushButton_operate_reset_clicked()
{
    FindorNot = false;
    QuesList::tNum = 1;

    ui->lineEdit_operate_search_str->clear();

    // begin - init list
    ui->listWidget_operate_List->clear();  // clear list
    QL.load_question(FindorNot);     // default load
    for(int i = 0; i < QL.m_questionList.size(); i++){
        // init list item
        // use pointer to avoid delete
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_operate_List);
        item->setSizeHint(QSize(ITEMQ_WIDTH,ITEMQ_HEIGHT));  // set box
        // create widget
        // use pointer to avoid delete
        item_Question *sublink = new item_Question;
        // setup widget
        sublink->setThisItem(QL.m_questionList[i]);
        // link
        ui->listWidget_operate_List->setItemWidget(item, sublink);
        ui->listWidget_operate_List->addItem(item);
    }
    // end - init list
}
