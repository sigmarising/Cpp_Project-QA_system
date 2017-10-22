#ifndef D_FOCUSFULL_H
#define D_FOCUSFULL_H

#include <QDialog>

// begin - hide titlebar, mouse drag anywhere
#include <QMouseEvent>
#include "BackEnd/header/define.h"
// end - hide titlebar, mouse drag anywhere
#include "BackEnd/header/kernal.h"
#include "BackEnd/header/func.h"
#include <string>
using namespace std;

namespace Ui {
class d_focusFull;
}

class d_focusFull : public QDialog
{
    Q_OBJECT

public:
    explicit d_focusFull(QWidget *parent = 0);
    ~d_focusFull();

    // begin - hide titlebar, mouse drag anywhere
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    // end - hide titlebar, mouse drag anywhere

private slots:
    void on_pushButton_focusfull_return_clicked();

    void on_pushButton_focusfull_Prev_clicked();

    void on_pushButton_focusfull_Next_clicked();

    void on_pushButton_focusfull_focus_clicked();

private:
    Ui::d_focusFull *ui;

    User UserLook;

    // begin - hide titlebar, mouse drag anywhere
    QPoint last;
    // end - hide titlebar, mouse drag anywhere
};

#endif // D_FOCUSFULL_H
