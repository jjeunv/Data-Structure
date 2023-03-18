#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	int value;
	Node* next;
	Node* prev;
public:
	Node() {
		this->value = 0;
		this->next = nullptr;
		this->prev = nullptr;
	}
	~Node() {
		this->value = 0;
		this->next = nullptr;
		this->prev = nullptr;
	}
	friend class LinkedList;
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
		this->tail->prev = this->head;
		this->size = 0;
	}
	~LinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	bool empty() {
		return(this->size == 0);
	}
	void Print() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		Node* curNode = this->head->next;
		while (curNode != this->tail) {
			cout << curNode->value << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
	void Append(int data) {
		Node* appendNode = new Node;
		appendNode->value = data;
		Node* prevNode = this->tail->prev;
		prevNode->next = appendNode;
		appendNode->prev = prevNode;
		appendNode->next = this->tail;
		this->tail->prev = appendNode;
		this->size++;
		Print();
	}
	int Delete(int index) {
		if (empty() || index >= this->size) {
			return -1;
		}
		Node* deleteNode = this->head->next;
		for (int i = 0; i < index; i++) {
			deleteNode = deleteNode->next;
		}
		int deleteValue = deleteNode->value;
		Node* prevNode = deleteNode->prev;
		Node* nextNode = deleteNode->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;
		this->size--;
		delete deleteNode;
		return deleteValue;
	}
	void Print_reverse() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		Node* curNode = this->tail->prev;
		while (curNode != this->head) {
			cout << curNode->value << " ";
			curNode = curNode->prev;
		}
		cout << endl;
	}
	void Max() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		int maximum = 0;
		Node* curNode = this->head->next;
		while (curNode != this->tail) {
			if (curNode->value > maximum) {
				maximum = curNode->value;
			}
			curNode = curNode->next;
		}
		cout << maximum << endl;
	}
};

int main() {
	string str;
	int M;
	int i, x;
	LinkedList ll;
	cin >> M;
	while (M--) {
		cin >> str;
		if (str == "Print") {
			ll.Print();
		}
		else if (str == "Append") {
			cin >> x;
			ll.Append(x);
		}
		else if (str == "Delete") {
			cin >> i;
			cout<<ll.Delete(i)<<endl;
		}
		else if (str == "Print_reverse") {
			ll.Print_reverse();
		}
		else if (str == "Max") {
			ll.Max();
		}
	}
}

