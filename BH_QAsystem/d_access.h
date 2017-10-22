#ifndef D_ACCESS_H
#define D_ACCESS_H

#include <QDialog>

// begin - hide titlebar, mouse drag anywhere
#include <QMouseEvent>
#include "BackEnd/header/define.h"
// end - hide titlebar, mouse drag anywhere

namespace Ui {
class d_access;
}

class d_access : public QDialog
{
    Q_OBJECT

public:
    explicit d_access(QWidget *parent = 0);
    ~d_access();

    // begin - hide titlebar, mouse drag anywhere
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    // end - hide titlebar, mouse drag anywhere

private slots:
    void on_pushButton_access_return_clicked();

    void on_pushButton_access_confirm_clicked();

private:
    Ui::d_access *ui;

    // begin - hide titlebar, mouse drag anywhere, glass shadow border
    QPoint last;
    // end - hide titlebar, mouse drag anywhere, glass shadow border
};

#endif // D_ACCESS_H
