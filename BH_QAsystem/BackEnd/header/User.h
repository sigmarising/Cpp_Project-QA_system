// class: "User"
// belong to namespace: "kernal"

#pragma once

#include <string>
#include <deque>
#include "define.h"
using namespace std;

namespace kernal {
	class User {
	public:
        // 用于定位位置
        // 实际使用时候其值仅仅会为 1 + n * MAX_LIST_NUM
        // 当tNum为 1 时   加载序号为 1 2 3 ..... 1+MAX_LISTNUM-1 的问题
		static long tNum_F;
		// 用于确定已加载的位置 默认为0
		static long tNum_QA;
        // 当前登录的用户
        static string g_UserNow;
        // 查看中的用户 关注列表中使用
        static string g_UserLook;

		// 根据 ID 查找用户的 用户名
		static string find_Name_from_ID(const string &ID);
		// 根据 用户名 查找用户的 ID
		static string find_ID_from_Name(const string &Name);


        // 关注人列表 - 仅在需要时才会加载
        // 加载后 按照时间为顺序排序 时间与现在越接近
        // 排位就会越靠前
        deque<string>m_focuslist;
        // 提问回答列表 - 仅在需要时才会加载
        deque<string>m_qalist;


		// 默认构造函数
		User();
		// 根据ID从文件中读取用户实例
		// 应当保证ID的正确性
		User(const string &ID);
		// 此构造函数会创建新文件 - 即创建新的用户必须调用此方法
		// 需要给出 用户名 密码
		// ID号码自动分配
		User(const string &Name, const string &Key);
		// 拷贝构造函数
		User(const User &A);
		// 默认析构函数
		~User();


		// 获取 用户ID
		string getm_ID() const;
		// 获取 用户名
		string getm_Name() const;
		// 获取 用户密码
		string getm_Key() const;
        // 获得关注数量
        long getmNum_Focus() const;
        // 获得贡献数
        long getmNum_QA() const;

		// 获取 ID文件名
		string getFileName_id() const;
		// 获取 关注列表文件名(带路径)
		string getFileName_f() const;
		// 获取 提问回答列表文件名(带路径)
		string getFileName_qa() const;


		// 检测 key 是否为正确的密钥
		bool check_key(const string &key) const;
        // 检测用户为ID的人是否已被关注
        bool check_focus(const string &ID) const;


        // 移除关注 使用前应该先检测
        void remove_focus(const string &UserID);
		// 将 UserID 添加到关注列表中
		// 永远将这个 str 插入到 line 2
        // 使用前应该先检测
		void add_focus(const string &UserID);
		// 将 QID 或者 AID 插入到问题列表文件 line 1
		void add_qa(const string &ID);


		// 改变密码
		void key_change(const string &NewKey);


        // 向前向后加载 关注者 列表
		// 当 GotoNext 为 true 则向后加载
		// 当 GotoNext 为 false 则向前加载
		// 
		// 本函数也可以用于 >初始化< focuslist
		// 用于初始化时调用的方法为：
		// GotoNext 为 true
		// 并提前赋值变量 User::tNum_f = 1 - MAX_LIST_NUM
		void load_f(const bool GotoNext);
        // 直接加载tNum处关注者列表
        void load_f();

        // 向前向后加载 提问&回答 列表
		// 当 GotoNext 为 true 则向后加载
		// 当 GotoNext 为 false 则向前加载
		void load_qa(const bool GotoNext);
        // 直接加载tNum处关注者列表
        void load_qa();


		// 重载输入流运算
		friend istream& operator>>(istream &input, User &U);
		// 重载输出流运算
		friend ostream& operator<<(ostream &output, User &U);
	private:
		// 用户ID
		string m_ID;
		// 用户名
		string m_Name;
		// 用户密码
		string m_Key;

		
		// 已关注数量
		long m_NumFocus;
		// 已提问数量
        long m_NumQA;
	};
}
