#include <iostream>
using namespace std;

class Array {
private:
	int* arr;
	int arrSize;
public:
	Array(int sz) {
		this->arrSize = sz;
		this->arr = new int[arrSize];
		for (int i = 0; i < sz; i++) {
			arr[i] = 0;
		}
	}

	void at(int idx) {
		cout << arr[idx]<<endl;
	}

	void add(int idx, int value) {
		for (int i = arrSize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}

	void remove(int idx) {
		for (int i = idx + 1; i < arrSize; i++) {
			arr[i - 1] = arr[i];
		}
		arr[arrSize - 1] = 0;
	}

	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void set(int idx, int value) {
		arr[idx] = value;
	}

	void find(int value) {
		int a = -1;
		for (int i = 0; i < arrSize; i++) {
			if (arr[i] == value) {
				a = 1;
				cout << i << endl;
				break;
			}
		}
		if (a == -1) {
			cout << a << endl;
		}
	}
};

int main(){
	int T, N = 0, i, s = 0;
	cin >> T >> N;
	string str;
	Array ar(N);
	while (T--) {
		cin >> str;
		if (str == "at") {
			cin >> i;
			ar.at(i);
		}
		else if (str == "add") {
			cin >> i >> s;
			ar.add(i, s);
		}
		else if (str == "remove") {
			cin >> i;
			ar.remove(i);
		}
		else if (str == "print") {
			ar.print();
		}
		else if (str == "set") {
			cin >> i >> s;
			ar.set(i, s);
		}
		else if (str == "find") {
			cin >> i;
			ar.find(i);
		}
	}
}