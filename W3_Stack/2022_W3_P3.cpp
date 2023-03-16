#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	char arr[10001]{};
	int size;
public:
	Stack() {
		this->size = 0;
	}
	bool empty() {
		return this->size == 0;
	}
	void push(char data) {
		arr[size] = data;
		this->size++;
	}
	void pop() {
		this->size--;
	}
	char top() {
		return arr[size - 1];
	}

};

int priority(char c)
{
	switch (c)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		break;
	}
}

int main() {
	int m;
	cin >> m;
	string str;
	while (m--) {
		cin >> str;
		Stack* s = new Stack;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				cout << str[i];
			}
			else if (str[i] == '(') {
				s->push(str[i]);
			}
			else if (str[i] == ')') {
				while (s->top() != '(') {
					cout << s->top();
					s->pop();
				}
				s->pop();
			}
			else {
				while (!s->empty() && priority(s->top()) >= priority(str[i])) {
					cout << s->top();
					s->pop();
				}
				s->push(str[i]);
			}
		}
		while (!s->empty()) {
			cout << s->top();
			s->pop();
		}
		cout << endl;
	}
}