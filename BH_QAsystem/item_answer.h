#ifndef ITEM_ANSWER_H
#define ITEM_ANSWER_H

#include <QWidget>
#include <string>
#include "BackEnd/header/kernal.h"
#include "BackEnd/header/func.h"
#include "BackEnd/header/define.h"
using namespace std;

namespace Ui {
class item_answer;
}

class item_answer : public QWidget
{
    Q_OBJECT

public:
    explicit item_answer(QWidget *parent = 0);
    ~item_answer();

    // 使用AnsID来初始化本widget
    void SetThisItem(const string &AnsID);
private:
    Ui::item_answer *ui;
};

#endif // ITEM_ANSWER_H
