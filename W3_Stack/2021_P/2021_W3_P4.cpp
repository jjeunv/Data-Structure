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
		this -> size = 0;
	}
	void push(int data) {
		arr[size] = data;
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
	Stack* s = new Stack;
	cin >> t;
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
					s->push(num1 + num2);
				}
				else if (str[i] == '-') {
					s->push(num1 - num2);
				}
				else if (str[i] == '*') {
					s->push(num1 * num2);
				}
			}
		}
		cout << s->top() << endl;
	}
	
}