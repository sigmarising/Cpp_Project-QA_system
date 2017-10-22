// class: "Question"
// belong to namespace: "kernal"

#pragma once

#include <string>
#include <iostream>
#include <deque>
#include "BasicInfo.h"
using namespace std;

namespace kernal {
	class Question : public kernal::BasicInfo {
	public:
        // 用于定位位置
        // 实际使用时候其值仅仅会为 1 + n * MAX_LIST_NUM
        // 当tNum为 1 时   加载序号为 1 2 3 ..... 1+MAX_LISTNUM-1 的问题
		static long tNum;
        // 当前的问题
        static string g_QuesNow;

        // 此问题对应的回答列表，仅在必要时才会加载
        deque<string>m_AnsList;


		// 默认构造函数
		// 不做什么操作
		Question();
		// 根据ID从文件中读取问题
		// 应当保证ID的正确性
		Question(const string &ID);
		// 参数构造函数
		// 此 函数会 自动创建并写入文件内容
		Question(const string &title, const string &UID, const string &Text);
		// 析构函数
		~Question();


		// 添加一个回答
		//	同时修改自身文件 - 答案数
		//  需要提供 创建者的 ID
		//  以及文本内容
		void add_answer(const string &UID, const string &Text);


		// 得到标题
		string get_mTitle() const;


		// 得到id文件名(带路径)
		string getFileName_id() const;
		// 得到第i个答案的文件名
		string getID_Ansi(const long i) const;
        // 得到此问题的答案数
        long get_mNumtoAns() const;


        // 向前或者向后加载 此问题的回答 列表
		// 当 GotoNext 为 true 则向后加载
		// 当 GotoNext 为 false 则向前加载
		void load_AnsList(const bool GotoNext);
        // 重载
        // 直接加载 tNum 位置的 问题回答列表
        void load_AnsList();


		// 重载输入流运算
		friend istream& operator>>(istream &input, Question &Q);
		// 重载输出流运算
		friend ostream& operator<<(ostream &output, Question &Q);
	private:
		// 问题的标题
		string m_Title;

		// 该问题拥有的回答数量
		long m_NumtoAns;
	};
}
