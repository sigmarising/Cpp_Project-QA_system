#include <fstream>
#include "BackEnd/header/User.h"
#include "BackEnd/header/func.h"
#include "BackEnd/header/define.h"
using namespace std;

string kernal::User::find_Name_from_ID(const string & ID) {
	return FileHandle::FileLine_Getline("users\\" + ID + ".txt", 1);
}

string kernal::User::find_ID_from_Name(const string & Name) {
	// we need to search all the file
	long SumNum = SystemNeed::get_NumUsers();

	// search all id files
	for (long i = 1; i <= SumNum; i++) {
		// get the filename we need
		string filename = Convert<long>::Convert_TYPEtoSTR(i);
		while (8 > filename.length()) {
			filename = "0" + filename;
		}
		string ID = filename;  // save this id
		filename = "users\\" + filename + ".txt";  // get ok

		// judge the name
		if (Name == FileHandle::FileLine_Getline(filename, 1))
			return ID;
	}

	return string();
}

kernal::User::User() {
	// just set zero here
    m_NumFocus = m_NumQA = 0;

	// everyone focus himself
	m_NumFocus = 1;
}

kernal::User::User(const string &ID) {
	// open the user's file
	ifstream file( "users\\" + ID + ".txt" );

	// read in the data (use the operator)
	// attention! the file doesn't include the ID 
	// so we need to init the ID manually
	file >> *this;
	m_ID = ID;

	// close the file
	file.close();
}

kernal::User::User(const string & Name, const string & Key) {
	// first init the member vars
	m_Name = Name;
	m_Key = Key;
    m_NumFocus = m_NumQA = 0;

	// everyone focus himself
	m_NumFocus = 1;

	// get the correct id
	m_ID = SystemNeed::Create_NewUser();

	// create the files , write and close
	fstream f_id(getFileName_id(), fstream::out);
	fstream f_f(getFileName_f(), fstream::out);
	fstream f_qa(getFileName_qa(), fstream::out);

	f_id << *this;
	f_f << m_ID << endl;

	f_id.close();
	f_f.close();
	f_qa.close();
}

kernal::User::User(const User & A) {
	m_ID = A.m_ID;
	m_Name = A.m_Name;
	m_Key = A.m_Key;

	m_NumFocus = A.m_NumFocus;
    m_NumQA = A.m_NumQA;
}

kernal::User::~User() {
	// nothing to do
}

string kernal::User::getm_ID() const {
	return m_ID;
}

string kernal::User::getm_Name() const {
	return m_Name;
}

string kernal::User::getm_Key() const {
	return m_Key;
}

istream & kernal::operator>>(istream & input, User & U) {
	// read in the name and key
	getline(input, U.m_Name);
	getline(input, U.m_Key);
	
	// read in the three number
	input >> U.m_NumFocus;
    input >> U.m_NumQA;

	return input;
}

ostream & kernal::operator<<(ostream & output, User & U) {
	// write the name and the key
	output << U.m_Name << endl;
	output << U.m_Key << endl;

	// write the numbers
	output << U.m_NumFocus << endl;
    output << U.m_NumQA << endl;

	return output;
}

string kernal::User::getFileName_id() const {
	return string("users\\" + m_ID + ".txt");
}

string kernal::User::getFileName_f() const {
	return string("users\\" + m_ID + "_f.txt");
}

string kernal::User::getFileName_qa() const {
	return string("users\\" + m_ID + "_qa.txt");
}

long kernal::User::getmNum_Focus() const{
    return m_NumFocus;
}

long kernal::User::getmNum_QA() const{
    return m_NumQA;
}

bool kernal::User::check_key(const string & key) const {
	if (key == m_Key)
		return true;
	return false;
}
bool kernal::User::check_focus(const string &ID) const{
    string id = ID;
    if(0==FileHandle::FileLine_Getnumber(getFileName_f(), id))
        return false;
    return true;
}
void kernal::User::remove_focus(const string &UserID){
    long num = FileHandle::FileLine_Getnumber(getFileName_f(), UserID);
    if (num == 1) // 自己关注自己不可以移除
        return ;

    FileHandle::FileLine_Delete(getFileName_f(), num);
    m_NumFocus--;
    FileHandle::FileLine_Change(getFileName_id(), 3, Convert<long>::Convert_TYPEtoSTR(m_NumFocus));
}
void kernal::User::add_focus(const string & UserID) {
	FileHandle::FileLine_Insert(getFileName_f(), 1, UserID);
    m_NumFocus++;
    FileHandle::FileLine_Change(getFileName_id(), 3, Convert<long>::Convert_TYPEtoSTR(m_NumFocus));
}

