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
	bool empty() {
		return(this->size == 0);
	}
	void Print() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		Node* curNode = this->head;
		while (curNode != nullptr) {
			cout << curNode->value << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
	void AddBack(int data) {
		Node* newNode = new Node;
		newNode->value = data;
		if (empty()) {
			this->head = newNode;
			this->tail = newNode;
		}
		else {
			this->tail->next = newNode;
			this->tail = newNode;
		}
		this->size++;
	}
	void RemoveBack() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		Node* prevNode = this->head;
		Node* removeNode = this->tail;
		int removeValue = removeNode->value;
		if (this->size == 1) {
			this->head = nullptr;
			this->tail = nullptr;
		}
		else {
			while (prevNode->next != this->tail) {
				prevNode = prevNode->next;
			}
			this->tail = prevNode;
			prevNode->next = nullptr;
		}
		this->size--;
		cout << removeValue<<endl;
		delete removeNode;
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
	void Max() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		int index = 0;
		int maxValue = 0;
		int maxIndex = 0;
		Node* curNode = this->head;
		while (curNode != nullptr) {
			if (curNode->value > maxValue) {
				maxValue = curNode->value;
				maxIndex = index;
			}
			curNode = curNode->next;
			index++;
		}
		cout << maxIndex << " " << maxValue << endl;
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
		else if (str == "AddBack") {
			cin >> x;
			ll.AddBack(x);
		}
		else if (str == "RemoveBack") {
			ll.RemoveBack();
		}
		else if (str == "Update") {
			cin >> i >> x;
			ll.Update(i, x);
		}
		else if (str == "Max") {
			ll.Max();
		}
	}
}