#ifndef D_WRITE_H
#define D_WRITE_H

#include <QDialog>

// begin - hide titlebar, mouse drag anywhere
#include <QMouseEvent>
#include "BackEnd/header/define.h"
// end - hide titlebar, mouse drag anywhere

namespace Ui {
class d_write;
}

class d_write : public QDialog
{
    Q_OBJECT

public:
    explicit d_write(QWidget *parent = 0);
    ~d_write();

    // begin - hide titlebar, mouse drag anywhere
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    // end - hide titlebar, mouse drag anywhere

private slots:
    void on_pushButton_write_return_clicked();

    void on_pushButton_write_ok_clicked();

private:
    Ui::d_write *ui;

    // begin - hide titlebar, mouse drag anywhere
    QPoint last;
    // end - hide titlebar, mouse drag anywhere
};

#endif // D_WRITE_H
