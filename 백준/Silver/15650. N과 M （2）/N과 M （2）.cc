#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> vc;

void prt(vector <int>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		if (i > 0 && vc[i - 1] > vc[i])
			return;
	}

	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << " ";
	}
	cout << '\n';
}

void dfs(int k, int visited[]) {
	if (vc.size() == m) {
		prt(vc);
		return;
	}

	for (int i = 0; i < n; i++) {
		// 이미 방문한 배열이면 다음 배열로 넘어감
		if (visited[i] == 1)
			continue;
		// 그렇지 않다면 방문처리 후 vector에 삽입
		visited[i] = 1;
		vc.push_back(i + 1);
		// 재귀 수행
		dfs(i + 1, visited);
		vc.pop_back();
		visited[i] = 0;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int* visited = new int[n];
	fill(visited, visited + n, 0);
	dfs(0, visited);
}