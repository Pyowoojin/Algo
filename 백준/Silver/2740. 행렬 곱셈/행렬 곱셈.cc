#include <bits/stdc++.h>
using namespace std;

void prt(vector <vector <int>>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			cout << vc[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m; cin >> n >> m;


	vector <vector <int>> vc(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vc[i][j];
		}
	}

	int k; cin >> m >> k;
	vector <vector <int>> vc2(m, vector<int>(k, 0));
	vector <vector <int>> ans(n, vector<int>(k, 0));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> vc2[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int l = 0; l < k; l++) {
			int c = 0;
			for (int j = 0; j < m; j++) {
				c += vc[i][j] * vc2[j][l];
			}
			ans[i][l] = c;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
}