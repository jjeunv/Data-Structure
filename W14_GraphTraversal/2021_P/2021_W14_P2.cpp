#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[101];
int dist[101];
vector<int> graph[101];

void DFS(int num) {
	visit[num] = true;
	for (auto i : graph[num]) {
		if (!visit[i]) {
			dist[i] = dist[num] + 1;
			DFS(i);
		}
	}
}
void BFS(int num) {
	queue<int> q;
	q.push(num);
	visit[num] = true;
	while (!q.empty()) {
		int curNum = q.front();
		q.pop();
		for (auto i : graph[curNum]) {
			if (!visit[i]) {
				q.push(i);
				dist[i] = dist[curNum] + 1;
				visit[i] = true;
			}
		}
	}
}

int main() {
	int T; cin >> T;
	while (T--) {
		int N, M, K; 
		cin >> N >> M >> K;
		for (int i = 0; i <= 100; i++) {
			graph[i].clear();
		}
		while (M--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		while (K--) {
			int c, d;
			cin >> c >> d;
			for (int i = 0; i <= 100; i++)
			{
				dist[i] = 0;
				visit[i] = false;
			}
			DFS(c);
			//BFS(c);
			cout << dist[d] << endl;
		}
	}
}


/*
2
11 9 3
1 2
1 7
1 3
1 4
3 8
4 5
5 6
10 9
9 11
8 6
1 10
6 7
5 3 2
1 2
1 3
1 4
4 3
5 2

5
0
4
2
0

*/