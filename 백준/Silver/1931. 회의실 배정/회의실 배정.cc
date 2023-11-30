#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector <pair<int, int>> vc;

	int cnt = 1;

	for (int i = 0; i < n; i++) {
		int start, end; cin >> start >> end;
		vc.push_back({ end, start});
	}

	sort(vc.begin(), vc.end());
	int k = 1;
	int init = vc[0].first;
	while (k < vc.size()) {
		if (vc[k].second >= init) {
			cnt++;
			init = vc[k].first;
		}
		k++;
	}

	cout << cnt;


}