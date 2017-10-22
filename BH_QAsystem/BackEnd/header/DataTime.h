// class: "DataTime"
// belong to namespace: "kernal"

#pragma once

#include <string>
using namespace std;

namespace kernal {
	class DataTime {
	public:
		// 构造函数
		// 默认调用时便可已成功初始化时间
		DataTime();

		// 拷贝构造函数
		// 直接拷贝字符串
		DataTime(DataTime &DT);

		// 析构函数
		~DataTime();


		// 返回 格式化 的 日期格式
		string get_DataTime();
		// 使用 C++ 字符串 设置 日期
		// 应该保证字符串格式的正确性
		void set_DataTime(string &str);

	private:
		// 标准日期格式 
		// 例如 "2017-01-11 13:23:23"
		string m_Data;
	};
}