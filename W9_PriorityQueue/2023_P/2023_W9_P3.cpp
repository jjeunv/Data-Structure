#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

class PriorityQueue {
public:
	vector<int> v;
	
	void insert(int value) {
		for (int i = 0; i < v.size(); i++) {
			if (value > v[i]) {
				v.insert(v.begin() + i, value);
				return;
			}
		}
		v.push_back(value);
	}

	void print() {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		for (int i = 1; i < v.size(); i++) {
			cout << v[0] - v[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--) {
		PriorityQueue pq;
		int N; cin >> N;
		while (N--) {
			int n; cin >> n;
			pq.insert(n);
		}
		pq.print();
	}
}