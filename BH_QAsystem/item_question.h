#ifndef ITEM_QUESTION_H
#define ITEM_QUESTION_H

#include <QWidget>
#include <string>
#include "BackEnd/header/func.h"
using namespace std;

namespace Ui {
class item_Question;
}

class item_Question : public QWidget
{
    Q_OBJECT

public:
    explicit item_Question(QWidget *parent = 0);
    ~item_Question();

    void setThisItem(const string &QID);
private:
    Ui::item_Question *ui;
};

#endif // ITEM_QUESTION_H
