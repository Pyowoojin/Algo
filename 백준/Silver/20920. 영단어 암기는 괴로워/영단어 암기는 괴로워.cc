#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(const pair <string, int>& a, const pair <string, int>& b) {
	// 단어 수 비교
	if (a.second > b.second)
		return a.second > b.second;
	// 단어가 같다면
	else if (a.second == b.second) {
		// 단어 길이도 같다면
		if (a.first.size() == b.first.size()) {
			if (a.first == b.first)
				return false;
			else
				return a.first < b.first;
		}
		else
			return a.first.size() > b.first.size();
	}
	return a.second > b.second;
}

// 17 - 42
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	
	int n, m; cin >> n >> m;

	map <string, int> mp;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;

		if (s.length() >= m) {
			if (mp.find(s) == mp.end()) {
				mp.insert({ s, 0 });
			}
			else {
				mp[s]++;
			}
		}
	}

	vector <pair <string, int>> vc(mp.begin(), mp.end());
	sort(vc.begin(), vc.end(), cmp);

	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i].first << '\n';
	}

}