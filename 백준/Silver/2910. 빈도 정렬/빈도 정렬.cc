#include <bits/stdc++.h>
using namespace std;

bool comp(pair <int, pair <int, int>>& a, pair <int, pair <int, int>>& b) {
	if (a.second.first != b.second.first) {
		return a.second.first > b.second.first;
	}
	else {
		return a.second.second < b.second.second;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	map <int, pair <int, int>> mp;

	int n, c; cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		if (mp.find(c) == mp.end())
			mp.insert({ c,{1, i} });
		else
			mp[c].first++;
	}

	vector <pair <int, pair<int, int>>> vc(mp.begin(), mp.end());
	sort(vc.begin(), vc.end(), comp);

	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[i].second.first; j++)
			cout << vc[i].first << " ";
	}

}