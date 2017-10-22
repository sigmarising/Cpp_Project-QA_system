#ifndef D_QUESTION_H
#define D_QUESTION_H

#include <QDialog>

// begin - hide titlebar, mouse drag anywhere
#include <QMouseEvent>
#include <QListWidgetItem>
#include "BackEnd/header/define.h"
// end - hide titlebar, mouse drag anywhere
#include "BackEnd/header/kernal.h"
#include "BackEnd/header/func.h"

namespace Ui {
class d_question;
}

class d_question : public QDialog
{
    Q_OBJECT

public:
    explicit d_question(QWidget *parent = 0);
    ~d_question();

    // begin - hide titlebar, mouse drag anywhere
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    // end - hide titlebar, mouse drag anywhere

private slots:
    void on_pushButton_question_return_clicked();

    void on_pushButton_question_focus_clicked();

    void on_pushButton__question_Write_clicked();

    void on_pushButton_question_Prev_clicked();

    void on_pushButton__question_Next_clicked();

    void on_listWidget_question_ansList_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::d_question *ui;

    // now in use
    User UserNow;
    Question QueNow;

    // begin - hide titlebar, mouse drag anywhere
    QPoint last;
    // end - hide titlebar, mouse drag anywhere
};

#endif // D_QUESTION_H
