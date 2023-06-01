#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

bool visit[101];
vector<int> graph[101];
int minimum = 101;
void DFS(int num) {
	if (num < minimum) {
		minimum = num;
	}
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
			minimum = 101;
			DFS(C);
			cout << minimum << endl;
		}
	}
}

/*

2
11 8 3
1 2
1 7
1 3
4 3
1 4
5 6
10 9
9 11
2 
8
10
5 3 2
1 2
1 3
1 4
4
5

1
8
9
1
5

*/