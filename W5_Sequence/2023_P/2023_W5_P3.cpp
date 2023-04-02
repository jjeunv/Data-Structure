#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node* prev;
	Node() {
		value = 0;
		next = nullptr;
		prev = nullptr;
	}
	~Node() {
		value = 0;
		next = nullptr;
		prev = nullptr;
	}
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
public:
	Node* head;
	Node* tail;
	int size;
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
			cout << "empty" << endl;
			return;
		}
		if (p.node == tail) {
			return;
		}
		Node* deleteNode = p.node;
		deleteNode->prev->next = deleteNode->next;
		deleteNode->next->prev = deleteNode->prev;
		delete deleteNode;
		size--;
		p.node = begin();
	}
	void nextP(Iterator& p) {
		if (p.node != tail) {
			p.node = p.node->next;
		}
	}
	void prevP(Iterator& p) {
		if (p.node != head->next) {
			p.node = p.node->prev;
		}
	}
	void finddivisor(int e) {
		int index = 0;
		int count = 0;
		Node* curNode = head->next;
		while (curNode != tail) {
			if (e % (curNode->value) == 0) {
				cout << index << " ";
				count++;
			}
			curNode = curNode->next;
			index++;
		}
		if (count == 0) {
			cout << -1;
		}
		cout << endl;
	}
};

int main() {
	string str;
	int N;
	cin >> N;
	Sequence seq = Sequence();
	Iterator p = Iterator();
	p.node = seq.begin();
	while (N--) {
		cin >> str;
		if (str == "begin") {
			p.node = seq.begin();
		}
		else if (str == "end") {
			p.node = seq.end();
		}
		else if (str == "insert") {
			int e;
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
		else if (str == "finddivisor") {
			int e;
			cin >> e;
			seq.finddivisor(e);
		}
	}
}