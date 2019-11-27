#include<iostream>
#include<cstdio>

using namespace std;
class queue {
private:
	int *q;
	int rloc, sloc;
public:
	queue(int num);
	~queue();
	void qput(int num);
	int qget();
	int Max();
	void rev(int num);
};

queue::queue(int num) { q = new int[num]; }
queue::~queue() { delete [] q; }
void queue::qput(int num){
	if (sloc == 99) {
		cout << "Full";
	}
	sloc++;
	q[sloc] = num;
}
int queue::qget(){
	if (rloc == sloc) {
		cout << "Empty";
	}
	rloc++;
	return q[rloc];
}
int queue::Max(){
	int temp = 0;
	for (int i = rloc + 1; i <= sloc; i++) {
		if (temp < q[i])temp = q[i];
	}
	return temp;
}
void queue::rev(int num){
	for (int i = sloc; q[i]; i--) {
		cout << q[i] << endl;
		num--; if (num == 0)break;
	}
}
int main() {
	queue qd(5);
	qd.qput(10);
	qd.qput(30);
	qd.qput(50);
	qd.qput(20);
	cout << qd.qget() << endl;
	cout << qd.Max() << endl;
	qd.rev(3);
}