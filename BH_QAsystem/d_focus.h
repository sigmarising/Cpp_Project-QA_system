#ifndef D_FOCUS_H
#define D_FOCUS_H

#include <QDialog>

#include <string>
// begin - hide titlebar, mouse drag anywhere
#include <QMouseEvent>
#include "BackEnd/header/define.h"
// end - hide titlebar, mouse drag anywhere
#include "BackEnd/header/kernal.h"
#include "BackEnd/header/func.h"
#include <QListWidgetItem>
using namespace std;

namespace Ui {
class d_focus;
}

class d_focus : public QDialog
{
    Q_OBJECT

public:
    explicit d_focus(QWidget *parent = 0);
    ~d_focus();

    // begin - hide titlebar, mouse drag anywhere
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    // end - hide titlebar, mouse drag anywhere

private slots:
    void on_pushButton_focus_return_clicked();

    void on_pushButton__focus_Prev_clicked();

    void on_pushButton_focus_Next_clicked();

    void on_listWidget_focus_list_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::d_focus *ui;
    User UserNow;

    // begin - hide titlebar, mouse drag anywhere
    QPoint last;
    // end - hide titlebar, mouse drag anywhere
};

#endif // D_FOCUS_H
