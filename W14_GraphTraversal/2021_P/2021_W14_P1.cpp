#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

bool visit[101];
vector<int> graph[101];

void DFS(int num) {
	cout << num << " ";
	visit[num] = true;
	for (auto i : graph[num]) {
		if (!visit[i]) {
			DFS(i);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T; cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
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
		DFS(1);
		cout << endl;
	}
}

/*

2
6 6
1 5
5 2
1 2
3 1
2 4
3 6
10 11
1 2
1 4
6 4
3 6
2 6
8 10
5 6
5 7
8 2
7 9
4 3

1 5 2 4 3 6
1 2 6 4 3 5 7 9 8 10

*/