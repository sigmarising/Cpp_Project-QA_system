#include "BackEnd/header/qtfunc.h"
#include "BackEnd/header/define.h"
#include "BackEnd/header/kernal.h"

func::Qtfunc::Qtfunc()
{

}

void func::Qtfunc::ListWidget_AddWidget(QListWidget *TargetList, list<string>sourceList, QWidget *sublink)
{
    for(int i = 1; i < MAX_LIST_NUM; i++){
        // init list item
        // use point to avoid delete
        QListWidgetItem *item = new QListWidgetItem(TargetList);
        // create win
        // use point to avoid delete
        sublink = new item_Question;
        // load question
        Question Q(sourceList[i]);
        sublink->setThisItem(User(Q.get_mUserID()).getm_Name(), Q.get_mNumtoAns(), Q.get_mTime(), Q.get_mTitle());
        // link
        ui->listWidget_operate_List->setItemWidget(item, sublink);
        ui->listWidget_operate_List->addItem(item);
    }
}
