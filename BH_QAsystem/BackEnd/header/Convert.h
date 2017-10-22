// class: "Convert"
// belong to namespace: "func"

#pragma once

#include <string>
#include <strstream>
#include <QString>
using namespace std;

namespace func {
	template<class Type>
	class Convert {
	public:
		Convert();
		~Convert();

		// C++字符串 转为 指定类型
		// 模板参数可为 long int double
		static Type Convert_STRtoTYPE(const string str);

		// 指定类型 转为 C++字符串
		// 模板参数可为 long int double
		static string Convert_TYPEtoSTR(const Type num);

		// C++字符串 转为 Qt字符串
		// 模板参数必须设定为 string
		static QString Convert_STRtoQSTR(const Type str);

		// Qt字符串 转为 C++字符串
		// 模板参数必须设定为 QString
        static string Convert_QSTRtoSTR(const Type qstr);

	};


	template<class Type>
	inline Convert<Type>::Convert() {
		// do nothing
	}
	template<class Type>
	inline Convert<Type>::~Convert() {
		// do nothing
	}
	template<class Type>
	inline Type Convert<Type>::Convert_STRtoTYPE(const string str) {
		// into strstream
		strstream ss;
		ss << str;

		// out from the strstream
		Type num;
		ss >> num;

		return num;
	}
	template<class Type>
	inline string Convert<Type>::Convert_TYPEtoSTR(const Type num) {
		// into strstream
		strstream ss;
		ss << num;

		// out from strstream
		string str;
		ss >> str;

		return str;
	}
	template<class Type>
	inline QString Convert<Type>::Convert_STRtoQSTR(const Type str) {
		QString qs;

		qs = QString::fromStdString(str);

		return qs;
	}
	template<class Type>
    inline string Convert<Type>::Convert_QSTRtoSTR(const Type qstr) {
		string s;

		s = qstr.toStdString();

		return s;
	}
}
