// class: "BasicInfo"
// belong to namespace: "kernal"

#pragma once

#include <string>
#include "DataTime.h"
using namespace kernal;
using namespace std;

namespace kernal {
	class BasicInfo {
	public:
		// 构造函数
		BasicInfo();
		// 重载构造函数 
		// 功能 - 生成问题ID 或者答案ID 加载UID    （仅进行此操作）
		//		创建并写相关文件的操作 在继承该类的 子类中实现
		// isaQuestion 为 true 时 生成问题ID
		// isaQuestion 为 false 时 生成答案ID
		// UID 为创建者ID
		// QID		是 在 isaQuestion 为 False 时 必须提供的 对应问题的ID
		// Q_Anum	是 在 isaQuestion 为 False 时 必须提供的 此答案对应的ID (即答案数量应该已经增一)
		BasicInfo(const bool &isaQuestion, const string &UID, const string &QID = "", const long &Q_Anum = 0);
		// 纯虚析构函数
		virtual ~BasicInfo() = 0;


		// 得到ID号
		string get_mID() const;
		// 得到创建者ID
		string get_mUserID() const;
		// 得到时间戳
		string get_mTime();
		// 得到信息内容
		string get_mText() const;


		// 设置ID
		void set_mID(string &str);
		// 设置用户ID
		void set_mUserID(string &str);
		// 设置时间值
		void set_mTime(DataTime &str);
		// 设置内容信息
		void set_mText(string &str);

	private:
		// ID号 可以为问题ID 或者答案ID
		string m_ID;
		// 创建者ID
		string m_UserID;
		// 时间戳
		// 此变量会自动初始化
		DataTime m_Time;

		
		// 文本内容信息
		string m_Text;
	};
}

