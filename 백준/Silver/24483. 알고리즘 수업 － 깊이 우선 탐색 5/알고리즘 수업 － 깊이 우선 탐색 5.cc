#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

long long total, seq;

int cnt = 1;

void dfs(vector <int> vc[], int start, bool visit[]) {
	//cout << "현재 방문 노드 :" << start << endl;
	visit[start] = true;
	for (int i = 0; i < vc[start].size(); i++) {
		int next = vc[start][i];
		if (visit[next] == false) {
			// cout << "total : " << total << "     /     " << "seq : " << seq << endl;
			seq++;
			cnt++;
			total += cnt * seq;
			// cout << next << " x " << seq << " = " << total << endl;
			dfs(vc, next, visit);
			seq--;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int vertex, edge, start; cin >> vertex >> edge >> start;

	vector <int>* vc = new vector<int>[vertex + 1];
	bool* visit = new bool[vertex + 1];

	fill(visit, visit + vertex + 1, 0);
	
	for (int i = 0; i < edge; i++) {
		int from, to; cin >> from >> to;
		vc[from].push_back(to);
		vc[to].push_back(from);
	}
	for (int i = 1; i < vertex + 1; i++) {
		sort(vc[i].begin(), vc[i].end());
	}

	dfs(vc, start, visit);

	cout << total;

}