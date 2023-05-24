#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

class PriorityQueue {
public:
	vector<int> first;
	vector<int> second;

	void insert(int value) {
		if (value % 5 == 0) {
			for (int i = 0; i < second.size(); i++) {
				if (value < second[i]) {
					second.insert(second.begin() + i, value);
					return;
				}
			}
			second.push_back(value);
		}
		else {
			for (int i = 0; i < first.size(); i++) {
				if (value < first[i]) {
					first.insert(first.begin() + i, value);
					return;
				}
			}
			first.push_back(value);
		}
	}
	
	void print() {
		for (int i = 0; i < first.size(); i++) {
			cout << first[i] << " ";
		}
		for (int i = 0; i < second.size(); i++) {
			cout << second[i] << " ";
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