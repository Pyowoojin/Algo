#include <bits/stdc++.h>
using namespace std;

vector <int> ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector <vector <int>> vc(n + 1);
	queue <int> q;

	int* arr = new int[n + 1];
	fill(arr, arr + n + 1, 0);
	arr[0] = -1;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		vc[a].push_back(b);
	}

	for (int i = 0; i < vc.size(); i++) {
		// cout << i << " : ";
		for (int j = 0; j < vc[i].size(); j++) {
			// cout << vc[i][j] << " ";
			arr[vc[i][j]]++;
		}
		// cout << endl;
	}
//	cout << "=================\n";

	/*for (int i = 0; i < n + 1; i++) {
		cout << i << " : " << arr[i] << endl;
	}*/

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {
			if (arr[j] == 0) {
				arr[j] = -1;
				q.push(j);
			}
		}

		while (!q.empty()) {
			// 일단 연결된 노드들의 위상 1씩 감소시킬거임
			int l = q.front();
			for (int k = 0; k < vc[l].size(); k++) {
				arr[vc[l][k]]--;
			}
			ans.push_back(l);
			q.pop();
		}
	}

	for (auto i : ans)
		cout << i << " ";

}