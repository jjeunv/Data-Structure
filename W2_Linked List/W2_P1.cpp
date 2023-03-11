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
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	~LinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	bool Empty() {
		return(this->size == 0);
	}
	void Print() {
		if (Empty()) {
			cout << "empty" << endl;
			return;
		}
		Node* curNode = this->head;
		while (curNode != nullptr) {
			cout << curNode->value << " ";
			curNode=curNode->next;
		}
		cout << endl;
		
	}
	void AddFront(int data) {
		Node* newNode = new Node;
		newNode->value = data;
		if(Empty()){
			this->head = newNode;
			this->tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		this->size++;
	}
	void RemoveFront() {
		if (Empty()) {
			cout << "empty" << endl;
			return;
		}
		Node* deleteNode = head;
		int deleteValue = deleteNode->value;
		if (this->size == 1) {
			this->head = nullptr;
			this->tail = nullptr;
		}
		else {
			this->head = deleteNode->next;
		}
		cout << deleteValue << endl;
		this->size--;
		delete deleteNode;
	}
	void Update(int index, int data) {
		if (index >= this->size) {
			cout << "error" << endl;
			return;
		}
		Node* updateNode = this->head;
		for (int i = 0; i < index; i++) {
			updateNode = updateNode->next;
		}
		updateNode->value = data;
	}
	void Min() {
		if (Empty()) {
			cout << "empty" << endl;
			return;
		}
		int index = 0;
		int indexNum = 0;
		int minValue = 10000;
		Node* curNode = head;
		while (curNode != nullptr) {
			if (curNode->value < minValue) {
				minValue = curNode->value;
				indexNum = index;
			}
			curNode = curNode->next;
			index++;
		}
		cout << indexNum << " " << minValue << endl;
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
		else if (str == "AddFront") {
			cin >> x;
			ll.AddFront(x);
		}
		else if (str == "RemoveFront") {
			ll.RemoveFront();
		}
		else if (str == "Update") {
			cin >> i >> x;
			ll.Update(i, x);
		}
		else if (str == "Min") {
			ll.Min();
		}
	}
}