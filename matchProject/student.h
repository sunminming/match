#include<string>
#include<vector>
#include<map>
using namespace std;
#ifndef STUDENTS_H
#define STUDENTS_H
class students {
	friend class dep;
private:
	int num;//ѧ��
	int score;//�ɼ�
	vector<string> interset;//��Ȥ
	vector<int> aspiration;//��Ը
	vector<string> times;//����ʱ��
	double intmatch;//ƥ��̶�
	
public:
	//����ѧ��
	void setnum(int num) {
		this->num = num;
	}
	//���óɼ�
	void setscore(int score) {
		this->score = score;
	}
	//�����Ȥ
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