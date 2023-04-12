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
	ios_base::sync_with_stdio(0);

	int r, c; cin >> r >> c;
	int ans = 0;
	
	vector <vector <int>> vc(r, vector <int>(c));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> vc[i][j];
		}
	}

	int z; cin >> z;

	for (int i = 0; i <= r - 3; i++) {
		for (int j = 0; j <= c - 3; j++) {

			vector <int> middle;
			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 3; l++) {
					middle.push_back(vc[k][l]);
				}
			}
			sort(middle.begin(), middle.end());
			if (middle[4] >= z)
				ans++;
		}
	}

	cout << ans;
}