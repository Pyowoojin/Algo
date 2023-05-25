#include <bits/stdc++.h>
using namespace std;

bool comp(pair <string, int>& a, pair <string, int>& b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	else
		return a.first > b.first;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	map <string, int> mp;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (mp.find(s) == mp.end()) {
			mp.insert({ s,1 });
		}
		else
			mp[s]++;
	}
	vector <pair <string, int>> vc(mp.begin(), mp.end());
	sort(vc.begin(), vc.end(), comp);

	cout << vc[0].first << " " << vc[0].second;
}