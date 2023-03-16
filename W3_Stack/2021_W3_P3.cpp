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
		Node* appendNode = new Node;
		appendNode->value = data;
		appendNode->next = this->head->next;
		this->head->next = appendNode;
		this->size++;
	}
	void Delete() {
		Node* deleteNode = this->head->next;
		int deleteValue = deleteNode->value;
		this->head->next = deleteNode->next;
		cout << deleteValue << endl;
		this->size--;
		delete deleteNode;
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
	bool empty() {
		return(this->size == 0);
	}
	int top() {
		if (empty()) {
			return -1;
		}
		else {
			return ll.head->next->value;
		}
	}
	void push(int data) {
		ll.Append(data);
		this->size++;
	}
	void pop() {
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			ll.Delete();
		}
		this->size--;
	}
};

int main() {
	string str;
	int N, x;
	cin >> N;
	Stack* s = new Stack();
	while (N--) {
		cin >> str;
		if (str == "empty") {
			cout << s->empty() << endl;
		}
		else if (str == "top") {
			cout<<s->top()<<endl;
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