#include <iostream>
#include <string>	
using namespace std;


const int max_size = 10001;
class Stack {
private:
	int arr[max_size];
	int size;
public:
	Stack() {
		size = 0;
	}
	int empty() {
		if (size == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int top() {
		if (empty() == 1) {
			return -1;
		}
		else {
			return arr[size - 1];
		}
	}
	void push(int x) {
		arr[size] = x;
		size++;
		return;
	}
	int pop() {
		if (empty() == 1) {
			return -1;
		}
		else {
			int value = arr[size - 1];
			size--;
			return value;
		}
	}
	int Size() {
		return size;
	}
};

int main() {
	int N, x;
	string str;
	cin >> N;
	Stack s;
	while (N--) {
		cin >> str;
		if (str == "empty") {
			cout<<s.empty()<<endl;
		}
		else if (str == "top") {
			cout << s.top()<<endl;
		}
		else if (str == "push") {
			cin >> x;
			s.push(x);
		}
		else if (str == "pop") {
			cout << s.pop()<<endl;
		}
		else if (str == "size") {
			cout << s.Size()<<endl;
		}
	}
}