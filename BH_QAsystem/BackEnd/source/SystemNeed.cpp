#include "BackEnd/header/SystemNeed.h"
#include "BackEnd/header/func.h"

func::SystemNeed::SystemNeed() {
	// nothing to do
}

func::SystemNeed::~SystemNeed() {
	// nothing to do
}

void func::SystemNeed::init_vars() {
	// init the var
	m_SysKeynote = "sys\\keynote.txt";
	m_Num_Users = Convert<long>::Convert_STRtoTYPE(FileHandle::FileLine_Getline(m_SysKeynote, 2));
	m_Num_Question = Convert<long>::Convert_STRtoTYPE(FileHandle::FileLine_Getline(m_SysKeynote, 3));
}

string func::SystemNeed::Create_NewUser() {
	// change the var
	++m_Num_Users;

	// change the file
	FileHandle::FileLine_Change(m_SysKeynote, 2, Convert<long>::Convert_TYPEtoSTR(m_Num_Users));

    // get the id string
    string str = Convert<long>::Convert_TYPEtoSTR(m_Num_Users);
    while (str.length() < 8)
        str = "0" + str;

	// return the new string
    return str;
}

string func::SystemNeed::Create_NewQuestion() {
	// change the var
	++m_Num_Question;

	// change the file
	FileHandle::FileLine_Change(m_SysKeynote, 3, Convert<long>::Convert_TYPEtoSTR(m_Num_Question));

    // get the string
    string str = Convert<long>::Convert_TYPEtoSTR(m_Num_Question);
    while(str.length() < 10)
        str = "0" + str;

	// return the new string
    return str;
}

long func::SystemNeed::get_NumUsers() {
	return m_Num_Users;
}

long func::SystemNeed::get_NumQuestion() {
	return m_Num_Question;
}
