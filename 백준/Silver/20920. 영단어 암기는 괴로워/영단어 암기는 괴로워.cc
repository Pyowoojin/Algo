#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(const pair <string, int>& a, const pair <string, int>& b) {
	// 단어 수 비교
	if (a.second != b.second)
		return a.second > b.second;

	if (a.first.size() != b.first.size())
		return a.first.size() > b.first.size();

	return a.first < b.first;
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