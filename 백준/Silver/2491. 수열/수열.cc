#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	
	vector <int> lis;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		lis.push_back(t);
	}

	// 증가 최대 길이
	int incre = 0;
	int nowlen = 1;
	for (int i = 0; i < n; i++) {
		if (i + 1 != n && lis[i] <= lis[i + 1]) {
			nowlen++;
			continue;
		}
		if (nowlen > incre)
			incre = nowlen;
		nowlen = 1;
	}

	int decre = 0;
	nowlen = 1;
	for (int i = 0; i < n; i++) {
		if ((i + 1 != n) && (lis[i] >= lis[i + 1])) {
			nowlen++;
			continue;
		}
		if (nowlen > decre)
			decre = nowlen;
		nowlen = 1;
	}
	
	incre = incre > decre ? incre : decre;
	cout << incre;
}