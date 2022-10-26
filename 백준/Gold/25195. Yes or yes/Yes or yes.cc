#include <bits/stdc++.h>
using namespace std;

bool success;

void dfs(vector <pair <int, vector <int>>>& graph, int x, bool arr[]) {
	arr[x] = true;

	// cout << "dfs 진입 방문 노드 : " << x + 1<< endl;
	// cout << "사이즈 : " << graph[x].second.size() << endl;
	if (graph[x].second.size() == 0) {
		success = true;
		return;
	}

	for (int i = 0; i < graph[x].second.size(); i++) {
		int nextX = graph[x].second[i];
		if (!arr[nextX] && graph[nextX].first != 1) {
			dfs(graph, nextX, arr);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;

	vector <pair <int, vector <int>>> graph(n);
	bool* arr = new bool[n];
	fill(arr, arr + n, false);

	for (int i = 0; i < m; i++) {
		int start, end; cin >> start >> end;
		graph[start-1].first = 0;
		graph[start - 1].second.push_back(end - 1);
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < graph[i].second.size(); j++) {
			cout << i + 1 << " 에서 " << graph[i].second[j] +1 << "\n";
		}
	}*/

	int gomgom; cin >> gomgom;

	for (int i = 0; i < gomgom; i++) {
		int t; cin >> t;
		graph[t - 1].first = 1;
	}

	dfs(graph, 0, arr);

	if (graph[0].first == 1)
		success = false;

	if (success)
		cout << "yes";
	else
		cout << "Yes";

}


