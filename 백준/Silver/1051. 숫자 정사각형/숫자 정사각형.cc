#include <bits/stdc++.h>
using namespace std;

void prt(vector <vector<int>>& v1) {
	cout << endl;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j];
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	
	vector <int> v2(m, 0);
	vector <vector<int>> v1(n, v2);

	cin.ignore();

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			v1[i][j] = s[j] - '0';
		}
	}

	// prt(v1);

	int maxS = -99;

	for (int j = 0; j < m-1; j++) {
		for (int i = 0; i < n - 1; i++) {
			for (int l = i + 1; l < n; l++) {
				if (v1[i][j] == v1[l][j]) {
					for (int k = j + 1; k < m; k++) {
						if ((v1[i][j] == v1[i][k]) && (v1[l][j] == v1[l][k])) {
							if (l - i == k - j) {
								maxS = max(maxS, ((l + 1 - i) * (k + 1 - j)));
							}
						}
					}

				}
			}
		}
	}
	if (maxS == -99)
		maxS = 1;
	cout << maxS;

}