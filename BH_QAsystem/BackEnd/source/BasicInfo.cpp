#include <fstream>
#include "BackEnd/header/BasicInfo.h"
#include "BackEnd/header/func.h"
using namespace std;

kernal::BasicInfo::BasicInfo() {
	// do nothing
}

kernal::BasicInfo::BasicInfo(const bool & isaQuestion, const string & UID, const string & QID, const long & Q_Anum) {
	if (isaQuestion) {  // need to create question id
		// get id
		m_ID = SystemNeed::Create_NewQuestion();
	}
	else {  // need to create answer id 
		// get ans id(short)
		string t = Convert<long>::Convert_TYPEtoSTR(Q_Anum);
		// get ans id(complete)
        while (t.length() < 5)
			t = "0" + t;
		// get ans id(long)
		m_ID = QID + "_" + t;
	}

	// init UID
	m_UserID = UID;
}

// 必须创建这个声明
// 否则会出现 LINK 问题
kernal::BasicInfo::~BasicInfo() {
	// nothing
}

string kernal::BasicInfo::get_mID() const {
	return m_ID;
}

string kernal::BasicInfo::get_mUserID() const {
	return m_UserID;
}

string kernal::BasicInfo::get_mTime() {
	return m_Time.get_DataTime();
}

string kernal::BasicInfo::get_mText() const {
	return m_Text;
}

void kernal::BasicInfo::set_mID(string & str) {
	m_ID = str;
}

void kernal::BasicInfo::set_mUserID(string & str) {
	m_UserID = str;
}

void kernal::BasicInfo::set_mTime(DataTime & str) {
	m_Time = str;
}

void kernal::BasicInfo::set_mText(string & str) {
	m_Text = str;
}
