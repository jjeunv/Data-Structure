#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	Node* next = nullptr;
	Node* prev = nullptr;
	int value = 0;
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
	void Insert(Iterator& p, int e) {
		Node* newNode = new Node;
		newNode->value = e;
		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;
		newNode->next = p.node;
		p.node->prev = newNode;
		size++;
	}
	void pooling(Iterator& p) {
		int num1 = p.node->prev->value;
		int num2 = p.node->value;
		int num3 = p.node->next->value;
		
		if ((num1 > num2) && (num1 > num3)){
			cout<<num1<<" ";
		}
		else if ((num2 > num1) && (num2 > num3)) {
			cout << num2 << " ";
		}
		else if ((num3 > num1) && (num3 > num2)) {
			cout << num3 << " ";
		}

	}

};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		Sequence seq = Sequence();
		Iterator p = Iterator();
		p.node = seq.begin();
		cin >> N;
		int num;
		for (int i = 0; i < N; i++) {
			cin >> num;
			seq.Insert(p, num);
		}
		p.node = seq.begin();
		for (int i = 0; i < N; i++) {
			seq.pooling(p);
			++p;
		}
		cout << endl;
	}
}