#include <iostream>
#include <string>
using namespace std;

int t;
class Stack {
private:
	int arr[21]{};
	int size;
public:
	Stack() {
		this->size = 0;
	}
	bool empty() {
		return this->size == 0;
	}
	int Size() {
		return this->size;
	}
	bool full() {
		return this->size == t;
	}
	int top() {
		if (empty()) {
			return -1;
		}
		else {
			return arr[size - 1];
		}
	}
	void push(int x) {
		if (this->size == t) {
			cout << "FULL" << endl;
		}
		else {
			arr[size] = x;
			this->size++;
		}
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			this->size--;
			return arr[size];
		}
	}
};

int main() {
	int N, x;
	cin >> t >> N;
	string str;
	Stack* s = new Stack;
	while (N--) {
		cin >> str;
		if (str == "size") {
			cout<< s->Size() << endl;
		}
		else if (str == "empty") {
			cout<< s->empty() << endl;
		}
		else if (str == "full") {
			cout << s->full() << endl;
		}
		else if (str == "top") {
			cout << s->top() << endl;
		}
		else if (str == "push") {
			cin >> x;
			s->push(x);
		}
		else if (str == "pop") {
			cout << s->pop() << endl;
		}
	}
}