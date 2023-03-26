#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	int value;
	Node* next;
	Node* prev;
public:
	Node(){
		this->value = 0;
		this->next = nullptr;
		this->prev = nullptr;
	}
	~Node() {
		this->value = 0;
		this->next = nullptr;
		this->prev = nullptr;
	}
	friend class Queue;
};

class Queue {
private:
	Node* head;
	Node* tail;
	int size;
public:
	Queue() {
		this->head = new Node;
		this->tail = new Node;
		this->head->next = this->tail;
		this->tail->prev = this->head;
		this->size = 0;
	}
	~Queue() {
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	int getSize() {
		return this->size;
	}
	bool isEmpty() {
		return this->size == 0;
	}
	void front() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << this->head->next->value << endl;
		}
	}
	void rear() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << this->tail->prev->value << endl;
		}
	}
	void enqueue(int x) {
		Node* newNode = new Node;
		newNode->value = x;
		this->tail->prev->next = newNode;
		newNode->prev = this->tail->prev;
		newNode->next = this->tail;
		this->tail->prev = newNode;
		this->size++;
	}
	void dequeue() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			Node* deleteNode = this->head->next;
			this->head->next = deleteNode->next;
			deleteNode->next->prev = this->head;
			cout << deleteNode->value << endl;
			delete deleteNode;
			this->size--;
		}
	}
};

int main() {
	int T;	
	int x;
	string str;
	cin >> T;
	Queue q;
	while (T--) {
		cin >> str;
		if (str == "size") {
			cout << q.getSize() << endl;
		}
		else if (str == "isEmpty") {
			cout << (q.isEmpty() ? "True\n" : "False\n");
		}
		else if (str == "front") {
			q.front();
		}
		else if (str == "rear") {
			q.rear();
		}
		else if (str == "enqueue") {
			cin >> x;
			q.enqueue(x);
		}
		else if (str == "dequeue") {
			q.dequeue();
		}
	}
}