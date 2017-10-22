// class: "QuesList"
// belong to namespace: "kernal"

#pragma once

#include <deque>
#include "DataTime.h"
using namespace kernal;
using namespace std;

namespace kernal {
	// 用于存储问题列表
	// 是主要操作界面的主要部分
	// 必须仅仅实例化 一个 对象
	class QuesList {
	public:
		// 用于定位位置
        // 实际使用时候其值仅仅会为 1 + n * MAX_LIST_NUM
        // 当tNum为 1 时   加载序号为 1 2 3 ..... 1+MAX_LISTNUM-1 的问题
		static long tNum;

        // 所有已存在问题的列表 仅在必要时才会加载
        deque<string>m_questionList;

		// 构造函数 会对路径字符串赋值
		QuesList();
		// 析构函数
		~QuesList();

        // 向前或向后加载 已知问题列表 列表
		// 当 GotoNext 为 true 则向后加载
		// 当 GotoNext 为 false 则向前加载
		//
		// 当 DoFindFunc 为 true 则进行 在搜索结果中进行加载
		// 当 DoFindFunc 为 false 则进行 在所有问题中进行加载
		void load_question(const bool GotoNext, const bool DoFindFunc);
        // 重载
        // 直接加载 tNum位置的问题列表
        // 应当保证tNum >=1
        void load_question(const bool DoFindFunc);


		// 执行对问题的搜索操作 重载1
		// 对 KeyWord 关键字进行 子串匹配型 搜索
		// 搜索结果会写入到文件 "qa\\findlist.txt" 中
		void findQuestion(string KeyWord);
		// 执行对问题的搜索操作 重载2
		// 对 Data 日期进行 搜索
		// 搜索结果会写入到文件 "qa\\findlist.txt" 中
		void findQuestion(DataTime Data);


		// 得到编号为i 的问题的 ID
		string getID_q(const long &i);
	private:
		// 存储"qa\\findlist.txt" 路径文件
		string Filename_findlist;
	};
}
