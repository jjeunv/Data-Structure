#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	Node* next;
	Node* prev;
	int value;
	Node() {
		next = nullptr;
		prev = nullptr;
		value = 0;
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
	void Insert(Iterator& p, int e) {
		Node* newNode = new Node;
		newNode->value = e;
		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;
		newNode->next = p.node;
		p.node->prev = newNode;
		size++;
	}
	void convolution(Iterator& p) {
		int num1 = p.node->prev->value;
		int num2 = p.node->value;
		int num3 = p.node->next->value;
		cout << num1 + 3 * num2 + num3 << " ";
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
			seq.convolution(p);
			++p;
		}
		cout << endl;
	}
}