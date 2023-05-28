#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int P;

class MinHeap {
public:
	vector<int> v;
	int size;

	MinHeap() {
		v.push_back(-1);
		size = 0;
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
		if (v[idx] < v[parent]) {
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
			if (v[left] < v[right]) {
				child = left;
			}
			else {
				child = right;
			}
		}
		if (v[child] < v[idx]) {
			swap(child, idx);
			downHeap(child);
		}
	}
	//41 76
	void insert(int value) {
		v.push_back(value);
		size++;
		upHeap(size);
	}

	int pop() {
		int value = v[1];
		v[1] = v[size];
		v.pop_back();
		size--;
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
			if (v[i] < P) {
				return true;
			}
		}
		return false;
	}

	void postTraversal(int idx) {
		if (idx * 2 <= size) {
			postTraversal(idx * 2);
		}
		if (idx * 2 + 1 <= size) {
			postTraversal(idx * 2 + 1);
		}
		cout << v[idx] << " ";
	}

	void print() {
		int count = 0;
		while (checkTemp()) {
			if (size <= 2) {
				cout << "False" << endl;
				return;
			}
			calcTemp();
			count++;
		}
		cout << count << endl;
		postTraversal(1);
		cout << endl;
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T; cin >> T;
	while (T--) {
		MinHeap h;
		int N; cin >> N >> P;
		while (N--) {
			int K; cin >> K;
			h.insert(K);
		}
		h.print();
	}
}

/*

5
8 57
10 76 44 55 3 4 15 57
10 57
23 35 84 14 36 76 67 43 3 94
5 71
19 29 10 63 84
4 41
48 22 65 85
5 13
47 63 48 68 97


False
4
94 64
False
1
85 43
0
68 97 63 48 47


*/