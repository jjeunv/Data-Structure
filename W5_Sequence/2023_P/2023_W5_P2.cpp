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
	void insert(Iterator& p, int e) {
		Node* newNode = new Node;
		newNode->value = e;
		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;
		newNode->next = p.node;
		p.node->prev = newNode;
		size++;
	}
	Node* move(Iterator& p, int num) {
		if (num >= 0) {
			for (int i = 0; i < num; i++) {
				if (p.node != tail) {
					p.node = p.node->next;
				}
			}
			int a = p.node->value;
			if (a >= 0) {
				for (int i = 0; i < a; i++) {
					if (p.node != tail) {
						p.node = p.node->next;
					}
				}
				return p.node;
			}
			else if (a < 0) {
				for (int i = 0; i > a; i--) {
					if (p.node != head->next) {
						p.node = p.node->prev;
					}
				}
				return p.node;
			}
		}
		else if (num < 0) {
			for (int i = 0; i > num; i--) {
				if (p.node != head->next) {
					p.node = p.node->prev;
				}
			}
			int a = p.node->value;
			if (a >= 0) {
				for (int i = 0; i < a; i++) {
					if (p.node != tail) {
						p.node = p.node->next;
					}
				}
				return p.node;
			}
			else if (a < 0) {
				for (int i = 0; i > a; i--) {
					if (p.node != head->next) {
						p.node = p.node->prev;
					}
				}
				return p.node;
			}
		}
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
			int e;
			cin >> e;
			seq.insert(p, e);
		}
		int M;
		cin >> M;
		p.node = seq.begin();
		for (int i = 0; i < M; i++) {
			int k;
			cin >> k;
			p.node = seq.move(p, k);
		}

		cout << p.node->value<<endl;
	}
}