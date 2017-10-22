#include <fstream>
#include <exception>
#include <QDebug>
#include "BackEnd/header/FileHandle.h"
using namespace std;

func::FileHandle::FileHandle() {
    // nothing to do
}

func::FileHandle::~FileHandle() {
    // nothing to do
}

void func::FileHandle::FileLine_Delete(const string & filename, const long & line) {
    try{

        // copy the file without the only 1 line
        fstream F_temp, F_file;

        F_temp.open("sys\\temp.txt", ios::in | ios::out | ios::trunc); // clear this temp file
        F_file.open(filename, ios::in | ios::out);
        long count = 0;
        string str;

        while (F_file.peek() != EOF) {
            count += 1;
            getline(F_file, str);
            if (count != line)
                F_temp << str << endl;
        }

        F_temp.close();
        F_file.close();

        // rewrite in the file

        F_temp.open("sys\\temp.txt", ios::in | ios::out);
        F_file.open(filename, ios::in | ios::out | ios::trunc); // clear file

        while (F_temp.peek() != EOF) {
            getline(F_temp, str);
            F_file << str << endl;

        }

        F_temp.close();
        F_file.close();

    }
    catch (exception &e){
        qDebug() << e.what() << endl;
        exit(1);
    }
}

void func::FileHandle::FileLine_Change(const string & filename, const long & line, const string & things) {
    try{

        // copy the file and change the only 1 line
        fstream F_temp, F_file;

        F_temp.open("sys\\temp.txt", ios::in | ios::out | ios::trunc); // clear this temp file
        F_file.open(filename, ios::in | ios::out);
        long count = 0;
        string str;

        while (F_file.peek() != EOF) {
            count += 1;
            getline(F_file, str);
            if (count != line)
                F_temp << str << endl;
            else
                F_temp << things << endl;
        }

        F_temp.close();
        F_file.close();

        // rewrite in the file

        F_temp.open("sys\\temp.txt", ios::in | ios::out);
        F_file.open(filename, ios::in | ios::out | ios::trunc); // clear file

        while (F_temp.peek() != EOF) {
            getline(F_temp, str);
            F_file << str << endl;

        }

        F_temp.close();
        F_file.close();

    }
    catch (exception &e){
        qDebug() << e.what() << endl;
        exit(1);
    }
}

void func::FileHandle::FileLine_Insert(const string & filename, const long & line, const string & things) {
    try{
        // 0 add to the first line

        // copy the file and insert the only 1 line
        fstream F_temp, F_file;

        F_temp.open("sys\\temp.txt", ios::in | ios::out | ios::trunc); // clear this temp file
        F_file.open(filename, ios::in | ios::out);
        long count = 0;
        if (count == line)
            F_temp << things << endl;
        string str;

        while (F_file.peek() != EOF) {
            count += 1;
            getline(F_file, str);
            F_temp << str << endl;
            if (count == line)
                F_temp << things << endl;
        }

        F_temp.close();
        F_file.close();

        // rewrite in the file

        F_temp.open("sys\\temp.txt", ios::in | ios::out);
        F_file.open(filename, ios::in | ios::out | ios::trunc); // clear file

        while (F_temp.peek() != EOF) {
            getline(F_temp, str);
            F_file << str << endl;

        }

        F_temp.close();
        F_file.close();

    }
    catch (exception &e){
        qDebug() << e.what() << endl;
        exit(1);
    }
}

void func::FileHandle::FileEnd_Add(const string & filename, const string & things) {
    try{

        // copy the file and insert the only 1 line
        fstream F_file;

        F_file.open(filename, ios::app);

        F_file << things << endl;

        F_file.close();

    }
    catch (exception &e){
        qDebug() << e.what() << endl;
        exit(1);
    }
}

long func::FileHandle::FileLine_Getnumber(const string & filename, const string & things) {
    try{

        fstream F_file;

        F_file.open(filename);
        long count = 0;
        string str;

        while (F_file.peek() != EOF) {
            count += 1;
            getline(F_file, str);
            if (str == things) {
                F_file.close();
                return count;
            }
        }

        F_file.close();
        return 0;

    }
    catch (exception &e){
        qDebug() << e.what() << endl;
        exit(1);
    }
}

string func::FileHandle::FileLine_Getline(const string & filename, const long & line) {
    try{


        fstream F_file;

        F_file.open(filename);
        long count = 0;
        string str;

        while (F_file.peek() != EOF) {
            count += 1;
            getline(F_file, str);
            if (count == line)
                return str;
        }

        return string();

    }
    catch (exception &e){
        qDebug() << e.what() << endl;
        exit(1);
    }
}
