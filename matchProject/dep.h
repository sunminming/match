#include<string>
#include<vector>
using namespace std;
#ifndef dep_H
#define dep_h
class dep {
	int depnum;
	string time;
	vector<string> interset;
	int high;
	vector<int> record;
public:
	void setdepnum(int dep) {
		this->depnum = dep;
	}
	void settime(string time) {
		this->time = time;
	}
	void addinterset(string interset) {
		(this->interset).push_back(interset);
	}
	void sethigh(int high) {
		this->high = high;
	}
	int getdep() {
		return this->depnum;
	}
	string gettime() {
		return this->time;
	}
	vector<string> getinterest() {
		return this->interset;
	}
	unsigned int gethigh() {
		return this->high;
	}
	vector<int> getrecord() {
		return this->record;
	}
	void addrecord(int num) {
		this->record.push_back(num);
	}
};
#endif
