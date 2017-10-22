#ifndef D_ASK_H
#define D_ASK_H

#include <QDialog>

// begin - hide titlebar, mouse drag anywhere
#include <QMouseEvent>
#include "BackEnd/header/define.h"
// end - hide titlebar, mouse drag anywhere

namespace Ui {
class d_ask;
}

class d_ask : public QDialog
{
    Q_OBJECT

public:
    explicit d_ask(QWidget *parent = 0);
    ~d_ask();

    // begin - hide titlebar, mouse drag anywhere
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    // end - hide titlebar, mouse drag anywhere

private slots:
    void on_pushButton_ask_return_clicked();

    void on_pushButton_ask_ok_clicked();

private:
    Ui::d_ask *ui;

    // begin - hide titlebar, mouse drag anywhere
    QPoint last;
    // end - hide titlebar, mouse drag anywhere
};

#endif // D_ASK_H
