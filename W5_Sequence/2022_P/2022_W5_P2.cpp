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
};

class Iterator {
public:
	Node* node = nullptr;
	Iterator* operator++() {
		node = node->next;
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
	Node* begin() {
		return head->next;
	}
	void Insert(Iterator& p, int e) {
		Node* newNode = new Node;
		newNode->value = e;
		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;
		newNode->next = p.node;
		p.node->prev = newNode;
		size++;
	}
	void sum(Iterator& p) {
		int num1 = p.node->prev->value;
		int num2 = p.node->value;
		int num3 = p.node->next->value;
		cout << num1 + num2 + num3 << " ";
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		Sequence seq = Sequence();
		Iterator p = Iterator();
		p.node = seq.begin();
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			seq.Insert(p,num);
		}
		p.node = seq.begin();
		for (int i = 0; i < N; i++) {
			seq.sum(p);
			++p;
		}
		cout << endl;
	}
}