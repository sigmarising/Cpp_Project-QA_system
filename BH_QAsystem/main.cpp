#include <QApplication>
#include <QFile>
#include <string>
#include <fstream>
#include <string>
#include "d_alldialogs.h"
#include "BackEnd/header/func.h"
#include "BackEnd/header/kernal.h"
using namespace std;

// tooltip 悬停显示文字

// 类中的静态成员变量必须在外面初始化
// 否则 error LINK2001
string SystemNeed::m_SysKeynote;
long SystemNeed::m_Num_Question = 0;
long SystemNeed::m_Num_Users = 0;
long User::tNum_F;
long User::tNum_QA;
string User::g_UserNow;
long Question::tNum;
long QuesList::tNum;
string Question::g_QuesNow;
string Answer::g_AnswerNow;
string User::g_UserLook;

// 系统运行变量
bool SysRun = true;
int uiset = 1;
int uiset_prev = 1;

// 全局变量


int main(int argc, char *argv[])
{
    // begin - necessary
    Q_INIT_RESOURCE(resource);
    QApplication a(argc, argv);
    // end - necessary

    // begin - 文件初始化
    if("" == FileHandle::FileLine_Getline("sys//keynote.txt", 1)){
        // make dir
        system("md sys");
        system("md users");
        system("md qa");

        // create files
        fstream f("sys//keynote.txt", fstream::out);
        f << 1 << endl;
        f << 0 << endl;
        f << 0 << endl;
        f.close();

        f.open("sys//temp.txt", fstream::out);
        f << 0 << endl;
        f.close();

        f.open("qa//findlist.txt", fstream::out);
        f << 0 << endl;
        f.close();
    }

    SystemNeed::init_vars();
    // end - 文件初始化

    // begin - 主状态自动机
    d_login *w1 = NULL;
    d_access *w2 = NULL;
    D_operate *w3 = NULL;
    d_question *w4 = NULL;
    d_ask *w5 = NULL;
    d_answer *w6 = NULL;
    d_write *w7 = NULL;
    d_me *w8 = NULL;
    d_changeKey *w9 = NULL;
    d_focus *w10 = NULL;
    d_focusFull *w11 = NULL;

    while (SysRun){
        switch (uiset) {
        case 1:
            w1 = new d_login;
            w1->exec();
            delete w1;

            break;
        case 2:
            w2 = new d_access;
            w2->exec();
            delete w2;

            break;
        case 3:
            w3 = new D_operate;
            w3->exec();
            delete w3;

            break;
        case 4:
            w4 = new d_question;
            w4->exec();
            delete w4;

            break;
        case 5:
            w5 = new d_ask;
            w5->exec();
            delete w5;

            break;
        case 6:
            w6 = new d_answer;
            w6->exec();
            delete w6;

            break;
        case 7:
            w7 = new d_write;
            w7->exec();
            delete w7;

            break;
        case 8:
            w8 = new d_me;
            w8->exec();
            delete w8;

            break;
        case 9:
            w9 = new d_changeKey;
            w9->exec();
            delete w9;

            break;
        case 10:
            w10 = new d_focus;
            w10->exec();
            delete w10;

            break;
        case 11:
            w11=new d_focusFull;
            w11->exec();
            delete w11;

            break;
        }
    }
    // end - 主状态自动机

    // begin - necessary
    qApp->quit();
    return 0;
    // end - necessary
}
