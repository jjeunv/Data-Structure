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
		this->head = new Node;
		this->tail = this->head;
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
		while (curNode != nullptr) {
			cout << curNode->value << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
	void Append(int data) {
		Node* appendNode = new Node;
		appendNode->value = data;
		this->tail->next = appendNode;
		this->tail = appendNode;
		this->size++;
		Print();
	}
	int Delete(int index) {
		if (empty() || index >= this->size) {
			return -1;
		}
		Node* prevNode = this->head;
		for (int i = 0; i < index; i++) {
			prevNode = prevNode->next;
		}
		Node* deleteNode = prevNode->next;
		int deleteValue = deleteNode->value;
		prevNode->next = deleteNode->next;
		this->size--;
		delete deleteNode;
		return deleteValue;		
	}
	void Insert(int index, int data) {
		if (index >= this->size) {
			cout << "Index Error" << endl;
			return;
		}
		Node* insertNode = new Node;
		insertNode->value = data;
		Node* prevNode = this->head;
		for (int i = 0; i < index; i++) {
			prevNode = prevNode->next;
		}
		insertNode->next = prevNode->next;
		prevNode->next = insertNode;
		Print();
	}
	int Sum() {
		if (empty()) {
			return 0;
		}
		int sum = 0;
		Node* curNode = this->head->next;
		while (curNode != nullptr) {
			sum += curNode->value;
			curNode = curNode->next;
		}
		return sum;
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
		else if (str == "Insert") {
			cin >> i >> x;
			ll.Insert(i, x);
		}
		else if (str == "Sum") {
			cout<<ll.Sum()<<endl;
		}
	}
}