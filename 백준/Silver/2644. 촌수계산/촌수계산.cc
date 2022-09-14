#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

int ans = -1;

//template <typename T>
//void prt(const vector <T>& v1) {
//	cout << endl;
//	for (int i = 0; i < v1.size(); i++) {
//		for (int j = 0; j < v1[0].size(); j++) {
//			cout << v1[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

void dfs(int start, int end, vector <int> person[], bool visit[], int cnt) {
	visit[start] = true;
	// cout << start << "를 방문했음\n";
	if (start == end) {
		ans = cnt;
	}

	for (int i = 0; i < person[start].size(); i++) {
		int next = person[start][i];

		if (visit[next] == false){
			cnt++;
			dfs(next, end, person, visit, cnt);
			cnt--;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	 //
	int vertex, edge; cin >> vertex;
	int start, end; cin >> start >> end;
	cin >> edge;

	bool* visit = new bool[vertex + 1];

	fill(visit, visit + vertex + 1, false);

	vector <int>* vert = new vector<int>[vertex + 1];

	for (int i = 0; i < edge; i++) {
		int from, to; cin >> from >> to;
		vert[from].push_back(to);
		vert[to].push_back(from);
	}

	/*for (int i = 1; i <= edge; i++) {
		sort(vert[i].begin(), vert[i].end());
	}*/

	dfs(start, end, vert, visit, cnt);

	cout << ans;

}