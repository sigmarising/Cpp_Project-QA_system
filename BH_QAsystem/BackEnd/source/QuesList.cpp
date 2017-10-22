#include <string>
#include <fstream>
#include "BackEnd/header/QuesList.h"
#include "BackEnd/header/define.h"
#include "BackEnd/header/func.h"
using namespace std;

kernal::QuesList::QuesList() {
    // load the path to findlist
    Filename_findlist = "qa\\findlist.txt";
}

kernal::QuesList::~QuesList() {
    // nothing todo
}

void kernal::QuesList::load_question(const bool DoFindFunc){
    if (!DoFindFunc){
        m_questionList.clear();
        if(tNum<1 || tNum>SystemNeed::get_NumQuestion())
            return;
        for(int i = tNum, j = 1; i <= SystemNeed::get_NumQuestion() && j<=MAX_LIST_NUM; i++, j++){
            if(i>0)
                m_questionList.push_back(getID_q(SystemNeed::get_NumQuestion() - i+1));
        }
    }
    else{
        m_questionList.clear();
        long TargetNum = Convert<long>::Convert_STRtoTYPE(FileHandle::FileLine_Getline(Filename_findlist, 1));
        if(tNum <1 || tNum >TargetNum)
            return;
        for(int i =tNum,j=1;j<=MAX_LIST_NUM && i<=TargetNum;i++,j++)
            if(i>0)
                m_questionList.push_back(FileHandle::FileLine_Getline(Filename_findlist, i + 1));

    }
}
void kernal::QuesList::load_question(const bool GotoNext, const bool DoFindFunc) {
    if (GotoNext) {  // we need to go to next -->> 去往旧的
        if (!DoFindFunc) {  // we do normal func 问题ID越大 问题越新 这里用置换方法
            if (tNum + MAX_LIST_NUM <= SystemNeed::get_NumQuestion()) {  // we can do this
                // clear list
                m_questionList.clear();
                // tNum
                tNum += MAX_LIST_NUM;
                for (long i = tNum, j = 1; j <= MAX_LIST_NUM && i <=SystemNeed::get_NumQuestion(); i++, j++) {
                    if( i>0 )
                        m_questionList.push_back(getID_q(SystemNeed::get_NumQuestion() - i + 1));//倒置法取ID
                }
            }
        }
        else {  // we need to do find func
            // get the num in sum
            long TargetNum = Convert<long>::Convert_STRtoTYPE(FileHandle::FileLine_Getline(Filename_findlist, 1));

            if (tNum + MAX_LIST_NUM <= TargetNum) {  // we can do this 行数越靠前 问题越新
                // clear list
                m_questionList.clear();
                // tNum
                tNum += MAX_LIST_NUM;
                for (long i = tNum, j = 1; j <= MAX_LIST_NUM && i <= TargetNum; i++, j++) {
                    if(i>0)
                        m_questionList.push_back(FileHandle::FileLine_Getline(Filename_findlist, i + 1));
                }
            }
        }
    }
    else { // we need to go to prev <<-- 去往新的
        if (!DoFindFunc) {  // we do normal func
            if (tNum - MAX_LIST_NUM >= 1) {  // we can do this
                // clear list
                m_questionList.clear();
                // tNum
                tNum -= MAX_LIST_NUM;
                for (long i = tNum, j = 1; j <= MAX_LIST_NUM && i <= SystemNeed::get_NumQuestion(); i++, j++) {
                    if(i >0)
                        m_questionList.push_back(getID_q(SystemNeed::get_NumQuestion() - i +1));
                }

            }
        }
        else {  // we need to do find func
            long TargetNum = Convert<long>::Convert_STRtoTYPE(FileHandle::FileLine_Getline(Filename_findlist, 1));

            if (tNum - MAX_LIST_NUM >=1){
                // clear
                m_questionList.clear();
                // tNum
                tNum -= MAX_LIST_NUM;
                for (long i = tNum, j = 1; j <= MAX_LIST_NUM && i <= TargetNum; i++, j++) {
                    if(i>0)
                        m_questionList.push_back(FileHandle::FileLine_Getline(Filename_findlist, i + 1));
                }
            }
        }
    }
}

void kernal::QuesList::findQuestion(string KeyWord) {
    fstream f;

    // open and clear the file
    f.open(Filename_findlist, ios::in | ios::out | ios::trunc);

    long Num_sum = SystemNeed::get_NumQuestion();
    long count = 0;
    // travle all files
    for (long i = Num_sum; i >= 1; i--) {
        // get title
        string title = FileHandle::FileLine_Getline("qa\\" + getID_q(i) + ".txt", 3);

        if (string::npos != title.find(KeyWord)) { // find success
            f << getID_q(i) << endl;
            count++;
        }

    }
    f.close();

    // insert the num
    FileHandle::FileLine_Insert(Filename_findlist, 0, Convert<long>::Convert_TYPEtoSTR(count));
}

void kernal::QuesList::findQuestion(DataTime Data) {
    fstream f;

    // open and clear the file
    f.open(Filename_findlist, ios::in | ios::out | ios::trunc);

    long Num_sum = SystemNeed::get_NumQuestion();
    long count = 0;
    // travle all files
    for (long i = Num_sum; i >= 1; i--) {
        // get time
        string time = FileHandle::FileLine_Getline("qa\\" + getID_q(i) + ".txt", 2);

        if (string::npos != time.find(Data.get_DataTime())) {// success
            f << getID_q(i) << endl;
            count++;
        }
    }
    f.close();

    // insert the num
    FileHandle::FileLine_Insert(Filename_findlist, 0, Convert<long>::Convert_TYPEtoSTR(count));
}

string kernal::QuesList::getID_q(const long & i) {
    string t = Convert<long>::Convert_TYPEtoSTR(i);

    while (t.length() < 10)
        t = "0" + t;

    return t;
}
