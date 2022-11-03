#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(const vector <T>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			cout << vc[i][j] << "";
		}
		cout << '\n';
	}
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, start; cin >> n >> start;

	vector <int> vc;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
	}

	int i = 0;
	int now = start;
	int ans = 0;
	while (1) {
		if (vc[i] < now) {
			ans = i;
			break;
		}
		
		i++;
		if (i == n) {
			i = 0;
		}
		now++;
	}
	cout << ans+1;
}


