#ifndef ITEM_LAST_H
#define ITEM_LAST_H

#include <QWidget>
#include "BackEnd/header/kernal.h"
#include "BackEnd/header/func.h"
#include <string>
using namespace std;

namespace Ui {
class item_last;
}

class item_last : public QWidget
{
    Q_OBJECT

public:
    explicit item_last(QWidget *parent = 0);
    ~item_last();

    void SetThisitem(const string &QAID);

private:
    Ui::item_last *ui;
};

#endif // ITEM_LAST_H
