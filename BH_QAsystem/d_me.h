#ifndef D_ME_H
#define D_ME_H

#include <QDialog>

// begin - hide titlebar, mouse drag anywhere
#include <QMouseEvent>
#include "BackEnd/header/define.h"
// end - hide titlebar, mouse drag anywhere

namespace Ui {
class d_me;
}

class d_me : public QDialog
{
    Q_OBJECT

public:
    explicit d_me(QWidget *parent = 0);
    ~d_me();

    // begin - hide titlebar, mouse drag anywhere
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    // end - hide titlebar, mouse drag anywhere

private slots:
    void on_pushButton__write_logout_clicked();

    void on_pushButton_me_return_clicked();

    void on_pushButton_write_changeKey_clicked();

    void on_pushButton_write_focus_clicked();

private:
    Ui::d_me *ui;

    // begin - hide titlebar, mouse drag anywhere
    QPoint last;
    // end - hide titlebar, mouse drag anywhere
};

#endif // D_ME_H
