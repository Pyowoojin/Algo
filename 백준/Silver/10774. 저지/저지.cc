#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int satis = 0;
	int j, a; cin >> j >> a;
	vector <char> jersey(1);

	for (int i = 0; i < j; i++) {
		char c; cin >> c;
		jersey.push_back(c);
	}

	vector <pair <int, char>> vc;

	for (int i = 0; i < a; i++) {
		char c; int k; cin >> c >> k;
		vc.push_back({ k,c });
	}

	sort(vc.begin(), vc.end());

	for (int i = 0; i < vc.size(); i++) {
		if (jersey[vc[i].first] <= vc[i].second) {
			satis++;
			jersey[vc[i].first] = 'Z';
		}
	}

	cout << satis;
}