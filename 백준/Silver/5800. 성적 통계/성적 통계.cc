#include <bits/stdc++.h>
using namespace std;

void pr(const vector<vector<int>> v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector<tuple<int, int, int>> vt;
	vector <int> tmp;

	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		int max = 0;
		for (int j = 0; j < k; j++) {
			int z; cin >> z;
			tmp.push_back(z);
		}

		sort(tmp.begin(), tmp.end());

		for (int o = tmp.size()-1; o > -1; o--) {
			if (o > 0 && max < tmp[o] - tmp[o - 1]) {
				max = tmp[o] - tmp[o - 1];
			}
		}

		vt.push_back({ tmp[k - 1], tmp[0], max });
		tmp.clear();
	}

	for (int i = 0; i < vt.size(); i++) {
		cout << "Class " << i + 1 << '\n';
		cout << "Max " << get<0>(vt[i]) << ", " << "Min " << get<1>(vt[i]) << ", " << "Largest gap " << get<2>(vt[i]) << '\n';
	}


}