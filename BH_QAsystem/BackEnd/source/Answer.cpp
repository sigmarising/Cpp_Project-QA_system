#include <fstream>
#include <string>
#include "BackEnd/header/Answer.h"
#include "BackEnd/header/func.h"
#include "BackEnd/header/kernal.h"
using namespace std;

istream & kernal::operator>>(istream & input, Answer & A) {
	string t;

	// UserID
	getline(input, t);
	A.set_mUserID(t);

	// time
	getline(input, t);
	DataTime dt;
	dt.set_DataTime(t);
	A.set_mTime(dt);

	// praise num
	getline(input, t);
	A.m_praiseNum = Convert<long>::Convert_STRtoTYPE(t);

	// text
	string text;
	getline(input, t);  // first line
	text = text + t;
	while (input.peek() != EOF) {  // get all the text
		getline(input, t);
		text = text + "\n" + t;
	}
	A.set_mText(text);

	return input;
}

ostream & kernal::operator<<(ostream & output, Answer & A) {
	// UserID
	output << A.get_mUserID() << endl;
	// time
	output << A.get_mTime() << endl;
	// praise num
	output << A.m_praiseNum << endl;
	// text
	output << A.get_mText() << endl;

	return output;
}

kernal::Answer::Answer() {
	// nothing todo
}

kernal::Answer::Answer(const string & ID) {
	// open the answer file
	ifstream file("qa\\" + ID + ".txt");

	// read in the data (use the operator)
	// attention! the file doesn't include the ID 
	// so we need to init the ID manually
	file >> *this;
	string t = ID;
	set_mID(t);

	// close the file
	file.close();
}

kernal::Answer::Answer(const string &UID, const string &QID, const long &Q_Anum, const string &Text)
	: BasicInfo(false, UID, QID, Q_Anum)
{
	string t = Text;
	set_mText(t);


	// create the files
	fstream f_id, f_p;
	f_id.open(getFileName_id(), fstream::out);
	f_p.open(getFileName_p(), fstream::out);

	f_id << *this;

	f_id.close();
	f_p.close();

    User(UID).add_qa(this->get_mID());
}

kernal::Answer::~Answer() {
	// nothing
}

long kernal::Answer::get_mpraiseNum() const {
	return m_praiseNum;
}

void kernal::Answer::add1_mpraiseNum(const string &UID) {
	++m_praiseNum;

	// change the file
	FileHandle::FileLine_Change(getFileName_id(), 3, Convert<long>::Convert_TYPEtoSTR(m_praiseNum));
	// add person id
	FileHandle::FileEnd_Add(getFileName_p(), UID);
}

void kernal::Answer::sub1_mpraiseNum(const string &UID) {
	--m_praiseNum;
	
	// change the file
	FileHandle::FileLine_Change(getFileName_id(), 3, Convert<long>::Convert_TYPEtoSTR(m_praiseNum));
	// delete person id
	long linenum = FileHandle::FileLine_Getnumber(getFileName_p(), UID);
	FileHandle::FileLine_Delete(getFileName_p(), linenum);
}

bool kernal::Answer::already_praise(const string & UID) {
	long linenum = FileHandle::FileLine_Getnumber(getFileName_p(), UID);
	
	if (linenum)
		return true;

	// 0 return for not find
	return false;
}

string kernal::Answer::getFileName_id() const {
    return string("qa\\" + get_mID() + ".txt");
}

string kernal::Answer::getFileName_p() const {
    return string("qa\\" + get_mID() + "_p.txt");
}
