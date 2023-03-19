#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	int arr[100]{};
	int size;
public:
	Stack() {
		this->size = 0;
	}
	void push(int x) {
		arr[size] = x;
		this->size++;
	}
	int pop() {
		this->size--;
		return arr[size];
	}

	int top() {
		return arr[size - 1];
	}
};

int main() {
	string str;
	int t;
	cin >> t;
	while (t--) {
		Stack* s = new Stack();
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] - '0' > 0 && str[i] - '0' <= 9) {
				s->push(str[i]-'0');
			}
			else {
				int num2 = s->pop();
				int num1 = s->pop();
				switch (str[i]) {
				case '+':
					s->push(num1 + num2);
					break;
				case '-':
					s->push(num1 - num2);
					break;
				case '*':
					s->push(num1 * num2);
					break;
				}
			}
		}
	
		string q = to_string(s->top());
		int sum = 0;
		for (int i = 0; i < q.size(); i++) {
			if (q[i] == '-') {
				continue;
			}
			else {
				sum = sum + (q[i] - '0');
			}
		}
		cout << sum << endl;
	}
}