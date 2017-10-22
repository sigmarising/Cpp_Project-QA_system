#ifndef D_OPERATE_H
#define D_OPERATE_H

#include <QDialog>
#include <QListWidgetItem>
#include "BackEnd/header/kernal.h"
#include "BackEnd/header/func.h"

// begin - hide titlebar, mouse drag anywhere
#include <QMouseEvent>
#include "BackEnd/header/define.h"
// end - hide titlebar, mouse drag anywhere

namespace Ui {
class D_operate;
}

class D_operate : public QDialog
{
    Q_OBJECT

public:
    explicit D_operate(QWidget *parent = 0);
    ~D_operate();

    // begin - hide titlebar, mouse drag anywhere, glass shadow border
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    // end - hide titlebar, mouse drag anywhere, glass shadow border

private slots:
    void on_pushButton_operate_AboutMe_clicked();

    void on_pushButton_operate_Prev_clicked();

    void on_pushButton_operate_Next_clicked();

    void on_pushButton_operate_ask_clicked();

    void on_pushButton_operate_search_clicked();

    void on_listWidget_operate_List_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_operate_reset_clicked();

private:
    Ui::D_operate *ui;

    User U;
    QuesList QL;
    bool FindorNot;

    // begin - hide titlebar, mouse drag anywhere
    QPoint last;
    // end - hide titlebar, mouse drag anywhere
};

#endif // D_OPERATE_H
