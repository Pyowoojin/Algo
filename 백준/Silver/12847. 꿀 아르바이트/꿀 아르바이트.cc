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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;

	vector <int> vc;

	long long sum = 0;
	long long maxN = -9999;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
		if (i < m) {
			sum += c;
			maxN = sum;
		}
		else {
			sum = sum - vc[i - m] + c;
			maxN = max(sum, maxN);
		}
	}
	cout << maxN;
}