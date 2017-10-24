#include"student.h"
#include"dep.h"
#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
ifstream ins("student.txt");
ifstream ind("dep.txt");
ofstream out("record.txt");
double w1=0.9;
vector<students> vs;
vector<dep> vd;
int intpp[301][21];

int cpp(vector<string> vit, vector<string> dit) {
	int count = 0;
	for (string v : vit) {
		for (string d : dit) {
			if (v == d) count++;
		}
	}
	return count;
}

void fun() {
	for (auto v : vs) {
		for (auto d : vd) {
			intpp[v.getnum()][d.getdep()] = cpp(v.getinterest(), d.getinterest());
		}
	}
}

bool findtime(string dt, vector<string> st) {
	for (auto t : st) {
		if (t == dt) return true;

	}
	return false;
}

bool findde(vector<int> saps, int de) {
	for (auto ap : saps) {
		if (ap == de) return true;
	}
	return false;
}

bool cmp(students a, students b) {
	return a.getw() > b.getw();
}

void violence() {
	
	//sort(vs.begin(), vs.end(), cmp);//按权排序
	//遍历每个部门
	for (auto d = vd.begin(); d != vd.end();++d) {
		int N = 300;
		//若要新生加入
		if ((d->gethigh() != 0)) {
			fun();
			for (auto it = vs.begin(); it != vs.end();++it) {
				 double w=intpp[it->getnum()][d->getdep()];				 
				 it->setw(w);				 
			}			
			sort(vs.begin(), vs.end(), cmp);
			//遍历学生			
			auto s = vs.begin();
			
			for (int k = 0; k < N;++k) {
				//合适				
				if ((findde(s->getas(), d->getdep())) && (findtime(d->gettime(), s->gettimes()))) {					
					if (d->getrecord().size() < (d->gethigh())) {
						d->addrecord(s->getnum());
						s = vs.erase(s);
						--N;
					}
					else {
						students temps = *s;
						s = vs.erase(s);
						vs.push_back(temps);
					}
				}
				//不合适放入队尾
				else {					
					students temps = *s;
					s=vs.erase(s);
					vs.push_back(temps);					
				}				
			}
		}
	}
}

students sinput() {
	students s;
	
	string line;
	int num;
	getline(ins, line);
	istringstream ssinnum(line);
	while (ssinnum >> num) {
		s.setnum(num);
	}
	int scource;
	getline(ins, line);
	istringstream ssinsc(line);
	while (ssinsc >> scource) {
		s.setscore(scource);
	}
	int ap;
	getline(ins, line);
	istringstream ssin(line);
	while (ssin >> ap) {
		s.addas(ap);
	}
	getline(ins, line);
	string inters;
	istringstream ssini(line);
	while (ssini >> inters) {
		s.addinterest(inters);
	}
	getline(ins, line);
	string times;
	istringstream ssint(line);
	while (ssint >> times) {
		s.addtimes(times);
	}
	return s;
}

dep dinput() {
	dep de;
	string line;
	int num;
	getline(ins, line);
	istringstream ssinnum(line);
	while (ssinnum >> num) {
		de.setdepnum(num);
	}
	string time;
	getline(ins, line);
	istringstream ssint(line);
	while (ssint >> time) {
		de.settime(time);
	}
	string inter;
	getline(ins, line);
	istringstream ssininter(line);
	while (ssininter >> inter) {
		de.addinterset(inter);
	}
	int high;
	getline(ins, line);
	istringstream ssinhigh(line);
	while (ssinhigh >> high) {
		de.sethigh(high);
	}
	return de;
}

void prinfR() {
	for (auto d : vd) {
		for (auto r : d.getrecord()) {			
			out << r << " ";
		}
		out << endl;
	}
}

int main() {
	
	for (int k = 0; k < 320; ++k) {
		if (k < 300) {
			students s = sinput();
			vs.push_back(s);
		}


		else {
			dep de = dinput();
			vd.push_back(de);
		}
	}

	violence();
	
	prinfR();
	
}