// class: "Answer"
// belong to namespace: "kernal"

#pragma once

#include <string>
#include "BasicInfo.h"
using namespace std;

namespace kernal {
	class Answer : public kernal::BasicInfo {
	public:
        static string g_AnswerNow;


		// 默认构造函数
		Answer();
		// 根据ID从文件中读取答案
		// 应当保证ID的正确性
		Answer(const string &ID);
		// 参数构造函数
		// 此函数会自动创建并写入文件
		//		UID 用户ID
		//		QID 此答案对应的问题的ID
		//		Q_Anum 此答案已有的问题数量
		//		Text 答案文本
		Answer(const string &UID, const string &QID, const long &Q_Anum, const string &Text);
		// 析构函数
		~Answer();


		// 得到 点赞数
		long get_mpraiseNum() const;
		// 点赞数 +1
		// 需要提供点赞人员的用户id
		void add1_mpraiseNum(const string &UID);
		// 点赞数 -1
		// 需要提供点赞人员的用户id
		void sub1_mpraiseNum(const string &UID);
		// 判断 用户ID 为 UID 的用户
		// 是否已经为此问题点赞
		bool already_praise(const string &UID);


		// 得到此回答的id文件名(带路径)
		string getFileName_id() const;
		// 得到此回答的点赞列表文件名(带路径)
		string getFileName_p() const;


		// 重载输入流运算
		friend istream& operator>>(istream &input, Answer &A);
		// 重载输出流运算
		friend ostream& operator<<(ostream &output, Answer &A);
	private:
		// 点赞数
		long m_praiseNum;
	};
}