void kernal::User::add_qa(const string & ID) {
	FileHandle::FileLine_Insert(getFileName_qa(), 0, ID);
    m_NumQA++;
    FileHandle::FileLine_Change(getFileName_id(), 4, Convert<long>::Convert_TYPEtoSTR(m_NumQA));
}

void kernal::User::key_change(const string & NewKey) {
	// update the key
	m_Key = NewKey;

	// change the file
	FileHandle::FileLine_Change(getFileName_id(), 2, m_Key);
}
void kernal::User::load_f() {
    if(tNum_F < 1 || tNum_F >m_NumFocus)
        return;
    m_focuslist.clear();
    for(int i = tNum_F, j =1; j<=MAX_LIST_NUM && i<=m_NumFocus; i++, j++){
        if(i>0)
            m_focuslist.push_back(FileHandle::FileLine_Getline(getFileName_f(), i));
    }
}
void kernal::User::load_f(const bool GotoNext) {
	if (GotoNext) {  // we need to go to the Next page
		if (tNum_F + MAX_LIST_NUM <= m_NumFocus) { // we can go to next page
			// clear list first
			m_focuslist.clear();
			// we load at most MAX_LIST_NUM items
            // load ok
            // change the tNum
            tNum_F += MAX_LIST_NUM;
			for (long i = tNum_F, j = 1; j <= MAX_LIST_NUM && i <= m_NumFocus; i++, j++) {
				// get the line i
                if(i>0)
                    m_focuslist.push_back(FileHandle::FileLine_Getline(getFileName_f(), i));
			}

		}
		// if we cannot go to next page
		// do nothing
	}
	else {  // we need to go to the Prev Page
		if (tNum_F - MAX_LIST_NUM >= 1) {  // we can go to the pre page
			// clear list first
			m_focuslist.clear();
            // load ok
            // change the tNum
            tNum_F -= MAX_LIST_NUM;
			// we load at most MAX_LIST_NUM items
            for (long i = tNum_F, j = 1; j <= MAX_LIST_NUM && i <= m_NumFocus; j++, i++) {
                if(i>0)
                    m_focuslist.push_back(FileHandle::FileLine_Getline(getFileName_f(), i));
			}

		}
	}

	// when do all these ok 
	// the id in the list is sort by time (late to early)
	// except the first item (youself)
}
void kernal::User::load_qa() {
    if(tNum_QA <1 || tNum_QA > m_NumQA)
        return;
    m_qalist.clear();
    for(int i = tNum_QA, j = 1; j<=MAX_LIST_NUM && i <=m_NumQA ; i++ , j++){
        if(i>0)
            m_qalist.push_back(FileHandle::FileLine_Getline(getFileName_qa(), i));
    }
}
void kernal::User::load_qa(const bool GotoNext) {
	if (GotoNext) {  // we need to go to next page
        if (tNum_QA + MAX_LIST_NUM <= m_NumQA) {
			// clear list first
			m_qalist.clear();
            // load ok
            // change the tNum
            tNum_QA += MAX_LIST_NUM;
			// we load at most MAX_LIST_NUM items
            for (long i = tNum_QA, j = 1; j <= MAX_LIST_NUM && i <= m_NumQA; i++, j++) {
                if(i>0)
                    m_qalist.push_back(FileHandle::FileLine_Getline(getFileName_qa(), i));
			}

		}
	}
	else {  // we need to go to prev page
		if (tNum_QA - MAX_LIST_NUM >= 1) {
			m_qalist.clear();
            tNum_QA -= MAX_LIST_NUM;
            for (long i = tNum_QA, j = 1; j <= MAX_LIST_NUM && i <= m_NumQA; j++, i++) {
                if(i>0)
                    m_qalist.push_back(FileHandle::FileLine_Getline(getFileName_qa(), i));
			}
		}
	}
}
