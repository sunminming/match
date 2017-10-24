#include<string>
#include<vector>
#include<map>
using namespace std;
#ifndef STUDENTS_H
#define STUDENTS_H
class students {
	friend class dep;
private:
	int num;//学号
	int score;//成绩
	vector<string> interset;//兴趣
	vector<int> aspiration;//意愿
	vector<string> times;//空闲时间
	double intmatch;//匹配程度
	
public:
	//设置学号
	void setnum(int num) {
		this->num = num;
	}
	//设置成绩
	void setscore(int score) {
		this->score = score;
	}
	//添加兴趣
	void addinterest(string interset) {
		(this->interset).push_back(interset);
	}
	void addas(int aspiration) {
		this->aspiration.push_back(aspiration);
	}
	void addtimes(string time) {
		(this->times).push_back(time);
	}
	int getnum() {
		return this->num;
	}
	int getscore() {
		return this->score;
	}
	vector<int> getas() {
		return this->aspiration;
	}
	vector<string> getinterest() {
		return this->interset;
	}
	vector<string> gettimes() {
		return this->times;
	}
	double getw() {
		return this->intmatch;
	}
	void setw(double match) {
		this->intmatch = match;
	}
};
#endif