#ifndef ITEM_FOCUS_H
#define ITEM_FOCUS_H

#include <QWidget>
#include <string>
#include "BackEnd/header/func.h"
#include "BackEnd/header/kernal.h"
#include "BackEnd/header/define.h"
using namespace std;

namespace Ui {
class item_focus;
}

class item_focus : public QWidget
{
    Q_OBJECT

public:
    explicit item_focus(QWidget *parent = 0);
    ~item_focus();

    void SetThisItem(const string &UserID);
private:
    Ui::item_focus *ui;
};

#endif // ITEM_FOCUS_H
