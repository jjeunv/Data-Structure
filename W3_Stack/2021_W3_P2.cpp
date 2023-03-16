#include <iostream>
#include <string>
using namespace std;

int t;
class Stack {
private:
	int arr[100]{};
	int size;
public:
	Stack() {
		this->size = 0;
	}
	bool empty() {
		return(this->size == 0);
	}
	int top() {
		return arr[size - 1];
	}
	void push(int data) {
		arr[size] = data;
		size++;
	}
	int pop() {
		size--;
		return arr[size];
	}
};

int main() {
	cin >> t;
	string str;
	Stack* s = new Stack();
	while (t--) {
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] - '0' > 0 && str[i] - '0' <= 9) {
				s->push(str[i] - '0');
			}
			else {
				int num2 = s->pop();
				int num1 = s->pop();
				if (str[i] == '+') {
					s->push((num1 + num2));
				}
				else if (str[i] == '-') {
					s->push((num1 - num2));
				}
				else if (str[i] == '*') {
					s->push((num1 * num2));
				}
			}
		}
		cout << s->top() % 10 << endl;
	}
}
