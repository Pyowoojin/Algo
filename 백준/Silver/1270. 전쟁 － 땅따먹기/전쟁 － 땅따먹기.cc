#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool comp(pair<long long, int>& a, pair<long long, int>& b) {
	return a.second > b.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc; cin >> tc;
	while (tc) {

		int n; cin >> n;
		unordered_map <long long, int> mp;

		for (int i = 0; i < n; i++) {
			long long c; cin >> c;
			if (mp.find(c) != mp.end())
				mp[c] += 1;
			else
				mp.insert({ c, 1 });
		}

		vector <pair<long long, int>> vc(mp.begin(), mp.end());
		sort(vc.begin(), vc.end(), comp);

		float half = float(vc[0].second) / float(n) * 100;

		if (half > 50)
			cout << vc[0].first << '\n';
		else
			cout << "SYJKGW" << '\n';
		tc--;
	}
}