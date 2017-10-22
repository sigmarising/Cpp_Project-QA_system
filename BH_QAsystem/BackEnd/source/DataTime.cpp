#include <ctime>
#include "BackEnd/header/DataTime.h"
using namespace std;

kernal::DataTime::DataTime() {
	// get current time
	time_t t = time(0);

	// the Formated Time is length 20
	char tmp[20];

	// formate the time
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&t));

	// convert to string
	string a(tmp);

	m_Data = a;
}

kernal::DataTime::DataTime(DataTime & DT) {
	m_Data = DT.m_Data;
}

kernal::DataTime::~DataTime() {
	// nothing to do
}

string kernal::DataTime::get_DataTime() {
	return m_Data;
}

void kernal::DataTime::set_DataTime(string & str) {
	m_Data = str;
}
