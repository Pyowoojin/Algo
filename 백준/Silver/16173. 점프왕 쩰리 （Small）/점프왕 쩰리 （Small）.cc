#include <bits/stdc++.h>
using namespace std;

string bfs(vector <vector<int>>& v) {
	/*
	map을 나타내는 2차원 벡터 v
	방문 여부를 나타내는 bool형 2차원 벡터 v
	queue에 방문한 노드를 집어 넣어 다음 노드로 가기 위한 발판으로 삼음
	*/
	queue <pair<int, int>> q;
	vector <bool> vs(3);
	vector <vector <bool>> visited(3, vs);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++)
			visited[i][j] = false;
	}
	// 첫 번째 방문노드 삽입
	q.push({ 0,0 });

	while (!q.empty()) {
		auto jelly = q.front(); q.pop();
		// x,y에 위치한 step은 몇일까? (무적권 step만큼 움직여야해!)
		int x = jelly.first, y = jelly.second;
		int step = v[x][y];

		// 목적지에 도착했다면 성공을 리턴함
		if (step == -1)
			return "HaruHaru";

		if (x + step < v.size() && !visited[x + step][y]) {
			q.push({ x + step, y });
			visited[x + step][y] = true;
		}
		if (y + step < v.size() && !visited[x][y + step]) {
			q.push({ x, y + step });
			visited[x][y + step] = true;
		}
	}

	return "Hing";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector <int> v2(n, 0);
	vector <vector <int>> v(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t; cin >> t; v[i][j] = t;
		}
	}
	vector <bool> vs(3);
	vector <vector <bool>> visited(3, vs);

	cout << bfs(v);

}