#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	int value;
	Node* next;
public:
	Node() {
		this->value = 0;
		this->next = nullptr;
	}
	~Node() {
		this->value = 0;
		this->next = nullptr;
	}
	friend class LinkedList;
	friend class Stack;
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList() {
		this->head = new Node;
		this->tail = new Node;
		this->head->next = this->tail;
		this->size = 0;
	}
	~LinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	void Append(int data) {
		Node* newNode = new Node;
		newNode->value = data;
		newNode->next = this->head->next;
		this->head->next = newNode;
		this->size++;
	}
	void Delete() {
		Node* deleteNode = this->head->next;
		int deleteValue = deleteNode->value;
		this->head->next = deleteNode->next;
		this->size--;
		delete deleteNode;
		cout << deleteValue << endl;
	}
	friend class Stack;
};

class Stack {
private:
	LinkedList ll;
	int size;
public:
	Stack() {
		this->size = 0;
	}
	void Size() {
		cout << this->size << endl;
	}
	bool empty() {
		return this->size == 0;
	}
	void top() {
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			cout << ll.head->next->value << endl;
		}
	}
	void push(int x) {
		ll.Append(x);
		this->size++;
	}
	void pop() {
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			ll.Delete();
			this->size--;
		}
	}
};

int main() {
	string str;
	int N, x;
	cin >> N;
	Stack* s = new Stack;
	while (N--) {
		cin >> str;
		if (str == "size") {
			s->Size();
		}
		else if (str == "empty") {
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