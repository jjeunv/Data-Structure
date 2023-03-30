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

	Iterator* operator++(){
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
	void insert(Iterator&p, int e) {
		Node* newNode = new Node;
		newNode->value = e;
		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;
		newNode->next = p.node;
		p.node->prev = newNode;
		size++;
	}
	void erase(Iterator& p){
		if (size == 0) {
			cout << "Empty" << endl;
			return;
		}
		Node* deleteNode = p.node;
		deleteNode->prev->next = deleteNode->next;
		deleteNode->next->prev = deleteNode->prev;
		size--;
		delete deleteNode;
		p.node = begin();
	}
	void reversePrint() {
		if (size == 0) {
			cout << "Empty" << endl;
			return;
		}
		Node* curNode = tail->prev;
		while (curNode != head) {
			cout << curNode->value << " ";
			curNode = curNode->prev;
		}
		cout << endl;
	}
	void find(int e) {
		if (size == 0) {
			cout << "Empty" << endl;
			return;
		}
		int index = 0;
		Node* curNode = head->next;
		while (curNode != tail) {
			if (curNode->value == e) {
				cout << index << endl;
				return;
			}
			else {
				curNode = curNode->next;
				index++;
			}
		}
		cout << -1 << endl;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Sequence seq = Sequence();
	Iterator p = Iterator();
	p.node = seq.begin();

	string cmd;
	int M;
	cin >> M;
	while (M--) {
		cin >> cmd;
		if (cmd == "begin") {
			p.node = seq.begin();
		}
		else if (cmd == "end") {
			p.node = seq.end();
		}
		else if (cmd == "insert") {
			int e;
			cin >> e;
			seq.insert(p, e);
		}
		else if (cmd == "erase") {
			seq.erase(p);
		}
		else if (cmd == "++") {
			++p;
		}
		else if (cmd == "--") {
			--p;
		}
		else if (cmd == "reversePrint") {
			seq.reversePrint();
		}
		else if (cmd == "find") {
			int e;
			cin >> e;
			seq.find(e);
		}
	}

}