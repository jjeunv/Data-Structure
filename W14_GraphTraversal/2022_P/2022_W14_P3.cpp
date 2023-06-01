#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[101];
vector<int> graph[101];

void BFS(int num) {
	int count = 1;
	queue<int> q;
	q.push(num);
	visit[num] = true;
	while (!q.empty()) {
		int curNum = q.front();
		q.pop();
		if (count % 2 != 0) {
			cout << curNum << " ";
		}
		count++;
		for (auto i : graph[curNum]) {
			if (!visit[i]) {
				q.push(i);
				visit[i] = true;
			}
		}
	}
}

int main() {
	int T; cin >> T;
	while (T--) {
		int N, M; 
		cin >> N >> M;
		for (int i = 0; i <= 100; i++) {
			visit[i] = false;
			graph[i].clear();
		}
		while (M--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		BFS(1);
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

1 2 4
1 4 8 5 7

*/