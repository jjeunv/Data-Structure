#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int value = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class Iterator {
public:
	Node* node = nullptr;
	Iterator* operator++() {
		node = node->next;
		return this;
	}
	Iterator* operator--() {
		node = node->prev;
		return this;
	}
};

class Sequence {
private:
	Node* head;
	Node* tail;
	int size;
public:
	Sequence() {
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	~Sequence() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	Node* begin() {
		return head->next;
	}
	Node* end() {
		return tail;
	}
	void insert(Iterator& p, int e) {
		Node* newNode = new Node;
		newNode->value = e;
		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;
		newNode->next = p.node;
		p.node->prev = newNode;
		size++;
	}
	void erase(Iterator& p) {
		if (size == 0) {
			cout << "Empty" << endl;
			return;
		}
		else if (p.node == tail) {
			return;
		}
		Node* deleteNode = p.node;
		deleteNode->prev->next = deleteNode->next;
		deleteNode->next->prev = deleteNode->prev;
		size--;
		delete deleteNode;
		p.node = begin();
	}
	void nextP(Iterator& p) {
		if (p.node== tail) {
			return;
		}
		++p;
	}
	void prevP(Iterator& p) {

		if (p.node == head->next) {
			return;
		}
		--p;
	}
	void print() {
		if (size == 0) {
			cout << "Empty" << endl;
			return;
		}
		Node* curNode = head->next;
		while (curNode != tail) {
			cout << curNode->value << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
	void find(int e) {
		int index = 0;
		int count = 0;
		Node* curNode = head->next;
		while (curNode != tail) {
			if (curNode->value == e) {
				cout << index << " ";
				count++;
			}
			curNode = curNode->next;
			index++;
		}
		if (count == 0) {
			cout << -1 << endl;
		}
		else {
			cout << endl;
		}
	}
};

int main() {
	string str;
	int N;
	Sequence seq=Sequence();
	Iterator p=Iterator();
	int e;
	p.node = seq.begin();
	cin >> N;
	while (N--) {
		cin >> str;
		if (str == "begin") {
			p.node = seq.begin();
		}
		else if (str == "end") {
			p.node = seq.end();
		}
		else if (str == "insert") {
			cin >> e;
			seq.insert(p, e);
		}
		else if (str == "erase") {
			seq.erase(p);
		}
		else if (str == "nextP") {
			seq.nextP(p);
		}
		else if (str == "prevP") {
			seq.prevP(p);
		}
		else if (str == "print") {
			seq.print();
		}
		else if (str == "find") {
			cin >> e;
			seq.find(e);
		}


	}
}