#ifndef D_LOGIN_H
#define D_LOGIN_H

#include <QDialog>

// begin - hide titlebar, mouse drag anywhere
#include <QMouseEvent>
#include "BackEnd/header/define.h"
// end - hide titlebar, mouse drag anywhere

namespace Ui {
class d_login;
}

class d_login : public QDialog
{
    Q_OBJECT

public:
    explicit d_login(QWidget *parent = 0);
    ~d_login();


    // begin - hide titlebar, mouse drag anywhere, glass shadow border
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    // end - hide titlebar, mouse drag anywhere, glass shadow border

private slots:
    void on_pushButton_login_quit_clicked();

    void on_pushButton_login_access_clicked();

    void on_pushButton_login_login_clicked();

private:
    Ui::d_login *ui;

    // begin - hide titlebar, mouse drag anywhere
    QPoint last;
    // end - hide titlebar, mouse drag anywhere
};

#endif // D_LOGIN_H
