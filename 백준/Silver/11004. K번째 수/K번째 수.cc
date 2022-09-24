#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << "";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k; cin >> n >> k;

	vector <int> vc;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
	}

	sort(vc.begin(), vc.end());

	cout << vc[k - 1];

}