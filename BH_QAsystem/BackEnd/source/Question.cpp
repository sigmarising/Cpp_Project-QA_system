#include <string>
#include <fstream>
#include "BackEnd/header/Question.h"
#include "BackEnd/header/func.h"
#include "BackEnd/header/define.h"
#include "BackEnd/header/Answer.h"
using namespace kernal;
using namespace std;

istream & kernal::operator>>(istream & input, Question & Q) {
	string t;

	// UserID
	getline(input, t);
	Q.set_mUserID(t);

	// time 
	getline(input, t);
	DataTime dt;
	dt.set_DataTime(t);
	Q.set_mTime(dt);

	// title
	getline(input, Q.m_Title);

	// num to ans
	getline(input, t);
	Q.m_NumtoAns = Convert<long>::Convert_STRtoTYPE(t);

	// text
	string text;
	getline(input, t);	// first line
	text = text + t;
	while (input.peek() != EOF) { // get all the text
		getline(input, t);
		text = text + "\n" + t;
	}
	Q.set_mText(text);

	return input;
}

ostream & kernal::operator<<(ostream & output, Question & Q) {
	// UID
	output << Q.get_mUserID() << endl;
	// time
	output << Q.get_mTime() << endl;
	// title
	output << Q.get_mTitle() << endl;
	// num to and
	output << Q.m_NumtoAns << endl;
	// text
	output << Q.get_mText() << endl;

	return output;
}

kernal::Question::Question() {
	// nothing to do
}

kernal::Question::Question(const string & ID) {
	// open the file
	ifstream file("qa\\" + ID + ".txt");

	// read in the data (use the operator)
	// attention! the file doesn't include the ID 
	// so we need to init the ID manually
	file >> *this;
	string t = ID;
	set_mID(t);

	// close
	file.close();
}

kernal::Question::Question(const string &title, const string &UID, const string &Text) 
	: BasicInfo(true, UID),  m_Title(title) 
{
	string t = Text;
	set_mText(t);
    m_NumtoAns = 0;


	// create the file
	fstream f;
	f.open(getFileName_id(), fstream::out);

	f << *this;

	f.close();
}

kernal::Question::~Question() {
	// nothing
}

void kernal::Question::add_answer(const string & UID, const string & Text) {
	// change the member var and rewite the file line
	++m_NumtoAns;
	FileHandle::FileLine_Change(getFileName_id(), 4, Convert<long>::Convert_TYPEtoSTR(m_NumtoAns));

	// creat the answer
	Answer A(UID, get_mID(), m_NumtoAns, Text);
}

string kernal::Question::get_mTitle() const {
	return m_Title;
}

string kernal::Question::getFileName_id() const {
	return string("qa\\" + get_mID() + ".txt");
}

long kernal::Question::get_mNumtoAns() const{
    return m_NumtoAns;
}

string kernal::Question::getID_Ansi(const long i) const {
	// get ans id (short)
	string t = Convert<long>::Convert_TYPEtoSTR(i);
	// get ans id (complete)
	while (t.length() < 5)
		t = "0" + t;
	//get ans id (long)
	t = get_mID() + "_" + t;

	return t;
}
void kernal::Question::load_AnsList(){
    if(tNum<1 || tNum>m_NumtoAns)
        return;
    m_AnsList.clear();
    for(int i = tNum, j =1; i<=m_NumtoAns && j<=MAX_LIST_NUM; i++,j++){
        if(i>0)
            m_AnsList.push_back(getID_Ansi(m_NumtoAns - i +1));
    }
}

void kernal::Question::load_AnsList(const bool GotoNext) {
	if (GotoNext) { // we need to go to the next page
		if (tNum + MAX_LIST_NUM <= m_NumtoAns) { // we can go to the next
			// clear list first
			m_AnsList.clear();
            //load ok
            tNum += MAX_LIST_NUM;
			for (long i = tNum, j = 1; j <= MAX_LIST_NUM && i <= m_NumtoAns; i++, j++) {
                if(i>0)
                    m_AnsList.push_back(getID_Ansi(m_NumtoAns - i +1));
			}

		}
	}
	else { // we need to go to the prev page
		if (tNum - MAX_LIST_NUM >= 1) {
			// clear list
			m_AnsList.clear();
            //load ok
            tNum -= MAX_LIST_NUM;
            for (long i = tNum, j = 1; j <= MAX_LIST_NUM && i <= m_NumtoAns; i++, j++) {
                if(i>0)
                    m_AnsList.push_back(getID_Ansi(m_NumtoAns - i +1));
			}

		}
	}
}
