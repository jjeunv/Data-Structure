#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

class MaxHeap {
public:
	vector<int> v;
	int size;

	MaxHeap() {
		v.push_back(-1);
		size = 0;
	}

	int Size() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void swap(int a, int b) {
		v[0] = v[a];
		v[a] = v[b];
		v[b] = v[0];
	}

	void upHeap(int idx) {
		if (size == 1) {
			return;
		}
		int parent = idx / 2;
		if (v[idx] > v[parent]) {
			swap(idx, parent);
			upHeap(parent);
		}
	}
	
	void downHeap(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		int child;
		if (left > size) {
			return;
		}
		if (left == size) {
			child = left;
		}
		else {
			if (v[left] > v[right]) {
				child = left;
			}
			else {
				child = right;
			}
		}
		if (v[child] > v[idx]) {
			swap(child, idx);
			downHeap(child);
		}
	}

	void insert(int value) {
		v.push_back(value);
		size++;
		upHeap(size);
	}
	
	void top() {
		if (isEmpty()) {
			cout << -1 << endl;
			return;
		}
		cout << v[1] << endl;
	}

	void pop() {
		if (isEmpty()) {
			cout << -1 << endl;
			return;
		}
		cout << v[1] << endl;
		v[1] = v[size];
		size--;
		v.pop_back();
		downHeap(1);
	}

	void print() {
		if (isEmpty()) {
			cout << -1 << endl;
			return;
		}
		for (int i = 1; i <= size; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T; cin >> T;
	string str;
	MaxHeap h;
	int i;
	while (T--) {
		cin >> str;
		if (str == "insert") {
			cin >> i;
			h.insert(i);
		}
		else if (str == "size") {
			cout << h.Size() << endl;
		}
		else if (str == "isEmpty") {
			cout << h.isEmpty() << endl;
		}
		else if (str == "pop") {
			h.pop();
		}
		else if (str == "top") {
			h.top();
		}
		else if (str == "print") {
			h.print();
		}
	}
}

/*

17
isEmpty
print
insert 10
insert 5
size
insert 6
insert 9
pop
insert 2
insert 4
top
insert 8
insert 11
pop
insert 15
insert 3
print


1
-1
2
10
9
11
15 5 9 3 4 6 8 2

*/