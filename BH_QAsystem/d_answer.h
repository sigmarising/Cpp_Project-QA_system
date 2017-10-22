#ifndef D_ANSWER_H
#define D_ANSWER_H

#include <QDialog>

// begin - hide titlebar, mouse drag anywhere
#include <QMouseEvent>
#include "BackEnd/header/define.h"
// end - hide titlebar, mouse drag anywhere
#include "BackEnd/header/func.h"
#include "BackEnd/header/kernal.h"

namespace Ui {
class d_answer;
}

class d_answer : public QDialog
{
    Q_OBJECT

public:
    explicit d_answer(QWidget *parent = 0);
    ~d_answer();

    // begin - hide titlebar, mouse drag anywhere, glass shadow border
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    // end - hide titlebar, mouse drag anywhere, glass shadow border

private slots:
    void on_pushButton_ask_return_clicked();

    void on_pushButton_ask_focus_clicked();

    void on_pushButton_ask_praise_clicked();

private:
    Ui::d_answer *ui;

    User UserNow;
    Question QueNow;
    Answer AnsNow;

    // begin - hide titlebar, mouse drag anywhere, glass shadow border
    QPoint last;
    // end - hide titlebar, mouse drag anywhere, glass shadow border
};

#endif // D_ANSWER_H
