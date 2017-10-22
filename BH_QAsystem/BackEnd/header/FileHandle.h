// class: "FileHandle"
// belong to namespace: "func"

#pragma once

#include <string>
using namespace std;

namespace func {
	class FileHandle {
	public:
		FileHandle();
		~FileHandle();

		// 删除文件中的指定行
		static void FileLine_Delete(const string &filename, const long &line);

		// 改变文件中指定行的内容
		static void FileLine_Change(const string &filename, const long &line, const string &things);

		// 在文件的指定行之后插入内容
		static void FileLine_Insert(const string &filename, const long &line, const string &things);

		// 将指定内容添加到文章末尾
		static void FileEnd_Add(const string &filename, const string &things);

		// 搜索指定内容的行号（一般用于ID）
		static long FileLine_Getnumber(const string &filename, const string &things);

		// 返回文件指定行的内容
		static string FileLine_Getline(const string &filename, const long &line);
	};
}