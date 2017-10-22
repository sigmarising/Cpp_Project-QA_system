// class: "SystemNeed"
// belong to namespace: "func"

#pragma once

#include <string>
using namespace std;

namespace func {
	// 这是系统必用类 在系统初始化时
	// 必须 仅仅 调用 1次 void init_vars() 函数
	class SystemNeed {
	public:
		SystemNeed();
		~SystemNeed();


		// 初始化变量 在main函数进行
		// 必须仅仅 使用一次
		static void init_vars();


		// 创建一个 新的用户
		// 会使总用户数量 +1 同时修改系统文件 和 静态变量
        // 并返回 新用户的ID string
		static string Create_NewUser();
		// 创建一个 新的问题
		// 会使总问题数 +1 同时修改系统文件 和 静态变量
        // 并返回 新问题的ID string
		static string Create_NewQuestion();


		// 返回 总用户数量
		static long get_NumUsers();
		// 返回 总问题数量
		static long get_NumQuestion();
	private:
		// 系统必备文件 文件名（带路径）
		static string m_SysKeynote;
		// 当前用户总数
		static long m_Num_Users;
		// 当前问题总数
		static long m_Num_Question;
	};
}
