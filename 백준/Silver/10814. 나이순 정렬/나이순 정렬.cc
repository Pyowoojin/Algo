#include <bits/stdc++.h>
using namespace std;

bool ret(tuple<int, int, string > s1,tuple<int, int, string > s2) {
	if (get<0>(s1) == get<0>(s2))
		return get<1>(s1) < get<1>(s2);
	return get<0>(s1) < get<0>(s2);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector <pair<int, string>> ls;
	for (int i = 0; i < n; i++) {
		int t; string s; cin >> t >> s;
		ls.push_back({ t,s });
	}
	stable_sort(ls.begin(), ls.end(), ret);
	// cout << endl;
	for (int i = 0; i < n; i++) {
		cout << ls[i].first << " " << ls[i].second << '\n';
	}
}
