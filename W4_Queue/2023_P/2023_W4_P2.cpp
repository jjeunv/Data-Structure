#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	int value;
	Node* next;
	Node* prev;
public:
	Node() {
		this->value = 0;
		this->next = nullptr;
		this->prev = nullptr;
	}
	~Node() {
		this->value = 0;
		this->next = nullptr;
		this->prev = nullptr;
	}
	friend class Queue;
};

class Queue {
private:
	Node* head;
	Node* tail;
	int size;
public:
	Queue() {
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	~Queue() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	void enqueue(int x) {
		Node* newNode = new Node;
		newNode->value = x;
		tail->prev->next = newNode;
		newNode->prev = tail->prev;
		newNode->next = tail;
		tail->prev = newNode;
		size++;
	}
	int dequeue() {
		Node* deleteNode = head->next;
		int deleteValue = deleteNode->value;
		head->next = deleteNode->next;
		deleteNode->next->prev = head;
		size--;
		return deleteValue;
	}
};

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		int card, p1score, p2score;
		int p1point{ 0 }, p2point{ 0 };
		int p1left = 0;
		int p2left = 0;

		Queue p1, p2;
		for (int i = 0; i < N; i++) {
			cin >> card;
			p1.enqueue(card);
		}
		for (int i = 0; i < N; i++) {
			cin >> card;
			p2.enqueue(card);
		}
		for (int i = 1; i <= N; i++) {
			p1score = p1.dequeue()+p1left;
			p2score = p2.dequeue()+p2left;
			if (p1score > p2score) {
				p1point++;
				p1left = p1score - p2score;
				p2left = 0;
				cout << "Round" << i << " " << p1score << ">" << p2score
					<< " " << p1point << ":" << p2point << endl;
			}
			else if (p1score < p2score) {
				p2point++;
				p2left = p2score - p1score;
				p1left = 0;
				cout << "Round" << i << " " << p1score << "<" << p2score
					<< " " << p1point << ":" << p2point << endl;
			}
			else {
				p1left = 0;
				p2left = 0;
				cout << "Round" << i << " " << p1score << "=" << p2score
					<< " " << p1point << ":" << p2point << endl;
			}
		}
		if (p1point > p2point) {
			cout << "Winner P1" << endl;
		}
		else if (p1point < p2point) {
			cout << "Winner p2" << endl;
		}
		else {
			cout << "Draw" << endl;
		}

	}
}