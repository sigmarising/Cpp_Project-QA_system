#ifndef D_CHANGEKEY_H
#define D_CHANGEKEY_H

#include <QDialog>

// begin - hide titlebar, mouse drag anywhere
#include <QMouseEvent>
#include "BackEnd/header/define.h"
// end - hide titlebar, mouse drag anywhere

namespace Ui {
class d_changeKey;
}

class d_changeKey : public QDialog
{
    Q_OBJECT

public:
    explicit d_changeKey(QWidget *parent = 0);
    ~d_changeKey();

    // begin - hide titlebar, mouse drag anywhere
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    // end - hide titlebar, mouse drag anywhere

private slots:
    void on_pushButton_changeKey_return_clicked();

    void on_pushButton_changeKey_ok_clicked();

private:
    Ui::d_changeKey *ui;

    // begin - hide titlebar, mouse drag anywhere
    QPoint last;
    // end - hide titlebar, mouse drag anywhere
};

#endif // D_CHANGEKEY_H
