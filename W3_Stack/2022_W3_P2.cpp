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
		Node* pushNode = new Node;
		pushNode->value = data;
		pushNode->next = this->head->next;
		this->head->next = pushNode;
		this->size++;
	}
	void Delete() {
		Node* deleteNode = this->head->next;
		int deleteValue = deleteNode->value;
		this->head->next = deleteNode->next;
		this->size--;
		delete deleteNode;
		cout<< deleteValue<<endl;
	}
	friend class Stack;
};

class Stack {
private:
	LinkedList ll;
	int size;
public:
	Stack() {
		ll = LinkedList();
		size = 0;
	}
	bool empty() {
		return this->size == 0;
	}
	int top() {
		if (empty()) {
			return -1;
		}
		return  ll.head->next->value;
	}
	void push(int data){
		ll.Append(data);
		size++;
	}
	void pop() {
		if (empty()) {
			cout<< -1<<endl;
		}
		else {
			size--;
			ll.Delete();
		}
	}
	int Size() {
		return size;
	}

};

int main() {
	string str;
	int N, x;
	cin >> N;
	Stack s;
	while (N--) {
		cin >> str;
		if (str == "empty") {
			cout << s.empty() << endl;
		}
		else if (str == "top") {
			cout << s.top() << endl;
		}
		else if (str == "push") {
			cin >> x;
			s.push(x);
		}
		else if (str == "pop") {
			s.pop();
		}
		else if (str == "size") {
			cout << s.Size() << endl;
		}
	}
}