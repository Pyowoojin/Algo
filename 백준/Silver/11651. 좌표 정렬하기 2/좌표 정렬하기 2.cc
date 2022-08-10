#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else
		return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector <pair<int, int>> lis;
	for (int i = 0; i < n; i++) {
		int tm, tbv; cin >> tm >> tbv;
		lis.push_back({ tm, tbv });
	}

	sort(lis.begin(), lis.end(), comp);

	for (auto i = lis.begin(); i != lis.end(); i++)
		cout << i->first << " " << i->second << '\n';

}