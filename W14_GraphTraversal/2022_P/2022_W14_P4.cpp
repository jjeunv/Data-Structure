#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

bool visit[101];
vector<int> graph[101];
int maximum = 0;

void DFS(int num) {
	if (num > maximum) {
		maximum = num;
	}
	visit[num] = true;
	for (auto i : graph[num]) {
		if (!visit[i]) {
			DFS(i);
		}
	}
}

int main() {
	int T; cin >> T;
	while (T--) {
		int N, M, K;
		cin >> N >> M >> K;
		for (int i = 0; i < 101; i++) {
			visit[i] = false;
			graph[i].clear();
		}
		while (M--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		while (K--) {
			int C; cin >> C;
			maximum = 0;
			DFS(C);
			cout << maximum << endl;
		}
	}
}