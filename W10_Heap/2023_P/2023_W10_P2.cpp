#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int P;

class MaxHeap {
public:
	vector<int> v;
	int size;

	MaxHeap() {
		v.push_back(-1);
		size = 0;
	}

	void swap(int a, int b) {
		v[0] = v[a];
		v[a] = v[b];
		v[b] = v[0];
	}

	void upHeap(int idx) {
		if (idx == 1) {
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

	int pop() {
		int value = v[1];
		v[1] = v[size];
		size--;
		v.pop_back();
		downHeap(1);
		return value;
	}

	void calcTemp() {
		int a = pop();
		int b = pop();
		int c = pop();
		int value = (a + c) / 2;
		insert(value);
	}

	bool checkTemp() {
		for (int i = 1; i <= size; i++) {
			if (v[i] > P) {
				return true;
			}
		}
		return false;
	}

	void preTraversal(int idx) {
		cout << v[idx] << " ";
		if (idx * 2 <= size) {
			preTraversal(idx * 2);
		}
		if (idx * 2 + 1 <= size) {
			preTraversal(idx * 2 + 1);
		}
	}

	void print() {
		int count = 0;
		while (checkTemp()) {
			if (size <= 2) {
				cout << "False";
				return;
			}
			calcTemp();
			count++;
		}
		cout << count << endl;
		preTraversal(1);
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T; cin >> T;
	while (T--) {
		MaxHeap h;
		int N;
		cin >> N >> P;
		while (N--) {
			int K; cin >> K;
			h.insert(K);
		}
		h.print();
		cout << endl;
	}
}

/*
5
6 91
92 35 55 3 98 10
8 31
1 41 30 63 57 42 6 34
7 38
22 90 83 92 63 45 39
9 95
82 4 54 1 17 76 71 86 8
3 80
60 63 59

1
76 35 3 10
3
24 1
False
0
86 82 17 1 8 4 76 54 71
0
63 60 59

*/