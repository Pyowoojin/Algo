#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n; int l; cin >> l;
	vector <int> vc;
	int cnt = 0;

	int nowA = 0;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);

		nowA += c;
		
		// 알코올의 지속시간이 끝나면 빼주어야함
		if (i >= l) {
			nowA -= vc[i - l];
		}

		if (nowA <=138 && nowA >= 129) {
			cnt++;
		}
	}
	cout << cnt;

}