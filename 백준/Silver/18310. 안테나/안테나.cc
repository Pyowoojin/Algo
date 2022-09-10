#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(vector <T> &v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> vc;
	
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
	}
	sort(vc.begin(), vc.end());

	if (vc.size() % 2 == 1) {
		cout << vc[vc.size() / 2];
	}
	else {
		int ans = 9999999;
		ans = min(vc[vc.size() / 2], vc[vc.size() / 2 -1]);
		cout << ans;
	}

}