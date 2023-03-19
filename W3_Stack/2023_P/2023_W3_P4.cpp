#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	char arr[100]{};
	int size;
public:
	Stack() {
		this->size = 0;
	}
	bool empty() {
		return this->size == 0;
	}
	void push(char x) {
		arr[size] = x;
		this->size++;
	}
	char top() {
		return arr[size - 1];
	}
	char pop() {
		this->size--;
		return arr[size];
	}
};

int priority(char x) {
	switch (x) {
	case '(':
		return 0;
	case'+':
	case'-':
		return 1;
	case '*':
		return 2;
	default:
		break;
	}
}

int main() {
	string str;
	int t,x;
	cin >> t;
	while (t--) {
		Stack* s = new Stack;
		cin >> str;
		int count=0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] - '0' > 0 && str[i] - '0' <= 9) {
				cout << str[i];
			}
			else if (str[i] == '('){
				s->push(str[i]);
			}
			else if (str[i] == ')') {
				while (s->top() != '(') {
					cout<<s->pop();
				}
				s->pop();
				if (s->empty()) {
					count++;
				}
			}
			else {
				if (s->empty()) {
					s->push(str[i]);
				}
				else {
					while (!s->empty() && priority(s->top()) >= priority(str[i])) {
						cout << s->pop();
					}
					if (s->empty()) {
						count++;
					}
					s->push(str[i]);
				}

			}
		}
		while (!s->empty()) {
			cout << s->pop();
		}
		if (s->empty()) {
			count++;
		}
		cout << " " << count<<endl;
	}
}
