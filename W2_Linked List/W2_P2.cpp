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
		while (curNode != tail) {
			cout << curNode->value << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
	void Insert(int index, int data) {
		if (index > this->size) {
			cout << "error" << endl;
			return;
		}
		Node* insertNode = new Node;
		insertNode->value = data;
		Node* curNode = this->head->next;
		for (int i = 0; i < index; i++) {
			curNode = curNode->next;
		}
		Node* prevNode = curNode->prev;
		insertNode->next = curNode;
		curNode->prev = insertNode;
		prevNode->next = insertNode;
		insertNode->prev = prevNode;
		this->size++;
	}
	void Remove(int index) {
		if (empty() || index >= this->size) {
			cout << "error" << endl;
			return;
		}
		Node* removeNode = this->head->next;
		for (int i = 0; i < index; i++) {
			removeNode = removeNode->next;
		}
		int removeValue = removeNode->value;
		Node* prevNode = removeNode->prev;
		prevNode->next = removeNode->next;
		removeNode->next->prev = prevNode;
		cout << removeValue << endl;
		delete removeNode;
		this->size--;
	}
	void RemoveAll(int data) {
		int count = 0;
		Node* curNode = this->head->next;
		while (curNode != tail) {
			Node* removeNode = curNode;
			if (removeNode->value == data) {
				curNode = curNode->next;
				Node* prevNode = removeNode->prev;
				Node* nextNode = removeNode->next;
				prevNode->next = nextNode;
				nextNode->prev = prevNode;
				count++;
				delete removeNode;
				this->size--;
			}
			else {
				curNode = curNode->next;
			}
		}
		if (count == 0) {
			cout << "not found" << endl;
		}
		else {
			cout << count << endl;
		}
	}
	void NeighborMax(int index) {
		if (index >= this->size) {
			cout << "error" << endl;
			return;
		}
		Node* curNode = this->head->next;
		for (int i = 0; i < index; i++) {
			curNode = curNode->next;
		}
		Node* prevNode = curNode->prev;
		Node* nextNode = curNode->next;
		if (prevNode->value > nextNode->value) {
			cout << prevNode->value << endl;
		}
		else {
			cout << nextNode->value<<endl;
		}
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
		else if (str == "Insert") {
			cin >> i>> x;
			ll.Insert(i, x);
		}
		else if (str == "Remove") {
			cin >> i;
			ll.Remove(i);
		}
		else if (str == "RemoveAll") {
			cin >> x;
			ll.RemoveAll(x);
		}
		else if (str == "NeighborMax") {
			cin >> i;
			ll.NeighborMax(i);
		}
	}
}