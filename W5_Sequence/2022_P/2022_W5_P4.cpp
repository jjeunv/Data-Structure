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
	void sub(Iterator& p) {
		int num1 = p.node->prev->value;
		int num2 = p.node->value;
		int num3 = p.node->next->value;
		int max = num1;
		int min = num1;
		if (p.node == head->next) {
			if (num2 > num3) {
				cout << num2 - num3 << " ";
			}
			else {
				cout << num3 - num2 << " ";
			}
		}
		else if (p.node == tail->prev) {
			if (num1 > num2) {
				cout << num1 - num2 << " ";
			}
			else {
				cout << num2 - num1 << " ";
			}
		}
		else {
			if (num2 > max) {
				max = num2;
				if (num3 > max) {
					max = num3;
				}
			}
			else if (num3 > max) {
				max = num3;
			}
			if (num2 < min) {
				min = num2;
				if (num3 < min) {
					min = num3;
				}
			}
			else if (num3 < min) {
				min = num3;
			}
			cout << max - min << " ";
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
			int num;
			cin >> num;
			seq.Insert(p, num);
		}
		p.node = seq.begin();
		for (int i = 0; i < N; i++) {
			seq.sub(p);
			++p;
		}
		cout << endl;
	}
}