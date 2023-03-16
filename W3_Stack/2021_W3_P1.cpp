#include <iostream>
#include <string>
using namespace std;

int N, T;

class Stack {
private:
	int arr[10]{};
	int size;
public:
	Stack() {
		this->size = 0;
	}
	bool empty() {
		return(this->size == 0);
	}
	void top() {
		if (empty()) {
			cout << -1 << endl;
			return;
		}
		cout << arr[size - 1] << endl;
	}
	void push(int x) {
		if (size == T) {
			cout << "FULL" << endl;
			return;
		}
		arr[size] = x;
		this->size++;
	}
	void pop() {
		if (empty()) {
			cout << -1 << endl;
			return;
		}
		this->top();
		this->size--;
	}
};
int main() {
	cin >> T >> N;
	string str;
	int x;
	Stack* s = new Stack();
	while (N--) {
		cin >> str;
		if (str == "empty") {
			cout << s->empty() << endl;
		}
		else if (str == "top") {
			s->top();
		}
		else if (str == "push") {
			cin >> x;
			s->push(x);
		}
		else if (str == "pop") {
			s->pop();
		}
	}
}